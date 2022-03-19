#ifndef RENDERLIB_INCLUDE_SIMPLERENDER_H_
#define RENDERLIB_INCLUDE_SIMPLERENDER_H_

#include <iostream>
#include <opencv2/calib3d.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>

using namespace cv;


void render_line_segment(Mat img, Vec3f p1, Vec3f p2, Vec3d rvec, Vec3d tvec, InputArray cameraMatrix, InputArray distCoeffs, int thickness);

#endif


