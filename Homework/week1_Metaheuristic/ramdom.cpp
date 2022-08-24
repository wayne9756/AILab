#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;
int evaluate(string str){
	int sum = 0;
	for(int i = 0 ; i < 100 ; i++)
		sum += str[i]-'0';
	return sum;
}
string enumNext(){
	string str;
	for(int i = 0;i <100 ;i++)
		str += to_string(rand()%2);
	return str;
}
int main(){
	srand(time(0)*10000);
	string s(100 ,'0');
	int f1 = evaluate(s);
	for(int i = 0 ; i < 100000;i++){
		string v(enumNext());
		int f2 = evaluate(v);
		if(f2 > f1){
			s = v;
			f1 = f2;
		}
	}
	cout << "1的個數 = " << evaluate(s) << endl;
	cout << "output = "<< s << endl; 
}
