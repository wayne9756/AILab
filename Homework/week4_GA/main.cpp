#include"GA.h"
#include<fstream>
#include<unistd.h>

using namespace std;

inline int max(int a, int b){return (a>b?a:b);}

int main(int argc, char *argv[]){
	srand(time(NULL));
	const int bit_len = atoi(argv[1]);
	const int group_size = atoi(argv[2]);
	const int target_fitness = bit_len;
	Group group,new_group;
	//fstream file;
	//file.open("output.txt",ios::out);
    group.reserve(1000);new_group.reserve(1000);
	for(int i = 0; i < group_size; i++)
		group.push_back(Indiviual(bit_len));
	int best_fitness = 0;
	int iteration = 0;
	while(best_fitness != target_fitness){
		selection(group);//天擇
		crossover(group,bit_len);//交配
		new_group = mutation(group,bit_len);//突變
		group = Group(new_group);//進化
		best_fitness = bestFitness(best_fitness,new_group);
		iteration++;
        cout << iteration  << " " << best_fitness << endl;
	}
	return 0;
}
