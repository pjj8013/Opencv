#include<opencv2/opencv.hpp>
#include<iostream>
#include<vector>
using namespace cv;
using namespace std;


//Mat ��� ���� �� �ʱ�ȭ
#if 0
int main() {
	Mat mtx(3, 3, CV_32F);
	Mat cmt(10, 1, CV_64FC2);

	Mat img(Size(5, 3), CV_8UC3);	//����5 ����3
	
	Mat mtx2;
	mtx2 = Mat(3, 3, CV_32F);
	Mat cmtx2;
	cmtx2 = Mat(10, 1, CV_32F);

	Mat* mtx3 = new Mat(3, 3, CV_32F);
	delete mtx3;

	mtx.setTo(10);	//�� �ʱ�ȭ
	cout << mtx << endl;

	cmtx2.setTo(11);
	cout << cmtx2 << endl;
	
	Mat m = Mat::ones(3, 3, CV_64F);
	//m = m * 3;
	cout << m << endl;
	
	//�迭�� ��Ŀ� �����Ͽ� �ʱ�ȭ
	double dm[3][3] = { {1,2,0},{2,2,0},{3,2,1} };
	Mat m2 = Mat(3, 3, CV_64F, dm);
	cout << m2 << endl;
	
	waitKey();

}
#endif

//��� ����
#if 0
int main() {

	//��Ģ���� ����
	/*
	 + �� ��� ���ϱ�
	 - �� ��� ����
	 * �� ��İ����� ������
	 
	 */
	Mat m = Mat::ones(3, 3, CV_64F);
	double dm[3][3] = { {1,2,0},{2,2,0},{3,2,1} };
	Mat m2 = Mat(3, 3, CV_64F, dm);

	//cout << m + m2 << endl;
	//cout << m - m2 << endl;
	//cout << m * m2 << endl;	//��� ������ ������
	//cout << m.mul(m2) << endl;//��Ҹ� ���ϰ� �ʹٸ� ���̺귯�� ���
	//cout << m / m2 << endl;

	
	cout << m2.inv() << endl;
	cout << m2.t() << endl;
}

#endif

//�̹��� �ε�
#if 0
int main() {

	Mat img = imread("Image/dog.jpg");
	Sobel(img, img, img.depth(), 1, 0);
	namedWindow("img", WINDOW_AUTOSIZE);	//������ �̸��� ���� ������ â�� ����
	imshow("img", img);

	waitKey();

}

#endif

// matŬ���� ����
#if 0
int main() {
	Mat img = imread("Image/dog.jpg", IMREAD_COLOR);
	imshow("1", img);
	Mat img_g;
	
	for (int i = 0; i < img.rows; i++)
	{
		for (int j = 0; j < img.cols; j++)
		{
			/*img.at<Vec3b>(i, j) = img.at<Vec3b>(i, j)[0] * 0.2 +
				img.at<Vec3b>(i, j)[1] * 0.3 +
				img.at<Vec3b>(i, j)[2] * 0.5;*/
			Vec3b v = img.at<Vec3b>(i, j);
			uchar result = v[0] * 0.11 + v[1] * 0.3 + v[2] * 0.45;
			img_g.at<uchar>(i, j) = result;

		}

	}
	imshow("2", img_g);
	waitKey();

}

#endif


//Mat Ŭ���� ����

#if 0
int main() {
	
	Mat mtx = Mat::ones(4,3 ,CV_8U);
	Mat mtx2;
	cout << mtx.dims << endl;
	//cout << mtx << endl;
//	mtx.push_back(1);
	//cout << mtx << endl;

	//vector<int> v1;
	//
	//vector<int> v2(5);

	//vector<int> v3 = { 1,2,3,4,5, };
	//vector<int> v4{ 1,2,3,4,5,6,7,8 };

	//vector<int>v5[] = { {1,2},{3,4} };	//�迭�� ���Ұ� ����
	//
	//vector<vector<int>> v7(5, vector<int>(5, 10));	//2���� ���ͻ���, �� ������ ���Ҵ� 5���� 10���� �ʱ�ȭ�� ����
	

	mtx.resize(3);	//�� �� ����
	cout << mtx << endl;

	int dm[3][2] = { {1,2},{2,3},{4,2} };
	Mat m(3, 2, CV_32F, dm);
	cout << m << endl;
	


}

