long long int binExp(long long int base, long long int power){
  long long int result=1;
  while(power>0){
    if(power%2 != 0) result*=base;
    base*=base;
    power/=2;
  }
  return result;
}
long long int binExp(long long int base, long long int power, long long int mod){
  long long int result=1;
  while(power>0){
    if(power%2 != 0) result = (result*base)%mod;
    base=(base*base)%mod;
    power/=2;
  }
  return result;
}

int main(){}
