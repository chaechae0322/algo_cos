#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <queue>
#include <algorithm>
#include <stack>

using namespace std;

typedef struct info
{
	int score = 0;
	int num = 0;

	info* right = NULL;
	info* left = NULL;
} info;

info* head;
info* tail;
info* b[5];
info* h[4];

int R[10];
int max_score = 0;

void init()
{
	head = new info();
	tail = new info();

	head->score = 0;
	tail->score = 0;

	head->right = tail;
	tail->right = head;

	head->left = tail;
	tail->left = head;

	head->num = 0;
	tail->num = 32;

	for (int i = 0; i < 5; i++)
	{
		b[i] = new info();
		if (i < 4) h[i] = head;
	}
	b[3]->score = 25;
	b[3]->num = 24;
}

void insert_right(info* start, info* add)
{
	info* p = start->right;

	start->right = add;
	add->right = p;
}

void insert_left(info* start, info* add)
{
	info* p = start->left;

	start->left = add;
	add->right = p;
}

void insert()
{
	for (int i = 20; i > 0; i--)
	{
		info* s = new info();
		s->score = i * 2;
		s->num = i;

		insert_right(head, s);

		if (i == 5) b[0] = s;
		else if (i == 10) b[1] = s;
		else if (i == 15) b[2] = s;
		else if (i == 20) b[4] = s;
	}

	for (int i = 0; i < 3; i++)
	{
		b[i]->left = b[3];
	}

	for (int i = 1; i <= 3; i++)
	{
		info* s = new info();
		s->score = 22 - 3*i;
		s->num = 24 - i;
		insert_left(b[0], s);
	}

	for (int i = 0; i < 2; i++)
	{
		info* s = new info();
		s->score = 24 - 2 * i;
		s->num = 26 - i;
		insert_left(b[1], s);
	}

	for (int i = 0; i < 3; i++)
	{
		info* s = new info();
		s->score = 26 + i;
		s->num = 29 - i;
		insert_left(b[2], s);
	}

	b[3]->right = b[4];

	for (int i = 0; i < 2; i++)
	{
		info* s = new info();
		s->score = 35 - 5 * i;
		s->num = 31 - i;
		insert_right(b[3], s);
	}
}

void game(int pr_h_score, info* pr_h[4], int n, int pr_visited[35])
{
	if (n == 10)
	{
		if (max_score < pr_h_score)	max_score = pr_h_score;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		info* nx_h[4];
		int nx_visited[35];

		memcpy(nx_h, pr_h, sizeof(pr_h[i]) * 4);
		memcpy(nx_visited, pr_visited, sizeof(int) * 35);

		if (nx_h[i] == tail) continue;

		int pr_position = nx_h[i]->num;
		int move = R[n];

		if (pr_position == b[0]->num || pr_position == b[1]->num || pr_position == b[2]->num)
		{
			nx_h[i] = nx_h[i]->left;
			move--;
		}

		for (int j = 0; j < move; j++)
		{
			if (nx_h[i] == tail) break;
			nx_h[i] = nx_h[i]->right;
		}

		int nx_position = nx_h[i]->num;

		if (nx_visited[nx_position] == 1 && nx_h[i] != tail) continue;

		nx_visited[nx_position] = 1; nx_visited[pr_position] = 0;

		game(pr_h_score + nx_h[i]->score, nx_h, n + 1, nx_visited);
	}
}

void delete_all()
{
	info* p;
	info* q;

	for (int i = 0; i < 3; i++)
	{
		p = b[0]->left;
		q = p->right;
		b[0]->left = q;
		delete[] p;
	}

	for (int i = 0; i < 3; i++)
	{
		p = b[2]->left;
		q = p->right;
		b[2]->left = q;
		delete[] p;
	}

	for (int i = 0; i < 2; i++)
	{
		p = b[1]->left;
		q = p->right;
		b[1]->left = q;
		delete[] p;
	}

	for (int i = 0; i < 2; i++)
	{
		p = b[3]->right;
		q = p->right;
		b[3]->right = q;
		delete[] p;
	}

	delete[] b[3];

	for (int i = 0; i < 20; i++)
	{
		p = head->right;
		q = p->right;
		head->right = q;
		delete[] p;
	}

	delete[] head;
	delete[] tail;
}

int main()
{
	for (int i = 0; i < 10; i++)
	{
		cin >> R[i];
	}

	init();
	insert();

	int h_score[4];
	memset(h_score, 0, sizeof(h_score));

	int visited[35];
	memset(visited, 0, sizeof(visited));

	game(0, h, 0, visited);

	cout << max_score;

	delete_all();
	return 0;
}