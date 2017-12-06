#include <iostream>
using namespace std;

bool gameOver;
const int widht = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
enum eDirection
{
	STOP,
	LEFT,
	RIGHT,
	UP,
	DOWN
};
eDirection dir;

void setup()
{
	bool gameOver = false;
	dir = STOP;
	x = widht / 2;
	y = height / 2;
	fruitX = rand() % widht;
	fruitY = rand() % height;
	score = 0;
}

void input()
{
	system("cls");
	for (int i = 0; i < widht; i++)
	{
		cout << "-";
	}
	cout << endl;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < widht; j++)
		{
			if (j == 0 || j == widht - 1)
				cout << "|";
			if (i == y && j == x)
				cout << 0;
			cout << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < widht; i++)
	{
		cout << "-";
	}
	cout << endl;
}

void draw()
{

}

void logic()
{

}
void main()
{
	setup();
	while (!gameOver)
	{
		draw();
		input();
		logic();
	}
}