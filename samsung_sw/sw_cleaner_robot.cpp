#include <iostream>
#include <cmath>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;

typedef struct info
{
	int r;
	int c;
	int d;
}_INFO;

_INFO robot;
int map[51][51];

int dir_back(int pd)
{
	switch(pd)
	{
		case 0: return 1;
		case 1: return 0;
		case 2: return 3;
		case 3: return 2;
	}
}

int simulation()
{
	//3 2 1 0
	int dx[] = {-1, 0, 1, 0};
	int dy[] = {0, 1, 0, -1};
	int px = robot.c; int py = robot.r; int pd = robot.d;
	int det, i;
	int ret = 1;
	
	while(1)
	{
		det = 4 - pd;
		if(det == 4) det = 0;

		for(i = 0; i < 4; i++)
		{			
			int nd = 3 - det;
			int nx = px + dx[det];
			int ny = py + dy[det];
			
			if(map[ny][nx] == 0) 
			{
				ret++;
				px = nx; py = ny; pd = nd;
				map[ny][nx] = 2;
				break;
			}
			det++;
			if(det > 3) det = 0;
		}
		
		int back = dir_back(pd);
		if(i == 4)
		{
			px += dx[back]; py += dy[back];
			if(map[py][px] == 1) return ret;
		}
	}
}

int main()
{
	cin >> N >> M >> robot.r >> robot.c >> robot.d;
	
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
			cin >> map[i][j];
	
	map[robot.r][robot.c] = 2;
	int ret = simulation();
	cout << ret;
	
	return 0;
}