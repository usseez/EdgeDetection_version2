#include <stdio.h>
#include <iostream>
#include <fstream>
#include "opencv2/core/core.hpp" 
#include "opencv2/highgui/highgui.hpp" 
#include "opencv2/imgproc.hpp"
#include "EdgeDetection.h"



//#include "EdgeDetection.h"
// yuv가 input인가...? 그럼 거기서 y field만 받는 방법은.....

//unsigned char inputimage[IMAGEHEIGHT * IMAGEWIDTH * CHANNEL];
unsigned char outbuffer_foreground[IMAGEHEIGHT * IMAGEWIDTH * CHANNEL];
unsigned char outbuffer[IMAGEHEIGHT * IMAGEWIDTH * CHANNEL];
unsigned char inputbuffer[IMAGEWIDTH * IMAGEHEIGHT * (CHANNEL)];
unsigned char overlayimage[IMAGEWIDTH * IMAGEHEIGHT * (CHANNEL + 1)];

cv::Mat edgedetected(IMAGEHEIGHT, IMAGEWIDTH, CV_8UC4);
cv::Mat outbuffer_yuv(IMAGEHEIGHT, IMAGEWIDTH, CV_8UC3);
cv::Mat outbuffer_yuvtransform(IMAGEHEIGHT, IMAGEWIDTH, CV_8UC3);

//home/jisu/cstudy/imageoverlay/image/lena.bmpdata2buffer
int data2buffer(cv::Mat image, unsigned char* inputbuffer);
int check_image_exist(cv::Mat image);
void displayimage(const std::string& name, cv::Mat outbuffer);
void createMat(cv::Mat& outputMat, int height, int width, int type, unsigned char* data);
void saveArrayToBinaryFile(const std::string& filePath, unsigned char* data, size_t dataSize);

int main(void) 
{

	inputbuffer[IMAGEHEIGHT * IMAGEWIDTH * CHANNEL];
	//read the image
	cv::Mat image = cv::imread("/mnt/d/cstudy/imageoverlay/image/Lenna.bmp", 0);


	
	data2buffer(image, inputbuffer);

   
	EdgeDetect(inputbuffer, outbuffer);
	//transform_to_blending(outbuffer_foreground, outbuffer_transform);
	//imageoverlay(inputbuffer, outbuffer_transform, overlayimage);//back, fore, result
	
	// for(int pixel = 0; pixel < IMAGEHEIGHT * IMAGEWIDTH * CHANNEL; pixel += 3)
	// {
	// 	printf("y : %d, u : %d, v : %d \n", outbuffer_foreground[pixel], outbuffer_foreground[pixel + 1], outbuffer_foreground[pixel + 2]);
	// }

	// for(int pixel = 0; pixel < IMAGEHEIGHT * IMAGEWIDTH * CHANNEL; pixel += 4)
	// {
	// 	printf("b : %d, g : %d, r : %d \n", overlayimage[pixel], overlayimage[pixel + 1], overlayimage[pixel + 2]);
	// }

	
		
		



	//buffer to MAT image
	 createMat(edgedetected, IMAGEHEIGHT, IMAGEWIDTH, CV_8UC1, outbuffer);


	// show image
	//displayimage("original", image);
	//displayimage("overlayed", outbuffer_overlayed);
	//displayimage("background", outbuffer_bgr);
	displayimage("edgedetected", edgedetected);

	//save a file in bin
//	size_t yuvSize = IMAGEHEIGHT * IMAGEWIDTH * 3;
//	saveArrayToBinaryFile("../output/yuvimage.bin", yuvimage, yuvSize);


	return 0;

}





void createMat(cv::Mat& outputMat, int height, int width, int type, unsigned char* data) 
{
    // 매개변수로 전달된 cv::Mat 객체를 초기화
    outputMat = cv::Mat(height, width, type, data);

	#if 0//buffer to MAT 3channel bgrimage
	
	for (int pixel = 0; pixel < IMAGEHEIGHT * IMAGEWIDTH * (CHANNEL) ; pixel+=3)
	{
		
		outbuffer.data[pixel] = bgrimage[pixel];
        outbuffer.data[pixel + 1] = bgrimage[pixel + 1];
        outbuffer.data[pixel + 2] = bgrimage[pixel + 2];
 	
	}
	

#endif
}





void displayimage(const std::string& name, cv::Mat outbuffer)
{

	while(1)
	{
		cv::imshow(name, outbuffer);
		//cv::imshow("u", yuv_channels[1]);
		
		//cv::imshow("v", yuv_channels[2]);
		//cv::imshow("UV Image", uv);
		

		cv::waitKey(0);
	}
	#if 0
	// show uv image
	cv::Mat yuv;
	cv::Mat uv;
	cv::Mat merge;

	cv::cvtColor(image, yuv, cv::COLOR_BGR2YUV);
	
	std::vector<cv::Mat>  yuv_channels;

	cv::split(yuv, yuv_channels);
	yuv_channels[0] = cv::Mat::zeros(IMAGEHEIGHT, IMAGEWIDTH, CV_8UC1) * 255;
	cv::Mat u_channel = yuv_channels[1];  // U 채널
    cv::Mat v_channel = yuv_channels[2];  // V 채널
	cv::merge(yuv_channels, uv);

	
	#endif 
	
	//std::vector<cv::Mat> uv_channels = {u_channel, v_channel};
	//merge(uv_channels, uv);
}


int data2buffer(cv::Mat image, unsigned char* inputbuffer)
{

	check_image_exist(image);

	for (int pixel = 0; pixel < IMAGEHEIGHT * IMAGEWIDTH * CHANNEL; pixel++)
	{
		//FIXME:segmentation fault
		inputbuffer[pixel] = image.data[pixel];
	}

	#if 0
	for (int row = 0; row < IMAGEHEIGHT; row++)
	{
		for (int col = 0; col < IMAGEWIDTH; col++)
		{
			inputbuffer[row * IMAGEWIDTH + col] = image.data[row * IMAGEWIDTH + col];
			//inputimage[row * IMAGEWIDTH + col] = img_data[row * IMAGEWIDTH + col];
			//printf("\t %d", inputimage);
		}
		//cout << "\n" << endl;
	}
	
	#endif

	
	#if 0
	 
	for (int row = 0; row < IMAGEHEIGHT; row++)
	{
		for (int col = 0; col < IMAGEWIDTH; col++)
		{
			unsigned char inputimage = img_data[row * IMAGEWIDTH + col];
			//inputimage[row * IMAGEWIDTH + col] = img_data[row * IMAGEWIDTH + col];
			printf("\t %d", inputimage);
		}
		cout << "\n" << endl;
	}
	#endif
	return 0;
	
}

int check_image_exist(cv::Mat image)
{	
	// Check if the file exists
    if (image.empty()) {
        std::cerr << "Error: Unable to open image file!!" << std::endl;
        return 1;
    }
	return 0;
}


void saveArrayToBinaryFile(const std::string& filePath, unsigned char* data, size_t dataSize) {
    std::ofstream file(filePath, std::ios::binary);
    if (!file) {
        std::cerr << "Error: Unable to open file " << filePath << " for writing!" << std::endl;
        return;
    }
    file.write(reinterpret_cast<const char*>(data), dataSize);
    file.close();
    std::cout << "Data successfully saved to " << filePath << std::endl;
}