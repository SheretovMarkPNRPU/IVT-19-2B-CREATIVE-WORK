#include "graph.h"
using namespace std;
//
//		Глобальные переменные
//
int WinW = 1280;					//ширина окна
int WinH = 720;						//высота окна
				
bool printSteps = false;			//печатать шаги или нет
bool drawing = true;				//отвечает за отрисовку шагов пути			
bool* onMouse = new bool[maxSize];	//если мышь на вершине - true
bool movable = false;				//режим перестановки, нет масштабирования
bool moving = false;				//двигаем вершину - true

bool merging = false;				//соединение - true
bool cutting = false;				//режем - true

vector<pair<int, int>> path;		//вектор отрезков пути коммивояжера
vector<int> newpath;				//вектор полного пути коммивояжера
int R;								//радиус вершин

int fNode;							//Первая вершина для соединения
int sNode;							//Вторая вершина для соединения

int curNode;						//текущая двигаемая вершина
int curPosX;						//позиция курсора Х
int curPosY;						//позиция курсора Y

vertC vC[maxSize + 2];				//массив координат

pair<int, int> lineFirst;			//координаты режущей линии X
pair<int, int> lineSecond;			//координаты режущей линии Y

pair<int, int>  mergeLineFirst;		//Координаты соединяющей линии X	(не работает)
pair<int, int > mergeLineSecond;	//Координаты соединяющей линии Y	(не работает)	

Graph graph;						//граф

int buttonsState;					//отвечает за положиние курсора на кнопке

int maxRad; int minRad = 10;		//макс. и мин. радиусы



//
//				Функции для работы с графом
// 

Graph::Graph()		//заполнение матрицы смежности нулями и массива вхождения курсора в вершину
{
	for (int i = 0; i < maxSize; i++)
	{
		for (int j = 0; j < maxSize; j++)
			adjMatrix[i][j] = 0;
		onMouse[i] = false;			
	}
}

Graph::~Graph()		//деструктор
{}

int Graph::GetVertPos(const int& vertex)	//получить позицию вершины
{
	for (size_t i = 0; i < vertList.size(); i++)
		if (vertList[i] == vertex)
			return i;
	return -1;
}

bool Graph::IsEmpty()
{
	if (vertList.size() != 0)
		return false;
	else
		return true;		//если пуст возвращаем true
}

bool Graph::IsFull()
{
	return (vertList.size() == maxSize);	//если полон возвращаем true
}

void Graph::InsertVertex(const int& vertex)
{
	if (!IsFull())		//если граф не полон то добавляем вершину
		vertList.push_back(vertex);
	else
	{
		cout << "Граф заполнен!" << endl;
		return;
	}
}

void Graph::InsertEdge(const int& vertex1, const int& vertex2, int weight)
{
	if (weight < 1)	//если вес ребра отрицательный, то завершаем функцию
	{
		cout << "\nТакой вес не может быть.\n";
		return;
	}
	if (GetVertPos(vertex1) != (-1) && GetVertPos(vertex2) != (-1))						//если вершины есть в графе
	{
		int vertPos1 = GetVertPos(vertex1);												//находим позиции вершин
		int vertPos2 = GetVertPos(vertex2);
		if (adjMatrix[vertPos1][vertPos2] != 0 && adjMatrix[vertPos2][vertPos1] != 0)	//если между ними уже есть ребро
		{
			cout << "Ребро между вершинами уже есть" << endl;							//то возвращаемся
			return;
		}
		else																			//иначе добавляем ребро
		{
			adjMatrix[vertPos1][vertPos2] = weight;
			adjMatrix[vertPos2][vertPos1] = weight;
		}
	}
	else
	{
		cout << "Обеих вершин (или одной из них) нет в графе " << endl;
		return;
	}
}

void Graph::Print()
{
	if (!IsEmpty())											//если граф не пуст
	{
		cout << "Матрица смежности графа: " << endl;		//то печатаем элементы матрицы смежности
		for (size_t i = 0; i < vertList.size(); i++)
		{
			cout << vertList[i] << " ";
			for (size_t j = 0; j < vertList.size(); j++)
				cout << setw(4) << adjMatrix[i][j];
			cout << endl;
		}
	}
	else
		cout << "Граф пуст!" << endl;
}

void Graph::eraseLastVert()
{
	if (IsEmpty())					//если граф пусть - возвращаемся
	{
		cout << "\nГраф пуст\n";
		return;
	}

	int n = vertList.size();		
	for (int j = 0; j < n; j++)		//иначе зануляем ребра выбранной вершины
		SetEdgeZero(n - 1, j);

	vertList.pop_back();			//и удаляем ее из вектора вершин
}

void Graph::eraseEdge(const int& vertex1, const int& vertex2)
{
	if (GetVertPos(vertex1) != (-1) && GetVertPos(vertex2) != (-1))						//если вершины есть в графе
	{
		int vertPos1 = GetVertPos(vertex1);												//находим позиции вершин
		int vertPos2 = GetVertPos(vertex2);
		if (adjMatrix[vertPos1][vertPos2] == 0 && adjMatrix[vertPos2][vertPos1] == 0)	//если между ними уже нет ребра
		{
			cout << "Здесь ребра нет!" << endl;											//то возвращаемся
			return;
		}
		else																			//иначе зануляем данное ребро
			SetEdgeZero(vertPos1, vertPos2);
	}
	else
	{
		cout << "Обеих вершин (или одной из них) нет в графе!" << endl;
		return;
	}
}

