#include <iostream>
#pragma warning (disable:4996)
using namespace std;
int N, map[200][200];

int check(int n, int x, int y){
	int flag_0 = 1;
	int flag_1 = 1;
	for(int i = x; i < x + n; i++){
		for(int j = y; j < y + n; j++){
			if(map[i][j] == 1){
				flag_1 &= 1;
				flag_0 &= 0;
			}else {
				flag_1 &= 0;
				flag_0 &= 1;
			}
		}
	}
	if(flag_1 == 1) return 1;
	if(flag_0 == 1) return 0;
	return -1;
}

int trang, xanh;
void dequy(int x, int y, int n){
	if(check(n, x, y) == 1){
		xanh++;
		return;
	}
	if(check(n, x, y) == 0){
		trang++;
		return;
	}
		dequy(x, y, n/2);
		dequy(x , y + n/2, n/2);
		dequy(x + n/2, y, n/2);
		dequy(x + n/2, y + n/2, n/2);
}


int main()
{
	freopen("Text.txt", "r", stdin);
	int T; cin >> T;
	for(int tc = 1; tc <= T; tc++){
		cin >> N;

		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				cin >> map[i][j];
			}
		}
		trang = xanh = 0;
		dequy(0, 0, N);
		cout << "Case #" << tc << endl << trang << " " << xanh << endl;
	}

	return 0;
}
