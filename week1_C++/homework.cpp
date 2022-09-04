#include<iostream>
#include<string>
#include<cmath>
#include<cstdio>
using namespace std;
int GCD(int a,int b){//如果a<b的情況,遞迴一次後a,b會交換
	if(a%b)return GCD(b,a%b);
	return b;	
}
int fib(int n){
	int fib_array[n+1];
	fib_array[0] = 0;
	fib_array[1] = 1;
	for(int i = 2 ; i <= n ; i++)
		fib_array[i] = fib_array[i-1]+fib_array[i-2];//dp
	return fib_array[n];
}
int b2d(string n_str){
	int length = n_str.length();
	int decimal = 0;
	for(int i = 0; i < length  ; i++)
		decimal += (int)(n_str[i]-'0')*pow(2,length-i-1);//'0' == 48
	return decimal;
}
