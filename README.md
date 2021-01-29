# Please Read It thoroughly To Know How To Run This Program

# Mask-Detection-Version1
Use camera and Python machine learning algorithms to detect if users wear a mask!

This is a working-together project: Gene & Akria

Youtube Video for coding explnation:
[![test](https://github.com/sheisol310/Mask-Detection-Version1/blob/main/images/mask%20detectioin%20thumbnail.jpeg?raw=true)](https://www.youtube.com/channel/UCA1cA4FFXrMivctVkcedavg)
--------------------------------------------------------------------------------
# Credits
First of all, I'd like to give credits to the following projects that I borrow code from:

| Project | LICENSE |
|:---:|----|
| [opencv](https://github.com/opencv/opencv) | [LICENSE](https://github.com/opencv/opencv/blob/master/LICENSE) |

Program's source <br>
Youtuber Video : [BrainMentors Pvt Ltd - Live Implementation of Face Mask Detection using Python| OpenCV | Machine Learning | Webinar](https://www.youtube.com/watch?v=csYkGeJ5bCM&ab_channel=BrainMentorsPvtLtd) <br>

Project Collaborator： <br>
CS Student [Linkedin－Gene](https://www.linkedin.com/in/ching-kung-lin-878633196/) <br>
Vtuber [Youtube Channel－ProjectV. Akira Ch. アキラ](https://www.youtube.com/channel/UCA1cA4FFXrMivctVkcedavg) 

# Installation
## Software
*  Python3.9 (installation via [Pycharm](https://www.jetbrains.com/pycharm/) is recommended)
*  Python libraries<br>
  You can type, for example `pip install Pillow	8.1.0` in the terminal to install required packages<br>
  *Pillow	8.1.0	<br>
  *cycler	0.10.0	<br>
  *joblib	1.0.0	<br>
  *kiwisolver	1.3.1	<br>
  *numpy	1.19.5	<br>
  *opencv-python	4.5.1.48	<br>
  *pip	21.0	<br>
  *pyparsing	2.4.7	<br>
  *python-dateutil	2.8.1	<br>
  *scikit-learn	0.24.1	<br>
  *scipy	1.6.0	<br>
  *setuptools	52.0.0	<br>
  *six	1.15.0	<br>
  *threadpoolctl	2.1.0	<br>

# How to Start
## 1.  Collect Face Data<br>
**suggestion: To reduce misrecognition of face detection, you may want to use your camera with a clear background. <br>**
  a. Run file "Collect Face Data-Without Mask" to collect 400 pictures of your face with no mask, and the file "wihout mask.npy" will be created.<br> 
  b. Then wear your mask(Black Mask is hard to be detected), run file "Collect Face Data-Wear Mask" to collect 400 pictures of your face with mask, 
     and the file "with mask.npy" will be created.<br>

## 2.  Begin to dectect<br>
After collecting face data, run file "Detect Mask." The program will do machine learning by file "wihout mask.npy" and "with mask.npy." <br>
Within 10 seconds, the machine learning will be done, and the camera will be turned on again, then you can begin to put on / take off your mask to test if it works. <br>

## 3. Demonstration
If you run the program successfully, you should see following:
<p align="center">
  <img src="images/detection result.gif", width="45%">
  <img src="images/mask result .gif", width="45%">
  <br>
</p>

## 4. Tutroal Video
**If you are still confused about how to run the program or any codes in the program, check the video below : <br>**
[]()
# Conclusion
## Advantages : Quick data collection to support machine learning.<br>
## Disadvantages : Wrong data collection due to face misdetection, which will give wrong data to machine learning.<br>
## Solution : Create database with correct face data (with and without mask) in order to increase the acurracy of dectection. <br>
  **To create database, instread of collecting face data with camera, setting two files "with mask" and "without mask" with all correct images.<br>
  ** The Solution will be tested and applied in ongoing Project2 (Mask Detection Verion2)<br>
  
# License
[MIT License](LICENSE.txt)
