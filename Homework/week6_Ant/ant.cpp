#include "ant.h"

using namespace std;
//-------------class Graph-----------------//
Graph::Graph(string dataname,int number,int ants_number):data_number(number),ant_number(ants_number),x(data_number),y(data_number),pheromone(data_number,vector<double> (data_number,0)),distance(data_number,vector<double> (data_number,0)){
    fstream file;
    file.open(dataname,ios::in);
    if(!file){
        cerr << "File is not exist." << endl;
        exit(1);
    }
    int i = 0;
    while(!file.eof()){
        string x_temp,y_temp;
        file >> x_temp;
        file >> x_temp;
        file >> y_temp;
        if(x_temp != "EOF" && y_temp != "EOF"){
        x[i] = (stoi(x_temp));
        y[i] = (stoi(y_temp));
        i++;
        }
    }

    
}

double Graph::distance(int v1, int v2){
    int x_v1 = x[v1], y_v1 = y[v1], x_v2 = x[v2], y_v2 = y[v2];
    cout << x[v1] << " " << x_v2 << " " << y_v1 << " " << y_v2 << endl;
    return (double)sqrt(pow(abs(x_v1-x_v2),2) + pow(abs(y_v1-y_v2),2));
    return 0.0;
}

void Graph::updatePheromone(){
    for(int i = 0; i < data_number; i++)
        for(int j = i; j < data_number; j++)
            pheromone[j][i] = pheromone[i][j] = distance[i][j]/((data_number-1) * distance(i,j));
}

int Graph::sumOfAnts(int i, int j){
    int sum = 0;
    for(int k = 0; k < ant_number; k++)
        if(ants[k].get_location() == i or ants[k].get_location() == j)
            ++sum;
    return sum;
}

int Ant::get_location()const{
    return location;
}

//---------------class Ant------------------//

Ant::Ant(int location):path(data_number,0), visited(data_number,false){
    visited[location] = true;
    path[0] = location;
}

int Ant::nextVertex(){
    int i = rand()%data_number;
    double heuristic_information = (double)1/
    while(visited[i] == true)i = rand()%data_number;
    return i;
}


