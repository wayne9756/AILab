#include"GA.h"
#include<fstream>
#include<unistd.h>

using namespace std;

int max(int a, int b){return (a>b?a:b);}

int main(int argc, char *argv[]){
	srand(time(NULL));
    fstream file;
    file.open("output.txt",ios::out);
	const int bit_len = atoi(argv[1]);
	const int group_size = atoi(argv[2]);
	const int iteration = atoi(argv[3]);
    const int run = atoi(argv[4]);
	//const int target_fitness = bit_len;
    vector<int> output(iteration);
    for(int k = 0; k < run; k++){
        int best_fitness = 0;
        Group group,new_group;
        for(int i = 0; i < group_size; i++)
            group.push_back(Indiviual(bit_len));
            int i = 0;
            while(i != iteration){
                selection(group);//天擇
                crossover(group,bit_len);//交配
                new_group = mutation(group,bit_len);//突變
                group = new_group;//進化
                best_fitness = bestFitness(best_fitness,new_group);
                output[i] += best_fitness;
                //cout << best_fitness << endl;
                i++;
            }
    }
    for(int i = 0; i < iteration; i++) 
        file << i << " " << (double)output[i]/run << endl;
	return 0;
}
