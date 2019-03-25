#include <iostream>
#include <opencv/highgui.h>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

Mat src, gray_src;
int thresh  = 130;
int max_count = 255;
void harris_demo(int , void*);

int main(int argc, char const *argv[])
{
	src = imread(argv[1]);
	if (src.empty())
	{
		/* code */
		cout<<"can not open image\n";
		return 1;
	}

	namedWindow("input", CV_WINDOW_AUTOSIZE);
	imshow("input", src);

	namedWindow("output", CV_WINDOW_AUTOSIZE);
	cvtColor(src, gray_src, COLOR_BGR2GRAY);
	createTrackbar("threshshold", "output", &thresh, max_count, harris_demo);
	harris_demo(0 ,0);

	Mat m(4,4,CV_8UC1, Scalar(200));
	cout<<"mat="<<m<<endl;
	Mat m2;
	convertScaleAbs(m, m2, 1.5, 1);
	cout<<"mat="<<m2<<endl;
	cvWaitKey(0);
	return 0;
}

void harris_demo(int , void*)
{
	Mat dst,dst8u,dstshow,imageSource;
	dst=Mat::zeros(gray_src.size(),CV_32FC1);  

	imageSource=src.clone();

	cornerHarris(gray_src,dst,2,3,0.04,BORDER_DEFAULT);
	normalize(dst,dst8u,0,255,CV_MINMAX);  //归一化dst8u data is float type
	convertScaleAbs(dst8u,dstshow);//dstshowdata is int type
	cout<<dst8u.row(0)<<endl;
	cout<<dstshow.row(0)<<endl;
	// imshow("output",dstshow);  //dst显示
	for(int i=0;i<imageSource.rows;i++)
	{
		for(int j=0;j<imageSource.cols;j++)
		{
			if(dstshow.at<uchar>(i,j)>thresh)  //阈值判断
			{
				circle(imageSource,Point(j,i),2,Scalar(0,255,0),2); //标注角点
			}
		}
	}
	imshow("output",imageSource);
}