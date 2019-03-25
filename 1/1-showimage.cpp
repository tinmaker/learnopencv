#include <iostream>
#include <opencv/highgui.h>
using namespace std;
using namespace cv;

int main(int argc, char const *argv[])
{
	IplImage * img = cvLoadImage(argv[1]);

	cvNamedWindow("showimage", CV_WINDOW_AUTOSIZE);
	cvShowImage("showimage", img);
	cvWaitKey(0);
	cvReleaseImage(&img);
	cvDestroyWindow("showimage");
	return 0;
}