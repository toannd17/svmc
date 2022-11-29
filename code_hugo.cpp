#include <iostream>
#pragma warning (disable:4996)
using namespace std;
int map[20][20];
int map_lua[20][20];
int map_ho[20][20];
int M, N, SR, SC;
int map_jew[20][20];
int visitLua[20][20];
int visitBackTrack[20][20];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int answer;
struct Queue{
	int q[10000];
	int front, rear;
	void initQ(){
		front = 0; 
		rear = 0;
	}

	bool isEmpty(){
		return front == rear;
	}

	void push(int a){
		q[rear] = a;
		rear++;
	}

	int pop(){
		int a = q[front];
		front++;
		return a;
	}
};

void Lua(int x, int y){
	Queue queue;
	queue.initQ();
	queue.push(x);
	queue.push(y);
	visitLua[x][y] = 1;
	while(!queue.isEmpty()){
		int hang = queue.pop();
		int cot = queue.pop();
		for(int i = 0; i < 4; i++){
			int h = hang + dx[i];
			int c = cot + dy[i];
			if(h >= 1 && h <= M && c >= 1 && c <= N){
				if(visitLua[h][c] > (visitLua[hang][cot] + 1) && map_ho[h][c] != 2){
					queue.push(h);
					queue.push(c);
					visitLua[h][c] = visitLua[hang][cot] + 1;
				}
			}
		}
	}
}

bool check(int hang, int cot,int dem){
	if(dem < visitLua[hang][cot]) return true;
	return false;
}

void backTrack(int x, int y, int dem, int thuong){
	if(!check(x, y, dem)){
		return;
	}
	if(map[x][y] == 4){
		if(answer < thuong){
			answer = thuong;
		}
	}

	for(int i = 0; i < 4; i++){
		int h = x + dx[i];
		int c = y + dy[i];
		if(h > 0 && h <= M && c > 0 && c <= N && visitBackTrack[h][c] == 0){
			if(map_ho[h][c] == 2){
				if(check(x, y, dem)){
					visitBackTrack[h][c] = 1;
					backTrack(h, c, dem + 2, thuong + map_jew[h][c]);
					visitBackTrack[h][c] = 0;
				}
			}else {
				visitBackTrack[h][c] = 1;
				backTrack(h, c, dem + 1, thuong + map_jew[h][c]);
				visitBackTrack[h][c] = 0;
			}
		}
	}
}


int main(){
	freopen("Text.txt", "r", stdin);
	int T; cin >> T;
	for(int tc = 1; tc <= T; tc++){
		cin >> M >> N >> SR >> SC;
		int nDamChay; cin >> nDamChay;
		// Reset map lua
		for(int i = 1; i <= M; i++){
			for(int j = 1; j <= N; j++){
				map_lua[i][j] = 0;
				map[i][j] = 0;
				map_jew[i][j] = 0;
				visitLua[i][j] = 999;
				map_ho[i][j] = 0;
				visitBackTrack[i][j] = 0;
			}
		}
		for(int i = 0; i < nDamChay; i++){
			int x, y; cin >> x >> y;
			map_lua[x][y] = 1;
		}
		int nHo; cin >> nHo;
		for(int i = 0; i < nHo; i++){
			int x, y; cin >> x >> y;
			map_ho[x][y] = 2;
		}
		int nLThoat; cin >> nLThoat;
		for(int i = 0; i < nLThoat; i++){
			int x, y; cin >> x >> y;
			map[x][y] = 4;
		}
		map[SR][SC] = 3;
		visitBackTrack[SR][SC] = 1;
		for(int i = 1; i <= M; i++){
			for(int j = 1; j <= N; j++){
				cin >> map_jew[i][j];
				if(map_lua[i][j] == 1){
					Lua(i, j);
				}
			}
		}
		answer = -1;
		backTrack(SR, SC, 1, map_jew[SR][SC]);
		cout << "Case #" << tc << endl << answer << endl;
	}
	return 0;
}
