#include<iostream>
#include<vector>
#include<ctime>
#include<cmath>
#include<cfloat>
#include<valarray>

/* Population have two parameters, one is population size another is the generation.
 * The generation gradually increase after finishing a iteration.
 * The population must have difference in every generation.
 */ 

using namespace std;

class Particle;
class Swarm;

const double mutation_factor = 0.9;//F
const double crossover_rate = 0.6;//CR
const double x_max = 32.0;
const double x_min = -32.0;
const double PI = 3.14159;


void randomPick(int &, int &, int&, int, int);
double ackleyFunc(valarray<double>, int);//Automatically update the value of p_best for each particles and g_best.
double sumOfSquare(valarray<double>, int);
double sumOfCos(valarray<double>, int);

class Particle{
	public:
		Particle(int);
		void set_target_vector(valarray<double>);
        void set_donor_vector(valarray<double>);
		valarray<double>& get_target_vector();
        valarray<double>& get_donor_vector();
        valarray<double>& get_trail_vector();
	private:
        int dimension;
		valarray<double> target_vector;//[-32,32]
        valarray<double> donor_vector;
        valarray<double> trial_vector;
};

class Swarm{
	public:
		Swarm(){};
		Swarm(int,int);
		void mutation();//generate donor vector
		void crossover();
		void selection();
        void output();
        double get_answer()const;
        valarray<double> get_target()const;
		valarray<double> target;//save the best answer array
	private:
        int size;
        int dimension;
        double answer;
		vector<Particle> particles;
};


