#include <iostream>
#include <deque>
#include <fstream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

inline int Evalute(vector<int> &x, int n ){
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

int binaryToDecimal(vector<int> &x, int n){
	int sum = 0;
	for(int i = 0; i < n ; i++)
		sum += (x[i] * pow(2,n-i-1));
	return abs(sum);
}

inline vector<int> tabu_select(vector<int> x, vector<int> &tabu_list, int n){
	int position = rand()%n;
	x[position] ^= 1;//取反
	int x_b2d = binaryToDecimal(x,n);
	for(int i = 0; i < tabu_list.size(); i++)
		if(x_b2d == tabu_list[i]){
			position = rand()%n;
			x[position] ^= 1;
			x_b2d = binaryToDecimal(x,n);
			i = 0;//make sure there are not any value is same as x_b2d
		}
	return x;
}

inline void display(vector<int> &x, fstream &file ){
	file << "current_state = " ;
	for(auto n:x)
		file << n;
}

int main(int argc, char *argv[]){// ./a.out bit_len run
	srand(time(0));
	int bit_len = atoi(argv[1]);
	fstream file;
	int tabu_len = 10;//the size of tabu_list
	int i = 0;
	vector<int> tabu_list(tabu_len);
	file.open("onemax.txt",ios::out);
	for(int run = 0 ;run < atoi(argv[3]); run++){
		int iteration = 0;
		vector<int> current_state(bit_len,0);//initicial vector
		int current_energy = Evalute(current_state, bit_len);
		vector<int> new_state;
		while(iteration < atoi(argv[2])){
			i = i%tabu_len;//it makes tabu_list FIFO
			new_state = tabu_select(current_state, tabu_list, bit_len);//pick a new state and not exist in tabu_list
			int new_energy = Evalute(new_state, bit_len);
			tabu_list[i] =  binaryToDecimal(new_state, bit_len);//add to tabu_list
			if(new_energy > current_energy){
				current_state = new_state;
				current_energy = new_energy;
			}
			display(current_state, file);
			file << ", iteration = " << iteration << endl;
			++iteration;
			++i;
		}
	}
	return 0;
}
