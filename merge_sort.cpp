// spoj.cpp : Defines the entry point for the console application.

#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

void merge(int A[],int start,int mid,int end){
	int p = start;
	int q = mid+1;
	int B[end-start+1];
	int k= 0;
	int inversion = 0;;
	for(int i=start;i<=end;i++){
		if(p>mid){
			B[k++] = A[q++];			
		}else if(q>end){
			B[k++] = A[p++];
		}else if(A[p]<A[q]){
			B[k++] = A[p++];
		}else{
			B[k++] = A[q++];
		}
	}
	for(int i=0;i<k;i++){
		A[start++] = B[i];
	}
}

void merge_sentinel(int A[],int start,int mid,int end){
	int n1 = mid-start+1;
	int n2 = end - mid;
	int L[n1+1];
	int R[n2+1];
	for(int i=0;i<n1;i++){
		L[i] = A[start + i];
	}
	for(int i=0;i<n2;i++){
		R[i] = mid+1+i;
	}
	L[n1] = 200001;
	R[n2] = 200001;
	int i = 0;
	int j = 0;
	int inversions = 0;
	for(int k = start;k<=end;k++){
		if(L[i]<R[j]){
			A[k] = L[i++];
		}else{
			A[k] = R[j++];
			inversions+=mid - i + 1;
		}
	}
	cout<<inversions<<endl;
}

void merge_sort(int A[],int start,int end){
	if(start<end){
		int mid = (start+end)/2;
		merge_sort(A,start,mid);
		merge_sort(A,mid+1,end);
		merge_sentinel(A,start,mid,end);	
	}
	
}

int main(){
	
	int t;
	cin>>t;
	
	while(t--){
		cout<<endl;
		int a;
		cin>>a;
		int A[a];
		for(int i=0;i<a;i++){
			int p;
			cin>>p;
			A[i] = p;
		}
		
		merge_sort(A,0,a-1);
		
	}

	return 0;

}

