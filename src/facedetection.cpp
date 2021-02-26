#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
 VideoCapture cap(0);
 cap.open(0);
 Mat img;

 CascadeClassifier faceCascade;
 faceCascade.load("haarcascade_frontalface_default.xml");

 if (faceCascade.empty())
 {
  cout << "XML file not loaded " << endl;
 }

 double fps = camera.get(CAP_PROP_FPS);
 cout << "Frames per second using video.get(CAP_PROP_FPS) : " << fps << endl;

 for (;;)
 {
  cap >> img;
  cap.retrieve(img, CAP_OPENNI_BGR_IMAGE);
  resize(img, img, Size(1080, 720));

  vector<Rect> faces;
  faceCascade.detectMultiScale(img, faces, 1.1, 10);

  for (int i = 0; i < faces.size(); i++)
  {
   rectangle(img, faces[i].tl(), faces[i].br(), Scalar(255, 0, 255), 3);
  }
  imshow("Face Detection", img);
  int key2 = waitKey(20);
 }

 return 0;
}