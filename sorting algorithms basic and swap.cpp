#include<iostream>
#include<time.h>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int b_search(int tbs,int p,int q,vector<int> A);

void swap(int& i,int& j);

void m_sort(int p,int r,int B[]);
void bubble_sort(vector<int> A);
void merge(int p,int q,int r,int B[]);
void selection_sort(vector<int> A);
void insertion_sort(vector<int> A);
void merge(int A[], int start, int mid, int end);
void merge_sort (int A[] , int start , int end );

int main(){
clock_t startTime = clock();
int t;
vector<int> A;
for(int i=0;i<5;i++){
	A.push_back(i+1);
}
for(int i=0;i<5;i++){
	cout<<A[i]<<" ";
}
cout<<endl;
cout<<b_search(2,0,A.size()-1,A);


cout << endl<<double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
cin.ignore();
return 0;
}


// #include<vector>
int b_search(int tbs,int p,int q,vector<int> A){
	while(p<q){
		int mid = p+(q-p)/2
		;
		if(A[mid]==tbs){
			return mid;
		}else if(tbs<A[mid]){
			return b_search(tbs,p,mid-1,A);
		}else{
			return b_search(tbs,mid+1,q,A);
		}
	}
	if(p==q){
		if(A[p]==tbs){
			return p;
		}
	}
	
}

// #include<algorithm> and #include
	
void bubble_sort(vector<int> A){
	for(int k=0;k<A.size();k++){
		for(int i=0;i<A.size()-k;i++){
			if(A[i]>A[i+1]){
				swap(A[i],A[i+1]);
			}
		}
	}
	cout<<"Bubble sorted :\n";
	for(int i=0;i<A.size();i++){
		cout<<A[i]<<endl;
	}
}

// #include<vector> and #include<algorithm>
void selection_sort(vector<int> A){
	for(int i=0;i<A.size()-1;i++){
		int min=i;
		for(int j=i+1;j<A.size();j++){
			if(A[j]<A[min]){
				swap(A[j],A[min]);
			}
		}
	}
	cout<<"Selection sorted :\n";
	for(int i=0;i<A.size();i++){
		cout<<A[i]<<endl;
	}
}

void insertion_sort(vector<int> A){
	for(int i=0;i<A.size();i++){
		int j = i;
		int temp = A[i];
		while(j>0 && A[j-1]>temp){
			A[j] = A[j-1];
			j--;
		}
		A[j]  = temp;
	}
	cout<<"Insertion sorted :\n";
	for(int i=0;i<A.size();i++){
		cout<<A[i]<<endl;
	}
}

void merge(int A[] , int start, int mid, int end) {

   //stores the starting position of both parts in temporary variables.
    int p = start ,q = mid+1;

    int Arr[end-start+1] , k=0;

    for(int i = start ;i <= end ;i++) {
        if(p > mid)      //checks if first part comes to an end or not .
           Arr[ k++ ] = A[ q++] ;

       else if ( q > end)   //checks if second part comes to an end or not
           Arr[ k++ ] = A[ p++ ];

       else if( A[ p ] < A[ q ])     //checks which part has smaller element.
          Arr[ k++ ] = A[ p++ ];

       else
          Arr[ k++ ] = A[ q++];
   }
   for (int p=0 ; p< k ;p ++) {
     /* Now the real array has elements in sorted manner including both 
            parts.*/
       A[ start++ ] = Arr[ p ] ;                          
   }
}

void merge_sort (int A[], int start , int end ) {
    if( start < end ) {
       int mid = (start + end ) / 2 ;           // defines the current array in 2 parts .
       merge_sort (A, start , mid ) ;                 // sort the 1st part of array .
       merge_sort (A,mid+1 , end ) ;              // sort the 2nd part of array.

     // merge the both parts by comparing elements of both the parts.
        merge(A,start , mid , end );   
   }                    
}



void swap(int& i,int& j){
	int temp = i;
	i=j;
	j=temp;
}
