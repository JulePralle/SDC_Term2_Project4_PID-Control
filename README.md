
# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---


[//]: # (Image References)

[image1]: ./writeup/Simulator.jpg "Introduction Image of Simulator"
[image2]: ./writeup/PID_varyingP.jpg "Example of P-Control (https://en.wikipedia.org/wiki/PID_controller#/media/File:PID_varyingP.jpg)"
[image3]: ./writeup/PID_varyingD.jpg "Example of D-Control (https://en.wikipedia.org/wiki/PID_controller#/media/File:Change_with_Kd.png)"
[image4]: ./writeup/PID_varyingI.jpg "Example of I-Control (https://en.wikipedia.org/wiki/PID_controller#/media/File:Change_with_Ki.png)"



## Introduction 
In this project, a PID controller should be programed in C++ to maneuver the vehicle around a track in the udacity simulator. The simulator provides the cross track error (CTE) and the velocity (mph) in order to compute the appropriate steering angle.

![alt text][image1]

## PID Control Components

### P - Proportional
The proportional control system is defined as `Kp * CTE` and is a type of linear feedback control system. We can control the oscillation by this parameter, the higher this value the faster it will oscillates.

![alt text][image2]

### D - Differential Control
The differential control system is defined as `Kd * (CTE_t - CTE_t-1)/delta_t`. The slope of the error (CTE) whch is  rate of change will be determinated over time and multiplied by the derivative gain `Kd`. This control is able to prevent the controller from overshooting. The higher value of `Kd` the slower the control will reach the value 0.

![alt text][image3]

### I - Integral Control
The integral control system is defined as `Ki * sum(CTE)`. The integral in a PID controller is the sum of the error (CTE) over time to give the accumulated system bias, which can then be corrected. The smaller value of `Ki` the slower the system bias is removed. 

[alt text][image4]


## Defining Hyperparameters
In this project I used manual tuning to chose the final hyperparameters (Kp, Kd, Ki) for the PID-controller of the steering. I set the throttle to a small constant value of 0.1 which leads to a speed of 7 to 9 mph in the simulator. Then I optimized every hyperparameter at a time. I first tuned my Kp so that the car could complete at least the beginning of the track. Then I added Kd to reduce the osciallations. Then once I had tuned Kp and also Kd, I started to add Ki. The hyperparameter Ki needed to be quite small for a smoother ride. 
Here are the final result of my manual tuning of hyperparameters:

* Kp: 0.17
* Ki: 0.0000001
* Kd: 3.2


## Discussion
Here I implemented a basic solution to maneuver the vehicle around the given track. I chose the hyperparameters of the PID-controller for steering with manual tuning and set the throttle value to a small constant value. 
To improve the outcome of the project, I would suggest the following steps:
* use also PID-controller for the velocity (by controlling the throttle value)
* use the twiddle method to tune the hyperparameters


## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets 
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.

There's an experimental patch for windows in this [PR](https://github.com/udacity/CarND-PID-Control-Project/pull/3)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 

## Editor Settings

We've purposefully kept editor configuration files out of this repo in order to
keep it as simple and environment agnostic as possible. However, we recommend
using the following settings:

* indent using spaces
* set tab width to 2 spaces (keeps the matrices in source code aligned)

## Code Style

Please (do your best to) stick to [Google's C++ style guide](https://google.github.io/styleguide/cppguide.html).

## Project Instructions and Rubric

Note: regardless of the changes you make, your project must be buildable using
cmake and make!

More information is only accessible by people who are already enrolled in Term 2
of CarND. If you are enrolled, see [the project page](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/f1820894-8322-4bb3-81aa-b26b3c6dcbaf/lessons/e8235395-22dd-4b87-88e0-d108c5e5bbf4/concepts/6a4d8d42-6a04-4aa6-b284-1697c0fd6562)
for instructions and the project rubric.

## Hints!

* You don't have to follow this directory structure, but if you do, your work
  will span all of the .cpp files here. Keep an eye out for TODOs.

## Call for IDE Profiles Pull Requests

Help your fellow students!

We decided to create Makefiles with cmake to keep this project as platform
agnostic as possible. Similarly, we omitted IDE profiles in order to we ensure
that students don't feel pressured to use one IDE or another.

However! I'd love to help people get up and running with their IDEs of choice.
If you've created a profile for an IDE that you think other students would
appreciate, we'd love to have you add the requisite profile files and
instructions to ide_profiles/. For example if you wanted to add a VS Code
profile, you'd add:

* /ide_profiles/vscode/.vscode
* /ide_profiles/vscode/README.md

The README should explain what the profile does, how to take advantage of it,
and how to install it.

Frankly, I've never been involved in a project with multiple IDE profiles
before. I believe the best way to handle this would be to keep them out of the
repo root to avoid clutter. My expectation is that most profiles will include
instructions to copy files to a new location to get picked up by the IDE, but
that's just a guess.

One last note here: regardless of the IDE used, every submitted project must
still be compilable with cmake and make./
