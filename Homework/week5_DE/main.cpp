#include "DE.h"

using namespace std;

int main(){
	int number = 5;
	int dimension = 5;
	Swarm population = Swarm(number,dimension);
	Swarm new_population;
	while(){
		new_population = population.mutation();
		population.crossover(new_population);
		population.selection(new_population);
	}
}
