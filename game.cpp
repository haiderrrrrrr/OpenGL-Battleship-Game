/* Haider Ali                                    22i-2655
                       PF Project      */
#ifndef Battleship_CPP_
#define Battleship_CPP_
#include "util.h"
#include <iostream>
#include<string>
#include<cmath> 
// for basic math functions such as cos, sin, sqrt
using namespace std;

//Declaring Global Variables
int arrx[10] = {1425,1300,1225,1050,1050,1050,1050,1150,1250,1350};
int arry[10] = { 100,100,100,250,175,100,350,350,350,350 };
int arrw[10] = { 50,50,50,112,112,112,50,50,50,50 };
int arrh[10] = { 224,168,168,50,50,50,50,50,50,50 };  


// seed the random numbers generator by current time (see the documentation of srand for further help)...
/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height)
{
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}



//Global Variables
int xI = 400, yI = 400;
//Function to Display Ships in gridmenu
//Initailizin the Colour of the Ships
ColorNames changecolour = DARK_SLATE_GRAY;
void drawObject()
{
	DrawString(1150, 600, "Battle Ships", colors[RED]);
	for (int i = 0; i < 10; i++)
	{
		DrawRoundRect(arrx[i], arry[i], arrw[i], arrh[i], colors[changecolour], 30);
	}

	glutPostRedisplay();
	//Displaying Back  Button
	DrawRoundRect(1500, 810, 170, 40, colors[WHITE], 0);
	DrawString(1515, 820, "Menu", colors[BLACK]);
	DrawRoundRect(1500, 750, 170, 40, colors[WHITE], 0);
	DrawString(1506, 760, "Options", colors[BLACK]);
}



bool flag = true;
void moveObject()
{
	if (xI > 10 && flag)
	{
		xI -= 10;
		cout << "going left";
		if(xI < 100)
			
			flag = false;
	}
	else if (xI < 1010 && !flag) 
	{
		cout << "go right";
		xI += 10;
		if (xI > 900)
			flag = true;
	}
}



// Main Canvas drawing function.
void GameDisplay()
{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim red and 1 means pure red and so on.
	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	
	//Button For Game
	DrawRoundRect(750, 800, 170, 40, colors[WHITE], 0);

	DrawString(300, 800, "Game Grid", colors[RED]);
	//Dimesnions for Making Grid
	for (int i = 100; i < 700; i += 60) {
		for (int j = 100; j < 700 ; j+= 60) {
			DrawSquare(i, j, 56, colors[WHITE]);
		}
	}
	DrawLine(100, 100, 100, 700, 4, colors[DARK_SLATE_GRAY]);
	for (int k = 157; k < 757; k += 60) {
			DrawLine(k, 100, k, 700, 5, colors[DARK_SLATE_GRAY]);
	}
	DrawLine(98, 100, 700, 100, 4, colors[DARK_SLATE_GRAY]);
	for (int k = 157; k < 757; k += 60) {
		DrawLine(100, k, 700, k, 5, colors[DARK_SLATE_GRAY]);
	}

	//DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
	//Drawing line for partition between game menu
	DrawLine( 800 , 0 ,  800 , 900 , 12 , colors[WHITE] );	
	
	drawObject(); 
	glutSwapBuffers(); // do not modify this line..   
}



