#include "pso.h"
#include <unistd.h>

using namespace std;

int main(int argc, char* argv[]){
	srand(time(0));
	int n = atoi(argv[1]);
	int dimension = atoi(argv[2]);
    int run = atoi(argv[3]);
	int iteration = dimension*10000;
    fstream file;
    file.open("output.txt",ios::out);
    vector<double> output(iteration);
//---------------------------------------------------//
    for(int k = 0; k < run; k++){
        int i = 0;
        Swarm flocks = Swarm(n,dimension);
        while(i < iteration){
            ackleyFunc(flocks,dimension);
            flocks.update_velocity();
            flocks.update_position();
            output[i] += flocks.get_ans();
            //cout << flocks.get_ans() << endl;
            i++;
        }
    }
//---------------------------------------------------//
        for(int i = 0; i < iteration; i++)
            file << i << " " << (double)output[i]/run << endl;
    /*
        for(int i = 0; i < iteration; i++)
            cout << "the g_best are = " ; 
		for(int i = 0; i < dimension; i++)
            cout << flocks.get_gbest()[i] << "  ";
		cout << endl;
	}
	cout << "iteration = " << iteration << endl;
    */
	return 0;
}
