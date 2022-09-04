#include "ant.h"

using namespace std;

double path_length(vector<int> &path, vector< vector<double> > &table){
    double sum_distance = 0.0;
        for(int i = 0; i < (int)path.size()-1; i++){
            sum_distance += table[path[i]][path[i+1]];
        }
        return sum_distance;
}

vector<int> twoOptSwap(vector<int> path, int i, int j){
    reverse(path.begin()+i,path.begin()+j);   
    return path;
}

bool myCompare(const Ant &left, const Ant &right){
    return left.get_sum_length() < right.get_sum_length();
}

//-------------class Graph-----------------//
Graph::Graph(string dataname,int number,int ants_number,double Q,double rho,double alpha, double beta):data_number(number),ant_number(ants_number),Q(Q),evaporation_rate(rho),alpha(alpha),beta(beta),ants(ants_number,Ant(data_number)),data(data_number),pheromone(data_number,vector<double> (data_number,0)),distance(data_number,vector<double> (data_number,0)){
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
            distance[j][i] = distance[i][j] = cal_distance(i,j);
    
    for(int i = 0; i < data_number; i++)//Initialize the table of pheromone.
        for(int j = i+1; j < data_number; j++)
            pheromone[j][i] = pheromone[i][j] = (double)ant_number/((data_number-1) * distance[i][j]);
}

double Graph::cal_distance(int v1, int v2)const{
    int x_v1 = data[v1].x, y_v1 = data[v1].y, x_v2 = data[v2].x, y_v2 = data[v2].y;
    return (double)sqrt(pow(abs(x_v1-x_v2),2) + pow(abs(y_v1-y_v2),2));
}

void Graph::updatePheromone(){
    double sum_length = 0.0;
    for(int i = 0; i < data_number; i++){
        for(int j = i+1; j < data_number; j++){
            for(int k = 0; k < ant_number; k++){
                Ant &ant = ants[k];
                int pre_location = ant.get_location(1);
                int now_location = ant.get_location();
                if((pre_location == i and now_location == j) or (pre_location == j and now_location == i))
                    sum_length += (double)1/ant.get_length();
            }
            pheromone[j][i] = pheromone[i][j] = (double)(1-evaporation_rate)*pheromone[i][j] + (double)Q*sum_length;
        }
    }
}

void Graph::goNextVertex(){
    vector< vector<double> > probability(ant_number, vector<double> (data_number,0));
    for(int k = 0; k < ant_number; k++){
        Ant &ant = ants[k];
        int now_location = ant.get_location();
        for(int j = 0; j < data_number; j++){
            if(!ant.visit(j)){//If city j not visit yet
            double sum_not_visited = 0.0;
                for(int s = 0; s < data_number; ++s){
                if(!ant.visit(s))//If city s not visit yet.
                    sum_not_visited += (double)pow(pheromone[now_location][s],alpha) * pow((double)1/distance[now_location][s],beta);//Sum is the total pheromone
                }
                probability[k][j] = (double)pow(pheromone[now_location][j],alpha) * pow((double)1/distance[now_location][j],beta)/sum_not_visited;//Update the pheromone table.
            }
            else
                probability[k][j] = 0;//If j city was visited.
        }
        double rnd = (double)rand()/(RAND_MAX+1.0);
        double offset = 0.0;
        for(int i = 0; i < data_number; i++){
            offset += probability[k][i];
            if(rnd < offset){
                ant.go_ahead(i,distance[ant.get_location()][i]);
                break;
            }
        }
    }
    ++t;
}

void Graph::twoOptimization(){
    if( t > 4 )
    for(int k = 0; k < ant_number; k++){
        Ant &ant = ants[k];
        bool improved = true;
        while(improved){
            improved = false;
            for(int i = 1; i < t-1; i++){
                for(int j = i+1; j < t; j++){
                    vector<int> new_path = twoOptSwap(ant.path,i,j);
                    if(ant.get_sum_length() > path_length(new_path,distance)){
                        ant.path = new_path;
                        ant.sum_length = path_length(new_path,distance);
                        improved = true;
                    }
                }
            }
        }
    }
}

bool Graph::terminate()const{
    for(int i = 0; i < data_number; i++)
        if(ants[i].finish())return true;
    return false;
}

void Graph::tsp(){
    sort(ants.begin(),ants.end(),myCompare);
    for(int i = 0; i < 5; i++){
        const Ant &ant = ants[i];
        cout << "DISTANCE = " << ant.get_sum_length() << endl;
        cout << "Ant " << i << "th's path = "; 
        for(int j = 0; j < data_number; j++)
            cout << ant.path[j]+1 << "-> ";
        cout << endl;
    }
}

//---------------class Ant------------------//

Ant::Ant(int data_number):path(data_number),sum_length(0),step(0),length(0){
    visited[step] = 1;
    path[step] = 0;
}

void Ant::go_ahead(int position, double distance){
    ++step;
    path[step] = position;
    length = distance;
    sum_length += length; 
    visited[path[step]] = true;
}


