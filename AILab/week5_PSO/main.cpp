#include "pso.h"

using namespace std;

int main(int argc, char* argv[]){
	srand(time(0));
	int dimension = 10;
	int n = 10;
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
