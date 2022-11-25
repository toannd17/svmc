#include <iostream>
using namespace std;
char a[5][5];
int res;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
bool check(){
	char x=a[0][0];
	for (int i=0; i<4; i++){
		for (int j=0; j<4; j++){
			if (a[i][j]!=x){
				return false;
			}
		}
	}
	return true;
}

void change(int row, int col){
	if (a[row][col]=='b'){
		a[row][col]='w';
	}
	else 
		a[row][col]='b';
	for (int i=0; i<4; i++){
		int x=row+dx[i];
		int y=col+dy[i];
		if (x>=0 && x<4 && y>=0 && y<4){
			if (a[x][y]=='b'){
				a[x][y]='w';
			}else 
				a[x][y]='b';
		}
	}
}

void backtrack(int vitri, int dem){
	if (dem>=res) 
		return;
	if (vitri==4*4){
		if (check()){
			if (dem<res){
				res=dem;
			}
		}
		return;
	}
	int r=vitri/4;
	int c=vitri%4;
	dem++;
	change(r,c);
	backtrack(vitri+1, dem);
	change(r,c);
	dem--;
	backtrack(vitri+1, dem);

}

int main(){
//	freopen ("input.txt","r", stdin);
	int T;
	cin >> T;
	for (int tc=1; tc<=T; tc++){
		for (int i=0; i<4; i++){
			cin >> a[i];
		}
		res=9999;
		backtrack(0,0);
		cout << "Case #" << tc << endl;
		if (res>16){
			cout << "impossible"<< endl;;
		}else 
			cout << res << endl;

	}
	return 0;
}
