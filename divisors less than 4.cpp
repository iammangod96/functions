    #include<iostream>
    #include<vector>
    #include<math.h>
    #include<algorithm>
    using namespace std;
 bool is_prime(long long n){
	if (n==1){return false;} 
	else if(n<4){return true;}
	else if(n%2==0){return false;}
	else if(n<9){return true;}
	else if(n%3==0){return false;}
	else{
		long long r = floor(sqrt(n));
		long long f=5;
		while(f<=r){
			if(n%f==0){return false;}
			else if(n%(f+2)==0){return false;}
			f+=6;
		}
	}
	return true;
}

bool is_perfectsquare(long long n){
	if(sqrt(n)==floor(sqrt(n))){
		if(is_prime(sqrt(n))){
			return true;
		}else{
			return false;
		}
	}else{
		return false;
	}
}
int main (void) {
	int n;cin>>n;
	while(n--){
		long long x;cin>>x;
		if(x==1){
			cout<<"NO"<<endl;
		}else{
			if(is_prime(x) || is_perfectsquare(x)){
			cout<<"NO"<<endl;
		}else{
			cout<<"YES"<<endl;
		}
		}
		
	}
  return 0;
}