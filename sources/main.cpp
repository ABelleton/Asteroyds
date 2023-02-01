#include <iostream>
#include <GL/glut.h>

// declaration variables
int windowH;
int windowW;




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

    // On dessine les tokens

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

		// ESCAPE on termine l'application
	case 27:
		exit(0);
		break;
	}

}


int main(int argc, char** argv) {

	// init GLUT and create window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);

    //initialisation du back


    //initialisation de la fenetre
    windowH=600;
    windowW=600;
	glutInitWindowSize(windowH, windowW);
	glutCreateWindow("Astéroïds");


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


	// start loop
	glutMainLoop();

	return 1;
}