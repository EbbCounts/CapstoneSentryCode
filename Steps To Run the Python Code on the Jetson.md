Steps to Run This Code:
Install Jetson.GPIO:

The library is pre-installed on most Jetson systems. If not, install it using:
bash
Copy code
sudo apt-get install python3-jetson-gpio
Run the Script with Root Privileges:

GPIO access requires root permissions:
bash
Copy code
sudo python3 stepper_motor_control.py
Connect the GPIO Pins:

Ensure the GPIO pins specified (17, 27, 22, 23) match your hardware connections.
Adjust Timing if Needed:

Modify the time.sleep(0.0005) values for pulse width and gap to suit your stepper motor and driver requirements.
