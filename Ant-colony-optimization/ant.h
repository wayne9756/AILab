#include<iostream>
#include<algorithm>
#include<fstream>
#include<string>
#include<bitset>
#include<vector>
#include<ctime>
#include<cmath>

using namespace std;
class Ant;
class Graph;

inline double path_length(vector<int>&, vector< vector<double> > &);
inline vector<int> twoOptSwap(vector<int>, int, int);
inline bool myCompare(const Ant &, const Ant &);

typedef struct point{
    int x;
    int y;
}Point;

class Ant{
    public:
        Ant(){};
        Ant(int);
        void go_ahead(int, double);
        int get_location(int i = 0)const{return path[step-i];};
        bool finish()const{return visited.all();};
        bool visit(int i)const{return visited[i];};
        double get_length()const{return length;};
        double get_sum_length()const{return sum_length;};
        vector<int> path;//space(O(data_number))
        double sum_length;
    private:
        int step;//This parameter is the number of step.k
        double length;//This parameter is the path length of ant.
        bitset<(size_t)51> visited; //space(O(data_number))
};

class Graph{
    public:
        Graph(string,int, int, double, double,double,double);//This string is the dataset
        void updatePheromone();
        void goNextVertex();//Return next vertex.
        void twoOptimization();
        void tsp();
        bool terminate()const;
        double cal_distance(int, int)const;
    private:
        int t = 0;
        const int data_number;
        const int ant_number;
        const double Q;
        const double evaporation_rate;//rho
        const double alpha;
        const double beta;
        vector<Ant> ants;
        vector<Point> data;//Testing set story in this vector
        vector<vector <double> >pheromone;//Pheromone table
        vector<vector <double> >distance;//Distance for each city.
};

