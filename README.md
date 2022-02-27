# custom-tilt5-localizer

Localization module for Tilt5 project

## Aruco

Average FPS using webcam was 183.698 is latest run. This includes drawing detections and axis of the marker.

### Instructions

1. `cd aruco`
2. `cmake .`
3. `make`
4. Create an aruco marker running `./Create_marker.o`
5. Start detecting arucos in you camera with `./Aruco.o`.
6. Stop with `Esc` and read the average from terminal.

By default `Aruco.o` tries to use input 1 (in my case virtual OBS camera). Change this to 0 in `main.cpp` if you want to use your webcam.
