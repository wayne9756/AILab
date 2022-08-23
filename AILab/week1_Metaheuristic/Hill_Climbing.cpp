#include<iostream>
#include<fstream>
#include<vector>
#include<ctime>
#include<cstdlib>
using namespace std;

inline int Evalute(vector<int> &x, int n){
	int sum = 0;
	for(int i = 0 ; i < n ;i++)
		sum += x[i];
	return sum;
}

vector<int> init(vector<int> &x, int n){
	for(int i = 0; i < n ; i++)
		x[i] = rand()%2;//0 or 1;
	return x;
}

inline vector<int> random_select(vector<int>x, int n){
	int position = rand()%n;
	x[position] ^= 1;//取反 
	return x;	
}

inline void display(vector<int> &x, fstream &file){
	for(auto n : x)
		file << n;
}

int main(int argc, char* argv[]){//argv[1] 代表 bit_len數 ,argv[2]代表run ,argv[3]代表iteration.
	int bit_len = atoi(argv[1]);
	srand(time(0));
	fstream file;
	file.open("output_file.txt",ios::out);
	vector<int> s(bit_len);
	vector<int> v(bit_len);// container
	for(int run = 0; run < atoi(argv[2]); run++){
		file << "run = " << run << endl;
		init(s, bit_len);//get a random vector
		int f1 = Evalute(s,bit_len);
		for(int iteration = 0; iteration < atoi(argv[3]) ;iteration++){
			v = random_select(s,bit_len);
			int f2 = Evalute(v,bit_len);
			if(f2 > f1){
				s = v;
				f1 = f2;
			}
			file << "iteration = " << iteration << " : ";
			display(s,file);
			file << ", the # of 1 is " << f1 << endl;
		}
	}
	return 0;
}
