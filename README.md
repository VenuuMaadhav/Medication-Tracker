# Medication-Tracker

# 1.Abstract

People suffering from diseases like Alzheimer’s, Huntington’s disease, Corticobasal Degeneration etc ften experience with memory loss and difficulty in remembering things. Such people and old agepeople often forget to take their regular medication which might affect their physical as well as mentalhealth. A working model with the help of IFTTT and Adafruit Cloud helps patients keep track of theirmedicine consumption on daily basis and reminds them to take medicines on time and also refill the edicines on weekly basis via an Audio-Visual Stimuli.

# 2. Introduction
The main objective of the project is to provide a remedy to Old-age people who forget to take their medicines on-time which might affect their physical and mental health. I considered Alzheimer’s patients in the process of crafting the solution. In the real world there is no remedy which are focused on the above-mentioned problems and also which might be a hardware solution integrated with IoT.
I developed a working model of a Medication tracker using with low level communication protocol and cloud which helps patients keep track of their medicine consumption on daily basis and reminds them to take medicines on time and also refill the medicines on weekly basis via an Audio-Visual Stimuli. In addition, there is an SMS, Email featutre to notify the patient's guardian for any panic attacks or Medical Emergency

# 3)Proposed methodology

1. First Step, we created a cloud account in Adafruit.io
2. We will be using Adafruit for storing the User Input feed.
3. We have created an applet with IFTTT with the same credentials and also integrate theArduino code with it.
4. IFTTT will help in determining if the medication is taken or not.
5. In response to that, Adafruit will store that information in the created cloud account.
6. The reminders will send either as email or messages via Mobile application.
7. If necessary, We can attach a GSM module to the device, so that we can generate a SMS message.
5. Module description

# Software requirements
▪ Arduino IDE
▪ Adafruit cloud account
▪ Mobile Installed with IFTT App

# Hardware Requirements
▪ Bread Board
▪ Humidity Sensor
▪ Temperature Sensor
▪ Node MCU
▪ LED
▪ Buzzer
▪ Resistors
▪ Jumper wires
