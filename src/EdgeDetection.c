#include "EdgeDetection.h"
#define FILTERVALUE 2
//#include <stdio.h>

static int boundaryCheck(int , int , int , int );
static double _sqrt(double);
static double _pow(double, double);



//int EdgeDetect(unsigned char image[IMAGEWIDTH * IMAGEHEIGHT], unsigned char outimage[IMAGEWIDTH * IMAGEHEIGHT]) : return outimage[];
//int EdgeDetect(unsigned char *image, unsigned char *outimage){
// static : 1) private���� ����� 2) local���� static�� ���������� ������ ��
void EdgeDetect(unsigned char* image, unsigned char* outimage) {

//unsigned char* EdgeDetect(unsigned char* image) {
    //How to set tempin and tempout, tempout�� ��� outimage�� ���� �� �ִ°�
    
    //int ret = 0;
    //unsigned char tempin[IMAGEWIDTH * IMAGEHEIGHT] = { 0, };
    //unsigned char tempout[IMAGEWIDTH * IMAGEHEIGHT] = { 0, };
    //unsigned char tempout[IMAGEWIDTH * IMAGEHEIGHT] = { 0, };
//#if 0
    int index = 0; 
    int temp_x = 0;
    int temp_y = 0;     
    int abstempx = 0;
    int abstempy = 0;
    int square[9] = { 0 };
    //unsigned char outimage[IMAGEWIDTH * IMAGEHEIGHT] = { 0 };



    //for (int i = 0; i < IMAGEHEIGHT; i++) {
    //    for (int j = 0; j < IMAGEWIDTH; j++) {

    //        tempin[IMAGEWIDTH * i  + j] = image[IMAGEWIDTH * i + j];
    //    }
    //}
 
    //printf(tempin[]);


    //sobel Algorithm
    for (int i = 1; i < IMAGEHEIGHT; i++) {
        for (int j = 1; j < IMAGEWIDTH; j++) {
            index = 0;
            // record the values in the 3x3 square:
            for (int m = -1; m < 2; m++) {
                for (int n = -1; n < 2; n++) {
                    // use boundary check and select the image region into square array:

                    square[index++] = boundaryCheck(j + n, i + m, IMAGEWIDTH, IMAGEHEIGHT) ? image[IMAGEWIDTH * (i + m) + (j + n)] : 0;
                }
            }
            temp_x = (square[2] + FILTERVALUE * square[5] + square[8] - square[0] - FILTERVALUE * square[3] - square[6]);
            temp_y = (square[6] + FILTERVALUE * square[7] + square[8] - square[0] - FILTERVALUE * square[1] - square[2]);

            abstempx = (temp_x < 0) ? -temp_x : temp_x;
            abstempy = (temp_y < 0) ? -temp_y : temp_y;

            outimage[IMAGEWIDTH * i + j] = _sqrt(_pow(temp_x, 2) + _pow(temp_y, 2));
        }
    }
//#endif    

    //unsigned char outimage[IMAGEWIDTH * IMAGEHEIGHT] = tempout[];???
    //printf();

    //return ret;
}




static double _sqrt(double n) {
    double s = 0;
    double t = 0;

    s = n / 2;
    for (; s != t;)
    {
        t = s;
        s = ((n / t) + t) / 2;

    }
    return s;
}

static double _pow(double n, double m) {
    double nn = n;
    if(m == 0)
        return 1.0;
    for(int i = 0; i< (m - 1); i++)
        n *= nn;
    return n;
}


static int boundaryCheck(int index_x, int index_y, int width, int height) {
    if (index_x > 0 && index_y > 0 && index_x < width && index_y < height) return 1;
    else return 0;
}


