﻿#include <iostream>
#include<set>
#include<algorithm>
#include <Windows.h>
using namespace std;

void Set_Font_Special(const wchar_t* text, int size)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_FONT_INFOEX fontInfo;

	// эта строка нужна
	fontInfo.cbSize = sizeof(fontInfo);

	GetCurrentConsoleFontEx(hConsole, TRUE, &fontInfo);

	// это неправильное использование функции
	//wcsncpy(L"Lucida Console", fontInfo.FaceName, LF_FACESIZE);

	wcscpy_s(fontInfo.FaceName, text);

	fontInfo.dwFontSize.Y = size;
	fontInfo.dwFontSize.X = size;
	SetCurrentConsoleFontEx(hConsole, TRUE, &fontInfo);
}
void SetColor(int text, int bg) {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | text));
}
char desk[10][10];
char desk_copy[10][10];
int cube[8][2]
{
	{-1,0},
	{-1,-1},
	{0,-1},
	{1,-1},
	{1,0},
	{1,1},
	{0,1},
	{-1,1},
};
struct Ship
{
	char empty = static_cast<char>(178);
	char filled = static_cast<char>(176);
	char damaged = 'X';
	char exists = '+';
	int size;
	enum {one = 1, two, three, four};
	int type;
	int damage;
	bool status;
	int orientation;
	Ship(int _type)
	{
		type = _type;
		create(type);

	}
	void maky_copy(char dest[][10], char source[][10]) 
	{
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 10; j++)
				dest[i][j] = source[i][j];
	}
	void clear_desk(char dest[][10]) 
	{
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 10; j++)
				dest[i][j] = empty;
	}
	bool try_create(int _size)
	{
		size = _size;
		int x = random_func();
		int y = random_func();
		clear_desk(desk_copy);
		maky_copy(desk_copy, desk);
		bool status = true;
		for (int i = 0; i < size; i++)
		{
			if (desk[x][y + i] == filled || y + size > 10)
				return false;
				for (int k = 0; k < 8; k++)
				{
					if (desk[x + cube[k][0]][y + i + cube[k][1]] == filled) 
					{
						status = false;
						return false;
					}

				}

				if(status)
				desk_copy[x][y + i] = filled;
			
			
		}
		maky_copy(desk, desk_copy);
		return true;
	}
	void create(int _size) 
	{
		while (!try_create(_size));
		
	}
	int random_func()
	{
		int result;
		result = rand() % 10;

		return result;
	}
};

struct Game
{
	
	int count_of_ships = 0;

	Game()
	{
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 10; j++)
				desk[i][j] = static_cast<char>(178);
	}
	void create_ship(int _type)
	{
		for (int i = 5 - _type; i > 0; i--)
		{
			new Ship(_type);
			count_of_ships++;
		}
	}
	void print() 
	{
		char space;

		for (int i = 0; i < 10; i++) 
		{
			for (int j = 0; j < 10; j++)
			{
				if (desk[i][j] == static_cast<char>(176))
				{
					space = static_cast<char>(176);
					
					SetColor(13, 0);
				}
				else 
				{
					space = static_cast<char>(178);
				
					SetColor(15, 0);
				}

					cout << desk[i][j]<<space;

			
			}
			cout << "\n";
		}
	
	}
};

int main()
{
	Set_Font_Special(L"Lusida Console",20);
	srand((int)time(NULL));
	Game player1;
	for (int i = 4; i>0;i--)
	player1.create_ship(i);
	player1.print();
	SetColor(15, 0);
	cout << "\n" << player1.count_of_ships << "\n";
	for (int i = 176; i < 230; i++)
	{
		cout << static_cast<char>(i) << " ";
	}

}
