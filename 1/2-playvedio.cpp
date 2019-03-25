#include <iostream>
#include <opencv/highgui.h>

using namespace std;
using namespace cv;

int main(int argc, char const *argv[])
{
	CvCapture * capture = cvCreateCameraCapture(1);
	// CvCapture * capture = cvCreateFileCapture(argv[1]);
	IplImage * frame;
	cvNamedWindow("play video", CV_WINDOW_AUTOSIZE);
	int count = 0;
	while(true)
	{
		frame = cvQueryFrame(capture);
		if(!frame)
		{
			break;
		}
		count++;
		cvShowImage("play video", frame);
		printf("%d\n", count);
		char c = cvWaitKey(33);
		if(c==27){break;}
	}
	cvReleaseCapture(&capture);
	cvDestroyWindow("play video");

	return 0;
}