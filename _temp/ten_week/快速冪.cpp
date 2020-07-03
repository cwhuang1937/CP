#include<iostream>
#include<cstdio>
using namespace std;

long long bigmod( long long B, long long P, long long M ){
  if( P == 0 )
    return 1;
  else if( P == 1 )
    return B%M;
  else{
    long long result = bigmod( B, P/2, M );
    if( P%2 )
      return result*result*B % M;
    else
      return result*result % M;
  }
}

int main(){
  long long B, P, M;
  while( scanf( "%lld%lld%lld", &B, &P, &M ) != EOF )
    printf( "%lld\n", bigmod( B, P, M ) );
  return 0;
}