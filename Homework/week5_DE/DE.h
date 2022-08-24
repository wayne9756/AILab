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
		void set_position(valarray<double>);
		valarray<double> get_position();
		void set_ans(double);
		double get_ans();
	private:
		valarray<double> position;//[-32,32]
};

class Swarm{
	public:
		Swarm(){};
		Swarm(int,int);
		int size()const;
		valarray<double> mutation();//generate donor vector
		valarray<double> crossover();
		void selection();
		void set_ans(double);
		double get_ans();
		vector<Particle> indiviual;
	private:
		valarray<double> target;//save the best answer array
}
