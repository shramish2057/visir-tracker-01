#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
 VideoCapture camera;
 if (!camera.open(0))
 {
		printf("Can't find a camera\n");
		return 1;
 };
 double fps = camera.get(CAP_PROP_FPS);
 cout << "Frames per second using video.get(CAP_PROP_FPS) : " << fps << endl;

 // Main loop
 Mat img;
 for (;;)
 {
		camera >> img;
		imshow("Camera", img);
		int key = waitKey(5);
		if (key == 27 || key == 'q')
			break;
 }

 double fps2 = camera.get(CAP_PROP_FPS);
 cout << "Frames per second using video.get(CAP_PROP_FPS) : " << fps2 << endl;
 camera.release();
 return 0;
}
