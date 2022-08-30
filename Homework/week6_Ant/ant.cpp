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
    for(int i = 0; i < data_number; i++)
        for(int j = i; j < data_number; j++)
            distance[i][j] = calDistance(i,j);
}

double Graph::calDistance(int v1, int v2)const{
    int x_v1 = x[v1], y_v1 = y[v1], x_v2 = x[v2], y_v2 = y[v2];
    return (double)sqrt(pow(abs(x_v1-x_v2),2) + pow(abs(y_v1-y_v2),2));
    return 0.0;
}

void Graph::updatePheromone(){
    for(int i = 0; i < data_number; i++)
        for(int j = i+1; j < data_number; j++){
            pheromone[j][i] = pheromone[i][j] = sumOfAnts(i,j)/((data_number-1) * calDistance(i,j));
    }
}

int Graph::sumOfAnts(int i, int j)const{
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

void Graph::goNextVertex(){
    int alpha = 1;
    int beta = 1;
    vector< vector<double> > probability(ant_number, vector<double> (data_number,0));
    for(int k = 0; k < ant_number; k++){
        int location = ants[k].location;
        for(int j = 0; j < data_number; j++){
            double sum = 0;
            for(int s = 0; s < data_number; s++){
            if(ants[k].visited[j] == false)
                sum += (double) pow(pheromone[location][j],alpha) + pow((double)1/distance[location][j],beta);
            }
            probability[k][j] = (double)(pow(pheromone[location][j],alpha) + pow(pheromone[location][j],beta))/sum;
        }
        double rnd = rand()/(double)(RAND_MAX+1.0);
        double offset = 0.0;
        for(int i = 0; i < data_number; i++){
            offset += probability[k][i];
            if(rnd < offset){
                ants[k].location = i;
                break;
            }
        }
    }
}

void Graph::updatePheromone(){
    


}



