int Graph::GetcountEdges()									//Вернуть количество рёбер
{
	int edges = 0;
	for (int i = 0; i < vertList.size(); i++)				//проходимся по 2 диагональной части матрицы, не включая диагональ
		for (int j = i + 1; j < vertList.size(); j++)
			if (adjMatrix[i][j] > 0)						//если элемент больше нуля
				edges++;									//то кол-во ребер +1
	return edges;
}

int** makeTSPMatrix()	//создаем матрицу и меняем 0 на -1
{
	int n = graph.GetVertListSize();
	int** matrix = new int* [n];		//создаем матрицу размером как матрица смежности
	for (int i = 0; i < n; i++)
		matrix[i] = new int[n];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			int elem = graph.GetAdjMatrixElem(i, j);	//копируем все элементы из матрицы смежности
			if (elem == 0 or i == j)					//если нет путей, то замена на -1 тк 0 будет использоватся
				matrix[i][j] = -1;
			else
				matrix[i][j] = elem;
		}

	if (printSteps)								//если включена печать шагов
	{
		cout << "Первоначальная матрица: \n";	//то печатаем матрицу
		printMatrix(matrix);
	}
	return matrix;
}

int* findMin(int* line, int n)	
{
	int min = 1000000;
	for (int j = 0; j < n; j++)					//поиск минимума в строке
		if (line[j] >= 0 && line[j] < min)
			min = line[j];

	for (int j = 0; j < n; j++)					//и вычитание его из каждого элемента строки
		if (line[j] >= 0)
			line[j] -= min;
	return line;
}

void printMatrix(int** matrix)		//печать текущей матрицы
{
	int n = graph.GetVertListSize();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(4) << matrix[i][j];
		cout << endl;
	}
}

int** reductionLines(int** oldmatrix)		//редукция строк и столбцов
{
	int** matrix = oldmatrix;				//копируем старую матрицу
	int n = graph.GetVertListSize();
	for (int i = 0; i < n; i++)				//редуцируем сначала строки
		matrix[i] = findMin(matrix[i], n);

	for (int i = 0; i < n; i++)				//потом стобцы
	{
		int min = 1000000;
		for (int j = 0; j < n; j++)
		{
			if (matrix[j][i] >= 0 && matrix[j][i] < min)
				min = matrix[j][i];
		}
		for (int j = 0; j < n; j++)
		{
			if (matrix[j][i] >= 0)
				matrix[j][i] -= min;
		}
	}
	if (printSteps)							//если включена печать шагов
	{
		cout << "\nРедуцированная матрица: \n";
		printMatrix(matrix);				//то печатаем матрицу
	}
	return matrix;
}

int** rebuildMatrix(int** oldmatrix)			//Перестраивает матрицу смежности
{
	int n = graph.GetVertListSize();
	int** matrix = reductionLines(oldmatrix);	//принимаем редуцированную матрицу

	int max = -1;
	int line, column;

	for (int i = 0; i < n; i++)					//поиск 0 с наибольшей оценкой
	{
		for (int j = 0; j < n; j++)
		{
			if (matrix[i][j] == 0)				//если нашли 0 в матрице
			{
				int minLine = 1000000;
				int minColumn = 1000000;
				for (int k = 0; k < n; k++)
				{
					if (matrix[i][k] != -1 && k != j && matrix[i][k] < minLine)			//поиск минимума в строке
						minLine = matrix[i][k];
				}
				for (int k = 0; k < n; k++)
				{
					if (matrix[k][j] != -1 && k != i && matrix[k][j] < minColumn)		//поиск минимума в столбце
						minColumn = matrix[k][j];
				}
				if (max < minColumn + minLine)		//если сумма минимумов больше текущего максимума
				{
					max = minColumn + minLine;		//за переписываем максимум
					line = i;						//и записываем положение текущего 0 в матрице
					column = j;
				}									//это и есть отрезки пути
			}
		}
	}

	pair<int, int> p;		//записываем вершину в pair
	p.first = line + 1;		//откуда (+1 т.к. отсчет с 0)
	p.second = column + 1;	//куда
	path.push_back(p);		//и запись в вектор отрезков пути

	matrix[line][column] = -1;		//удаление нуля с наиб. оценкой c одной части
	matrix[column][line] = -1;		//удаление нуля с наиб. оценкой с другой части

	for (int i = 0; i < n; i++)		//удаление данных данного отрезка пути из матрцы
	{
		matrix[line][i] = -1;
		matrix[i][column] = -1;
	}
	if (printSteps)		//если включена печать шагов
	{
		cout << endl;
		cout << "Матрица после удаления наибольшего 0: \n";
		printMatrix(matrix);				//вывод текущей матрицы после удаления
		cout << "\nЧасти пути: ";
		for (int i = 0; i < path.size(); i++)	//и отреза пути
			cout << path[i].first << " -> " << path[i].second << "   ";
		cout << endl;
	}
	return matrix;
}

