#include "ant.h"

using namespace std;

bool terminate(){
    return false;
}

//-------------class Graph-----------------//
Graph::Graph(string dataname,int number,int ants_number):data_number(number),ant_number(ants_number),data(data_number),pheromone(data_number,vector<double> (data_number,0)),distance(data_number,vector<double> (data_number,0)){
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
        data[i].x = (stoi(x_temp));
        data[i].y = (stoi(y_temp));
        i++;
        }
    }

    for(int i = 0; i < data_number; i++)//Initialize distance e.g:distance[i][j] = distance[j][i] = the distance between i and j.
        for(int j = i; j < data_number; j++)
            distance[j][i] = distance[i][j] = calDistance(i,j);
    
    for(int i = 0; i < ant_number; i++)//Initialize the ant vector.
        ants.push_back(Ant(0));
    

    for(int i = 0; i < data_number; i++)//Initialize the table of pheromone.
        for(int j = i+1; j < data_number; j++)
            pheromone[j][i] = pheromone[i][j] = (double)sumOfAnts(i,j)/((data_number-1) * calDistance(i,j));
}

double Graph::calDistance(int v1, int v2)const{
    int x_v1 = data[v1].x, y_v1 = data[v1].y, x_v2 = data[v2].x, y_v2 = data[v2].y;
    return (double)sqrt(pow(abs(x_v1-x_v2),2) + pow(abs(y_v1-y_v2),2));
}

void Graph::updatePheromone(){
    double sum_length = 0.0;
    for(int i = 0; i < data_number; i++){
        for(int j = i+1; j < data_number; j++){
            for(int k = 0; k < ant_number; k++){
                int pre_location = ants[k].pre_location;
                int now_location = ants[k].now_location;
                if((pre_location == i and now_location == j) or (pre_location == j and now_location == i))
                    sum_length += (double)1/ants[k].length;
            }
            pheromone[j][i] = pheromone[i][j] = (double)(1-evaporation_rate)*pheromone[i][j] + (double)Q*sum_length;
        }
    }
}

int Graph::sumOfAnts(int i, int j)const{
    int sum = 0;
    for(int k = 0; k < ant_number; k++)
        if(ants[k].get_location() == i or ants[k].get_location() == j)
            ++sum;
    return sum;
}

void Graph::goNextVertex(){
    double alpha = 1.0;
    double beta = 3.0;
    vector< vector<double> > probability(ant_number, vector<double> (data_number,0));
    for(int k = 0; k < ant_number; k++){
        int now_location = ants[k].now_location;
        int step = ants[k].step;
        for(int j = 0; j < data_number; j++){
            if(ants[k].visited[j] == 0){
            double sum = 0.0;
                for(int s = 0; s < data_number; ++s){
                if(ants[k].visited[s] == 0)//Not visited yet.
                    sum += (double)pow(pheromone[now_location][s],alpha) * pow((double)1/distance[now_location][s],beta);//Sum is the total pheromone
                }
                probability[k][j] = (double)pow(pheromone[now_location][j],alpha) * pow((double)1/distance[now_location][j],beta)/sum;
            }
            else
                probability[k][j] = 0;
        }
        double rnd = (double)rand()/(RAND_MAX+1.0);
        double offset = 0.0;
        for(int i = 0; i < data_number; i++){
            offset += probability[k][i];
            if(rnd < offset){
                ants[k].step+=1;
                ants[k].pre_location = now_location;
                ants[k].now_location = i;
                ants[k].length = (double)distance[ants[k].pre_location][ants[k].now_location];
                ants[k].visited[ants[k].now_location] = 1;
                ants[k].path[ants[k].step] = ants[k].now_location;
                ants[k].sum_length += ants[k].length;
                break;
            }
        }
    }
}

bool Graph::terminate()const{
    for(int i = 0; i < data_number; i++)
        if(ants[i].visited.all())return true;
    return false;
}

void Graph::TSP()const{
    for(int i = 0; i < ant_number; i++){
        cout << "DISTANCE = " << ants[i].sum_length << endl;
    }
}

//---------------class Ant------------------//

Ant::Ant(int position):data_number(51),path(data_number),pre_location(position),now_location(position),step(0),length(0),sum_length(0){
    visited[now_location] = 1;
    path[step] = now_location;
    
}

int Ant::get_location()const{
    return now_location;
}


