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
        Ant();
        Ant(int);
        int nextVertex();//return next vertex.
        void updatePheromone();
    private:
        vector<int> allowed;
        vector<int> visited;
};

class Graph{
    public:
        Graph(string);//this int is the number of vertex.
        double distance(int, int);
    private:
        vector<int> x;
        vector<int> y;
};

