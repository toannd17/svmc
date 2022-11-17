#include <iostream>
#pragma warning (disable:4996)
using namespace std;
int a[11];
int visit[11];
int kq, n;

int tinhdiem(int vi_tri){
	int diem1 = 0;
	int diem2 = 0;
	for(int i = vi_tri+1; i < n; i++){
		if(visit[i] == 0){
			diem1 = a[i];
			break;
		}
	}
	for(int i = vi_tri-1; i >= 0; i--) {
		if(visit[i] == 0) {
			diem2 = a[i];
			break;
		}
	}
	if(diem1 != 0 && diem2 != 0){
		return diem1*diem2;
	}else if (diem1 != 0){
		return diem1;
	}else if (diem2 != 0){
		return diem2;
	}else {
		return a[vi_tri];
	}
}


void back_track(int dem, int diem){
	if(dem == n) {
		if(diem > kq) {
			kq = diem;
		}
		return;
	}
	for(int i = 0; i < n; i++) {
		if(visit[i] == 0) {
			visit[i] = 1;
			back_track(dem + 1, diem + tinhdiem(i));
			visit[i] = 0;
		}
	}
}


int main()
{
	freopen("Text.txt", "r", stdin);
	int T; cin >> T;
	for(int tc = 1; tc <= T; tc++){
		cin >> n;
		// doc input
		for(int i = 0; i < n; i++){
			cin >> a[i];
			visit[i] = 0;
		}
		kq = 0;
		back_track(0, 0);
		cout << "#" << tc << " " << kq << endl;
	}
	return 0;
}
