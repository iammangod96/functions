int gcd(int n1,int n2){
  int t = 1;
  for(int i=2;i<=n1;i++){
    if(n2%i == 0 && n1%i == 0){
      t = i;
    }
  }
  return t;
}