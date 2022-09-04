#include "ant.h"

using namespace std;

int main(){
    srand(time(NULL));
    int ant_number = 40;
    int data_number = 51;
    double Q = 2.0;
    double rho = 0.8;
    double alpha = 0.8;
    double beta = 5.0;
    Graph graph = Graph("data.txt",data_number,ant_number,Q,rho,alpha,beta);//Graph會長螞蟻
    while(!graph.terminate()){
        graph.goNextVertex();
        graph.twoOptimization();
        graph.updatePheromone();
    }
    graph.tsp();
    return 0;
}
