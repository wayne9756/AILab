#include<iostream>
#include<vector>
#include<ctime>
#include<cmath>
#include<cfloat>
#include<valarray>

/* position is a vector, length of vector is dimension
 * x is a vector in f(x).
 * g_best is the minmum value of all p_best
 * the target is to minimize the output of f(x) and record the x.
 * x = [-32,32]
 * dimension == the number of particles
 * every particles have their own position initially
 *
*/
using namespace std;

class Particle;
class Swarm;

const double INERTIA_WEIGHT = 0.85;
const double LEARNING_RATE1 = 2;
const double LEARNING_RATE2 = 2;
const double V_MAX = 0.7;
const double PI = 3.14159;
const double X_MAX = 32.0;
const double X_MIN = -32.0;

void ackleyFunc(Swarm&, int);//automatically update the value of p_best for each particles and g_best.
double sumOfSquare(Particle&, int);
double sumOfCos(Particle&, int);

class Particle{
	public:
		Particle(int);
		void set_pbest(valarray<double>);
		void set_position(valarray<double>);
		void set_velocity(valarray<double>);
		void set_ans(double);
		double get_ans();
		valarray<double> get_pbest()const;
		valarray<double> get_position()const;
		valarray<double> get_velocity()const;
	private:
		double answer = 100;
		valarray<double> position;//[-32,32]
		valarray<double> velocity;//
		valarray<double> p_best;
};

class Swarm{
	public:
		Swarm(int,int);
		int size()const;
		void update_position();
		void update_velocity();
		void set_gbest(valarray<double>);
		void set_ans(double);
		double get_ans();
		valarray<double> get_gbest()const;
		vector<Particle> particles;

	private:
		valarray<double> g_best;
		double answer = 100;
};
