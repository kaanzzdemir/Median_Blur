#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui_c.h>

using namespace cv;


Mat orgImg;
Mat dst;

int trackVal = 1;

void track(int, void *) {
	// Burada sadece tek sayıları almak zorundayız çünkü 2 2 boyutunda bir filtrenin orta değeri olamaz.
	if (trackVal % 2 == 1) {
		medianBlur(orgImg, dst, trackVal);

		printf("%d", trackVal);
		imshow("HazırFonk", dst);
	}
}
int main(int argc, char** argv)
{

	orgImg = imread("lena_40.jpg");

	namedWindow("Trackbar Penceresi", CV_WINDOW_AUTOSIZE);
	createTrackbar("Name", "Trackbar Penceresi", &trackVal, 100, track);

	imshow("Resim", orgImg);

	waitKey(0);
	return 0;

}
