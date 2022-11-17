#include <iostream>
using namespace std;
int lan, len;
char so[10];
int arr[10];
int visit[10];
int ranks[10];
int dem[10];


int len_so(){
	int l = 0;
	while(so[l] != '\0'){
		l++;
	}
	return l;
}


int arrToNum(int len){
	int s = 0;
	for(int i = 0; i < len; i++){
		s = s*10 + arr[i];
	}
	return s;
}

bool check(int len){
	for(int i = 0; i < len - 1; i++){
		if(ranks[i] > ranks[i+1]) return false;
	}
	return true;
}

int main()
{
	freopen("Text.txt", "r", stdin);
	int T; cin >> T;
	for(int tc = 1; tc <= T; tc++){
		cin >> so >> lan;

		// rs mang
		for(int i = 0; i < 10; i++){
			arr[i] = 0;
			visit[i] = 0;
			ranks[i] = 0;
			dem[i] = 0;
		}
		len = len_so();
		for(int i = 0; i < len; i++){
			arr[i] = so[i] - '0';
		}

		int f = 0;
		for(int i = 0; i < len; i++){
			dem[arr[i]]++;
			if(dem[arr[i]] > 1) f = 2;
		}
		int c = 0;
		for(int i = 0; i < 10; i++){
			if(dem[i] > 0){
				c++;
			}
		}
		for(int i = 0; i < 10; i++){
			if(dem[i] >= 1){
				for(int j = 0; j < len; j++){
					if(arr[j] == i){
						ranks[j] = c;
					}
				}
				c--;
			}
		}

		int vitri = 0;
		while(lan > 0){

			if(check(len)){
				break;
			}

			int min = 99;
			int idm;
			for(int i = 0; i < len; i++){
				if(ranks[i] <= min && visit[i] == 0){
					min = ranks[i];
					idm = i;
				}
			}

			if(ranks[vitri] <= ranks[idm]){
				visit[vitri] = 1;
				vitri++;
				continue;
			}

			// swap
			int temp = arr[idm];
			arr[idm] = arr[vitri];
			arr[vitri] = temp;

			temp = ranks[idm];
			ranks[idm] = ranks[vitri];
			ranks[vitri] = temp;

			visit[vitri] = 1;
			vitri++;
			lan--;
		}

		cout << "Case #" << tc << endl;

		if(lan > 0){
			if(f == 2 || lan%2 == 0){
				int n = arrToNum(len);
				cout << n << endl;
			}else {
				int temp = arr[len-1];
				arr[len-1] = arr[len-2];
				arr[len-2] = temp;
				int n = arrToNum(len);
				cout << n << endl;
			}
		}else {
			int n = arrToNum(len);
			cout << n << endl;
		}

	}
	return 0;
}
