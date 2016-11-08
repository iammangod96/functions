#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

//wagner-fischer algorithm
//#include<algorithm> #include<string>
int WF_edit_distance(string s1,string s2){
	int m = s1.length(), n = s2.length();
	static int d[2001][2001];
	for(int i=0;i<m+1;i++){
		d[i][0] = i;
	}
	for(int j=0;j<n+1;j++){
		d[0][j] = j;
	}
	for(int j = 1;j<n+1;j++){
		for(int i=1;i<m+1;i++){
			if(s1[i-1]==s2[j-1]){
				d[i][j]= d[i-1][j-1];
			}else{
				d[i][j] = min(min(d[i][j-1],d[i-1][j]),d[i-1][j-1]) + 1;
			}
		}
	}
	return d[s1.length()][s2.length()];
}

int main(){
	
	int t;
	cin>>t;
	while(t--){
		string s1;
		string s2;
		cin>>s1;
		cin>>s2;
		cout<<WF_edit_distance(s1,s2)<<endl;
	}
	return 0;
}
