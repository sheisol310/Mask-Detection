#Dectect if you wear a mask after the program did machine learning with face data
import cv2 as cv
import numpy as np
from sklearn.svm import SVC #svm - Support Vector Machine; SVC - Support Vector Classsification
from sklearn.metrics import accuracy_score #check the data's accuracy
from sklearn.model_selection import train_test_split #divide your data into train group and test group to do machine learning
from sklearn.decomposition import PCA #principal component analysis, to perform dimesionality reduction - to reduce a large amout of data into small amount

#loading the face data
with_mask = np.load("with_mask.npy")
without_mask = np.load("without_mask.npy")

#before reshape: (400, 50, 50, 3) = 200 pictures, each picture's x = 50, y = 50, with 3 channels
#after reshape : (400, 50*50*3)  x = 200, y = 50*50*3 => a big picture with size 200*7500
# reason: to assign
with_mask = with_mask.reshape(400, 50*50*3)
without_mask = without_mask.reshape(400, 50*50*3)

# # check size of reshape
# print(with_mask.shape)
# print(without_mask.shape)

#Concatenation in numpy
combine_set = np.r_[with_mask, without_mask]

#create all 0 array with size of combine_mask
labels = np.zeros(combine_set.shape[0])

#assign 1 to tag picture of without_mask
labels[400: ] = 1

#using the method of train_test-check import train_test_split
#train_test_split(x , y , test_size)- 25% of data = test group  75% of data = train group
x_train, x_test, y_train, y_test = train_test_split(combine_set, labels, test_size=0.25)

#reduce the number of 7500 colors by using PCA, huge data slow down the speed of mahcine learning
pca = PCA(n_components=3)
x_train = pca.fit_transform(x_train)

#import SVC - Support Vector Classsification
#using classification to do machine learning
svm = SVC() #call SVC()
svm.fit(x_train, y_train) #match x and y train group

#reduce the size of x_test group
x_test = pca.transform(x_test)

#check the prediction of x test group to see how accurate the predition is after machines learning on train group
y_predict = svm.predict(x_test)
result = accuracy_score(y_test, y_predict) #apply the check score to check the accuracy
print("Accuracy Of The Machine Learning: ",result)

#machine learning is done

#Using camera to test the program
#import front face dectection
face_Classifer = cv.CascadeClassifier("haarcascade_frontalface_default.xml")

#open camera to collect the face data
cap_face = cv.VideoCapture(0)

#check dictionaries on python, 0 is mask, 1 is no mask
names = {0: "Mask", 1: "No Mask"}

while cap_face.isOpened():
    ret, vid_frame = cap_face.read()
    if ret:
        gray_img = cv.cvtColor(vid_frame, cv.COLOR_BGR2GRAY)
        face_detect = face_Classifer.detectMultiScale(gray_img, 1.1, 4)

        #draw rectangle on dectected faces
        for x, y,w ,h in face_detect:
            cv.rectangle(vid_frame, (x, y), (x+w, y+h), (255, 0, 0), thickness=3)

            #keep copying the detected faces
            face = vid_frame[y:y+h, x: x+w, :]

            #resize the face in 50*50 (the size of pic we put into machine learning)
            face = cv.resize(face, (50, 50))

            #face.shape = (1, 7500)
            #get to know reshape (1, -1): https://www.youtube.com/watch?v=3wi0lJPfLUY&ab_channel=BhaveshBhatt
            face = face.reshape(1, -1)

            #reduce the size of (1, 7500)
            face = pca.transform(face)

            #use the predict method, the predict of face is either 0 or 1
            #when call svm.predict, it gets the learning data from previous program
            prediction = svm.predict(face)

            # 0 is mask, 1 is no mask to word_of_prediction
            Word_of_prediction = names[int(prediction)]
            print(Word_of_prediction)

            #put the text on the rectangle
            font = cv.FONT_HERSHEY_DUPLEX
            cv.putText(vid_frame, Word_of_prediction, (x, y), font, 1, (0, 255, 0), 2)

        cv.imshow("Result", vid_frame)

        #call stop when pressing ESC
        if cv.waitKey(1) == 27:
            break

cap_face.release()
cv.destroyAllWindows()

#using machine learning to train program reconginzing with and without mask picture
#machine learning = math + programming
#defn: what we want is a machine that can learn from experiences
#supervised: classification(logistic regression, SVM, decision tree)
#unsupervised
#semi=supervised
#reinforcement learning

