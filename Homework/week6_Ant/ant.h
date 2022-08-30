#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<ctime>
#include<cmath>

using namespace std;

const double Q = 5;
const double evaporation_rate = 0.5;


class Ant{
    public:
        Ant(){};
        Ant(int);
        int get_location()const;
        vector<int> path;
        vector<bool> visited;
        int location;
    private:
        int data_number;
        int length;
};

class Graph{
    public:
        Graph(string,int, int);//This string is the dataset
        void updatePheromone();
        double calDistance(int, int)const;
        void goNextVertex();//Return next vertex.
        int sumOfAnts(int, int)const;
    private:
        int data_number;
        int ant_number;
        vector<int> x;
        vector<int> y;
        vector<Ant> ants;
        vector<vector <double> >pheromone;
        vector<vector <double> >distance;
};