//Second Page of The Game Gid
void GameDisplay2() 
{
	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
		0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear(GL_COLOR_BUFFER_BIT); //Update the colors

	DrawString(320, 800, "Player 1", colors[RED]);
	//Player 1 Grid
	for (int i = 100; i < 700; i += 60) {
		for (int j = 100; j < 700; j += 60) {
			DrawSquare(i, j, 56, colors[WHITE]);
		}
	}
	DrawLine(100, 100, 100, 700, 4, colors[DARK_SLATE_GRAY]);
	for (int k = 157; k < 757; k += 60) {
		DrawLine(k, 100, k, 700, 5, colors[DARK_SLATE_GRAY]);
	}
	DrawLine(98, 100, 700, 100, 4, colors[DARK_SLATE_GRAY]);
	for (int k = 157; k < 757; k += 60) {
		DrawLine(100, k, 700, k, 5, colors[DARK_SLATE_GRAY]);
	}

	//Player 2 Grid
	DrawString(1150, 800, "Computer", colors[RED]);

	for (int i = 900; i < 1500; i += 60) {
		for (int j = 100; j < 700; j += 60) {
			DrawSquare(i, j, 56, colors[WHITE]);
		}
	}
	// Separation between the Pages
	DrawLine(900, 100, 900, 700, 4, colors[DARK_SLATE_GRAY]);
	for (int k = 957; k < 1557; k += 60) {
		DrawLine(k, 100, k, 700, 5, colors[DARK_SLATE_GRAY]);
	}
	DrawLine(898, 100, 1500, 100, 4, colors[DARK_SLATE_GRAY]);
	for (int k = 157; k < 757; k += 60) {
		DrawLine(900, k, 1500, k, 5, colors[DARK_SLATE_GRAY]);
	}  

	//Drawing line for partition between game menu
	DrawLine(800, 0, 800, 900, 12, colors[WHITE]);

	glutSwapBuffers(); // do not modify this line.. 
}



//Function to Display MenuPage
void FrontMenu() 
{
	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
		0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear(GL_COLOR_BUFFER_BIT); //Update the colors
	//Title of the Page
	DrawString(638, 800, "SEA BATTLESHIP GAME", colors[RED]);
	DrawString(750, 750, "MENU", colors[RED]);
	// Drawing the Border
	DrawLine(400, 100, 1200, 100, 2, colors[WHITE]);
	DrawLine(1200, 680, 400, 680, 2, colors[WHITE]);
	DrawLine(1200, 100, 1200, 680, 2, colors[WHITE]);
	DrawLine(400, 680, 400, 100, 2, colors[WHITE]); 
	//Drawing Buttons
	DrawRoundRect(700, 560, 210, 40, colors[WHITE], 0);
	DrawRoundRect(700, 430, 210, 40, colors[WHITE], 0);
	DrawRoundRect(700, 300, 210, 40, colors[WHITE], 0);
	DrawRoundRect(700, 170, 210, 40, colors[WHITE], 0);
	//Button Display
	DrawString(775, 570, "Start", colors[BLACK]);
	DrawString(735, 440, "Leaderboard", colors[BLACK]);
	DrawString(760, 310, "Balance", colors[BLACK]);
	DrawString(760, 180, "Options", colors[BLACK]);
	glutSwapBuffers(); // do not modify this line..  
}



//LeaderBoard Function
void LeaderBoard()
{
	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
	    0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear(GL_COLOR_BUFFER_BIT); //Update the colors
	DrawString(735, 640, "LeaderBoard", colors[RED]);
	// Drawing the Border
	DrawLine(400, 100, 1200, 100, 2, colors[WHITE]);
	DrawLine(1200, 680, 400, 680, 2, colors[WHITE]);
	DrawLine(1200, 100, 1200, 680, 2, colors[WHITE]);
	DrawLine(400, 680, 400, 100, 2, colors[WHITE]);
	//Back Button
	DrawRoundRect(1500, 810, 170, 40, colors[WHITE], 0);
	DrawString(1520, 820, "Back", colors[BLACK]);
	DrawString(835, 820, "Back", colors[BLACK]);
	DrawString(475, 550, "Haider", colors[WHITE]);
	DrawString(475, 500, "Usman", colors[WHITE]);
	DrawString(475, 450, "Farzam", colors[WHITE]);
	DrawString(475, 400, "Zubair", colors[WHITE]);
	DrawString(475, 350, "Danish", colors[WHITE]);
	DrawString(475, 300, "Fizza", colors[WHITE]);
	DrawString(475, 250, "Laiba", colors[WHITE]);
	DrawString(475, 200, "Hadia", colors[WHITE]);
	DrawString(475, 150, "Asbah", colors[WHITE]);
	glutSwapBuffers(); // do not modify this line.. 
}



