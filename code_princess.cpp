#include <iostream>
#pragma warning (disable:4996)
using namespace std;
int N, map[205][205], checkC[205][205], checkD[205][205];
int dem[205][205];
int Dx, Dy;

int C, D;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

struct Queue {
	int arr[100000];
	int rear, front;
	Queue(){
		rear = 0;
		front = 0;
	}
	void init_(){
		rear = 0;
		front = 0;
	}

	void push(int a){
		arr[front] = a;
		front++;
	}
	
	int pop(){
		int r = arr[rear];
		rear++;
		return r;
	}	
	bool isEmpty(){
		return rear == front;
	}

};

void TimP(int i, int j){
	Queue queue = Queue();
	if(map[i][j] == 2){
		return;
	}
	queue.push(i);
	queue.push(j);
	
	while(!queue.isEmpty()){
		int x = queue.pop();
		int y = queue.pop();
		for(int k = 0; k < 4; k++){
			int hang = x + dx[k];
			int cot = y + dy[k];
			if(hang >= 1 && hang <= N && cot >= 1 && cot <= N && checkC[hang][cot] == 0 && map[hang][cot] != 0){
				if(map[hang][cot] == 2){
					checkC[hang][cot] = checkC[x][y] + 1;
					C = checkC[x][y] + 1;
					return;
				}
				checkC[hang][cot] = checkC[x][y] + 1; 
				queue.push(hang);
				queue.push(cot);
			}
		}
	}
}

void TimD(int i, int j){
	Queue queue = Queue();
	if(i == N && j == N){
		return;
	}
	queue.push(i);
	queue.push(j);
	
	while(!queue.isEmpty()){
		int x = queue.pop();
		int y = queue.pop();
		for(int k = 0; k < 4; k++){
			int hang = x + dx[k];
			int cot = y + dy[k];
			if(hang >= 1 && hang <= N && cot >= 1 && cot <= N && checkD[hang][cot] == 0 && map[hang][cot] != 0){
				if(hang == N && cot == N){
					checkD[hang][cot] = checkD[x][y] + 1;
					D = checkD[x][y] + 1;
					return;
				}
				checkD[hang][cot] = checkD[x][y] + 1; 
				queue.push(hang);
				queue.push(cot);
			}
		}
	}
}


int main()
{
//	freopen("Text.txt", "r", stdin);
	int T; cin >> T;
	for(int tc = 1; tc <= T; tc++){
		cin >> N;
		for(int i = 1; i <= N; i++){
			for(int j = 1; j <= N; j++){
				dem[i][j] = 0;
				checkC[i][j] = 0;
				checkD[i][j] = 0;
				cin >> map[i][j];
				if(map[i][j] == 2){
					Dx = i;
					Dy = j;
				}

			}
		}
		D = 0;
		C = 0;
		checkC[1][1] = 1;
		TimP(1,1);
		checkD[Dx][Dy] = 1;
		TimD(Dx,Dy);
		if(C*D > 0){
			cout << C + D - 2 << endl;
		}else {
			cout << -1 << endl;
		}
	}
	return 0;
}
