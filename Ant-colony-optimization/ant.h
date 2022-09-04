#include<iostream>
#include<fstream>
#include<string>
#include<bitset>
#include<vector>
#include<ctime>
#include<cmath>

using namespace std;

const double Q = 3;
const double evaporation_rate = 0.7;

typedef struct point{
    int x;
    int y;
}Data;

class Ant{
    private:
        int data_number;//
    public:
        Ant(){};
        Ant(int);
        vector<int> path;
        bitset<(size_t) 51> visited; 
        int get_location()const;
        int pre_location;
        int now_location;
        int step;//This parameter is the number of step.k
        double length;//This parameter is the path length of ant.
        double sum_length;
};

class Graph{
    public:
        Graph(string,int, int);//This string is the dataset
        void updatePheromone();
        double calDistance(int, int)const;
        void goNextVertex();//Return next vertex.
        int sumOfAnts(int, int)const;
        bool terminate()const;
        void TSP()const;
    private:
        int data_number;
        int ant_number;
        vector<Ant> ants;
        vector<Data> data;//Testing set story in this vector
        vector<vector <double> >pheromone;
        vector<vector <double> >distance;
};

