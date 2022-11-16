#include<iostream>
using namespace std;
int M, N;
int map[10001][10001];
int visit[10001][10001];

struct Point{
	int row,col;
};
Point queue[1000000];
int front, rear;
void initQ(){
	front = rear = 0;
}
void push(Point p){
	queue[rear] = p;
	rear ++;
}
Point popQ(){
	Point p = queue[front];
	front++;
	return p;
}

bool isEmpty(){
	return front==rear;
}





int main()
{
	freopen("Text.txt", "r", stdin);
	int T; cin >> T;
	for(int tc = 0; tc <= T; tc++) {
		cin >> M >> N;
	}

	return 0;

}