void resultPrint()
{
	//newpath - вектор полного пути коммивояжера
	int second = path[0].second;		//2 пункт всего пути						
	newpath.push_back(path[0].first);	//добавляем 1 пункт
	newpath.push_back(path[0].second);	//2 пункт
	int i = 2;							//кол-во добавленных пунктов

	while (i != graph.GetVertListSize() + 1)			//пока не добавили все пункты
		for (int j = 1; j < graph.GetVertListSize(); j++)
			if (path[j].first == second)				//если первая вершина текущего отрезка пути (начало) равна концу предыдущего отразка пути
			{
				second = path[j].second;				//то новый конец - конец текущего отрезка пути
				newpath.push_back(second);				//и записываем его как след. пункт пути
				i++;
			}											//таким образом записывается полный путь с отправной точки - в отправную точку

	cout << "Путь: ";
	for (int i = 0; i < newpath.size(); i++)			//печать полного пути
	{
		cout << newpath[i];
		if (i != newpath.size() - 1)
			cout << " -> ";
	}

	int sum = 0;
	for (int i = 0; i < path.size(); i++)				//нахождение суммы пути
	{
		int line = path[i].first - 1;
		int column = path[i].second - 1;
		sum += graph.GetAdjMatrixElem(line, column);
	}
	cout << "\nКратчайшая длина пути: " << sum << endl;;
}


//
//Интерфейс OpenGL
//

void drawButton1()
{
	if (buttonsState == 1)
		glColor3f(0.0f, 1.0f, 0.498f);
	else
		glColor3f(0.902f, 0.902f, 0.980f);

	glBegin(GL_QUADS);
	glVertex2i(0, WinH);
	glVertex2i(0, WinH - WinH / 6);
	glVertex2i(WinW / 6, WinH - WinH / 6);
	glVertex2i(WinW / 6, WinH);
	glEnd();

	glColor3f(0.0f, 0.0f, 0.0f);

	glBegin(GL_LINE_LOOP);
	glVertex2i(0, WinH);
	glVertex2i(0, WinH - WinH / 6);
	glVertex2i(WinW / 6, WinH - WinH / 6);
	glVertex2i(WinW / 6, WinH);
	glEnd();

	string but1 = "Matrix";
	string but2 = "Print";
	glRasterPos2i(4, WinH - 12);
	for (int i = 0; i < but1.length(); i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, but1[i]);
	glRasterPos2i(4, WinH - 32);
	for (int i = 0; i < but2.length(); i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, but2[i]);

}

void drawButton2()
{
	if (buttonsState == 2)
		glColor3f(0.0f, 1.0f, 0.498f);
	else
		glColor3f(0.902f, 0.902f, 0.980f);

	glBegin(GL_QUADS);
	glVertex2i(0, WinH - (WinH / 6));
	glVertex2i(0, WinH - 2 * (WinH / 6));
	glVertex2i(WinW / 6, WinH - 2 * (WinH / 6));
	glVertex2i(WinW / 6, WinH - (WinH / 6));
	glEnd();

	glColor3f(0.0f, 0.0f, 0.0f);

	glBegin(GL_LINE_LOOP);
	glVertex2i(0, WinH - (WinH / 6));
	glVertex2i(0, WinH - 2 * (WinH / 6));
	glVertex2i(WinW / 6, WinH - 2 * (WinH / 6));
	glVertex2i(WinW / 6, WinH - (WinH / 6));
	glEnd();

	string but1 = "Solve the";
	string but2 = "Salesman problem";
	glRasterPos2i(4, WinH - (WinH / 6) - 12);
	for (int i = 0; i < but1.length(); i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, but1[i]);
	glRasterPos2i(4, WinH - (WinH / 6) - 32);
	for (int i = 0; i < but2.length(); i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, but2[i]);

}

void drawButSteps()						//отрисовываем кнопку переключения режима отображения шагов
{
	if (printSteps)
		glColor3f(0.0f, 0.5f, 0.0f);
	else
		glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	glVertex2i(0, 0);
	glVertex2i(0, WinH / 6);
	glVertex2i(WinW / 6, WinH / 6);
	glVertex2i(WinW / 6, 0);
	glEnd();
}

void drawButton3()
{
	if (buttonsState == 3)
		glColor3f(0.0f, 1.0f, 0.498f);
	else
		glColor3f(0.902f, 0.902f, 0.980f);

	glBegin(GL_QUADS);
	glVertex2i(0, WinH - 2 * (WinH / 6));
	glVertex2i(0, WinH - 3 * (WinH / 6));
	glVertex2i(WinW / 6, WinH - 3 * (WinH / 6));
	glVertex2i(WinW / 6, WinH - 2 * (WinH / 6));
	glEnd();

	glColor3f(0.0f, 0.0f, 0.0f);

	glBegin(GL_LINE_LOOP);
	glVertex2i(0, WinH - 2 * (WinH / 6));
	glVertex2i(0, WinH - 3 * (WinH / 6));
	glVertex2i(WinW / 6, WinH - 3 * (WinH / 6));
	glVertex2i(WinW / 6, WinH - 2 * (WinH / 6));
	glEnd();

	string but1 = "Set New";
	string but2 = "Graph";
	glRasterPos2i(4, WinH - 2 * (WinH / 6) - 12);
	for (int i = 0; i < but1.length(); i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, but1[i]);
	glRasterPos2i(4, WinH - 2 * (WinH / 6) - 32);
	for (int i = 0; i < but2.length(); i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, but2[i]);
}

