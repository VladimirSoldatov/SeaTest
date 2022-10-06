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
	{-1,1},
};
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
