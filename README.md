# 2d_mapping_tof_sensor_vl53l0x
# ABSTRACT
The main purpose of this project is to create a 2D map of a specific area using an infrared ToF sensor. ToF sensors use infrared light to determine depth information. In the software part of the project, motor and sensor controls are made via Arduino IDE. Arduino UNO, servo motor and GY-53 VL53L0X ToF Sensor are used in the hardware part of the project. The data coming from the sensor is transferred to the MATLAB environment by serial port communication. This data is then processed and printed on the screen. With the GUI created in the MATLAB environment, users can easily perform mapping operations.
# APPLICATIONS
In this section, the connections of the materials described in the introduction section and the software part of the project will be explained.
Hardware Architecture
First of all, in order for the measurements to be accurate, no cables should pass in front of the sensor. Therefore, the sensor was placed on a small breadboard. Here it is very important that the breadboard is light. Because this breadboard will be rotated by a servo motor. Since the servo motor used is not very powerful, it may not reach the desired angle values in case of excessive weight loading. Moreover, in overload situations, the current drawn by the motor will increase and this may damage the motor and Arduino UNO. The breadboard was joined to the propeller part of the servo motor with the help of a silicone gun. Then, the connection of the servo motor and sensor with Arduino UNO was performed as shown in the Figure 1. 
 ![alt text](https://github.com/ozancanalper/2d_mapping_tof_sensor_vl53l0x/blob/main/1.png)
Figure 1: Connection Diagram of Robot

# I2C Protocol
I2C is a serial protocol for two-wire interface to connect low-speed devices like microcontrollers, EEPROMs, A/D and D/A converters, I/O interfaces and other similar peripherals in embedded systems. It provides communication with SCL and SDA pins. The SCL is called the serial clock and is the part that triggers the data transfer. SDA is called serial data and is the part where data is transferred. The I2C protocol operates three modes such as: fast mode, high-speed mode and standard mode wherein the standard mode data speed ranges 0Hz to 100Hz, and the fast mode data can transfer with 0Hz to 400 KHz speed and the high speed mode with 10 KHz to 100KHz. The 9-bit data is sent for each transfer wherein 8-bits are sent by the transmitter MSB to LSB, and the 9th bit is an acknowledgement bit sent by the receiver.

# Software Architecture
The software part of our project consists of two stages. The first of these is to provide sensor data and motor position controls on the Arduino IDE. The second stage is the simultaneous transfer of the measured sensor data to MATLAB and the creation of the map by processing these transferred data. In order to receive data from Arduino, COM Port from MATLAB was connected to Arduino's serial port screen. Then, the data printed here were simultaneously transferred to MATLAB via COM Port. A 2-dimensional map of the robot's environment was created with the transferred data.
A GUI has been created in the MATLAB environment for users to perform this mapping process more easily and the project to be more useful. The created GUI is shown in Figure 2.
 ![alt text](https://github.com/ozancanalper/2d_mapping_tof_sensor_vl53l0x/blob/main/2.png)
Figure 2: GUI of the project

When the Comport Connection button is pressed, the system is made ready for Comport connection. When the start button is pressed, the compport connection is started and the distance data starts to be received from the arduino serial port. These received data are printed on the screen between 0-180 degrees in polar coordinates. The Clear button is for clearing the plotting screen.
