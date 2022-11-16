#include <iostream>
using namespace std;
int A[1005][1005];
int B[1005][1005];
int queue[10000001];
int N,M;
int H[8] = {-1,-2,-2,-1,1,2,2,1};
int C[8] = {-2,-1,1,2,2,1,-1,-2};
struct Queue
{
	int rear, front;
	Queue()
	{
		rear = front = 1;
	}
	void push(int a)
	{
		queue[rear] = a;
		rear++;
	}
	bool isEmpty()
	{
		if(rear == front) return true;
		else return false;
	}
	int pop()
	{
		int a = queue[front];
		front++;
		return a;
	}
	int peek()
	{
		return queue[front];
	}
};
void BFS(int hang, int cot)
{
	int h, c;
	Queue Q = Queue();
	Q.push(hang);
	Q.push(cot);
	A[hang][cot] = 1;
	B[hang][cot] = 0;
	while(!Q.isEmpty())
	{
		h = Q.pop();
		c = Q.pop();
		for(int i = 0;i<8;i++)
		{
			if(h + H[i] >= 1 && h + H[i] <= N && c + C[i] >=1 && c + C[i] <= M && A[h + H[i]][c + C[i]] !=1)
			{
				B[h + H[i]][c + C[i]] = B[h][c] +1;
				if(A[h + H[i]][c + C[i]] == 2) return;
				Q.push(h+H[i]);
				Q.push(c+C[i]);
				A[h+H[i]][c + C[i]] = 1;
			}
		}
	}
}
int main()
{
	//freopen("input.txt","r", stdin);
	int T;
	cin >> T;
	for(int tc = 1; tc<=T;tc++)
	{
		cin >> N >> M;
		for(int i = 1; i<= N; i++)
		{
			for(int j = 1; j<=M;j++)
			{
				A[i][j] = 0;
				B[i][j] = 0;
			}
		}
		int x,y,x1,y1;
		cin >> x >> y >> x1 >> y1;
		A[x1][y1] = 2;
		BFS(x,y);
		cout << "Case #" << tc << endl <<  B[x1][y1] << endl;
		for(int i = 1; i<= N; i++)
		{
			for(int j = 1; j<=M;j++)
			{
				A[i][j] = 0;
				B[i][j] = 0;
			}
		}
	}
	return 0;
}
