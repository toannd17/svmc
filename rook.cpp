#include <iostream>
#pragma warning (disable:4996)
using namespace std;

int N;
char M[5][5];
int answer;

bool check(int row, int col) {
	if(M[row][col] == 'X') return false;
	int r = row-1;
	while (r>=0){
		if(M[r][col] == 'X') break;
		if(M[r][col] == '+') return false;
		r--;
	}
	int c = col - 1;
	while(c>=0){
		if(M[row][c] == 'X') break;
		if(M[row][c] == '+') return false;
		c--;
	}
	return true;
}


void solve(int pos, int cntRook){
	if (pos >= N*N){
		if(cntRook > answer){
			answer = cntRook;
		}
		return;
	}

	int row = pos / N;
	int col = pos % N;
	for(int i = 0; i < 2; i++){
		if(i==0){
			solve(pos+1, cntRook);
		}else {
			if(check(row, col)) {
				M[row][col] = '+';
				solve(pos+1, cntRook+1);
				M[row][col] = '.';
			}
		}
	}
}


int main(){
	freopen("Text.txt", "r", stdin);
	int T; cin >> T;
	for(int tc = 1; tc <= T; tc++){
		answer = 0;
		cin >> N;
		for(int i = 0; i < N; i++){
			cin >> M[i];
		}
		solve(0, 0);
		cout << "Case #" << tc <<endl<< answer << endl;
	}

	return 0;
}

