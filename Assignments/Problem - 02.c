/*
                        -- Course Name  : Structure Programming Language   --
                        -- Course No    : SWE121, SWE122                   --
                        -- Problem No   : 002                              --
                        -- Submitted By : Ariful Islam Shanto - 2019831029 --
*/

#include <stdio.h>

#define M 100000000
int marked[M/64 + 2];

#define on(x) (marked[x/64] & (1<<((x%64)/2)))
#define mark(x)  marked[x/64] |= (1<<((x%64)/2))

void sieve(int n) {
  for (int i = 3; i * i < n; i += 2) {
    if (!on(i)) {
      for (int j = i * i; j <= n; j += i + i) {
        mark(j);
      }
    }
  }
}

int isPrime(int num) {
  return ( num > 1 && (num == 2 || ((num & 1) && !on(num))) ); 
}

int main()
{
	int n;
	scanf("%d", &n);
	sieve(n);

	for( int i = 1; i <= n; i++ ) {
		if( isPrime(i) ) printf("%d\n", i);
	}
  return 0;
}