void drawButPath()			//Отрисовываем кнопку разбора шагов
{
	if (drawing)
		glColor3f(0.0f, 0.0f, 1.0f);
	else
		glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	glVertex2i(WinW, 0);
	glVertex2i(WinW, WinH / 6);
	glVertex2i(5 * (WinW / 6), WinH / 6);
	glVertex2i(5 * (WinW / 6), 0);
	glEnd();
}

void drawButton4()
{
	if (buttonsState == 4)
		glColor3f(0.0f, 1.0f, 0.498f);
	else
		glColor3f(0.902f, 0.902f, 0.980f);

	glBegin(GL_QUADS);
	glVertex2i(WinW, WinH);
	glVertex2i(WinW, WinH - WinH / 6);
	glVertex2i(5 * (WinW / 6), WinH - WinH / 6);
	glVertex2i(5 * (WinW / 6), WinH);
	glEnd();

	glColor3f(0.0f, 0.0f, 0.0f);

	glBegin(GL_LINE_LOOP);
	glVertex2i(WinW, WinH);
	glVertex2i(WinW, WinH - WinH / 6);
	glVertex2i(5 * (WinW / 6), WinH - WinH / 6);
	glVertex2i(5 * (WinW / 6), WinH);
	glEnd();

	string but1 = "Rescale and";
	string but2 = "Rebuild graph";
	glRasterPos2i(5 * (WinW / 6) + 4, WinH - 12);
	for (int i = 0; i < but1.length(); i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, but1[i]);
	glRasterPos2i(5 * (WinW / 6) + 4, WinH - 32);
	for (int i = 0; i < but2.length(); i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, but2[i]);

}

void drawButton5()
{
	if (buttonsState == 5)
		glColor3f(0.0f, 1.0f, 0.498f);
	else
		glColor3f(0.902f, 0.902f, 0.980f);

	glBegin(GL_QUADS);
	glVertex2i(WinW, WinH - (WinH / 6));
	glVertex2i(WinW, WinH - 2 * (WinH / 6));
	glVertex2i(5 * (WinW / 6), WinH - 2 * (WinH / 6));
	glVertex2i(5 * (WinW / 6), WinH - (WinH / 6));
	glEnd();

	glColor3f(0.0f, 0.0f, 0.0f);

	glBegin(GL_LINE_LOOP);
	glVertex2i(WinW, WinH - (WinH / 6));
	glVertex2i(WinW, WinH - 2 * (WinH / 6));
	glVertex2i(5 * (WinW / 6), WinH - 2 * (WinH / 6));
	glVertex2i(5 * (WinW / 6), WinH - (WinH / 6));
	glEnd();

	string but1 = "Add / delete";
	string but2 = "LAST vert";
	glRasterPos2i(5 * (WinW / 6) + 4, 5 * (WinH / 6) - 12);
	for (int i = 0; i < but1.length(); i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, but1[i]);
	glRasterPos2i(5 * (WinW / 6) + 4, 5 * (WinH / 6) - 32);
	for (int i = 0; i < but2.length(); i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, but2[i]);

}

void drawButton6()
{
	if (buttonsState == 6)
		glColor3f(0.0f, 1.0f, 0.498f);
	else
		glColor3f(0.902f, 0.902f, 0.980f);

	glBegin(GL_QUADS);
	glVertex2i(WinW, WinH - 2 * (WinH / 6));
	glVertex2i(WinW, WinH - 3 * (WinH / 6));
	glVertex2i(5 * (WinW / 6), WinH - 3 * (WinH / 6));
	glVertex2i(5 * (WinW / 6), WinH - 2 * (WinH / 6));
	glEnd();

	glColor3f(0.0f, 0.0f, 0.0f);

	glBegin(GL_LINE_LOOP);
	glVertex2i(WinW, WinH - 2 * (WinH / 6));
	glVertex2i(WinW, WinH - 3 * (WinH / 6));
	glVertex2i(5 * (WinW / 6), WinH - 3 * (WinH / 6));
	glVertex2i(5 * (WinW / 6), WinH - 2 * (WinH / 6));
	glEnd();

	string but1 = "Add / delete";
	string but2 = "edges";
	glRasterPos2i(5 * (WinW / 6) + 4, 4 * (WinH / 6) - 12);
	for (int i = 0; i < but1.length(); i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, but1[i]);
	glRasterPos2i(5 * (WinW / 6) + 4, 4 * (WinH / 6) - 32);
	for (int i = 0; i < but2.length(); i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, but2[i]);

}

void drawCircle(int x, int y, int R) //круг в заданных координатах
{
	glColor3f(0.93725f, 0.79607f, 0.08235f);
	float x1, y1;
	glBegin(GL_POLYGON);			//круг
	for (int i = 0; i < 360; i++)
	{
		float theta = 2.0f * 3.1415926f * float(i) / float(360);
		y1 = R * cos(theta) + y;
		x1 = R * sin(theta) + x;;
		glVertex2f(x1, y1);
	}
	glEnd();

	glColor3f(0.0f, 0.0f, 0.0f);
	float x2, y2;
	glBegin(GL_LINE_LOOP);			//окружность
	for (int i = 0; i < 360; i++)
	{
		float theta = 2.0f * 3.1415926f * float(i) / float(360);
		y2 = R * cos(theta) + y;
		x2 = R * sin(theta) + x;
		glVertex2f(x2, y2);
	}
	glEnd();
}

