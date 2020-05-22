#pragma once
#include <vector>
#include <glut.h>
#include <iostream>
#include <string>
#include <iomanip>
#include <Windows.h>
#define maxSize 20
using namespace std;

extern int WinW;					//������ ����
extern int WinH;					//������ ����				

struct vertC						//��������� ��������� ������
{
	int x, y;
};

class Graph
{
private:
	vector<int> vertList;					//������ ������
	int adjMatrix[maxSize][maxSize];		//������� ���������
	 
public:
	Graph();			//�����������
	~Graph();			//����������

	bool IsEmpty();		//�������� �� ������� �����
	bool IsFull();		//�������� �� ������� �����

	int GetAdjMatrixElem(int i, int j) { return adjMatrix[i][j]; }//����� ������� ������� ���������
	int GetVertListSize() { return vertList.size(); }		//����� ���-�� ������ �����
	int GetVertPos(const int& vertex);						//����� ������� �������
	int GetcountEdges();									//����� ���-�� �����

	void SetEdgeZero(int i, int j) { adjMatrix[i][j] = 0; adjMatrix[j][i] = 0; } //��������� �������� ������� ���������
	void InsertVertex(const int& vertex);					//������� �������
	void InsertEdge(const int& vertex1, const int& vertex2, int weigth);//������� �����

	void Print();											//������� � ������� ������� ���������

	void eraseLastVert();									//������ ��������� �������
	void eraseEdge(const int& vertex1, const int& vertex2);	//������ ��������� �����
};

extern Graph graph;		//����

//������� ������ ������������
int** makeTSPMatrix();					//������� ������� � ������� 0 �� -1
int* findMin(int* line, int n);			//����� �������� � ������
void printMatrix(int** matrix);			//������ ������� �������
int** reductionLines(int** oldmatrix);	//�������� ����� � ��������
int** rebuildMatrix(int** oldmatrix);	//������������ �������, ���������� ������� ����
void resultPrint();						//������ ���������� ����

//���������
void drawButton1();			//�������� ������
void drawButton2();
void drawButSteps();
void drawButton3();
void drawButPath();
void drawButton4();
void drawButton5();
void drawButton6();
void drawSomeInfo();		//��������� ���������� � �����

void drawCircle(int x, int y, int R);					//�������� ����
void drawBorderedCircle(int x, int y, int R);			//�������(�������� ������) ���� �����, ���� ������ ������ �� ����
void drawText(int nom, int x1, int y1);					//�������� �����
void drawLine(int text, int x0, int y0, int x1, int y1);//�������� ����������� �����
void drawVertex(int n);									//�������� ������� � ����� (���� � �����)
void drawPathVertex(int n);								//������������ ���� ������������
void drawGraph();										//�������� ���� ���� ���������

void setGraph();										//������� �����

void setCoords(int i, int n);							//��������� ���������

bool checkCommi(int** matrix);							//�������� �� ����������� ������ ������������
int checkCircle(int x, int y);							//�������� �� ��������� ������� � ����
void checkButton(int x, int y);							//�������� �� ��������� ������� � ������

void drawLineCut(int x, int y);							//��������� ���������� �����
bool cross(int x11, int x12, int y11, int y12, int x21, int x22, int y21, int y22);	//���������� ����� ����������� �����. ����� � ����� (�����)
void deleteEdgeByCut();									//�������� ���������� (��� ���������) ����� (�����)

void moveMouse(int x, int y);							//������������ �������� ����
void clickMouse(int button, int state, int x, int y);	//������������ ������� ����
void reshape(int w, int h);								//���������� �����
void display();											//��������� ����������� ����


