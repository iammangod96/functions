// To know the prime number if the upper bound is given like to find 1001'st prime

#include<iostream>
#include<math.h>

using namespace std;


bool is_prime(int n){
	if (n==1){return false;} 
	else if(n<4){return true;}
	else if(n%2==0){return false;}
	else if(n<9){return true;}
	else if(n%3==0){return false;}
	else{
		int r = floor(sqrt(n));
		int f=5;
		while(f<=r){
			if(n%f==0){return false;}
			else if(n%(f+2)==0){return false;}
			f+=6;
		}
	}
	return true;
}

int main(){
	
	int limit = 1001;
	int count = 1; // 2 is prime
	int candidate = 1;
	do{
		candidate +=2;
		if(is_prime(candidate)==true){
			count++;
		}
	}while(count!=limit);
	cout<<candidate;
	
	
	
	
	return 0;
}