void drawBorderedCircle(int x, int y, int R) //круг в заданных координатах
{
	glColor3f(1.0f, 0.9f, 0.1f);
	float x1, y1;
	glBegin(GL_POLYGON);		//круг
	for (int i = 0; i < 360; i++)
	{
		float theta = 2.0f * 3.1415926f * float(i) / float(360);
		y1 = R * cos(theta) + y;
		x1 = R * sin(theta) + x;;
		glVertex2f(x1, y1);
	}
	glEnd();

	glColor3f(0.000, 0.000, 0.502);
	float x2, y2;
	glBegin(GL_LINE_LOOP);		//окружность
	for (int i = 0; i < 360; i++)
	{
		float theta = 2.0f * 3.1415926f * float(i) / float(360);
		y2 = R * cos(theta) + y;
		x2 = R * sin(theta) + x;
		glVertex2f(x2, y2);
	}
	glEnd();
}

void drawText(int nom, int x1, int y1)		//рисуем вес ребра между 2 вершинами
{
	GLvoid* font = GLUT_BITMAP_HELVETICA_18;	//шрифт
	string s = to_string(nom);					//текст
	glRasterPos2i(x1 - 10, y1 - 10);				//установка позиции
	for (size_t j = 0; j < s.length(); j++)
		glutBitmapCharacter(font, s[j]);		//рисование посимвольно
}

void drawLine(int text, int x0, int y0, int x1, int y1) 
{
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);		//ребро неориентированного взвешенного графа 
	glVertex2i(x0, y0);
	glVertex2i(x1, y1);  
	glEnd();

	drawText(text, (x0 + x1) / 2 + 10, (y0 + y1) / 2 + 10);
}

void drawVertex(int n)		//рисование вершины
{
	for (int i = 0; i < n; i++)
	{
		if (onMouse[i])		//если курсор в зоне круга
			drawBorderedCircle(vC[i].x, vC[i].y, R);
		else
			drawCircle(vC[i].x, vC[i].y, R);
		drawText(i + 1, vC[i].x, vC[i].y);
	}

}

void drawPathVertex(int n)		//рисование пути
{
	if (newpath.empty())	//если задача коммивояжера не была решена
	{
		drawGraph();
		cout << "\nСначала решите задачу коммивояжера!!!\n";
		drawing = true;
		return;
	}

	glutSwapBuffers();
	glClearColor(0.35686, 0.69803, 0.47058, 0.8);
	glClear(GL_COLOR_BUFFER_BIT);

	for (int k = 0; k < graph.GetVertListSize(); k++)	//рисуем все вершины графа
	{
		int n1 = newpath[k]; n1--;
		drawBorderedCircle(vC[n1].x, vC[n1].y, R);
		drawText(newpath[k], vC[n1].x, vC[n1].y);
	}
	Sleep(1000);		//задержка чтобы рисовать последовательно
	glutSwapBuffers();

	for (int i = 0; i < graph.GetVertListSize(); i++)
	{
		for (int j = 0; j <= i; j++)		//из вектора пути последовательно берем вершины
		{
			int n1 = newpath[j]; n1--;
			int n2 = newpath[j + 1]; n2--;
			drawLine(graph.GetAdjMatrixElem(n1, n2), vC[n1].x, vC[n1].y, vC[n2].x, vC[n2].y);		//и риусем ребро между ними
		}
		for (int k = 0; k < graph.GetVertListSize(); k++)		//и снова рисуем все вершины
		{
			int n1 = newpath[k]; n1--;
			drawBorderedCircle(vC[n1].x, vC[n1].y, R);
			drawText(newpath[k], vC[n1].x, vC[n1].y);
		}
		Sleep(1000);			//задержка чтобы рисовать последовательно
		glutSwapBuffers();
	}

	//отрисовка последних 2 вершин (конца и начала) и линии между ними
	drawLine(graph.GetAdjMatrixElem(newpath[0] - 1, newpath[newpath.size() - 2] - 1), vC[newpath[0] - 1].x, vC[newpath[0] - 1].y, vC[newpath[newpath.size() - 2] - 1].x, vC[newpath[newpath.size() - 2] - 1].y);
	drawBorderedCircle(vC[newpath[0] - 1].x, vC[newpath[0] - 1].y, R);
	drawText(newpath[0], vC[newpath[0] - 1].x, vC[newpath[0] - 1].y);
	drawBorderedCircle(vC[newpath[newpath.size() - 2] - 1].x, vC[newpath[newpath.size() - 2] - 1].y, R);
	drawText(newpath[newpath.size() - 2], vC[newpath[newpath.size() - 2] - 1].x, vC[newpath[newpath.size() - 2] - 1].y);
	glutSwapBuffers();
	Sleep(2000);
	drawing = true;

}

