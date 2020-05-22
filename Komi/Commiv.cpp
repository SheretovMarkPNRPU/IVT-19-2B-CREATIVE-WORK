#pragma  once
#include "graph.h"
#include <Windows.h>
#include <iostream>

using namespace std;



int main(int argc, char** argv)
{
	setlocale(LC_ALL, "rus");			//Подготовка консоли к работе
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	glutInit(&argc, argv);				//Инициализация GLUT

	setGraph();							//создание графа		
	
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); //Создание OpenGL окна и начало работы с ним.
	glutInitWindowSize(WinW, WinH);
	glutCreateWindow("Задача посыльного");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMouseFunc(clickMouse);
	glutPassiveMotionFunc(moveMouse);
	
	glutMainLoop();
}

