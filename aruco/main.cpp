#include <stdio.h>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/aruco.hpp>

#include "simpleRender.h"


int main(){
    cv::VideoCapture inputVideo;

    // Connecting to the virtual OBS camera
    // Change to 0 if you want to use webcam
    inputVideo.open(0);

    // Setting wrong but basic camera and distortion coefficients
    cv::Mat distCoeffs = (cv::Mat1d(4, 1) << 0, 0, 0, 0);
    cv::Mat cameraMatrix = (cv::Mat1d(3, 3) << 1, 0, 100, 0, 1, 100, 0, 0, 1);

    // fyi
    // You can read camera parameters from tutorial_camera_params.yml
    // readCameraParameters(filename, cameraMatrix, distCoeffs); // This function is located in detect_markers.cpp

    // Gets a dictionary of aruco markers
    cv::Ptr<cv::aruco::Dictionary> dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_6X6_250);

    time_t start, end;
    double mean = 0;
    int count = 0;

    // points defining constant cube shape
    std::vector< Point3f > cubePoints;
    cubePoints.push_back(Point3f(-.05, 0, 0));
    cubePoints.push_back(Point3f(0, .05, 0));
    cubePoints.push_back(Point3f(.05, 0, 0));
    cubePoints.push_back(Point3f(0, -.05, 0));
    cubePoints.push_back(Point3f(-.05, 0, 0));
    cubePoints.push_back(Point3f(-.05, 0, .0025));
    cubePoints.push_back(Point3f(0, .05, .0025));
    cubePoints.push_back(Point3f(.05, 0, .0025));
    cubePoints.push_back(Point3f(0, -.05, .0025));
    cubePoints.push_back(Point3f(-.05, 0, .0025));
            
    while (inputVideo.grab()) {
        int64 start = cv::getTickCount();

        cv::Mat image, imageCopy;
        inputVideo.retrieve(image);
        image.copyTo(imageCopy);

        std::vector<int> ids;
        std::vector<std::vector<cv::Point2f>> corners;
        cv::aruco::detectMarkers(image, dictionary, corners, ids);

        // if at least one marker detected
        if (ids.size() > 0) {
            cv::aruco::drawDetectedMarkers(imageCopy, corners, ids);
            std::vector<cv::Vec3d> rvecs, tvecs;
            cv::aruco::estimatePoseSingleMarkers(corners, 0.05, cameraMatrix, distCoeffs, rvecs, tvecs);

	    // draw axis for each marker
            for(int i=0; i<ids.size(); i++) {
                cv::aruco::drawAxis(imageCopy, cameraMatrix, distCoeffs, rvecs[i], tvecs[i], 0.1);
		// render shape
		for(int j=0; j<cubePoints.size()-1; j++)
	        	render_line_segment(imageCopy, cubePoints[j], cubePoints[j+1], rvecs[i], tvecs[i], cameraMatrix, distCoeffs, 1);
            }
	}
        cv::imshow("out", imageCopy);

        double fps = cv::getTickFrequency() / (cv::getTickCount() - start);
        mean = (mean * count + fps) / (count + 1);
        count++;
        std::cout << "FPS : " << fps << std::endl;
        
        char key = (char) cv::waitKey(10);
        if (key == 27)
            break;
    }
    std::cout << "Average FPS: " << mean << std::endl;
    return 0;
}
