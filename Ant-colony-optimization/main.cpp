#include "ant.h"

using namespace std;

int main(){
    srand(time(NULL));
    int ant_number = 50;
    int data_number = 51;
    double Q = 5.0;
    double rho = 0.8;
    double alpha = .4;
    double beta = 4.0;
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
