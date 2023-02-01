#pragma once


#include <math.h>
#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>
#include <glext.h>
#include "FreeImage/Dist/x32/FreeImage.h"

#ifndef M_PI
 #define M_PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679 
#endif

#define FREEIMAGE_COLORORDER FREEIMAGE_COLORORDER_RGB

class texture
{
    private:
        const char* imageName;
        
        GLbyte* image;
        int width, height;


    public:
        void LoadJPEG();
        void loadTex();
        void draw(float centerX, float centerY, int angle);
        void draw(float x, float y);

        texture(const char* imageName) {
            this->imageName = imageName;

            LoadJPEG();
        }
};