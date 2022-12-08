#include<iostream>
#include<stdio.h>
using namespace std;
int n,e,k,t,kt;
int A[101][201];
float B[101][201];
float N[101];
float M[101][101];
int check[101][101];
int Qx[1000000];
float Qy[1000000];
int Qd[10000000];
int f,r;

void reset(){
	for(int i=1;i<=101;i++){
		for(int j=1;j<=101;j++){
			 A[i][j]=0;
			B[i][j]=0;
			 N[i]=0;
			 M[i][j]=0;
			 check[i][j]=0;
		}
	}
}
void BFS(){
	Qx[f]=1;
	M[1][0]=1;
	Qd[f++]=0;
	check[1][0]=0;
	while(f!=r){
		int a=Qx[r];
		int c=Qd[r++];
		for(int i=1;i<=A[a][0];i++){
			if(c+1<=kt){
				if(check[A[a][i]][c+1]==0){
					check[A[a][i]][c+1]=1;
					Qx[f]=A[a][i];
					M[A[a][i]][c+1]+=M[a][c]*B[a][i];
					Qd[f++]=c+1;
				}
				else {
					M[A[a][i]][c+1]+=M[a][c]*B[a][i];
				}
			}

		}
	}
}
int main(){
	//freopen("Text.txt","r",stdin);
	for(int tc=1;tc<=10;tc++){
		reset();
		cin>>n>>e>>k>>t;
		int x,y;
		float z;
		for(int i=1;i<=e;i++){
			cin>>x>>y;
			scanf("%f",&z);
			A[x][0]++;
			A[x][A[x][0]]=y;
			B[x][A[x][0]]=z;
		}
		kt=t/10;
		BFS();
		float maxx=0;
		int vt=1;
		for(int i=1;i<=n;i++){
			if(M[i][kt]>maxx){
				maxx=M[i][kt];
				vt=i;
			}
		}
		if(maxx==0) vt=0;
		kt=(t-k)/10;
		float maxx2=0;
		int vt2=1;
		for(int i=1;i<=n;i++){
			if(M[i][kt]>maxx2){
				maxx2=M[i][kt];
				vt2=i;
			}
		}
		if(maxx==0) vt=0;
		cout<<"#"<<tc<<" "<<vt<<" ";
		printf("%0.6f", maxx);
		cout<<" "<<vt2<<" ";
		printf("%0.6f", maxx2);
		cout<<endl;
	}
	
	return 0;
}