void setCoords(int i, int n)	//установка координат вершины в завис. от размеров окна
{
	int R_;
	int x0 = WinW / 2;
	int y0 = WinH / 2;
	if (WinW > WinH)
	{
		R = 5 * (WinH / 13) / n;
		R_ = WinH / 2 - R - 10;
	}
	else
	{
		R = 5 * (WinW / 13) / n;
		R_ = WinW / 2 - R - 10;
	}
	float theta = 2.0f * 3.1415926f * i / n;
	int y1 = R_ * cos(theta) + y0;
	int x1 = R_ * sin(theta) + x0;
	vC[i].x = x1;
	vC[i].y = y1;
}

void drawGraph()		//рисование созданного графа
{
	int n = graph.GetVertListSize();
	for (int i = 0; i < n; i++)
	{
		if (!movable)			//если мы двигаем вершину, то координаты не устанавливаются, т.к. мы сами их устанавливаем
			setCoords(i, n);	//установка координат
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			int a = graph.GetAdjMatrixElem(i, j);
			if (a != 0)												//если есть путь
				drawLine(a, vC[i].x, vC[i].y, vC[j].x, vC[j].y);	//то рисусем ребро
		}
	}
	drawVertex(n);		//рисуем вершины
	glutPostRedisplay();
}

void setGraph()	//создание графа
{
	movable = false;			//создание графа с нуля

	int amountVerts, countEdges, sourceVertex, targetVertex, edgeWeight;
	cout << "Введите количество вершин графа: "; cin >> amountVerts;
	cout << "Введите количество ребер графа: "; cin >> countEdges;
	for (int i = 1; i <= amountVerts; i++) {

		graph.InsertVertex(i);
	}
	for (int i = 0; i < countEdges; i++)
	{
		cout << "Исходная вершина: "; cin >> sourceVertex;
		cout << "Конечная вершина: "; cin >> targetVertex;
		cout << "Вес ребра: "; cin >> edgeWeight;
		graph.InsertEdge(sourceVertex, targetVertex, edgeWeight);
	}
	cout << endl;
	graph.Print();
}

bool checkCommi(int** matrix)
{
	if (graph.IsEmpty())
		return false;
	for (int i = 0; i < graph.GetVertListSize(); i++)
	{
		int counter = 0;
		for (int j = 0; j < graph.GetVertListSize(); j++)		//если есть вершины, у которых только 1 путь
		{
			if (matrix[i][j] > 0)								//то такие задачи не решаем
				counter++;
		}
		if (counter <= 1)
			return false;
	}
	return true;
}

int checkCircle(int x, int y) //проверяем входит ли мышь в зону круга
{
	for (int i = 0; i < graph.GetVertListSize(); i++)
		if (pow(x - vC[i].x, 2) + pow(y - vC[i].y, 2) <= pow(R, 2))
			return i;	//возвращаем индекс вершины в векторе
	return -1;
}

void drawLineCut(int x, int y)	//отрисоква режущей линии
{
	glBegin(GL_LINES);
	glColor3f(1, 0, 0);
	glVertex2i(lineFirst.first, lineFirst.second);		//координаты начала
	glVertex2i(x, y);									//координаты конца
	glEnd();
}

// void drawLineMerge(int x, int y)	//отрисоква соединяющей линии (не работает и отключено за отсутсвием необходимости)
// {
// 	glBegin(GL_LINES);
// 	glColor3f(0, 0, 1);
// 	glVertex2i(mergeLineFirst.first, mergeLineFirst.second);		//координаты начала
// 	glVertex2i(x, y);									//координаты конца
// 	glEnd();
// }

void checkButton(int x, int y)		//проверка на вхождение курсора в область кнопки и возвращение номера кнопки
{
	if (x < (WinW / 6) && y > 5 * (WinH / 6))
		buttonsState = 1;
	else if (x < (WinW / 6) && y < 5 * (WinH / 6) && y > 4 * (WinH / 6))
		buttonsState = 2;
	else if (x < (WinW / 6) && y < 4 * (WinH / 6) && y > 3 * (WinH / 6))
		buttonsState = 3;
	else if (x > 5 * (WinW / 6) && y > 5 * (WinH / 6))
		buttonsState = 4;
	else if (x > 5 * (WinW / 6) && y < 5 * (WinH / 6) && y > 4 * (WinH / 6))
		buttonsState = 5;
	else if (x > 5 * (WinW / 6) && y < 4 * (WinH / 6) && y > 3 * (WinH / 6))
		buttonsState = 6;
	else
		buttonsState = 0;
}

void moveMouse(int x, int y) //функция отслеживания движения мыши
{
	y = WinH - y;
	curPosX = x;	//текущая позиция курсора
	curPosY = y;

	int i = checkCircle(x, y);	//проверка на вхождение курсора в вершину
	if (i != -1)
		onMouse[i] = true;	//если есть такая вершина, то элемент массива с индексом вершины - true
	else
		for (int j = 0; j < graph.GetVertListSize(); j++)
			onMouse[j] = false;
	if (moving)		//когда двигаем вершину, то ее кординаты = координаты курсора
	{
		vC[curNode].x = curPosX;
		vC[curNode].y = curPosY;
	}
	checkButton(x, y);	//проверка на вхождение в зоне кнопки
	glutPostRedisplay();
}

