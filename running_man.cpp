#include<iostream>
using namespace std;
int M,D,k[5][3],b[5][2];
int tong;
void backtrack(int k,int kq,int nangluong, int step){
	if(k==4){
		if(tong>kq+(D-step)*b[4][0]&&nangluong+(D-step)*b[4][1]<=M){
			tong=kq+(D-step)*b[4][0];
		}
		return;
	}
	if(kq>=tong||nangluong>M) return;
	for(int i=0;i<=D-step;i++){
		backtrack(k+1,kq+i*b[k][0],nangluong+i*b[k][1],step+i);
	}
}
int main(){
	//freopen("Text.txt","r",stdin);
	int T;
	cin>>T;
	for (int tc = 1; tc <= T; tc++)
	{
		tong=999999999;
		cin>>M>>D;
		for (int i = 0; i < 5; i++)
		{
			cin>>k[i][0]>>k[i][1]>>k[i][2];
			b[i][0]=k[i][0]*60+k[i][1];
			b[i][1]=k[i][2];
		}
		backtrack(0,0,0,0);
		int h=tong/60;
		int g=tong%60;
		cout<<"Case #"<<tc<<endl;
		if(tong==999999999){
			cout<<"-1"<<endl;
		}
		else{
			cout<<h<<" "<<g<<endl;
		}
	}
	return 0;
}
