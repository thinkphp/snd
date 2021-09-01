#include <iostream>
#include <fstream>
#define FIN "ssnd.in"
#define FOUT "ssnd.out"

const int MAXN = 1000005;
const int MOD = 9973;
bool visited[MAXN];
int T, k, Primes[MAXN];
long long N;

using namespace std;

ifstream fin (FIN);
ofstream fout (FOUT);

void ciur() {

     for(int i = 2; i < MAXN; i++) {

         if(visited[i]==false) {

             Primes[++k] = i;

             for(int j = i+i; j < MAXN; j +=i)

                  visited[j] = true;

         }
     }

}

inline int pow(int x, int p) {

	int rez = 1;
	x %= MOD;

	for(; p; p >>= 1) {
		if(p & 1) {
			rez *= x;
			rez %= MOD;
		}

		x *= x;
		x %= MOD;
	}

	return rez;
}

void solve() {

     int numDiv = 1,
         sumDiv = 1;

     fin>>N;

     for(int i = 1; i <= k && 1LL * Primes[i] * Primes[i] <= N; ++i) {

             int p = 0;

             if(N % Primes[i] != 0) continue;

             while(N % Primes[i] == 0) {

                   N/=Primes[i];

                   ++p;
             }

             numDiv *= (p + 1);

             int p1 = (pow(Primes[i], p + 1) - 1) % MOD;

             int p2 = pow(Primes[i] - 1,  MOD - 2) % MOD;

             sumDiv = (((sumDiv * p1) % MOD) * p2) % MOD;
     }

     if(N > 1) {
	   	numDiv *= 2;
		  sumDiv = (1LL*sumDiv*(N+1) % MOD);
	   }

     fout<<numDiv<<" "<<sumDiv;
     fout<<"\n";
}

int main(int argc, char const *argv[]) {

  ciur();
  for(fin>>T; T; T--)
  solve();

  return 0;
}
