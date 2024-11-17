#include <iostream>
#include <thread>   // For sleep_for
#include <chrono>   // For duration

//current x and y variables
//these represent what the camera is currently pointing at
//these will change as the motors spin, moving the camera

int currentX = 0;
int currentY = 0;

//desired x and y variables
//these represent what the camera wants to point at
//these will change as the drone moves
//these numbers will be taken from the neural network and updated dynamically

int desiredX = 0;
int desiredY = 0;

//the goal is to have both sets of x and y variables be the same, signifying that the camera is pointing at the drone



// Speed variables for controlling motor adjustments
int adjustmentSpeedX = 1; // speed at which X position adjusts
int adjustmentSpeedY = 1; // speed at which Y position adjusts

// Update function to move currentX and currentY towards desiredX and desiredY
void updateCameraPosition() {
    // Adjust currentX towards desiredX
    if (currentX < desiredX) {
        currentX += adjustmentSpeedX;
        if (currentX > desiredX) currentX = desiredX; // Clamp to avoid overshoot
    } else if (currentX > desiredX) {
        currentX -= adjustmentSpeedX;
        if (currentX < desiredX) currentX = desiredX; // Clamp to avoid overshoot
    }

    // Adjust currentY towards desiredY
    if (currentY < desiredY) {
        currentY += adjustmentSpeedY;
        if (currentY > desiredY) currentY = desiredY; // Clamp to avoid overshoot
    } else if (currentY > desiredY) {
        currentY -= adjustmentSpeedY;
        if (currentY < desiredY) currentY = desiredY; // Clamp to avoid overshoot
    }
}

// Main loop
void loop() {
    while (true) {
        // Simulate updating desiredX and desiredY from neural network data
        // For example, desiredX = ... ; desiredY = ... ;

        // Update the current camera position towards the desired position
        updateCameraPosition();

        // Print the current position for debugging
        std::cout << "Current Position: (" << currentX << ", " << currentY << ")" << std::endl;


        // Check if the camera is pointing at the desired position
        if (currentX == desiredX && currentY == desiredY) {
            // Camera is aligned with the desired position
            std::cout << "Camera is aligned with the desired position." << std::endl;
            // Take necessary action or keep the camera steady
        } else {
            // Camera is moving towards the desired position
            // Optionally, update the motors here based on currentX and currentY
        }

        // Add a delay to control update speed
        // Pause for 50 milliseconds to control update speed
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}

int main() {
    // Set initial desired position for testing
    //the desired X and Y will come from the Neural Network
    desiredX = 10;
    desiredY = 10;

    // Run the main loop
    loop();

    return 0;
}