#include<iostream>
using namespace std;
#define cons 25
int n,so_movang;
int gold_x[cons];
int gold_y[cons];
int arr_map[cons][cons];
int index_gold[cons][cons];
int maxmax,minmin;
bool kiem_tra[cons];
bool kiemtra_temp[cons];
int min_index;
int dem_gold;

int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};

struct Queue
{
	int rear,front;
	int arr_data[100000];
	Queue()
	{
		rear = front = 0;
	}
	bool isEmpty()
	{
		return rear == front;
	}
	void push(int a)
	{
		arr_data[rear] = a;
		rear++;
		rear = rear % 100000;
	}
	int pop()
	{
		int a = arr_data[front];
		front++;
		front = front % 100000;
		return a;
	}
};


void BFS(int vt_hang,int vt_cot)
{
	for (int i = 0; i < so_movang; i++)
	{
		kiemtra_temp[i] = false;
	}
	maxmax = 0;
	dem_gold = 0;
	int check_BFS[cons][cons];
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			check_BFS[i][j] = -1;
		}
	}
	Queue Q = Queue();
	Q.push(vt_hang);
	Q.push(vt_cot);
	check_BFS[vt_hang][vt_cot] = 0;
	while (!Q.isEmpty())
	{
		int x = Q.pop();
		int y = Q.pop();
		for (int i = 0; i < 4; i++)
		{
			int hang = x + dx[i];
			int cot = y + dy[i];
			if(hang>=1 && hang<=n && cot>= 1 && cot<=n && arr_map[hang][cot] !=0 && check_BFS[hang][cot] == -1)
			{
				check_BFS[hang][cot] = check_BFS[x][y] + 1;
				Q.push(hang);
				Q.push(cot);
				if(arr_map[hang][cot] == 9)
				{
					dem_gold++;
					kiemtra_temp[index_gold[hang][cot]] = true;
					if(check_BFS[hang][cot] > maxmax )
					{
						maxmax = check_BFS[hang][cot];	

					}
				}
			}
		}
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
	int th;cin>>th;
	for (int tc = 1; tc <= th; tc++)
	{
		cin >> n >> so_movang;
		for (int i = 0; i < so_movang; i++)
		{
			cin >> gold_x[i] >> gold_y[i];
			index_gold[gold_x[i]][gold_y[i]] = i;
			kiem_tra[i] = false;

		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				cin >> arr_map[i][j];
			}
		}
		for (int i = 0; i < so_movang; i++)
		{
			arr_map[gold_x[i]][gold_y[i]] = 9;
		}

		maxmax =0;
		minmin = 999999;
		int sl = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if(arr_map[i][j] == 1)
				{
					BFS(i,j);
					if(dem_gold > sl)
					{
						sl = dem_gold;
						minmin = maxmax;
						for (int k = 0; k < so_movang; k++)
						{
							kiem_tra[k] = kiemtra_temp[k]; 
						}
					}
					else if(dem_gold == sl)
					{
						if(maxmax != 0)
						{
							if(minmin > maxmax)
							{
								minmin = maxmax;
								for (int k = 0; k < so_movang; k++)
								{
									kiem_tra[k] = kiemtra_temp[k]; 
								}
							}
						}
					}
				}
			}
		}
		cout << "Case #" << tc << endl;
		if(minmin == 999999)
		{
			cout << -1 << endl;
		}
		else
		{
			cout << minmin << endl;
			for (int i = 0; i < so_movang; i++)
			{
				if(kiem_tra[i] == false)
				{
					cout << gold_x[i] << " " << gold_y[i] << endl; 
				}
			}
		}
	}

	return 0;
}
