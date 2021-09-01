int main(int argc, char const *argv[]) {
 
  long long n, s = 0;
  scanf("%lld", &n);
  for(int i = 1; i <= sqrt(n); i++) {
      if(n % i == 0) {
         int j = n / i;
          if(i!=j) s+= i + j;
          else s+=i;
      }
  }
  printf("%lld",s);
  return 0;
}
