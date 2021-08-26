# HandControllerRobot

In this study, the NRF24L01 modules were communicated to transmit commands to the robot according to the status of the mvu 6050. This 3 axis gyro and 3 axis angular accelerometer determines the rotation direction and speed by comparing the angular ratios of the axes of a fixed object.[5] When the acceleration sensor tilts to the right, the right motor goes forward left motor backward and the right led flashes. When acceleration sensor tilts left, left motor goes forward, right motor goes backward and the left led flashes. When the sensor is tilted forward, the motors go forward and both leds turn on. As the angle of inclination made by the mpu 6050 increases, the rotation speed of the motors increases. Motors do not move when the acceleration sensor is in balance position. Flowchart and block diagram give information about this study in Figure 1 and Figure 2.
![alt text](https://github.com/Burakzdd/HandControllerRobot/blob/main/system%20flowchart.png)
![alt text](https://github.com/Burakzdd/HandControllerRobot/blob/main/blog%20diagram.png)

