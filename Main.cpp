#include "Capture.h"
#include <thread>

using namespace std;
using namespace cv;

map<milliseconds, Frame> frames;
vector<map<milliseconds, vector<Point>>> allTracks;
mutex mutex_frames, mutex_tracks;

const int cameraNumber = 0;
//const string fileName = R"(/home/drew/ClionProjects/detection/123.avi)";
//const string fileName = R"(/Users/yellowos/Desktop/intel杯/detection/TB.mp4)";




int main() {
    Capture capture(cameraNumber);
    if (!capture.isOpened()) {
        cout << "Error: Camera #" << cameraNumber << " is not available now." << endl;
        return -1;
    }

//	const char* file = fileName.c_str();
//	FILE* f = fopen(file, "r");
//	if (f == NULL) {
//		cout << "Error: File "<< file << " is not found." << endl;
//		return -1;
//	}
//	fclose(f);
//	Capture capture(file);
//    VideoCapture capture(0);


//	thread capturing(&Capture::find, ref(capture), ref(frames), ref(mutex_frames), ref(allTracks), ref(mutex_tracks));
//	thread display(&Capture::display, ref(capture), ref(frames), ref(mutex_frames), ref(allTracks), ref(mutex_tracks));
//    thread capturing(ref(capture.find), ref(frames), ref(mutex_frames), ref(allTracks), ref(mutex_tracks));
//    thread display(ref(capture.display), ref(frames), ref(mutex_frames), ref(allTracks), ref(mutex_tracks));
    while (1) {
        capture.find(frames, mutex_frames, allTracks, mutex_tracks);
        capture.display(frames, mutex_frames, allTracks, mutex_tracks);
    }

//	if (capturing.joinable())
//	{
//		capturing.join();
//	}
//
//
//	if (display.joinable())
//	{
//		display.join();
//	}

	return 0;
}

