#include <iostream>
#pragma warning (disable:4996)
using namespace std;
int arr[10];

int dem[10];
int So, lan, len;
int rank_[10]={0};
int visit[10];

int arrToSo(int len){
	int so = 0;
	for(int i = len - 1; i >= 0 ; i--){
		so = so*10 + arr[i];
	}
	return so;

}




int soToArr(int s){
	int n = 0;
	while(s!=0){
		arr[n] = s%10;
		n++;
		s/=10;
	}
	return n;
}

bool check(){
	for(int i = 0; i < len - 1; i++){
		if(rank_[i] > rank_[i+1]) return false;
	}
	return true;
}




int main()
{
	freopen("Text.txt", "r", stdin);
	int T; cin >> T;
	for(int tc = 1; tc <= T; tc++){
		cin >> So >> lan;
		for(int i = 0; i < 10; i++){
			arr[i] = 0;
			dem[i] = 0;
			rank_[i] = 0;
			visit[i] = 0;
		}
		len = soToArr(So);
		for(int i = 0; i < len; i++ ){
			dem[arr[i]]++;
		}

		int count = 0;
		for(int i = 0; i < 10; i++){
			if(dem[i] != 0){
				count++;
			}
		}
		
		for(int i = 0; i < 10; i++){
			if(dem[i] != 0){
				for(int j = 0; j < len; j++){
					if(arr[j] == i){
						rank_[j] = count;
					}
				}
				count--;
			}
		}

		int chiso = len - 1;
		while(lan > 0){
			if(check()) {
				break;
			}
			int min_ = 9;
			int min = -1;
			for(int i = 0; i < len; i++){
				if(rank_[i] < min_ && visit[i] == 0){
					min_ = rank_[i];
					min = i;
				}
			}
			visit[min] = 1;
			if(rank_[chiso] < rank_[min]){
				chiso--;
				continue;
			}
			int temp = rank_[chiso];
			rank_[chiso] = rank_[min];
			rank_[min] = rank_[chiso];
			chiso--;
			lan--;
		}

		cout << "#" << tc << endl;
		/*
		for(int i = len - 1; i >= 0; i--){
			cout << arr[i] << " ";
		}
		cout << endl;*/
		for(int i = len - 1; i >= 0; i--){
			cout << rank_[i] << " ";
		}
		cout << endl;

		//cout << arrToSo(len) << endl;


	}


	return 0;
}
