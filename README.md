# custom-tilt5-localizer

Localization module for Tilt5 project

## Aruco

Average FPS using webcam was 183.698 is latest run. This includes drawing detections and axis of the marker.

### Instructions

#### Build the render library
1. `cd custom-tilt5-localizer/renderLib`
2. `mkdir build`
3. `cd build`
4. `cmake ..`
5. `make`

#### Build the project

1. `cd custom-tilt5-localizer`
2. `mkdir build`
3. `cd build`
4. `cmake ..`
5. `make`
6. Create an aruco marker running `./Create_marker.o`
7. Start detecting arucos in you camera with `./Aruco.o`.
8. Stop with `Esc` and read the average from terminal.

By default `Aruco.o` tries to use input 0 (webcam). Change this to 1 in `main.cpp` if you want to use another camera.
