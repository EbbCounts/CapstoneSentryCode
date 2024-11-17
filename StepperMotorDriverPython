import Jetson.GPIO as GPIO
import time

# This is going to be a lot easier to do in Python like you said, the Jetson already has a GPIO library for Python

# Pin Definitions
step_pin_x = 17  # GPIO pin for X-axis step (BCM numbering)
dir_pin_x = 27   # GPIO pin for X-axis direction
step_pin_y = 22  # GPIO pin for Y-axis step
dir_pin_y = 23   # GPIO pin for Y-axis direction

# Steps per unit (adjust according to your stepper motor and driver settings)
steps_per_unit_x = 10
steps_per_unit_y = 10

# Current position variables
current_x = 0
current_y = 0

# Desired position variables
desired_x = 0
desired_y = 0

# Setup GPIO pins
def setup_gpio():
    GPIO.setmode(GPIO.BCM)  # Use BCM pin numbering
    GPIO.setup(step_pin_x, GPIO.OUT, initial=GPIO.LOW)
    GPIO.setup(dir_pin_x, GPIO.OUT, initial=GPIO.LOW)
    GPIO.setup(step_pin_y, GPIO.OUT, initial=GPIO.LOW)
    GPIO.setup(dir_pin_y, GPIO.OUT, initial=GPIO.LOW)

# Move a stepper motor
def move_stepper(steps, step_pin, dir_pin, direction):
    GPIO.output(dir_pin, GPIO.HIGH if direction else GPIO.LOW)  # Set direction
    for _ in range(steps):
        GPIO.output(step_pin, GPIO.HIGH)
        time.sleep(0.0005)  # Pulse width (500 microseconds)
        GPIO.output(step_pin, GPIO.LOW)
        time.sleep(0.0005)  # Pulse gap

# Update the camera position
def update_camera_position():
    global current_x, current_y

    # Move X-axis
    if current_x < desired_x:
        steps = (desired_x - current_x) * steps_per_unit_x
        move_stepper(steps, step_pin_x, dir_pin_x, True)
        current_x = desired_x
    elif current_x > desired_x:
        steps = (current_x - desired_x) * steps_per_unit_x
        move_stepper(steps, step_pin_x, dir_pin_x, False)
        current_x = desired_x

    # Move Y-axis
    if current_y < desired_y:
        steps = (desired_y - current_y) * steps_per_unit_y
        move_stepper(steps, step_pin_y, dir_pin_y, True)
        current_y = desired_y
    elif current_y > desired_y:
        steps = (current_y - desired_y) * steps_per_unit_y
        move_stepper(steps, step_pin_y, dir_pin
