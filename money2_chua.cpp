#include<iostream>

using namespace std;
char str[6];
int m[6];
int K, leng;
int KQ;

bool check(){
	for (int i=1;i<leng;i++){
		if (m[i-1] < m[i]) return false;
	}
	return true;
}

void solve(int position, int k){
	if (k>=K || position >= leng) {
		int kq = 0;
		for (int i=0;i<leng;i++){
			kq = kq*10+m[i];
		}
		if (kq>KQ){
			KQ = kq;
		}
		return;
	}
	if (check()){
		int a[10];
		for (int i=0;i<10;i++){
			a[i] = 0;
		}
		for (int i=0;i<leng;i++){
			a[m[i]]++;
			if (a[m[i]] >= 2) {
				int kq = 0;
				for (int i=0;i<leng;i++){
					kq = kq*10+m[i];
				}
				if (kq>KQ){
					KQ = kq;
				}
				return;
			}
		}
		int tem = K-k;
		if (tem%2!=0){
			int tt = m[leng-1];
			m[leng-1] = m[leng-2];
			m[leng-2] = tt;
		}
		int kq = 0;
		for (int i=0;i<leng;i++){
			kq = kq*10+m[i];
		}
		if (kq>KQ){
			KQ = kq;
		}
		return;
	}

	bool swap = false;
	for (int i=position;i<leng;i++){
		if (m[i] > m[position]){
			swap = true;
			int tt = m[i];
			m[i] = m[position];
			m[position] = tt;
			solve(position+1, k+1);
			tt = m[i];
			m[i] = m[position];
			m[position] = tt;
		}
	}
	if (!swap){
		solve(position+1, k);
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	ios::sync_with_stdio(false);

	freopen("input.txt", "r", stdin);
	cin >> T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin>>str>>K;
		leng = 0;
		while (str[leng] != '\0'){
			m[leng] = str[leng] - '0';
			leng++;
		}
		KQ = 0;
		solve(0, 0);
		
		cout << "Case #" << test_case << endl << KQ << endl;
	}
	return 0;//Your program should return 0 on normal termination.
}
