#include <stdio.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>    

using namespace cv;
using namespace std;

int main( int argc, char** argv )
{
    if( argc != 2)
    {
     cout <<" Usage: display_image ImageToLoadAndDisplay" << endl;
     return -1;
    }

    Mat image,fin_img;
    image = imread(argv[1], IMREAD_ANYCOLOR | IMREAD_ANYDEPTH);   // Read the file

    if(! image.data )                              // Check for invalid input
    {
        cout <<  "Could not open or find the image" << std::endl ;
        return -1;
    }

   namedWindow( "Display window", CV_WINDOW_AUTOSIZE );// Create a window for display.
                      // Show our image inside it.

    // Create Windows
    namedWindow("Red",1);
    namedWindow("Green",1);
    namedWindow("Blue",1);

    // Create Matrices (make sure there is an image in input!)

    Mat channel[3];
    imshow( "Original Image", image );


    // The actual splitting.
    split(image, channel);

    //OpenCV uses BGR! not RGB!
   channel[0]=Mat::zeros(image.rows, image.cols, CV_16UC1);//Set blue channel to 0
   channel[1]=Mat::zeros(image.rows, image.cols, CV_16UC1);//Set green channel to 0


    //Merging red and green channels

    merge(channel,3,image);
    imshow("R+G", image);
    imwrite("dest1.tif",image);

    waitKey(0);//Wait for a keystroke in the window
    return 0;
}