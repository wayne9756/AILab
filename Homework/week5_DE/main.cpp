#include "DE.h"

using namespace std;

int main(int argc, char* argv[]){
    srand(time(0));
	int number = atoi(argv[1]);//the number of particle.
    int dimension = atoi(argv[2]);//the number of dimension.
    int iteration = dimension * 1000;
	Swarm population = Swarm(number,dimension);
	for(int i = 0; i < iteration; i++){
		population.mutation();
		population.crossover();
		population.selection();
        cout << "the ackley output = " << population.get_answer() << endl;
	}
//---------------------------output the best answer--------------------------//
    population.output();
}
