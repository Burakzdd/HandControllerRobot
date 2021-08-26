# HandControllerRobot

In this study, the NRF24L01 modules were communicated to transmit commands to the robot according to the status of the mvu 6050. This 3 axis gyro and 3 axis angular accelerometer determines the rotation direction and speed by comparing the angular ratios of the axes of a fixed object. When the acceleration sensor tilts to the right, the right motor goes forward left motor backward and the right led flashes. When acceleration sensor tilts left, left motor goes forward, right motor goes backward and the left led flashes. When the sensor is tilted forward, the motors go forward and both leds turn on. As the angle of inclination made by the mpu 6050 increases, the rotation speed of the motors increases. Motors do not move when the acceleration sensor is in balance position. Flowchart and block diagram give information about this study in Figure 1 and Figure 2.
![alt text](https://github.com/Burakzdd/HandControllerRobot/blob/main/system%20flowchart.png)

Figure 1
![alt text](https://github.com/Burakzdd/HandControllerRobot/blob/main/blog%20diagram.png)


Figure 2

## Materials 
### Arduino Uno/Nano

Arduino is an electronic platform based on hardware and software that can be used in many projects. The boards to be used in the proposed method is the ATmega328P microcontroller based nano model given in to the left of Figure 3 and the Atmega 328 microcontroller based uno model given in to the right of Figure3.
![alt text](https://github.com/Burakzdd/HandControllerRobot/blob/main/arduino.png)
###	Nrf24L01 + Adaptor Modul

Nrf24L01 module can perform many functions such as wireless communication of two or more Arduino boards with each other, data transfer, robot control. The NRF24L01 wireless module transmits and receives data at a specific frequency called a channel. Also, in order for two or more transceiver modules to communicate with each other, they must be on the same channel. This channel can be any frequency in the 2.4 GHz ISM band, or to be more precise, it can be between 2.400 and 2.525 GHz (2400 to 2525 MHz). Nrf24L01 may have problems working with 3.3 volts and there may be interference and can be used with the help of the adapter at the bottom of Figure 4 to eliminate them.
![alt text](https://github.com/Burakzdd/HandControllerRobot/blob/main/nrf.png)

###  MPU 6050

Mpu 6050 is an acceleration and gyroscope sensor used in aircraft, balance robots and remote-controlled devices such as UAVs and UGVs. It is an IMU sensor board with 3-axis gyro and 3-axis angular accelerometer. Since it has a voltage regulator on it, it is supplied with voltage between 3v and 5v. The ratio of the value measured from the accelerometer to the value measured at 90 degrees gives us the sine of the angle made in the X axis. sin (αx) = will be the measured g value / the maximum measurable g value. Euler Angle calculation can be used for more accurate angle calculation. The angles made on the X and Y axis according to this calculation are:
![alt text](https://github.com/Burakzdd/HandControllerRobot/blob/main/mpu.png)

### Motors and Motor Driver (L298N)
With Arduino, the DC motor can go forward or backward and its rotation speed can be adjusted. The current supplied to the motors from the Arduino is not sufficient to run the motors. Therefore, dc motors are used with a motor driver. The L298N module in the middle of Figure 5 is an example of a motor drive.
![alt text](https://github.com/Burakzdd/HandControllerRobot/blob/main/motor.png)

### Other Materials
LED, switch, battery and breadboard are also used in this study. Led has two legs, anode and cathode. The anode leg corresponds to the + pole and the cathode leg to the - pole. Cathode
- its leg is connected to GND (ground line) in our circuit. It has two states, open or closed. There is electricity transmission in the closed state, no electricity transmission in the open state. Devices that directly convert chemical energy into electrical energy and store it within are called batteries.[12] In this study, 6 batteries of 1.5 volt are used in the receiver and one 9-volt battery are used in the transmitter. Breadboard allows easy testing of established circuits without soldering to each other.

## EXPERIMENTAL RESULTS
In this study, firstly, the motors is connected to the driver and the driver to the Arduino. NRF24L01 module is connected to Arduino and turned into receiver position. NRF24L01 at the transmitter position is connected to the arduino. The MPU6050 sensor is connected to the transmitter. The codes is uploaded to the Arduino's. Power connections is made to the circuits. The robot is moved by sending information to the robot (receiver) according to the position of the MPU650. There was a communication problem with this source NRF24 modules. This trouble was solved using the NRF24L01 Module Adapter. Camera is tried to be used in this project. Image transfer was provided from the OV7670 camera via PC, but its use was abandoned because the camera module could not be connected wirelessly. The design of the system is shown in Figure 7.

![alt text](https://github.com/Burakzdd/HandControllerRobot/blob/main/sytem_design.png)
