#include<iostream>
#pragma warning (disable:4996)
using namespace std;

struct Point{
	int row, col;
};

int N, M;
int A[100][100];// mang goc
int QuanDich[100][100];// mang chi so quan dich
Point ToaDo[15]; // luu toa do cua quan ma va cac quan dich
int Matrix[15][15];
int VisitBFS[100][100];
int VisitBacktrack[100];
int Answer;
int dRow[8] = {1,1,2,2,-1,-1,-2,-2};
int dCol[8] = {2,-2,1,-1,2,-2,1,-1};
int cntQuanDich;

Point Q[10000];
int front, rear;

void initQ(){
	front = 0;
	rear = 0;
}
void pushQ(Point point){
	Q[rear] = point;
	rear++;
}
bool isEmpty(){
	return front>=rear;
}
Point popQ(){
	Point point = Q[front];
	front++;
	return point;
}

void BFS(int start){
	initQ();
	for (int i=0;i<N;i++){
		for (int j=0;j<M;j++){
			VisitBFS[i][j] = -1;
		}
	}
	pushQ(ToaDo[start]);
	VisitBFS[ToaDo[start].row][ToaDo[start].col] = 0;
	while (!isEmpty()){
		Point current = popQ();
		for (int i=0;i<8;i++){
			int row = current.row+dRow[i];
			int col = current.col+dCol[i];
			if (row>=0 && row<N && col>=0 && col<M 
				&& VisitBFS[row][col] == -1){
					VisitBFS[row][col] = VisitBFS[current.row][current.col]+1;
					Point p;
					p.row = row;
					p.col = col;
					pushQ(p);
					if (A[row][col] == 1) {
						int end = QuanDich[row][col];
						Matrix[start][end] = VisitBFS[row][col];
						Matrix[end][start] = VisitBFS[row][col];
					}
			}
		}
	}
}

void solve(int pos,int pre, int step){
	if (pos>=cntQuanDich){
		if (step < Answer){
			Answer = step;
		}
		return;
	}
	if (step>=Answer) return;
	for (int i=1;i<cntQuanDich;i++){
		if (VisitBacktrack[i] == 0){
			VisitBacktrack[i] = 1;
			solve(pos+1, i, step+Matrix[i][pre]);
			VisitBacktrack[i] = 0;
		}
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	freopen("input.txt", "r", stdin);
	cin >> T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		Answer = 0;
		cin>>N>>M;
		cntQuanDich = 1;
		for (int i=0;i<N;i++){
			for (int j=0;j<M;j++){
				cin>>A[i][j];
				if (A[i][j] == 3){
					ToaDo[0].row = i;
					ToaDo[0].col = j;
				}
				QuanDich[i][j] = -1;
				if (A[i][j] == 1){
					ToaDo[cntQuanDich].row = i;
					ToaDo[cntQuanDich].col = j;
					QuanDich[i][j] = cntQuanDich;
					cntQuanDich++;
				}
			}
		}
		for (int i=0;i<15;i++)
			for (int j=0;j<15;j++)
				Matrix[i][j] = 0;
		Answer = 99999999;
		for (int i=0;i<cntQuanDich;i++){
			BFS(i);
		}
		solve(1, 0, 0);
		cout << "Case #" << test_case <<endl<< Answer << endl;
	}
	return 0;//Your program should return 0 on normal termination.
}
