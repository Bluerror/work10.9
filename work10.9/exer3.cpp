#include<iostream>
#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;

string window_name = "binaryMat";

void threshod_Mat(int th, void* data)
{
	Mat scr = *(Mat*)(data);

	Mat dst;
	//��ֵ����
	threshold(scr, dst, th, 255, 0);

	imshow(window_name, dst);
}

int main()
{
	Mat scrMat;
	Mat gryMat;
	int lowth = 30;
	int maxth = 255;
	
	scrMat = imread("C:\\Users\\Lenovo\\Pictures\\��ֽ\\1.jpg");
	if (!scrMat.data)
	{
		cout << "ͼ������ʧ��" << endl;
		return 0;
	}

	cvtColor(scrMat, gryMat, CV_BGR2GRAY);
	imshow(window_name, gryMat);
	createTrackbar("threshold",
		window_name,
		&lowth,
		maxth,
		threshod_Mat,
		&gryMat);

	waitKey(0);

	return 0;
}