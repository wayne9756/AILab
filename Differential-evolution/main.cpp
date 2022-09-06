#include "DE.h"
#include<fstream>
using namespace std;

int main(int argc, char* argv[]){
    srand(time(0)*1000);
    int number = atoi(argv[1]);//the number of particle.
    int dimension = atoi(argv[2]);//the number of dimension.
    int run = atoi(argv[3]);
    int iteration = dimension * 1000;
    fstream file;
    file.open("output.txt",ios::out);
    vector<double> output(iteration);
//--------------------------------------------------------------------------//
    for(int k = 0; k < run; k++){
        Swarm population = Swarm(number,dimension);
        for(int i = 0; i < iteration; i++){
            population.mutation();
            population.crossover();
            population.selection();
            output[i] += population.get_answer();
            //cout << "the ackley output = " << population.get_answer() << endl;
        }
    }
        for(int i = 0; i < iteration; i++)
            file << i << " " << (double)output[i]/run << endl;
//---------------------------output the best answer--------------------------//
    //population.output();
}
