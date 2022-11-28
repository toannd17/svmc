//Hoán vị
int SET[10] = {1,2,3,4,5,6,7,8,9,10};// chứa các ptu 
int HV[10];
int VS[10];
int N = 10;
void BT_HV(int vtPtu <, int tong>){
	if (vtPtu >= N){// N số lượng ptu, N = SET.Length();
		// nếu biến tong, cập nhật tong
		for (int i=0;i<N;i++){
			cout<<HV[i]<<" ";
		}
		cout<<endl;
		return;
	}
	// điều kiện dừng khi tìm min
	for (int i=0;i<N;i++){// duyệt tất cả các ptu trong tập SET
		if (VS[i] == 0){// nếu phần tử thứ i chưa được chọn
			VS[i] = 1;
			HV[vtPtu] = SET[i];
			BT_HV(vtPtu+1);
			VS[i] = 0;
		}
	}
}


//Tập con
int SET[10] = {1,2,3,4,5,6,7,8,9,10};// chứa các ptu 
int TC[10];
int N=10;
int SUM = 12;
void BT_TC(int vtPtu, int tong){
	if (vtPtu>=N){
		return;
	}
	if (tong == SUM){
		for (int i=0;i<10;i++){
			if (TC[i] == 1) cout<<SET[i]<<" ";
		}
		cout<<endl;
	}
	if (tong>=SUM) return;
	for (int i=0;i<2; i++){
		TC[vtPtu] = i;
		if (i==1){
			BT_TC(vtPtu+1, tong+SET[vtPtu]);
		} else {
			BT_TC(vtPtu+1, tong);
		}
		TC[vtPtu] = 0;
	}
}

// chọn tập con có k ptu
int TCK[10];
int K = 5;
void BT_TCK(int vtPtu, int k){
	if (k>=K){
		for (int i=0;i<K;i++){
			cout<<TCK[i]<<" ";
		}
		cout<<endl;
		return;
	}
	
	for (int i=vtPtu;i<N;i++){
		TCK[k] = SET[i];
		BT_TCK(i+1; k+1);
	}
}






