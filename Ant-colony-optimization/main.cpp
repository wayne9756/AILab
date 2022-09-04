#include "ant.h"

using namespace std;

int main(){
    srand(time(NULL));
    int ant_number = 80;
    int data_number = 51;
    Graph graph = Graph("data.txt",data_number,ant_number);//Graph會長螞蟻
    while(!graph.terminate()){
        graph.goNextVertex();
        graph.updatePheromone();
    }
    graph.TSP();
    return 0;
}
