#include "texture.h"

void texture::LoadJPEG()
   {
    FIBITMAP* img= FreeImage_Load(FIF_PNG, imageName, PNG_DEFAULT);

    image = (GLbyte*)FreeImage_GetBits(img);

    width = FreeImage_GetWidth(img);
    height = FreeImage_GetHeight(img);

}

void texture::loadTex() {
    // Loading a texture
    //GLuint textureID = 0;
    //glGenTextures(1, &textureID);
    //glBindTexture(GL_TEXTURE_2D, textureID);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
    //glGenerateMipmap(GL_TEXTURE_2D);  //Generate mipmaps now!!! Not working in VM
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_BASE_LEVEL, 0);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAX_LEVEL, 0);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    //glTexParameteri(GL_TEXTURE_2D, GL_GENERATE_MIPMAP, GL_TRUE);
}

void texture::draw(float centerX, float centerY, int angle){
    //calcul des sommets
    std::cout << width << std::endl;
    float rayon = sqrt(width*width+height*height)/2;
    float COS, SIN;
    
    COS = rayon*cos(M_PI/4+angle*M_PI/3);
    SIN = rayon*sin(M_PI/4+angle*M_PI/3);


    glEnable(GL_TEXTURE_2D);

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glTexCoord2d(0.0f, 0.0f);
    glVertex2f(centerX+COS, centerY+SIN);
    glTexCoord2d(1.0f, 0.0f);
    glVertex2f(centerX-SIN, centerY+COS);
    glTexCoord2d(1.0f, 1.0f);
    glVertex2f(centerX-COS, centerY-SIN);
    glTexCoord2d(0.0f, 1.0f);
    glVertex2f(centerX+SIN, centerY-COS);
    glEnd();

    glDisable(GL_TEXTURE_2D);
}

void texture::draw(float x, float y) {
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glTexCoord2d(0.0f, 0.0f);
    glVertex2f(x, y);
    glTexCoord2d(1.0f, 0.0f);
    glVertex2f(x+width, y);
    glTexCoord2d(1.0f, 1.0f);
    glVertex2f(x+width, y+height);
    glTexCoord2d(0.0f, 1.0f);
    glVertex2f(x, y+height);
    glEnd();
    glDisable(GL_TEXTURE_2D);
}