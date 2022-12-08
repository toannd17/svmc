#include<iostream>
#include<stdio.h>
using namespace std;

int n, m, tg_den, deadline, deadline2;
double a[101][101];
double sx[101][1001];
bool check[101][1001];
int queue[10001];
int queuetg[10001];
int front, back;
int vt;
double mmax;

void init(){
	cin >> n >> m;
	cin >> tg_den >> deadline;
	deadline2 = (deadline-tg_den) - (deadline-tg_den)%10;
	deadline = deadline - deadline%10;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			a[i][j] = 0; // khong di duoc
		}
	}
	for(int i = 1; i <= m; i++){
		int x, y; 
		double z;
		cin >> x >> y >> z;
		a[x][y] = z; // di duoc
	}
	for(int i = 1; i <= n; i++){ // n phong ban
		for(int j = 0; j <= 1000; j += 10){ // khoang cach 10 phut
			sx[i][j] = 0; // xac suat phong ban i, tai thoi gian j
		}
	}
	for(int i = 1; i <= n; i++){ // n phong ban
		for(int j = 0; j <= 1000; j += 10){ // khoang cach 10 phut
			sx[i][j] = 0; // xac suat phong ban i, tai thoi gian j
			check[i][j] = true;
		}
	}		
}	

void bfs(int gioihan){
	vt = 1; mmax = (double) 0.0;
	front = 0; back = 0;
	queue[back] = 1;
	queuetg[back] = 0;  
	back++; // push phong ban 1, can 10 phut
	sx[1][0] = 1; // xac suat phong 1 = 1
	sx[1][10] = 1;
	while(front < back){
		int top = queue[front];
		int tg = queuetg[front];
		front++; // pop
		for(int i = 1; i <= n; i++){
			if(a[top][i] > 0){ // di duoc
				if(tg + 10 <= gioihan && check[i][tg+10]) { // chua den han thoi gian
					check[i][tg+10] = false; // da xet
					sx[i][tg+10] = sx[i][tg+10] + (sx[top][tg] * a[top][i]); // xac suat phong i tai thoi gian j
					queue[back] = i;
					queuetg[back] = tg+10;
					back++; // push
					if(tg+10 == gioihan && mmax < sx[i][tg+10]){
						mmax = sx[i][tg+10];
						vt = i;
					}
				}else 
					if(tg + 10 <= gioihan && !check[i][tg+10]){
						sx[i][tg+10] = sx[i][tg+10] + (sx[top][tg] * a[top][i]); // xac suat phong i tai thoi gian j
						if(tg+10 == gioihan && mmax < sx[i][tg+10]){
							mmax = sx[i][tg+10];
							vt = i;
						}
					}					
			}
		}
		//if(ok) return;
	}
}
void reset(int x){
	for(int i = 1; i <= n; i++){ // n phong ban
		for(int j = 0; j <= x; j += 10){ // khoang cach 10 phut
			sx[i][j] = 0; // xac suat phong ban i, tai thoi gian j
		}
	}
	for(int i = 1; i <= n; i++){ // n phong ban
		for(int j = 0; j <= 1000; j += 10){ // khoang cach 10 phut
			sx[i][j] = 0; // xac suat phong ban i, tai thoi gian j
			check[i][j] = true;
		}
	}
}	

int main(){
	int t = 10;
	for(int i = 1; i <= t; i++){
		init();
		bfs(deadline);
		//dis();
		int phong1 = vt;
		double sx1;
		if(phong1 == -1) {
			phong1 = 0;
			sx1 = (double) 0.000000; 
		}else sx1 = sx[phong1][deadline];

		reset(deadline2);
		bfs(deadline2);
		int phong2 = vt;
		double sx2;
		if(phong2 == -1) {
			phong2 = 0;
			sx2 = (double) 0.000000; 
		}else sx2 = sx[phong2][deadline2];

		cout << "#" << i << " " << phong1 << " ";
		printf("%.6f", sx1);
		//cout<<sx1;
		cout << " " << phong2 << " ";
		printf("%.6f", sx2);
		//cout<<sx2;
		cout << endl;
	}
	return 0;
}
