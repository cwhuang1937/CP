#include<iostream>
#include<cstdio>
using namespace std;

int main(){
  bool composite[1000005] = { true, true };
  bool find;
  int a;

  for( int i = 2 ; i <= 1000000 ; i++ )
    if( !composite[i] )
      for( int j = i+i ; j <= 1000000 ; j += i )
        composite[j] = true;

  int n;
  while( scanf( "%d", &n ) != EOF && n != 0 ){
    find = false;
    for( a = 2 ; a <= n/2 ; a++ )
      if( !composite[a] )
        if( !composite[n-a] ){
          find = true;
          break;
        }
    if( find ) printf( "%d = %d + %d\n", n, a, n-a );
    else printf( "Goldbach's conjecture is wrong.\n" );
  }

  return 0;
}