#endif

//waitKey��ȯ��
#if 0



int main() {
	
	Mat m(3, 3, CV_8UC3,Scalar(0,255,0));
	namedWindow("ddd", 0);
	imshow("ddd", m);

	while (true)
	{
		if (waitKey(10) >0)
			cout << waitKey(0) << endl;
	}

	return 0;
}



#endif

//�̹��� ����
#if 0
int main() {
	
	Mat img = imread("Image/dog.jpg");
	bitwise_not(img, img);
	
	Mat img2 = img;			//���� ���簡 �ƴ� ����
	bitwise_not(img, img);



	img2 = img.clone();
	bitwise_not(img, img);

	

	Rect r(img.cols / 4, img.rows / 4, img.cols / 4 * 2, img.rows / 4 * 2);
	
	cout << r << endl;
	img2 = img(r).clone();

	imshow("ims2", img2);
	imshow("img", img);

	waitKey();



}

#endif

//�̹��� �κк���
#if 0
int main() {
	Mat img = imread("Image/dog.jpg");

	Mat cimg(Size(img.cols * 2, img.rows), img.type());
	//cimg.setTo(255);
	imshow("1", img);

	imshow("2", cimg);

	//copyTo(rows,cols)
	//img.copyTo(cimg(Range::all(),Range(0,img.cols)));	//img�̹��� ��ü�� img ����ũ�⸸ŭ ����
	//img.copyTo(cimg(Range::all(), Range(img.cols, img.cols*2)));	//�̹��� ��ü�� 

	imshow("3", cimg);
	waitKey();
	


}

#endif

//�̹��� ���� data ���
#if 0
int main() {
	Mat img = imread("Image/dog.jpg");

	for (int i = 0; i < img.rows; i++)
	{
		for (int j = 0; j < img.cols; j++)
		{

			unsigned char r, g, b;
			b = img.data[i * img.step + j * img.elemSize() + 0]; //img.step :������ ����ũ��(��������Ʈũ��),
			g = img.data[i * img.step + j * img.elemSize() + 1];//img.elemSize() : x��ġ(ä�μ� ����� ������)
			r = img.data[i * img.step + j * img.elemSize() + 2];

			img.data[i * img.step + j * img.elemSize() + 0] = unsigned char(255 - b);
			img.data[i * img.step + j * img.elemSize() + 1] = unsigned char(255 - g);
			img.data[i * img.step + j * img.elemSize() + 2] = unsigned char(255 - r);



		}
	}
	imshow("1", img);
	cout << img.step << endl;
	cout << img.cols << endl;
	waitKey();
}

#endif

//�̹��� ���� at���
#if 0
int main() {
	Mat img = imread("Image/dog.jpg");

	for (int i = 0; i < img.rows; i++)
	{
		for (int j = 0; j < img.cols; j++)
		{
			unsigned char b = img.at<Vec3b>(i, j)[0];
			unsigned char g = img.at<Vec3b>(i, j)[1];
			unsigned char r = img.at<Vec3b>(i, j)[2];

			img.at<Vec3b>(i, j)[0] = unsigned char(255 - b);
			img.at<Vec3b>(i, j)[1] = unsigned char(255 - g);
			img.at<Vec3b>(i, j)[2] = unsigned char(255 - r);

		}

	}
	imshow("img", img);
	waitKey();
}

#endif

