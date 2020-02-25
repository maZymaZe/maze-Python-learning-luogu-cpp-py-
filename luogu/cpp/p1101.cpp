#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
char s[110][110], ch[10] = "yizhong";
int u[110][110] = {0}, n;
void check(int x, int y)
{
	int f;
	f = 1;
	if (x - 6 >= 0)
	{ //north
		for (int i = 1; i <= 6; i++)
		{
			if (s[x - i][y] != ch[i])
			{
				f = 0;
				break;
			}
		}

		if (f == 1)
		{
			for (int i = 0; i <= 6; i++)
			{
				u[x - i][y] = 1;
			}
		}
	}
	////////////////////////////////////////
	f = 1;
	if (x + 6 < n)
	{ //south
		for (int i = 1; i <= 6; i++)
		{
			if (s[x + i][y] != ch[i])
			{
				f = 0;
				break;
			}
		}

		if (f == 1)
		{
			for (int i = 0; i <= 6; i++)
			{
				u[x + i][y] = 1;
			}
		}
	}
	/////////////////////////////////////////////
	f = 1;
	if (y - 6 >= 0)
	{ //west
		for (int i = 1; i <= 6; i++)
		{
			if (s[x][y - i] != ch[i])
			{
				f = 0;
				break;
			}
		}

		if (f == 1)
		{
			for (int i = 0; i <= 6; i++)
			{
				u[x][y - i] = 1;
			}
		}
	}
	//////////////////////////////////
	f = 1;
	if (y + 6 < n)
	{ //east
		for (int i = 1; i <= 6; i++)
		{
			if (s[x][y + i] != ch[i])
			{
				f = 0;
				break;
			}
		}

		if (f == 1)
		{
			for (int i = 0; i <= 6; i++)
			{
				u[x][y + i] = 1;
			}
		}
	}
	////////////////////////////////////////
	f = 1;
	if (y + 6 < n && x - 6 >= 0)
	{ //northeast
		for (int i = 1; i <= 6; i++)
		{
			if (s[x - i][y + i] != ch[i])
			{
				f = 0;
				break;
			}
		}

		if (f == 1)
		{
			for (int i = 0; i <= 6; i++)
			{
				u[x - i][y + i] = 1;
			}
		}
	}
	////////////////////////////////////////
	f = 1;
	if (y + 6 < n && x + 6 < n)
	{ //southeast
		for (int i = 1; i <= 6; i++)
		{
			if (s[x + i][y + i] != ch[i])
			{
				f = 0;
				break;
			}
		}

		if (f == 1)
		{
			for (int i = 0; i <= 6; i++)
			{
				u[x + i][y + i] = 1;
			}
		}
	}
	////////////////////////////////////////
	f = 1;
	if (y - 6 >= 0 && x - 6 >= 0)
	{ //northwest
		for (int i = 1; i <= 6; i++)
		{
			if (s[x - i][y - i] != ch[i])
			{
				f = 0;
				break;
			}
		}

		if (f == 1)
		{
			for (int i = 0; i <= 6; i++)
			{
				u[x - i][y - i] = 1;
			}
		}
	}
	//////////////////////////////////
	f = 1;
	if (y - 6 >= 0 && x + 6 < n)
	{ //southwest
		for (int i = 1; i <= 6; i++)
		{
			if (s[x + i][y - i] != ch[i])
			{
				f = 0;
				break;
			}
		}

		if (f == 1)
		{
			for (int i = 0; i <= 6; i++)
			{
				u[x + i][y - i] = 1;
			}
		}
	}
	//////////////////////////////////
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (s[i][j] == 'y')
				check(i, j);
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (u[i][j] == 1)
				printf("%c", s[i][j]);
			else
				printf("*");
		}
		printf("\n");
	}
	return 0;
}
