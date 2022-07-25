
#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/objdetect.hpp>
#include<iostream>
#include<string>

using namespace std;
using namespace cv;
/*
void main() {
	string path = "images.jpg";
	Mat img = imread(path);
	imshow("Frame", img);
	waitKey(0);
}
*/

void main() {
	CascadeClassifier facedetect;
	
	facedetect.load("D:\\opencv\\sources\\data\\haarcascades\\haarcascade_frontalface_default.xml");
	VideoCapture video(0);

	while (true) {
		Mat img;
		video >> img;
		vector<Rect> faces;

		facedetect.detectMultiScale(img, faces, 1.3, 5);

		//cout << faces.size() << endl;

		for (int i = 0; i < faces.size(); i++) {
			rectangle(img, faces[i].tl(), faces[i].br(), Scalar(50, 50, 255), 3);
			putText(img, to_string(faces.size()) + " Faces Found", Point(10, 40), FONT_HERSHEY_DUPLEX, 1, Scalar(0, 0, 0), 1);
		}
		
		imshow("Webcam Frame", img);
		waitKey(1);
	}
}