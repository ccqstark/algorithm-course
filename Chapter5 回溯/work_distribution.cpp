// 工作分配问题
#include <iostream>
#include <climits>
using namespace std;
#define MAX 22
int n;
int spend[MAX][MAX];
int nowp;
int bestp = INT_MAX;
int choice[MAX];

bool if_can_choice(int p,int t){
	
	for(int i=1;i<t;i++){
		if(choice[i] == p)
			return false;
	}
	
	return true;
}

void Backtrack(int t){
	
	if(t>n && nowp<bestp){
		bestp = nowp;	
	}
	
	for(int i=1;i<=n;i++){
		if(if_can_choice(i,t)){
			nowp+=spend[t][i];
			choice[t] = i;
			if(nowp < bestp){
				Backtrack(t+1);
			}	
			nowp -= spend[t][i];	
		}
	}
	
	return;
}


int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>spend[i][j];
		}
	}
	
	Backtrack(1);
	
	cout<<bestp;
} 