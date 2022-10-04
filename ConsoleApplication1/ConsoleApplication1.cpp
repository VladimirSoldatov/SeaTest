#include <iostream>
#include<set>
#include<algorithm>

using namespace std;

char desk[10][10];
struct Ship
{
	char empty = ' ';
	char filled = '*';
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
	bool try_create(int _size)
	{
		size = _size;
		int x = random_func();
		int y = random_func();
		for (int i = 0; i < size; i++)
		{
			if (desk[x][y + i] = empty)
				desk[x][y + i] = filled;
			else
				return false;
		}
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


	Game()
	{
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 10; j++)
				desk[i][j] = '0';
	}
	void create_ship(int _type)
	{
		for (int i = _type; i>0; i--)
		new Ship(_type);
	}
	void print() 
	{
		for (int i = 0; i < 10; i++) 
		{
			for (int j = 0; j < 10; j++)
			{
				cout << desk[i][j] << "   ";
			}
			cout << "\n\n";
		}
	
	}
};

int main()
{
	srand((int)time(NULL));
	Game player1;
	for (int i = 4; i>0;i--)
	player1.create_ship(i);
	player1.print();
}
