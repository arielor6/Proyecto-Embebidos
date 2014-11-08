/**
 * Referencia de: https://github.com/Itseez/opencv/blob/master/samples/cpp/tutorial_code/ImgTrans/HoughCircle_Demo.cpp
 * modificado por: Ariel Obando, Fabio Ugalde, Alejandro Vargas
 */

#include "Detection.hpp"

int main(int argc, char** argv)
{    
    // Read the image
    src = imread( "top.jpg", 1 );

    if( src.empty() )
    {
        std::cerr<<"Invalid input image\n";
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
        HoughCircles( src_gray, circles, CV_HOUGH_GRADIENT, 1, min_dist, cannyThreshold, accumulatorThreshold, min_radio, max_radio );
        
        // prints the number of detected circles
	int numCircles = circles.size();
	printf("Personas: %d\n",numCircles);

	  /// Draw the circles detected
	  for( size_t i = 0; i < circles.size(); i++ )
	  {
	      Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
	      int radius = cvRound(circles[i][2]);
	      // circle center
	      circle( src, center, 3, Scalar(0,255,0), -1, 8, 0 );
	      // circle outline
	      circle( src, center, radius, Scalar(0,0,255), 3, 8, 0 );
	   }

	  /// Show your results
	  namedWindow( "Conteo de Personas", CV_WINDOW_AUTOSIZE );
	  imshow( "Conteo de Personas", src );
        
        // get user key
        key = waitKey(10);
    }
    return 0;
}