bool cross(int x11, int x12, int y11, int y12, int x21, int x22, int y21, int y22)
{
	//создание из координат 2 линий 2 уравнения
	double a1 = y12 - y11;
	double b1 = x11 - x12;
	double c1 = a1 * (x11)+b1 * (y11);

	double a2 = y22 - y21;
	double b2 = x21 - x22;
	double c2 = a2 * (x21)+b2 * (y21);

	double determinant = a1 * b2 - a2 * b1;

	//поиск точки пересечения
	double x;
	double y;
	if (determinant == 0)
		return false;
	else
	{
		x = (b2 * c1 - b1 * c2) / determinant;
		y = (a1 * c2 - a2 * c1) / determinant;
	}
	cout << x << ' ' << y << endl;
	
	//если точка пересечения входит в зону пересечения двух прямых, возвращаем true
	if ((x11 <= x && x12 >= x) or (x11 >= x && x12 <= x))
	{
		if (x21 >= x && x22 <= x)
		{
			if (y21 >= y && y22 <= y)
			{
				return true;
			}
			else if (y21 <= y && y22 >= y)
			{
				return true;
			}
		}
		else if (x21 <= x && x22 >= x)
		{
			if (y21 >= y && y22 <= y)
			{
				return true;
			}
			else if (y21 <= y && y22 >= y)
			{
				return true;
			}
		}
	}
	//иначе false
	return false;

}

void deleteEdgeByCut()
{
	int n = graph.GetVertListSize();

	for (int i = 0; i < n; i++)			//проход по 2 диагональной части матрицы
	{
		for (int j = i + 1; j < n; j++)
		{
			bool cut = false;;
			int elem = graph.GetAdjMatrixElem(i, j);
			if (elem != 0)	//если есть ребро, то проверяем его на пересечение с обрезающей линией
				cut = cross(lineFirst.first, lineSecond.first, lineFirst.second, lineSecond.second, vC[i].x, vC[j].x, vC[i].y, vC[j].y);
			if (cut)	//если пересечение есть, то зануляем ребро (удаляем)
			{
				graph.SetEdgeZero(i, j);
				/*return;*/   //return - если нужно удалить только 1 ребро, если убрать - все пересеченные режущей линией 
			}
		}
	}
}

void drawSomeInfo()
{
	int radius = 0;
	if (graph.GetVertListSize() != 0)	//если есть граф - то берем его радиус
		radius = R;
	int space = 24;						//пробел между строками
	string rad = "Radius: " + to_string(radius);	//радиус
	string verts = "Verts: " + to_string(graph.GetVertListSize());	//вершины
	string edges = "Edges: " + to_string(graph.GetcountEdges());	//ребра

	if (R == maxRad || R == minRad)
		glColor3f(1.0f, 0.0f, 0.0f);
	else
		glColor3f(0.0f, 0.0f, 0.0f);

	glRasterPos2i(5 * (WinW / 6), WinH - 3 * (WinH / 6) - space);
	for (int i = 0; i < rad.length(); i++)
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, rad[i]);

	if (graph.GetVertListSize() == 20)
		glColor3f(1.0f, 0.0f, 0.0f);
	else
		glColor3f(0.0f, 0.0f, 0.0f);
	glRasterPos2i(5 * (WinW / 6), WinH - 3 * (WinH / 6) - space*2);
	for (int i = 0; i < verts.length(); i++)
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, verts[i]);

	glRasterPos2i(5 * (WinW / 6), WinH - 3 * (WinH / 6) - space * 3);
	for (int i = 0; i < edges.length(); i++)
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, edges[i]);
}

