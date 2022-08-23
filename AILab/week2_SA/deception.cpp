#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

inline int Evalute(vector<int> &x, int n ){
	int sum = 0;
	for(int i = 0; i < n ; i++)
		sum += (x[i] * pow(2,n-i-1));
	return (abs(sum-pow(2,n-2)));
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

int main(int argc, char *argv[]){
	srand(time(0));
	int bit_len = atoi(argv[1]);//改成10
	fstream file;
	file.open("deception.txt",ios::out);
	for(int run = 0 ;run < atoi(argv[2]); run++){
		int iteration = 0;
		float T = 100;//init temp
		vector<int> current_state(bit_len,0);//initicial vector
		int current_energy = Evalute(current_state, bit_len);
		vector<int> new_state;
		while(iteration < 1000 && T > 0){
			new_state = random_select(current_state, bit_len);
			int new_energy = Evalute(new_state, bit_len );
			double P = acceptance(new_energy, current_energy,T = 0.98*T);//P會趨近0
			float x = (float)rand()/RAND_MAX;
			if(x < P){
				current_state = new_state;
				current_energy = new_energy;
			}
			++iteration;
		file << "iteration = " << iteration << ":";
		display(current_state, file);
		file << ", f(current_state) = " << current_energy << ", rand()/RAND_MAX = " << x << ", P = " << P << endl;
		}
	}
	return 0;
}