//Balance Function
// Declaring Balance as Global Variable
int price = 500;
void balance()
{
	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
		0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear(GL_COLOR_BUFFER_BIT); //Update the colors
	// Drawing the Border
	DrawLine(400, 100, 1200, 100, 2, colors[WHITE]);
	DrawLine(1200, 680, 400, 680, 2, colors[WHITE]);
	DrawLine(1200, 100, 1200, 680, 2, colors[WHITE]);
	DrawLine(400, 680, 400, 100, 2, colors[WHITE]); 
	//Back Button
	DrawRoundRect(1500, 810, 170, 40, colors[WHITE], 0);
	DrawString(1515, 820, "Back", colors[BLACK]);
	//Displaying score by converting int to string
	stringstream display;
	display << price;
	string str = display.str();
	DrawString(650, 380, "Your Current Balance is $", colors[RED]);
	DrawString(955, 380, str, colors[RED]);
	glutSwapBuffers(); // do not modify this line..
	DrawString(250, 780, "Current Balance= $", colors[RED]);
	DrawString(400,780, str, colors[RED]);
}



//Option Function
void options()
{
	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
		0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear(GL_COLOR_BUFFER_BIT); //Update the colors
	// Drawing the Border
	DrawLine(400, 100, 1200, 100, 2, colors[WHITE]);
	DrawLine(1200, 680, 400, 680, 2, colors[WHITE]);
	DrawLine(1200, 100, 1200, 680, 2, colors[WHITE]);
	DrawLine(400, 680, 400, 100, 2, colors[WHITE]); 
	//Back Button
	DrawRoundRect(1500, 810, 170, 40, colors[WHITE], 0);
	DrawString(1515, 820, "Back", colors[BLACK]);
	
	//Displaying Colour choice Menu 
	DrawString(640, 600, "Colour Choice for BattleShips", colors[RED]);
	//First Row
	DrawSquare(740, 545, 20, colors[ORANGE]);
	DrawSquare(765, 545, 20, colors[DARK_SLATE_GRAY]);
	DrawSquare(790, 545, 20, colors[INDIGO]);
	DrawSquare(815, 545, 20, colors[FIREBRICK]);
	DrawSquare(840, 545, 20, colors[KHAKI]);
	//Second Row
	DrawSquare(740, 518, 20, colors[SADDLE_BROWN]);
	DrawSquare(765, 518, 20, colors[GREEN]);
	DrawSquare(790, 518, 20, colors[GOLD]);
	DrawSquare(815, 518, 20, colors[LIGHT_SKY_BLUE]);
	DrawSquare(840, 518, 20, colors[DEEP_PINK]);
	//Buttons
	DrawRoundRect(615, 400 , 400 , 40, colors[WHITE], 0);
	DrawString(730 , 410 , "Mines ($100)", colors[BLACK]);
	DrawRoundRect(615, 300 , 400 , 40, colors[WHITE], 0);
	DrawString(715 , 310 , "Bomber ($200)", colors[BLACK]);
	DrawRoundRect(615 , 200, 400, 40, colors[WHITE], 0);
	DrawString(700 , 210, "Submarine ($250)", colors[BLACK]);
	glutSwapBuffers(); // do not modify this line..
}



// Random Function
/*  void InitRandomizer()
{
	int x, y;
	unsigned seed = time(0);
	srand(seed);
	const long rmin = 100;
	const long rmax = 700;
	for (int i = 0; i < 9; i++)
	{
		x = GetRandInRange(rmin, rmax);
		y = GetRandInRange(rmin, rmax);
		while (x != y)
		{
			InitRandomizer();
		}
		void DrawRectangle(int x, int y, int ar3[3], int ar[4], float* GOLD);
	}
}



long GetRandInRange(const long& rmin, const long& rmax)
{
	long q;
	q = (rand () % (rmax - rmin + 1) + rmin);
	return q;
}   */



