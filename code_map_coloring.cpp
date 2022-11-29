#include <iostream>
#pragma warning (disable:4996)
using namespace std;
int arr[1005];
int matrix[1005][1005];
int nSo, nBienGioi;
int visit[1005];

bool check(){
	for(int i = 1; i <= nSo; i++){
		for(int j = 1; j <= nSo; j++){
			if(matrix[i][j] == 1){
				if(arr[i] == arr[j]) return false;
			}
		}
	}
	return true;
}

struct Queue {
	int q[100000];
	int front, rear;
	Queue(){
		front = 0;
		rear = 0;
	}
	void init(){
		front = 0;
		rear = 0;
	}

	void push(int i){
		q[rear] = i;
		rear++;
	}

	int pop(){
		int a = q[front];
		front++;
		return a;
	}
	bool isEmpty(){
		return front == rear;
	}
};


void toMau(){
	Queue queue;
	queue.init();
	arr[1] = 0;
	int dem = 0;
	queue.push(1);
	while(!queue.isEmpty()){
		int tmp = queue.pop();
		for(int i = 1; i <= nSo; i++){
			if(matrix[tmp][i] == 1 && arr[i] == -1){
				if(arr[tmp] == 0){
					arr[i] = 1;
				}else
					arr[i] = 0;
				queue.push(i);
			}
		}
	}
}

int main(){
	freopen("Text.txt", "r", stdin);
	int T; cin >> T;
	for(int tc = 1; tc <= T; tc++){
		cin >> nSo >> nBienGioi;
		for(int i = 0; i <= nSo; i++){
			arr[i] = -1;
			visit[i] = -1;
			for(int j = 0; j <= nSo; j++){
				matrix[i][j] = 0;
			}
		}
		for(int i = 0; i < nBienGioi; i++){
			int x, y;
			cin >> x >> y;
			matrix[x][y] = 1;
			matrix[y][x] = 1;
		}

		cout << "#" << tc << " ";
		toMau();
		if(check()){
			for(int i = 1; i <= nSo; i++){
				cout << arr[i];
			}
			cout << endl;
		}
		else 
			cout << "-1" << endl;
	}
	return 0;
}
