#include <iostream>
using namespace std;
int So, lan, len;
int arr[10];
int visit[10];
int ranks[10];
int dem[10];

int soToArr(int s){
	int len = 0;
	while(s != 0){
		arr[len++] = s%10;
		s/=10;
	}
	return len;
}

void daoMang(int len){
	for(int i = 0; i < len/2; i++){
		int temp = arr[len - i -1];
		arr[len-i-1] = arr[i];
		arr[i] = temp;
	}
}

void xuatMang(int len){
	for(int i = 0; i < len; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
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
		cin >> So >> lan;

		// rs mang
		for(int i = 0; i < 10; i++){
			arr[i] = 0;
			visit[i] = 0;
			ranks[i] = 0;
			dem[i] = 0;
		}
		len = soToArr(So);
		daoMang(len);
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
			if(dem[i] > 0){
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
