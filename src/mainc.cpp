#include <stdlib.h>
#include <stdio.h>

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <clibs/types/string.h>

#include <clibs/collections/dlist.h>

#include <clibs/files.h>

int main (int argc, char **argv) {

	if (argc > 1) {
		const char *dirname = argv[1];

		DoubleList *videos = files_get_from_dir (dirname);
		if (videos) {
			cv::VideoCapture cap;
			cv::Mat frame;
			cv::Mat new_frame;
			cv::namedWindow ("video");
			cv::setWindowProperty ("video", cv::WindowPropertyFlags::WND_PROP_FULLSCREEN, cv::WindowFlags::WINDOW_FULLSCREEN);
			cv::setWindowProperty ("video", cv::WindowPropertyFlags::WND_PROP_ASPECT_RATIO, cv::WindowFlags::WINDOW_FREERATIO);
			// cv::resizeWindow ("video", 2560, 1440);
			cv::moveWindow ("video", 0, 0);

			String *filename = NULL;
			for (ListElement *le = dlist_start (videos); le; le = le->next) {
				filename = (String *) le->data;

				printf ("%s\n", filename->str);

				cap.open (filename->str);
				if (cap.isOpened ()) {
					double fps = cap.get (CV_CAP_PROP_FPS);
					double width = cap.get (CV_CAP_PROP_FRAME_WIDTH);
					double height = cap.get (CV_CAP_PROP_FRAME_HEIGHT);

					cv::Size size (1440 * (width / height), 1440);

					while (1) {
						cap >> frame;

						if (!frame.empty ()) {
							cv::resize (frame, new_frame, size);
							cv::imshow ("video", new_frame);
							cv::waitKey (1000 / fps);
						}

						else {
							break;
						}
					}
				}
			}

			dlist_delete (videos);
		}
	}

	return 0;

}