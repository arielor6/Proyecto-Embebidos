#ifndef DETECTION_HPP_INCLUDED
#define DETECTION_HPP_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>
using namespace std;
using namespace cv;


// initial values of the parameters of interests.
int cannyThreshold = 50;
int accumulatorThreshold = 15;
const int min_dist = 80;
const int min_radio = 10;
const int max_radio = 50;
Mat src, src_gray;

int main(int argc, char** argv);

#endif // DETECTION_HPP_INCLUDED
