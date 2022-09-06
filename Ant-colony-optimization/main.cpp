#include "ant.h"

using namespace std;

int main(){
    srand(time(NULL));
    int ant_number = 50;
    int data_number = 51;
    double Q = 2.0;
    double rho = 0.7;
    double alpha = .5;
    double beta = 3.0;
    Graph graph = Graph("data.txt",data_number,ant_number,Q,rho,alpha,beta);//Graph會長螞蟻
    while(!graph.terminate()){
        graph.goNextVertex();
        graph.twoOptimization();//optional
        graph.updatePheromone();
    }
    //graph.tsp();//output
    graph.f_tsp();
    return 0;
}