//�̹��� ����  ptr ���
#if 0
int main() {
	Mat img = imread("Image/dog.jpg");

	

	for (int i = 0; i < img.rows; i++)
	{
		Vec3b* ptr = img.ptr<Vec3b>(i);		//i��° row���� ������ ������ (i��° row�� ����Ŵ)
		for (int j = 0; j < img.cols; j++)
		{
			unsigned char b1 = (ptr[j][0]);
			unsigned char g1 = (ptr[j][1]);
			unsigned char r1 = (ptr[j][2]);

			Vec3b bgr = ptr[j];
			unsigned char b2 = (bgr[0]);
			unsigned char g2 = (bgr[1]);
			unsigned char r2 = (bgr[2]);

			ptr[j] = Vec3b(255 - b1, 255 - g1, 255 - r1);
		}
	}
	imshow("img", img);
	waitKey();



}

#endif

//�̹��� ���� iterator
#if 0
int main() {
	Mat img = imread("Image/dog.jpg");

	MatIterator_<Vec3b> itd = img.begin <Vec3b>(), itd_end = img.end<Vec3b>();

	for (int i = 0; itd != itd_end;++itd, i++)
	{
		Vec3b bgr = (*itd);
		(*itd)[0] = 255 - bgr[0];
		(*itd)[1] = 255 - bgr[1];
		(*itd)[2] = 255 - bgr[2];


	}
	imshow("img", img);
	waitKey();

}

#endif

//�̹��� ����
#if 0
int main() {
	Mat img = imread("Image/dog.jpg");

	img.t();
	imshow("img", img);
	waitKey(0);

	imwrite("new_img.png", img);

}

#endif

//��� ����, ���Ϳ���
#if 0
int main() {

	Mat m = Mat::eye(3, 3, CV_8U);
	cout << m << endl;
	
	int va[] = { 1,1,1 };
	int vb[] = { 0,0,1 };
	int vc[3];

	Mat Va(3, 1, CV_32S, va);
	Mat Vb(3, 1, CV_32S, vb);
	Mat Vc(3, 1, CV_32S, vc);

	int res = Va.dot(Vb);
	cout << res << endl;



}

#endif

//�׸���(��, ��, �簢��)
#if 0
int main() {

	Mat img(500, 500, CV_8UC3);
	img.setTo(255);

	/*Point pt(300, 300);
	line(img, Point(10, 10), pt, CV_RGB(255, 0, 0), 2);
	line(img, Point(300, 10), Point(30, 300), Scalar(255, 0, 0), 3);
	

	circle(img, Point(250, 250), 100, CV_RGB(255, 0, 0), 3);

	Point center(400, 400);
	circle(img, center, 300, Scalar(255, 255, 0), 1);
	circle(img, Point(40, 40), 10, Scalar(0, 255, 0), -1);*/
	
	rectangle(img, Rect(10, 10, 200, 200), CV_RGB(255, 0, 0), 2);
	rectangle(img, Rect(Point(40, 40), Point(245, 245)), Scalar(255, 0, 0), 2);


	imshow("1", img);



	waitKey();

}

#endif

//�׸���(Ÿ��)
#if 1
int main() {

	Mat img(500, 500, CV_8UC3);
	ellipse(img, Point(100, 100), Size(100, 50), 0, 0, 360, CV_RGB(255, 0, 0));

	RotatedRect rRect = RotatedRect(Point2f(300, 300), Size2f(300, 100), 0);	
	ellipse(img, rRect, CV_RGB(255, 0, 0));

	Point2f vertices[4];
	rRect.points(vertices);

	for (int i = 0; i < 4; i++)
	{
		line(img, vertices[i], vertices[(i + 1) % 4], Scalar(255, 0, 0),3);
		cout << vertices[i] << endl;
	}

	imshow("img", img);
	waitKey();

	
}

#endif


#if 0
int main() {


}



#if 0
int main() {


}

#endif


#if 0
int main() {


}

#endif


#if 0
int main() {


}

#endif


#if 0
int main() {


}

#endif


#if 0
int main() {


}

#endif


#if 0
int main() {


}

#endif


#if 0
int main() {


}

#endif


#if 0
int main() {


}

#endif


#if 0
int main() {


}

#endif


#if 0
int main() {


}

#endif


#if 0
int main() {


}

#endif


#if 0
int main() {


}

#endif
#endif