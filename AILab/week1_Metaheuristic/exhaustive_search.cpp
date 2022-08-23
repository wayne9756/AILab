#include<unistd.h>
#include<iostream>
#include <signal.h>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<cstdio>
#include<exception>
using namespace std;

int Evalute(vector<int> &x){
	int sum = 0;
	for(int i = 0 ; i < 100 ;i++)
		sum += x[i];
	return sum;
}

inline void addition(vector<int> &x){//2進位加法
	int carry = 1;
	int temp;
	for(int i = 99;i >= 0 ; i-- ){
		temp = x[i];
		x[i] ^= carry;
		carry &= temp;
	}
}

vector<int> EnumNext(vector<int> &x){
	addition(x);
	return x;
}

int main(){
	time_t init_time;
	time(&init_time);
	vector<int> s(100,0);//inital vector
	vector<int> v(100);//solution container
	int f1 = Evalute(s);
	while(time(0) - init_time < 1800){//60sec*30min
		EnumNext(s);
		int f2 = Evalute(s);
		if(f2 > f1){
			v = s;
			f1 = f2;
		}
	for(int i = 0; i < 100 ; i++)
		printf("%d",s[i]);
	printf("\n");
	}
	printf("the best solution is ");
	for(int i = 0; i < 100 ; i++)
		printf("%d",v[i]);
	printf("\n");
	return 0;
}
