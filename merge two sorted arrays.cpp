#include<iostream>
#include<vector>
using namespace std;

//merge two sorted arrays
void merge(vector<int> A,vector<int> B,int n,int m){
	int x=0,y=0;
	vector<int> arr;
	while(x<n && y<m){
		if(B[y]<A[x]){
			arr.push_back(B[y++]);
		}else{
			arr.push_back(A[x++]);
		}
	}
	while(x<n){
		arr.push_back(A[x++]);
	}
	while(y<m){
		arr.push_back(B[y++]);
	}
	for(int i=0;i<arr.size();i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}


int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		vector<int> A;
		vector<int> B;
		for(int i=0;i<n;i++){
			int q;
			cin>>q;
			A.push_back(q);
		}
		for(int i=0;i<m;i++){
			int q;
			cin>>q;
			B.push_back(q);
		}
		merge(A,B,n,m);
		
	}
	
	return 0;
}
