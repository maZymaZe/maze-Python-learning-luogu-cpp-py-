#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
using namespace std;
int mp[9][9], it, hh[9][10], ss[9][10], bb[3][3][10], err = 0, v[9][9], cc = 0;
struct qs
{
	int x, y;
} ls[81];
int cmp(const qs &a, const qs &b)
{
	return v[a.x][a.y] > v[b.x][b.y];
}
void op()
{
	int s = 0;
	for (int i = 0; i <= 8; i++)
	{
		for (int j = 0; j <= 8; j++)
		{
			s += v[i][j] * mp[i][j];
		}
	}
	printf("%d", s);
}
void dfs(int w)
{

	if (w == cc + 1)
	{
		err = 0;
		printf("\n");
		for (int i = 0; i <= 8; i++)
		{
			for (int j = 0; j <= 8; j++)
			{
				printf("%d ", mp[i][j]);
			}
			printf("\n");
		}
		//	op();
		exit(0);
	}
	else
	{
		for (int k = 9; k >= 1; k--)
		{
			if (hh[ls[w].x][k] == 0)
				if (ss[ls[w].y][k] == 0)
					if (bb[ls[w].x / 3][ls[w].y / 3][k] == 0)
					{
						mp[ls[w].x][ls[w].y] = k;
						hh[ls[w].x][k]++;
						ss[ls[w].y][k]++;
						bb[ls[w].x / 3][ls[w].y / 3][k]++;
						dfs(w + 1);
						mp[ls[w].x][ls[w].y] = 0;
						hh[ls[w].x][k]--;
						ss[ls[w].y][k]--;
						bb[ls[w].x / 3][ls[w].y / 3][k]--;
					}
		}
	}
}
int main()
{
	for (int i = 0; i <= 8; i++)
	{
		for (int j = 0; j <= 8; j++)
		{
			v[i][j] = 10 - max(abs(i - 4), abs(j - 4));
			scanf("%d", &it);
			if (it != 0)
			{
				mp[i][j] = it;
				if (hh[i][it] == 0)
					hh[i][it] = 1;
				else
					err = 1;
				if (ss[j][it] == 0)
					ss[j][it] = 1;
				else
					err = 1;
				if (bb[i / 3][j / 3][it] == 0)
					bb[i / 3][j / 3][it] = 1;
				else
					err = 1;
			}
			else
			{
				cc++;
				ls[cc].x = i;
				ls[cc].y = j;
			}
		}
	}

	if (err == 1)
	{
		printf("-1");
	}
	else
	{
		err = 1;
		sort(ls + 1, ls + cc + 1, cmp);
		dfs(1);
		if (err == 1)
			printf("-1");
	}
	return 0;
}