void clickMouse(int button, int state, int x, int y) //отслеживание нажатий
{
	int i = checkCircle(x, WinH - y);	//проверяем вхождение курсора в область вершины

	if (moving)		//если вершина в режиме перемещания, то при нажатии режим ВЫКЛ
	{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			cout << "Режим перемещения ВЫКЛ" << endl;
			moving = false;
			return;
		}
	}

	if (i != -1)		//если курсор в зоне круга
	{
		movable = true;		//то граф не перерисовывается
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			//и при нажатии ВКЛ режим перемещания для данной вершины
			cout << "Режим перемещения ВКЛ" << endl;
			moving = true;
			curNode = i;		//индекс данной вершины
			return;
		}
		if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
		{
			if (!merging)
			{
				cout << "Режим соединения ВКЛ" << endl;
				merging = true;
				fNode = i+1;
				return;
			}
			else
			{
				merging = false;
				sNode = i+1;
				int weight; cout << "Вес: "; cin >> weight;
				graph.InsertEdge(fNode, sNode, weight);
				return;
			}
		}
		
	}

	

	if (button == 3 || button == 4)		//изменение радиуса вершины колесиком мыши
	{
		movable = true;		//граф не перерисовывается
		if (button == 3 && R < maxRad)	//если крутим вверх - радиус увеличивается
			R++;
		else if (button == 4 && R > minRad)	//если вниз - уменьшается
			R--;							//есть ограничения на размер радиуса
	}

	if (x <= (WinW / 6) and y <= (WinH / 6)) //1 кнопка - печать графа
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			graph.Print();
			return;
		}

	if (x <= (WinW / 6) and y <= 2 * (WinH / 6) and y > (WinH / 6)) //2 кнопка - решение задачи коммивояжера
	{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			newpath.clear();
			path.clear();
			cout << "\n\n\nРешение задачи коммивояжера: \n\n\n";
			int** matrix = makeTSPMatrix();		//создание новой матрицы
			bool checker = checkCommi(matrix);	//проверка на возможность решения
			if (!checker)
			{
				cout << "Данный граф не поддерживает задачу комивояжера";
				return;
			}

			int n = graph.GetVertListSize();
			while (path.size() < n)				//пока не найдем все отрезки пути
				matrix = rebuildMatrix(matrix);	//преобразуем матрицы
			cout << endl;						//в итоге получится матрица, заполненная -1
			resultPrint();
			return;
		}
	}
	if (x <= (WinW / 6) and y > 5 * (WinH / 6))			//кнопка показа шагов
	{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			if (printSteps)
			{
				printSteps = false;
				cout << "\nПоказ шагов ВЫКЛ\n";
			}

			else
			{
				printSteps = true;
				cout << "\nПоказ шагов ВКЛ\n";
			}
			return;
		}
	}
	if (x <= (WinW / 6) and y <= 3 * (WinH / 6) and y > 2 * (WinH / 6))		//3 кнопка - создание графа
	{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			newpath.clear();
			path.clear();
			Graph newgraph;
			graph = newgraph;
			setGraph();
			return;
		}
	}
	if (x >= (5 * (WinW / 6)) and y >= 5 * (WinH / 6))	//кнопка отрисовки пути
	{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			if (drawing)
				drawing = false;
			else
				drawing = true;
			return;
		}
	}
	if (x >= 5 * (WinW / 6) and y <= (WinH / 6))		//4 кнопка - перестроить граф заново
	{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			movable = false;
			return;
		}
	}

	if (x >= 5 * (WinW / 6) and y <= 2 * (WinH / 6) and y > (WinH / 6))	//5 кнопка - добавление и удаление вершины
	{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			int cur = graph.GetVertListSize();
			graph.InsertVertex(cur + 1);
			vC[cur].x = WinW / 2;
			vC[cur].y = WinH / 2;
			cout << "\nДобавлена вершина " << cur + 1 << endl;
			return;
		}
		if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
		{
			graph.eraseLastVert();
			int cur = graph.GetVertListSize();
			cout << "\nУдалена вершина " << cur+1 << endl;
			return;
		}
	}
	if (x >= 5 * (WinW / 6) and y <= 3 * (WinH / 6) and y > 2 * (WinH / 6))	//6 кнопка - добавление и удаление вершины
	{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			int sourceVertex, targetVertex, edgeWeight, vertNum;
			cout << "Кол-во новых ребер: "; cin >> vertNum;
			for (int i = 0; i < vertNum; i++)
			{
				cout << "Исходная вершина: "; cin >> sourceVertex; 
				cout << "Конечная вершина: "; cin >> targetVertex; 
				cout << "Вес ребра: "; cin >> edgeWeight; 
				graph.InsertEdge(sourceVertex, targetVertex, edgeWeight);
			}
			return;
		}
		if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
		{
			int sourceVertex, targetVertex;
			cout << "Исходная вершина: "; cin >> sourceVertex; 
			cout << "Конечная вершина: "; cin >> targetVertex; 
			graph.eraseEdge(sourceVertex, targetVertex);
			return;
		}
	}
	if (cutting)		//если ВКЛ режим резки ребер
	{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			cutting = false;				//то при нажатии он ВЫКЛ
			lineSecond.first = curPosX;		//рисуется полная линия
			lineSecond.second = curPosY;
			cout << "Режим обрезки ВЫКЛ\n";
			deleteEdgeByCut();				//и удаляются все (или 1
		}
	}
	else			//если режим ВЫКЛ, то начинаем рисовать линию
	{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
			cutting = true;
			lineFirst.first = curPosX;
			lineFirst.second = curPosY;
			cout << "Режим обрезки ВКЛ\n";
		}
	}
	

	
}

void reshape(int w, int h)	//решейп и установка новых размеров окна
{
	WinW = w;
	WinH = h;

	if (WinW >= WinH)		//задание макс. радиуса
		maxRad = WinH / 2;
	else
		maxRad = WinW / 2;

	glViewport(0, 0, (GLsizei)WinW, (GLsizei)WinH);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, (GLdouble)WinW, 0, (GLdouble)WinH);
	glutPostRedisplay();
}

void display()
{
	glMatrixMode(GL_PROJECTION);	//установка новой сис. координат
	glLoadIdentity();
	gluOrtho2D(0, WinW, 0, WinH);
	glViewport(0, 0, WinW, WinH);
	glClearColor(0.53725, 0.82745, 0.63529, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	if (drawing)		//если не рисуется путь
	{
		drawButton1();
		drawButton2();
		drawButton3();
		drawButton4();
		drawButton5();
		drawButton6();
		drawGraph();
		drawSomeInfo();
		drawButSteps();
		if (cutting)	//если режим резки - рисуем линию
			drawLineCut(curPosX, curPosY);
	}
	else    //если рисуется путь
		drawPathVertex(graph.GetVertListSize());

	drawButPath();

	Sleep(35);	//для меньшего потребления ресурсов

	glutSwapBuffers();
}