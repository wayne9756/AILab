#include "ant.h"

using namespace std;

int main(){
    int ant_number = 100;
    Graph x = Graph("data.txt");//make the dataset
    vector<Ant> ant_group(ant_number);
    for(int k = 0; k < ant_number; k++){
        int i = rand()%51;
        ant_group.push_back(Ant(i));
    }
    cout << x.distance(5,2) << endl;
    return 0;
}
