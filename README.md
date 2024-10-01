# Disk Shooting Robot
## Team Members: Diganto Haque, Soumik Sen

### Overview
This repository contains the code for a disk shooting robot. The robot is designed to move, aim, and launch disks using a remote control interface. It integrates multiple components, including motors, servo control, an infrared (IR) receiver for remote control input, and a liquid crystal display (LCD) for visual feedback. The robot can move forward, backward, and rotate, and the launcher mechanism allows for variable speed control.

### Features
- **Movement Control**: The robot’s wheels can be controlled to move forward, backward, and turn left or right.
- **Launcher Mechanism**: A motorized disk launcher that can be activated and deactivated, with adjustable speed via the remote control.
- **Servo Motor Control**: The robot includes a servo for aiming the launcher at different angles, which can be adjusted using the IR remote.
- **LCD Display**: Provides visual feedback to the user, showing messages or status updates during operation.
- **IR Remote Control**: The robot’s functions are controlled using a standard IR remote control. Each button press triggers a specific action, such as moving the wheels, adjusting the launcher speed, or changing the servo angle.
- **Pull-Back Mechanism**: An additional motor for a pull-back mechanism that can be activated to reset or prepare the launcher for the next shot.

### Components
- **IR Receiver**: Detects inputs from the IR remote control, allowing for wireless control of the robot’s movements and actions.
- **Servo Motor**: Used to adjust the angle of the launcher for aiming.
- **DC Motors**: Two DC motors for controlling the left and right wheels of the robot and two additional motors for the launcher and pull-back mechanism.
- **LCD Display (16x2)**: Provides a simple user interface, displaying feedback and status updates.
- **Arduino (or compatible microcontroller)**: The central controller of the robot, executing commands based on the IR remote inputs and controlling all other components.

### Hardware Pin Assignments
| Component         | Pin on Arduino  |
|-------------------|-----------------|
| Left Wheel Motor 1 | 3               |
| Left Wheel Motor 2 | 6               |
| Right Wheel Motor 1| 7               |
| Right Wheel Motor 2| 8               |
| IR Receiver        | 12              |
| Launcher Enable    | 5               |
| Launcher Motor 1   | 4               |
| Launcher Motor 2   | 2               |
| Servo Motor        | 9               |
| Pull Back Motor 1  | 10              |
| Pull Back Motor 2  | 11              |
| LCD I2C Address    | 0x27            |


### Installation
1. **Clone the repository**:

```bash
   git clone https://github.com/your-username/disk-shooting-robot.git
```
   
2. **Upload the code to your Arduino**: Open the code in the Arduino IDE and upload it to your Arduino board.
3. **Connect the hardware**: Assemble the robot and wire it according to the pin assignments listed above.
4. **Power the robot**: Once the hardware is connected, power the Arduino and ensure all motors and the IR receiver are functioning properly.

### IR Remote Control Commands
The robot is controlled using an IR remote, with each button corresponding to a specific action. Here are the key commands:

- **Move Forward**: `0xBF40FB04`
- **Move Backward**: `0xBE41FB04`
- **Turn Left**: `0xF906FB04`
- **Turn Right**: `0xF807FB04`
- **Start Launcher**: `0xBB44FB04`
- **Increase Servo Angle**: `0xFD02FB04`
- **Decrease Servo Angle**: `0xFC03FB04`
- **Fire Disk**: `0xE11EFB04`
- **Activate Pull-Back Mechanism**: `0xFE01FB04`
- **Reduce Launcher Speed**: `0xEE11FB04`
- **Increase Launcher Speed**: `0xED12FB04`

### How It Works
- **Movement Control**: The wheels are controlled using two DC motors connected to an H-bridge setup. Based on the IR remote commands, the robot moves forward, backward, or rotates.
- **Launcher**: The disk launcher is powered by a separate motor. It starts spinning when the appropriate remote command is received, and the speed can be adjusted dynamically. The launcher stops automatically after a preset duration.
- **Servo Control**: The angle of the launcher can be adjusted using the servo motor to aim higher or lower. This is controlled through the IR remote.
- **LCD Feedback**: On startup, the LCD displays a greeting message. It can be extended to show other messages based on the robot’s status (e.g., launcher ready, disk fired).

### Future Improvements
- **Collision Detection**: Adding sensors for obstacle detection to prevent crashes.
- **Autonomous Mode**: Implementing an autonomous mode where the robot can aim and shoot at targets without manual control.
- **Battery Status Indicator**: Display the battery level on the LCD screen.
  
### Acknowledgments
We would like to thank our instructor and mentors for their guidance and support throughout this project.

### License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

