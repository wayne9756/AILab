#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

inline int evalute(vector<int> &x, int n ){
	int sum = 0;
	for(int i = 0; i < n ; i++)
		sum += x[i];
	return sum;
}

vector<int> init(vector<int> &x, int n){
	for(int i = 0; i < n ; i++)
		x[i] = rand()%2;
	return x;
}

inline vector<int> random_select(vector<int> x, int n){
	int position = rand()%n;
	x[position] ^= 1;//取反
	return x;
}

double acceptance(int n, int o, float T){
	return exp((n-o)/T);
}

inline void display(vector<int> &x, fstream &file){
	for(auto n:x)
		file << n;
}

int main(int argc, char *argv[]){ // ./onemax bitlen run
	srand(time(0));
	int bit_len = atoi(argv[1]);//argument 1 is bit_len
	fstream file;
	file.open("one_max.txt",ios::out);
	for(int run = 0 ;run < atoi(argv[3]); run++){//2 is run
		int iteration = atoi(argv[2]);
		int i = 0;
		float T = 100;
		vector<int> current_state(bit_len,0);//initicial vector
		int current_energy = evalute(current_state, bit_len);
		vector<int> new_state;
		while( i < iteration && T > 0){
			new_state = random_select(current_state, bit_len);
			int new_energy = evalute(new_state, bit_len);
			double P = acceptance(new_energy, current_energy,T = 0.98*T);//P會趨近0有一定的機率接受不好的解
			float x = (float)rand()/RAND_MAX;
			if(x <= P){
				current_state = new_state;
				current_energy = new_energy;
			}
			++i;
			file << "iteration = " << i << ":";
			display(current_state, file);
			file << ", the # of 1 is " << current_energy << ", rand()/RAND_MAX = " << x << ", P = " << P << endl;
		}
	}
	return 0;
}
