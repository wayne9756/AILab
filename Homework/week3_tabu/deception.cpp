#include <vector>
#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <cmath>
using namespace std;

inline int evalute(vector<int> &x, int n){
	int sum = 0;
	for(int i = 0; i < n; i++)
		sum += (x[i] *pow(2,n-i-1));
	return (abs(sum-pow(2,n-2)));
}

vector<int> init(vector<int> &x, int n){
	for(int i = 0; i < n; i++)
		x[i] = rand()%2;
	return x;
	
}

inline vector<int> random_select(vector<int> x, int n){
	int position = rand()%n;
	x[position] ^= 1;
	return x;
}

inline void display(vector<int> &x, fstream &file){
	file << "current_state = " ;
	for(auto n:x)
		file << n;
}

int binaryToDecimal(vector<int> &x, int n){
	int sum = 0;
	for(int i = 0; i < n; i++){
		sum += (x[i] * pow(2,n-i-1));
	}
	return abs(sum);
}

inline vector<int> tabu_select(vector<int> x, vector<int> &tabu_list, int n){
	int position = rand()%n;
	x[position] ^= 1;
	int x_b2d = binaryToDecimal(x,n);
	for(int i = 0; i < tabu_list.size(); i++)
		if(x_b2d == tabu_list[i]){
			position = rand()%n;
			x[position] ^= 1;
			x_b2d = binaryToDecimal(x,n);
			i = 0;
		}
	return x;
}

int main(int argc, char *argv[]){
	srand(time(0));
	int bit_len = atoi(argv[1]);
	fstream file;
	int tabu_len = 10;
	int i = 0;
	vector<int> tabu_list(tabu_len);
	file.open("deception.txt", ios::out);
	for(int run = 0; run < atoi(argv[3]); run++){
		int iteration = 0;
		vector<int> current_state(bit_len,0);
		int current_energy = evalute(current_state, bit_len);
		vector<int> new_state;
		while(iteration < atoi(argv[2])){
			i = i%tabu_len;
			new_state = tabu_select(current_state, tabu_list, bit_len);
			int new_energy = evalute(new_state, bit_len);
			tabu_list[i] = binaryToDecimal(new_state, bit_len);
			if(new_energy > current_energy){
				current_state = new_state;
				current_energy = new_energy;
			}
			display(current_state, file);
			file << "iteration = " << iteration << endl;
			++iteration;
			++i;
		}
		
	}
	return 0;
}




