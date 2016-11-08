//max-subarray problem using divide and conquer
#include<iostream>

using namespace std;
int max_cross_sub(int A[],int low,int mid,int high);
int max_sub(int A[],int low,int high);

int main(){
	
	int B[5]={-13,-3,-25,-20.-10};
	int ans = max_sub(B,0,4);
	cout<<ans;
	
	return 0;
}

int max_cross_sub(int A[],int low,int mid,int high){
	int left_sum = -1000;
	int sum=0;
	int max_left=0;
	for(int i=mid;i>=low;i--){
		sum=sum+A[i];
		if (sum>left_sum){
		 left_sum=sum;
		 max_left=i;
		}
	}
	int right_sum=-1000;
	sum=0;
	int max_right=high;
	for(int j=mid+1;j<=high;j++){
		sum = sum + A[j];
		if(sum>right_sum){
			right_sum = sum;
			max_right=j;
		}
	}
	return (left_sum+right_sum);
}

int max_sub(int A[],int low,int high){
	if(high==low){
		return A[low];
	}else{
		int mid = int((low+high)/2);
		int left_sum = max_sub(A,low,mid);
		int right_sum = max_sub(A,mid+1,high);
		int cross_sum = max_cross_sub(A,low,mid,high);
		if ((left_sum>right_sum)&&(left_sum>cross_sum)){
			return left_sum;
		}else if((right_sum>left_sum)&&(right_sum>cross_sum)){
			return right_sum;
		}else{
			return cross_sum;
		}
	}
}






