#include<stdio.h>
void printBytes(int n);
int main(){
	for(int i=0;i<=700; i++){
		printBytes(i);
	}
}

void printBytes(int n){
	// given an integer n prints out one per line the bytes of n
	int a = (n>>24)   & 0xff;
	int b = (n>>16)   & 0xff;
	int c = (n>>8)    & 0xff;
	int d =  n 	  & 0xff;
	printf("%x\t%x\t%x\t%x\n",a,b,c,d);
}
