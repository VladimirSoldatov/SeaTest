#include <iostream>
#include<set>
#include<algorithm>

using namespace std;

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
	{1,-1}
};
struct Ship
{
	char empty = static_cast<char>(250);
	char filled = static_cast<char>(245);
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
	bool try_create(int _size)
	{
		size = _size;
		int x = random_func();
		int y = random_func();
		maky_copy(desk_copy, desk);
		for (int i = 0; i < size; i++)
		{
			if (desk[x][y + i] == empty || y + size < 10)
			{
				for (int k = 0; k < 8; k++)
				{
					if (desk[x + cube[k][1]][y + cube[k][0]] == filled)
						return false;
				}

				desk_copy[x][y + i] = filled;
			}
			else
				return false;
		}
		return true;
	}
	void create(int _size) 
	{
		while (!try_create(_size));
		maky_copy(desk, desk_copy);
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
				desk[i][j] = static_cast<char>(250);
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
	cout << "\n" << player1.count_of_ships << "\n";
}
