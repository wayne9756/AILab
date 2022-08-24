#include "pso.h"

using namespace std;

int main(int argc, char* argv[]){
	srand(time(0));
	int n = atoi(argv[1]);
	int dimension = atoi(argv[2]);
	int iteration = 0;
//---------------------------------------------------//
	Swarm flocks = Swarm(n,dimension);
	while(iteration < dimension * 10000){
		ackleyFunc(flocks,dimension);
		flocks.update_velocity();
		flocks.update_position();
		cout << flocks.get_ans() << endl;
		iteration++;
//---------------------------------------------------//
		cout << "the g_best are = " ; 
		for(int i = 0; i < dimension; i++)
			cout << flocks.get_gbest()[i] << "  ";
		cout << endl;
	}
	cout << "iteration = " << iteration << endl;
	return 0;
}
