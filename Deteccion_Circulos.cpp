/**
 * Referencia de: https://github.com/Itseez/opencv/blob/master/samples/cpp/tutorial_code/ImgTrans/HoughCircle_Demo.cpp
 * modificado por: Ariel Obando, Fabio Ugalde, Alejandro Vargas
 */

#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>

using namespace std;
using namespace cv;

namespace
{
    // initial values of the parameters of interests.
    const int cannyThreshold = 200;
    const int accumulatorThreshold = 50;
}


int main(int argc, char** argv)
{
    Mat src, src_gray;

    if (argc < 2)
    {
        std::cerr<<"No input image specified\n";
        std::cout<<usage;
        return -1;
    }

    // Read the image
    src = imread( argv[1], 1 );

    if( src.empty() )
    {
        std::cerr<<"Invalid input image\n";
        std::cout<<usage;
        return -1;
    }

    // Convert it to gray
    cvtColor( src, src_gray, COLOR_BGR2GRAY );

    // Reduce the noise so we avoid false circle detection
    GaussianBlur( src_gray, src_gray, Size(9, 9), 2, 2 );

    // infinite loop to display
    // and refresh the content of the output image
    // until the user presses q or Q
    int key = 0;
    while(key != 'q' && key != 'Q')
    {
        // those paramaters cannot be =0
        // so we must check here
        cannyThreshold = std::max(cannyThreshold, 1);
        accumulatorThreshold = std::max(accumulatorThreshold, 1);

        // will hold the results of the detection
        std::vector<Vec3f> circles;
        // runs the actual detection
        HoughCircles( src_gray, circles, HOUGH_GRADIENT, 1, src_gray.rows/8, cannyThreshold, accumulatorThreshold, 0, 0 );
        
        // prints the number of detected circles
        printf("%d\n", circles.size());
        
        // get user key
        key = waitKey(10);
    }
    return 0;
}
