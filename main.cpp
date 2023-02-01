#include <iostream>
#include <GL/glut.h>
#include <glext.h>
#include "texture.h"

// declaration variables
int windowH;
int windowW;

texture* map = NULL;
texture* ast_black = NULL;
texture* ast_blue = NULL;
texture* ast_red = NULL;
texture* ast_white = NULL;
texture* ast_whiteblue = NULL;
texture* ast_whitered = NULL;
texture* base = NULL;
texture* door0 = NULL;
texture* door1 = NULL;
texture* door2 = NULL;
texture* door3 = NULL;
texture* player = NULL;
texture* ia = NULL;

float case_width = 93;
float case_height = 80;
int anchor_x = 540;
int anchor_y = 60;

void draw_token(texture* token, int x, int y, int angle) {
	int newx = anchor_x + x * case_width- y * case_width/2;
	int newy = anchor_y + y * case_height;
	token->loadTex();
	token->draw(newx, newy, angle);
}




void redimensionner(int w, int h) {

	// on bloque la fenetre à des dimensions strictement positives
	if (h == 0)
		h = 1;

    // on stocke les valeurs de H et W
    windowH=h;
    windowW=w;

	// on passe en mode "matrice de projection"
	glMatrixMode(GL_PROJECTION);

	// on charge la matrice identite
	glLoadIdentity();

	// on definit le viewport pour prendre toute la fenetre
	glViewport(0, 0, w, h);

	// on definit la projection orthographique
	gluOrtho2D(0, w, 0, h);

	// on repasse en mode "matrice modelview"
	glMatrixMode(GL_MODELVIEW);
}

void affichageScene() {
	// On efface les tampons de couleur et de profondeur
	glClear(GL_COLOR_BUFFER_BIT);

	// on défini la projection orthographique
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, windowW, 0, windowH);

	// On passe en matrice modelview
	glMatrixMode(GL_MODELVIEW);

	// on charge la matrice identite
	glLoadIdentity();

	// On dessine le plateau
	map->loadTex();
	map->draw(0,0);
    // On dessine les tokens
	draw_token(ast_black, 3, 6, 0);
	draw_token(ast_blue, 11, 10, 2);
	draw_token(ast_red, 8, 2, 4);
	draw_token(ast_white, 3, 4, 3);
	draw_token(ast_whiteblue, 7, 8, 0);
	draw_token(ast_whitered, 9, 3, 5);
	draw_token(door0, 2, 2, 0);
	draw_token(door1, 10, 3, 5);
	draw_token(door2, 6, 10, 5);
	draw_token(door3, 14, 11, 3);
	draw_token(base, 6, 5, 0);
	draw_token(base, 7, 5, 0);
	draw_token(base, 6, 6, 0);
	draw_token(base, 7, 7, 0);
	draw_token(base, 8, 6, 0);
	draw_token(base, 8, 7, 0);
	draw_token(ia, 0, 5, 1);
	draw_token(player, 9, 11, 0);

	// on echange les tampons d'affichage
	glutSwapBuffers();
}


void clicSouris(int button, int state, int x, int y) {
    // fonction qui regis les clics
}


void mouvementSouris(int x, int y) {
	// fonction qui regis les deplacements de la souris lors du clic
}

void passiveMouvementSouris(int x, int y) {
	// fonction qui regis les deplacements de la souris lorsqu'il n'y a pas de clic
}


void clavier(unsigned char key, int xx, int yy) {
    // fonction qui gere les entree clavier

	// Quelle touche a ete appuyee ?
	switch (key) {

	case 32:
		map->LoadJPEG();
		break;

		// ESCAPE on termine l'application
	case 27:
		exit(0);
		break;
	}

}


int main(int argc, char** argv) {

	// init GLUT and create window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);

    //initialisation du back


    //initialisation de la fenetre
    windowH=1080;
    windowW=1920;
	glutInitWindowSize(windowW, windowH);
	glutCreateWindow("Asteroids");

	glutFullScreen();


    //initialise display settings
	glEnable(GL_TEXTURE_2D);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_ADD);

	
    // definition des callbacks
    //affichage
	glutDisplayFunc(affichageScene);
	glutReshapeFunc(redimensionner);
	glutIdleFunc(affichageScene);
	//clavier
    glutKeyboardFunc(clavier);
	//souris
	glutMouseFunc(clicSouris);
	glutMotionFunc(mouvementSouris);
	glutPassiveMotionFunc(passiveMouvementSouris);

	GLuint tex;
	glGenTextures(1, &tex);
	glBindTexture(GL_TEXTURE_2D, tex);


	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	map = new texture("Assets png/Assets_map.png");
	ast_black = new texture("Assets png/Assets_token_ast_black.png");
	ast_blue = new texture("Assets png/Assets_token_ast_blue.png");
	ast_red = new texture("Assets png/Assets_token_ast_red.png");
	ast_white = new texture("Assets png/Assets_token_ast_white.png");
	ast_whiteblue = new texture("Assets png/Assets_token_ast_whiteblue.png");
	ast_whitered = new texture("Assets png/Assets_token_ast_whitered.png");
	base = new texture("Assets png/Assets_token_base.png");
	door0 = new texture("Assets png/Assets_token_door0.png");
	door1 = new texture("Assets png/Assets_token_door1.png");
	door2 = new texture("Assets png/Assets_token_door2.png");
	door3 = new texture("Assets png/Assets_token_door3.png");
	player = new texture("Assets png/Assets_token_player.png");
	ia = new texture("Assets png/Assets_token_ia.png");



	// start loop
	glutMainLoop();

	return 1;
}