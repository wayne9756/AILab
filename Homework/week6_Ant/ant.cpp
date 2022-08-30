#include "ant.h"

using namespace std;
//-------------class Graph-----------------//
Graph::Graph(string dataname):x(51),y(51){
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

//---------------class Ant------------------//










