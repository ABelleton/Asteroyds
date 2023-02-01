#include "texture.h"

void texture::LoadJPEG(bool Fast)
   {
    // TEXTURE
    unsigned long x;
    unsigned long y;
    unsigned short int bpp; //bits per pixels   unsigned short int
    GLbyte* texData;             //the data of the image
    GLuint ID;                //the id ogl gives it
    unsigned long Size;     //length of the file
    int channels;      //the channels of the image 3 = RGA 4 = RGBA
    GLuint type;
    const char* FileName = imageName;


    FILE* file;
    fopen_s(&file, FileName, "rb");  //open the file
    struct jpeg_decompress_struct info;  //the jpeg decompress info
    struct jpeg_error_mgr err;           //the error handler

    info.err = jpeg_std_error(&err);     //tell the jpeg decompression handler to send the errors to err
    jpeg_create_decompress(&info);       //sets info to all the default stuff

    //if the jpeg file didnt load exit
    if (!file)
    {
        fprintf(stderr, "Error reading JPEG file %s!!!", FileName);
        return;
    }

    jpeg_stdio_src(&info, file);    //tell the jpeg lib the file we'er reading

    jpeg_read_header(&info, TRUE);   //tell it to start reading it

    //if it wants to be read fast or not
    if (Fast)
    {
        info.do_fancy_upsampling = FALSE;
    }

    jpeg_start_decompress(&info);    //decompress the file

    //set the x and y
    x = info.output_width;
    y = info.output_height;
    channels = info.num_components;

    type = GL_RGB;

    if (channels == 4)
    {
        type = GL_RGBA;
    }

    bpp = channels * 8;

    Size = x * y * 3;

    //read turn the uncompressed data into something ogl can read
    texData = new GLbyte[Size];      //setup data for the data its going to be handling

    GLbyte* p1 = texData;
    GLbyte** p2 = &p1;
    int numlines = 0;

    while (info.output_scanline < info.output_height)
    {
        numlines = jpeg_read_scanlines(&info, (JSAMPLE**)p2, 1);
        *p2 += numlines * 3 * info.output_width;
    }

    jpeg_finish_decompress(&info);   //finish decompressing this file

    fclose(file);                    //close the file

    image=texData;
    return;
}

void texture::loadTex() {
    // Loading a texture
    GLuint textureID = 0;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imageWidth, imageHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
    //glGenerateMipmap(GL_TEXTURE_2D);  //Generate mipmaps now!!! Not working in VM
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_BASE_LEVEL, 0);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAX_LEVEL, 0);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_GENERATE_MIPMAP, GL_TRUE);
}

void texture::draw(float centerX, float centerY, int angle){
    //calcul des sommets
    float rayon = sqrt(width*width+height*height)/2;
    float x1,y1,x2,y2;
    x1 = centerX+rayon*cos(-3*M_PI/4+angle*M_PI/6);
    y1 = centerY+rayon*sin(-3*M_PI/4+angle*M_PI/6);
    x2 = centerX+rayon*cos(M_PI/4+angle*M_PI/6);
    y2 = centerY+rayon*sin(M_PI/4+angle*M_PI/6);

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glTexCoord2d(0.0f, 0.0f);
    glVertex2f(x1, y1);
    glTexCoord2d(1.0f, 0.0f);
    glVertex2f(x2, y1);
    glTexCoord2d(1.0f, 1.0f);
    glVertex2f(x2, y2);
    glTexCoord2d(0.0f, 1.0f);
    glVertex2f(x1, y2);
    glEnd();
    


}