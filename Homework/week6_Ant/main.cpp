#include "ant.h"

using namespace std;

int main(){
    int ant_number = 100;
    int data_number = 51;
    Graph graph = Graph("data.txt",data_number,ant_number);//Graph會長螞蟻
    graph.goNextVertex();
    graph.updatePheromone();
    return 0;
}
