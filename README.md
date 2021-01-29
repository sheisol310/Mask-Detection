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
| [opencv](https://github.com/opencv/opencv) | [LICENSE](licenses/LICENSE.head-pose-estimation) |
| [BrainMentors Pvt Ltd](https://www.youtube.com/watch?v=csYkGeJ5bCM&ab_channel=BrainMentorsPvtLtd) | [LICENSE](licenses/LICENSE.face-alignment) |

Project Collaborator： <br>
CS Student [Linkedin－Gene](https://www.linkedin.com/in/ching-kung-lin-878633196/) <br>
Vtuber [Youtube Channel－ProjectV. Akira Ch. アキラ](https://www.youtube.com/channel/UCA1cA4FFXrMivctVkcedavg) 

# Installation
## Software
*  Python3.9 (installation via [Pycharm](https://www.jetbrains.com/pycharm/) is recommended;)
*  Python libraries
  You can type, for example `pip install Pillow	8.1.0` in the terminal to install required packages
  *Pillow	8.1.0	
  *cycler	0.10.0	
  *joblib	1.0.0	
  *kiwisolver	1.3.1	
  *numpy	1.19.5	
  *opencv-python	4.5.1.48	
  *pip	21.0	
  *pyparsing	2.4.7	
  *python-dateutil	2.8.1	
  *scikit-learn	0.24.1	
  *scipy	1.6.0	
  *setuptools	52.0.0	
  *six	1.15.0	
  *threadpoolctl	2.1.0	

# How to Start
## 1.  Collect Face Data
**suggestion: To reduce misrecognition of face detection, you may want to use your camera with a clear background. 
  a. Run file "Collect Face Data-Without Mask" to collect 400 pictures of your face with no mask, and the file "wihout mask.npy" will be created. 
  b. Then wear your mask(Black Mask is hard to be detected), run file "Collect Face Data-Wear Mask" to collect 400 pictures of your face with mask, 
     and the file "with mask.npy" will be created.
  
## 2.  Begin to dectect
**suggestion: To reduce misrecognition of face detection, you may want to use your camera with a clear background. 
After collecting face data, run file "Detect Mask." The program will do machine learning by file "wihout mask.npy" and "with mask.npy." 
Within 10 seconds, the machine learning will be done, and the camera will be turned on again, then you can begin to put on / take off your mask to test if it works. 

# License
[MIT License](LICENSE)