/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */
void NonPrintableKeys(int key, int x, int y) {
	if (key
			== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed...
		xI -= 10;

	} else if (key
			== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {
		xI += 10;
	} else if (key
			== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {
		yI += 10;
	}

	else if (key
			== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {
		yI -= 10;
	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();

}



/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}

	if (key == 'b' || key == 'B') //Key for placing the bomb
			{
		//do something if b is pressed
		cout << "b pressed" << endl;

	}
	glutPostRedisplay();
}



/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m)
{
	// implement your functionality here
	moveObject();

	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(100, Timer, 0);
}



/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y)
{
	cout << x << " " << y << endl;
	//if(MousePressedAndMoved && ())
	glutPostRedisplay();
}



void MouseMoved(int x, int y) {
	//cout << x << " " << y << endl;
	glutPostRedisplay();
}



/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
//Global Variable set a Flag
int fade = 0;
void MouseClicked(int button, int state, int x, int y)
{
	// Condition  for accessing Gamegrid Menu after clicking Start
	if (fade == 0)
	{
		if (button == GLUT_LEFT_BUTTON)      // dealing only with left button
		{

			if ((x > 600 && x < 780) && (y > 250 && y < 280))
			{
				glutDisplayFunc(GameDisplay);
				fade = 1;
			}
			//For accessing Leader Board
			if ((x > 600 && x < 780) && (y > 350 && y < 380))
			{
				glutDisplayFunc(LeaderBoard);
				fade = 1;
			}
			//For acessing Balance
			if ((x > 600 && x < 780) && (y > 460 && y < 500))
			{
				glutDisplayFunc(balance);
				fade = 1;
			}
			//For accessing Options
			if ((x > 600 && x < 780) && (y > 570 && y < 610))
			{
				glutDisplayFunc(options);
				fade = 1;
			}
			
		}

	}

	if (fade == 1) 
	{
		if (button == GLUT_LEFT_BUTTON)
		{
			//Cond for taking to Home
			if ((x > 1280 && x < 1370) && (y > 37 && y < 72))
			{
				fade = 0;
				glutDisplayFunc(FrontMenu);
			}

		//Cond for tking yu to the 
			else if ((x > 1280 && x < 1356) && (y > 84 && y < 120))
			{
				glutDisplayFunc(options);
				fade = 1;
			}
			
		}
	}



// Conditions for changing ships colours
//First Row
	if (fade == 1)
	{
		if (button == GLUT_LEFT_BUTTON)
		{
			if ((x > 635 && x < 650) && (y > 280 && y < 295))
			{
				changecolour = ORANGE;
			}
		}
		//Dark Slate Gray colour
		if (button == GLUT_LEFT_BUTTON)
		{
			if ((x > 655 && x < 670) && (y > 280 && y < 295))
			{
				changecolour = DARK_SLATE_GRAY;
			}
		}
		//Indigo Colour
		if (button == GLUT_LEFT_BUTTON)
		{
			if ((x > 675 && x < 690) && (y > 280 && y < 295))
			{
				changecolour = INDIGO;
			}
		}
		//FireBrick colour
		if (button == GLUT_LEFT_BUTTON)
		{
			if ((x > 695 && x < 710) && (y > 280 && y < 295))
			{
				changecolour = FIREBRICK;
			}
		}
		//Khaki colour
		if (button == GLUT_LEFT_BUTTON)
		{
			if ((x > 710 && x < 725) && (y > 303 && y < 318))
			{
				changecolour = KHAKI;
			}
		}

//Second Row
		//Saddle Brown colour
		if (button == GLUT_LEFT_BUTTON)
		{
			if ((x > 635 && x < 650) && (y > 303 && y < 318))
			{
				changecolour = SADDLE_BROWN;
			}
		}
		//Green colour
		if (button == GLUT_LEFT_BUTTON)
		{
			if ((x > 655 && x < 670) && (y > 303 && y < 318))
			{
				changecolour = GREEN;
			}
		}
		//Gold colour
		if (button == GLUT_LEFT_BUTTON)
		{
			if ((x > 675 && x < 690) && (y > 303 && y < 318))
			{
				changecolour = GOLD;
			}
		}
		//Light Sky Blue colour
		if (button == GLUT_LEFT_BUTTON)
		{
			if ((x > 695 && x < 710) && (y > 303 && y < 318))
			{
				changecolour = LIGHT_SKY_BLUE;
			}
		}
		//Deep Pink colour
		if (button == GLUT_LEFT_BUTTON)
		{
			if ((x > 710 && x < 725) && (y > 303 && y < 318))
			{
				changecolour = DEEP_PINK;
			}
		}
	}
	

	
	if (fade != 0)
	{
		//ship 1
		if (button == GLUT_LEFT_BUTTON)
		{
			if ((x > 1425 && x < 1475) && (y > 576 && y < 800))
			{
				fade = 3;
			}
		}

		//ship 2
		if (button == GLUT_LEFT_BUTTON) // dealing with right button
		{
			if ((x > 1300 && x < 1350) && (y > 632 && y < 800))
			{
				fade = 4;
			}
		}
		//ship 3
		if (button == GLUT_LEFT_BUTTON) // dealing with right button
		{
			if ((x > 1225 && x < 1275) && (y > 632 && y < 800))
			{
				fade = 5;
			}
		}
		//ship 4
		if (button == GLUT_LEFT_BUTTON) // dealing with right button
		{
			if ((x > 1050 && x < 1162) && (y > 600 && y < 650))
			{
				fade = 6;
			}
		}
		//ship 5
		if (button == GLUT_LEFT_BUTTON) // dealing with right button
		{
			if ((x > 1050 && x < 1162) && (y > 675 && y < 725))
			{
				fade = 7;
			}
		}
		//ship 6
		if (button == GLUT_LEFT_BUTTON) // dealing with right button
		{
			if ((x > 1050 && x < 1162) && (y > 750 && y < 800))
			{
				fade = 8;
			}
		}
		//ship 7
		if (button == GLUT_LEFT_BUTTON) // dealing with right button
		{
			if ((x > 1050 && x < 1100) && (y > 500 && y < 550))
			{
				fade = 9;
			}
		}
		//ship 8
		if (button == GLUT_LEFT_BUTTON) // dealing with right button
		{
			if ((x > 1150 && x < 1200) && (y > 500 && y < 550))
			{
				fade = 10;
			}
		}
		//ship 9
		if (button == GLUT_LEFT_BUTTON) // dealing with right button
		{
			if ((x > 1250 && x < 1300) && (y > 500 && y < 550))
			{
				fade = 11;
			}
		}
		//ship 10
		if (button == GLUT_LEFT_BUTTON) // dealing with right button
		{
			if ((x > 1350 && x < 1400) && (y > 500 && y < 550))
			{
				fade = 12;
			}
		}
	}

	//Conditions for curser moving
if (fade == 3)
{
	for (int i = 100; i < 700; i += 60)
	{
		for (int j = 100; j < 700; j += 60)
		{
			if (button == GLUT_LEFT_BUTTON)
			{
				if ((x > i && x < (i + 50)) && (y > (850 - j) && y < (900 - j)))
				{
					arrx[0] = i; arry[0] = j;
				}
			}
		}
	}
}

if (fade == 4)
{
	for (int i = 100; i < 700; i += 60)
	{
		for (int j = 100; j < 700; j += 60)
		{
			if (button == GLUT_LEFT_BUTTON)
			{
				if ((x > i && x < (i + 50)) && (y > (850 - j) && y < (900 - j)))
				{
					arrx[1] = i; arry[1] = j;
				}
			}
		}
	}
}

if (fade == 5)
{
	for (int i = 100; i < 700; i += 60)
	{
		for (int j = 100; j < 700; j += 60)
		{
			if (button == GLUT_LEFT_BUTTON)
			{
				if ((x > i && x < (i + 50)) && (y > (850 - j) && y < (900 - j)))
				{
					arrx[2] = i; arry[2] = j;
				}
			}
		}
	}
}

if (fade == 6)
{
	for (int i = 100; i < 700; i += 60)
	{
		for (int j = 100; j < 700; j += 60)
		{
			if (button == GLUT_LEFT_BUTTON)
			{
				if ((x > i && x < (i + 50)) && (y > (850 - j) && y < (900 - j)))
				{
					arrx[3] = i; arry[3] = j;
				}
			}
		}
	}
}

if (fade == 7)
{
	for (int i = 100; i < 700; i += 60)
	{
		for (int j = 100; j < 700; j += 60)
		{
			if (button == GLUT_LEFT_BUTTON)
			{
				if ((x > i && x < (i + 50)) && (y > (850 - j) && y < (900 - j)))
				{
					arrx[4] = i; arry[4] = j;
				}
			}
		}
	}
}

if (fade == 8)
{
	for (int i = 100; i < 700; i += 60)
	{
		for (int j = 100; j < 700; j += 60)
		{
			if (button == GLUT_LEFT_BUTTON)
			{
				if ((x > i && x < (i + 50)) && (y > (850 - j) && y < (900 - j)))
				{
					arrx[5] = i; arry[5] = j;
				}
			}
		}
	}
}

if (fade == 9)
{
	for (int i = 100; i < 700; i += 60)
	{
		for (int j = 100; j < 700; j += 60)
		{
			if (button == GLUT_LEFT_BUTTON)
			{
				if ((x > i && x < (i + 50)) && (y > (850 - j) && y < (900 - j)))
				{
					arrx[6] = i; arry[6] = j;
				}
			}
		}
	}
}

if (fade == 10)
{
	for (int i = 100 ; i < 700; i += 60)
	{
		for (int j = 100; j < 700; j += 60)
		{
			if (button == GLUT_LEFT_BUTTON)
			{
				if ((x > i && x < (i + 50)) && (y > (850 - j) && y < (900 - j)))
				{
					arrx[7] = i; arry[7] = j;
				}
			}
		}
	}
}

if (fade == 11)
{
	for (int i = 100; i < 700; i += 60)
	{
		for (int j = 100; j < 700; j += 60)
		{
			if (button == GLUT_LEFT_BUTTON)
			{
				if ((x > i && x < (i + 50)) && (y > (850 - j) && y < (900 - j)))
				{
					arrx[8] = i; arry[8] = j;
				}
			}
		}
	}
}

if (fade == 12)
{
	for (int i = 100; i < 700; i += 60)
	{
		for (int j = 100; j < 700; j += 60)
		{
			if (button == GLUT_LEFT_BUTTON)
			{
				if ((x > i && x < (i + 50)) && (y > (850 - j) && y < (900 - j)))
				{
					arrx[9] = i; arry[9] = j;
				}
			}
		}
	}
}

	glutPostRedisplay();
}



/*   Our Gateway Main Function   */
int main(int argc, char*argv[]) {

	int width =1600, height = 900;       // i have set my window size to be 800 x 600
	InitRandomizer();           // seed the random number generator...
	glutInit(&argc, argv);        // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);       // we will be using color display mode
	glutInitWindowPosition(50, 50);       // set the initial position of our window
	glutInitWindowSize(width, height);       // set the size of our window
	glutCreateWindow("Battleship Game");       // set the title of our game window
	SetCanvasSize(width, height);       // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.


	//Function call to Display the Menu Page
	glutDisplayFunc(FrontMenu);         // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys);     // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys);      // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved);       // Mouse
	glutMotionFunc(MousePressedAndMoved);     // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* Battleship_CPP_ */
