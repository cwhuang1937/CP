#include <stdio.h>
#include <stdlib.h>

int isPrime(int num);

int list[4792]={2};

int main(void) {
 int number;
 int listcount=1;
 for(int i=3;i<46338;i++) {
  if(isPrime(i)) {
   list[listcount]=i;
   listcount++;
  }
 }
 
 while(scanf("%d", &number)!=EOF) {
  int i=0, in=1;
  while(i<4792) {
   if(number>list[i]&&number%list[i]==0) {
    in=0;
    break;
   }
   i++;
  }
  if(in) {
   printf("質數\n");
  } else {
   printf("非質數\n");
  }
 }
 
 return 0;
}

int isPrime(int num) {
 if(num==2) {
  return 1;
 } else if(num%2==0) {
  return 0;
 } else {
  for(int i=3;i*i<=num;i+=2) {
   if(num%i==0)
    return 0;
  }
 }
 return 1;
}
