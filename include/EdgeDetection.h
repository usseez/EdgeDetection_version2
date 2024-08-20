#pragma once
#ifndef EDGEDETECT_H //header�̸�_H
#define EDGEDETECT_H
#define IMAGEWIDTH 512
#define IMAGEHEIGHT 512
#define CHANNEL 3

#ifdef __cplusplus 
		extern"C" {
#endif

	extern void EdgeDetect(unsigned char* image, unsigned char* outimage);

#ifdef __cplusplus

		} /*end of the 'externC' block*/
#endif


//extern int EdgeDetect(unsigned char image[IMAGEWIDTH * IMAGEHEIGHT], unsigned char outimage[IMAGEWIDTH * IMAGEHEIGHT]);
//extern void EdgeDetect(unsigned char *image, unsigned char *outimage);




#endif	// EDGEDETECT_H