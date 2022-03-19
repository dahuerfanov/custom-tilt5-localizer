#include "simpleRender.h"

using namespace cv;


void render_line_segment(Mat img, Vec3f p1, Vec3f p2, Vec3d rvec, Vec3d tvec, InputArray cameraMatrix, InputArray distCoeffs, int thickness){

    std::vector< Point3f > linePoints;
    linePoints.push_back(p1);
    linePoints.push_back(p2);
    std::vector< Point2f > imagePoints;
    projectPoints(linePoints, rvec, tvec, cameraMatrix, distCoeffs, imagePoints);

    // draw axis lines
    line(img, imagePoints[0], imagePoints[1], Scalar(255, 255, 0), thickness);
}



