#include <iostream>
#pragma warning (disable:4996)
using namespace std;
int visit[61], visit_cong[3], n, vitri_cong[3], so_luong_nguoi[3], kq;

int tinh(int vt_cong, int sl, int uu_tien) 
{
	if(uu_tien == 0){
		// Uu tien xet trai
		int kc = 0;
	if(visit[vt_cong] == 0){
		sl--;
		visit[vt_cong] = 1;
		kc += 1;
	}
	int i = vt_cong - 1;
	int j = vt_cong + 1;
	while(sl > 0) {
		// Xet ben trai
		if(i > 0 && visit[i] == 0) {
			sl--;
			visit[i] = 1;
			kc += (vt_cong - i + 1);
			if(sl == 0) break;
		}
		// Xet ben phai
		if(j <= n && visit[j] == 0) {
			sl--;
			visit[j] = 1;
			kc += (j - vt_cong + 1);
			if(sl == 0) break;
		}
		i--;
		j++;
	}
	return kc;
	}else
	{
		// Uu tien xet trai
		int kc = 0;
	if(visit[vt_cong] == 0){
		sl--;
		visit[vt_cong] = 1;
		kc += 1;
	}
	int i = vt_cong - 1;
	int j = vt_cong + 1;
	while(sl > 0) {
		// Xet ben phai
		if(j <= n && visit[j] == 0) {
			sl--;
			visit[j] = 1;
			kc += (j - vt_cong + 1);
			if(sl == 0) break;
		}
		// Xet ben trai
		if(i > 0 && visit[i] == 0) {
			sl--;
			visit[i] = 1;
			kc += (vt_cong - i + 1);
			if(sl == 0) break;
		}
		i--;
		j++;
	}
	return kc;
	}	
}



void back_track(int dem, int kc, int uu_tien){
	if(dem == 3){
		if(kc < kq){
			kq = kc;
		}
		return;
	}

	for(int i = 0; i < 3; i++){
		if(visit_cong[i] == 0){
			visit_cong[i] = 1;
			int back_up[61];
			for(int j = 1; j <= n; j++) {
				back_up[j] = visit[j];
			}
			back_track(dem+1, kc + tinh(vitri_cong[i], so_luong_nguoi[i], uu_tien), uu_tien);
			for(int j = 1; j <= n; j++) {
				visit[j] = back_up[j];
			}
			visit_cong[i] = 0;
		}
	}
}


int main()
{
	freopen("Text.txt", "r", stdin);
	int T; cin >> T;
	for(int tc = 1; tc <= T; tc++){
		cin >> n;
		for(int i = 1; i <= n; i++){
			visit[i] = 0;
		}
		for(int i = 0; i < 3; i++){
			cin >> vitri_cong[i];
			cin >> so_luong_nguoi[i];
			visit_cong[i] = 0;
		}
		kq = 99999999;
		back_track(0, 0, 0);
		back_track(0, 0, 1);
		cout << "Case #" << tc << endl;
		cout << kq << endl;
	}
	return 0;
}
