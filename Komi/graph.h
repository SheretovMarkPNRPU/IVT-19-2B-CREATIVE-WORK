#pragma once
#include <vector>
#include <glut.h>
#include <iostream>
#include <string>
#include <iomanip>
#include <Windows.h>
#define maxSize 20
using namespace std;

extern int WinW;					//ширина окна
extern int WinH;					//высота окна				

struct vertC						//структура координат вершин
{
	int x, y;
};

class Graph
{
private:
	vector<int> vertList;					//вектор вершин
	int adjMatrix[maxSize][maxSize];		//матрица смежности
	 
public:
	Graph();			//конструктор
	~Graph();			//деструктор

	bool IsEmpty();		//проверка на пустоту графа
	bool IsFull();		//проверка на полноту графа

	int GetAdjMatrixElem(int i, int j) { return adjMatrix[i][j]; }//вернёт элемент матрицы смежности
	int GetVertListSize() { return vertList.size(); }		//вернёт кол-во вершин графа
	int GetVertPos(const int& vertex);						//вернёт позицию вершины
	int GetcountEdges();									//вернёт кол-во ребер

	void SetEdgeZero(int i, int j) { adjMatrix[i][j] = 0; adjMatrix[j][i] = 0; } //зануленит элементы матрицы смежности
	void InsertVertex(const int& vertex);					//добавит вершину
	void InsertEdge(const int& vertex1, const int& vertex2, int weigth);//добавит ребро

	void Print();											//Выведет в консоль матрицу смежности

	void eraseLastVert();									//удалит последнюю вершину
	void eraseEdge(const int& vertex1, const int& vertex2);	//удалит выбранное ребро
};

extern Graph graph;		//граф

//решение задачи коммивояжера
int** makeTSPMatrix();					//создаст матрицу и изменит 0 на -1
int* findMin(int* line, int n);			//поиск минимума в строке
void printMatrix(int** matrix);			//печать текущей матрицы
int** reductionLines(int** oldmatrix);	//редукция строк и столбцов
int** rebuildMatrix(int** oldmatrix);	//перестроение матрицы, нахождение отрезка пути
void resultPrint();						//печать найденного пути

//отрисовка
void drawButton1();			//отрисвка кнопок
void drawButton2();
void drawButSteps();
void drawButton3();
void drawButPath();
void drawButton4();
void drawButton5();
void drawButton6();
void drawSomeInfo();		//отрисовка информации о графе

void drawCircle(int x, int y, int R);					//нарисует круг
void drawBorderedCircle(int x, int y, int R);			//Изменит(нарисует поверх) цвет круга, если курсос наведён на него
void drawText(int nom, int x1, int y1);					//нарисует текст
void drawLine(int text, int x0, int y0, int x1, int y1);//нарисует соединяющую линию
void drawVertex(int n);									//нарисует вершину и текст (круг и текст)
void drawPathVertex(int n);								//визуализация пути коммивояжера
void drawGraph();										//нарисует весь граф полностью

void setGraph();										//создаст графа

void setCoords(int i, int n);							//установка координат

bool checkCommi(int** matrix);							//проверка на возможность задачи коммивояжера
int checkCircle(int x, int y);							//проверка на вхождение курсора в круг
void checkButton(int x, int y);							//проверка на вхождение курсора в кнопку

void drawLineCut(int x, int y);							//отрисовка отрезающей линии
bool cross(int x11, int x12, int y11, int y12, int x21, int x22, int y21, int y22);	//нахождение точки пересечения отрез. линии и ребра (ребер)
void deleteEdgeByCut();									//удаление выбранного (или выбранных) ребра (ребер)

void moveMouse(int x, int y);							//отслеживание движения мыши
void clickMouse(int button, int state, int x, int y);	//отслеживание нажатий мыши
void reshape(int w, int h);								//Пересборка формы
void display();											//отрисовка содержимого окна


