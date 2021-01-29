#Using Camera To Collect Face Data (wearing mask)
import cv2 as cv
import numpy as np

#import front face dectection
face_Classifer = cv.CascadeClassifier("haarcascade_frontalface_default.xml")

#open camera
cap_face = cv.VideoCapture(0)

#array to store the face data
data = []

while cap_face.isOpened():
    ret, vid_frame = cap_face.read()
    if ret:
        gray_img = cv.cvtColor(vid_frame, cv.COLOR_BGR2GRAY)
        face_detect = face_Classifer.detectMultiScale(gray_img, 1.05, 6)

        #draw rectangle on dectected faces
        for x, y,w ,h in face_detect:
            cv.rectangle(vid_frame, (x, y), (x+w, y+h), (255, 0, 0), thickness=3)

            #collect each dected face
            #[difference of y axies, difference of x axies, all difference of z axies]
            face = vid_frame[y: y+h, x:x+w, : ]

            #make all faces into same size
            face = cv.resize(face, (50, 50))

            #print the number of detected faces it has collected
            print(len(data))

            #only collect 400 faces
            if len(data) < 400:
                data.append(face)

        cv.imshow("Result", vid_frame)

        #call stop if press ESC or collect 400 pics
        if cv.waitKey(1) == 27 or len(data) == 400:
            break

#save collected data
np.save("with_mask.npy", data)

cap_face.release()
cv.destroyAllWindows()



