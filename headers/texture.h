#pragma once


#include <math.h>
#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>
#include <glext.h>
#include <jpeglib.h>

#ifndef M_PI
 #define M_PI 3.1415926535 8979323846 2643383279 5028841971 6939937510 5820974944 5923078164 0628620899 8628034825 3421170679 
#endif

class texture
{
    private:
        int imageWidth;
        int imageHeight;
        int width;
        int height;
        char* imageName;
        GLbyte* image;

    public:
        void LoadJPEG(bool Fast);
        void loadTex();
        void draw(float centerX, float centerY, int angle);
};