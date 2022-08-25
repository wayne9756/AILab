#include "pso.h"

using namespace std;

extern d;//Dimension define at main.cpp

void ackleyFunc(Swarm &swarm, int dimension){//answer & g_best = min(p_best)
	int n = swarm.size();
	for(int i = 0; i < n; i++){
		Particle &particle = swarm.particles[i];
		double answer = -20 * exp(-0.2*sqrt((double)sumOfSquare(particle,dimension))) - exp(sumOfCos(particle,dimension)) + 20 + exp(1);
		if(answer <= particle.get_ans()){
			particle.set_pbest(particle.get_position());// update every particles's p_best
			particle.set_ans(answer);//update the best answer;
			if(answer <= swarm.get_ans()){
				swarm.set_ans(answer);
				swarm.set_gbest(particle.get_position());// update the swarm's g_best
			}
		}
	}
}

double sumOfSquare(Particle &particle, int d){
	double sum = 0;
	for(int i = 0; i < d; i++){
		sum += (particle.get_position() * particle.get_position()).sum(); 
	}
	return (double)sum/d;
}

double sumOfCos(Particle &particle, int d){
	double sum = 0;
	for(int i = 0; i < d; i++){
		sum += cos((double)2*PI*(particle.get_position()).sum());
	}
	return (double)sum/d;
}	

void randPick(int &r1, int &r2, int &r3, int size){
	while(!(bool)((r1 = rand()%size)^(r2 = rand()%size)))r3 = rand()%size;
	while((r3 == r1)||(r3 == r2))r3 = rand()%size;
}

//=============Class Particle==============//

Particle::Particle(int n):position(n),velocity(n),p_best(n,0.0){
	for(int i = 0; i < n; i++){
		position[i] = (double)(X_MAX-X_MIN)*rand()/(RAND_MAX+1.0)+X_MIN;//inital position
		velocity[i] = (double)V_MAX*rand()/(RAND_MAX+1.0);//inital velocity
	}
}

void Particle::set_ans(double ans){
	answer = ans;
}

double Particle::get_ans(){
	return answer;
}

valarray<double> Particle::get_pbest()const{
	return p_best;
}

valarray<double> Particle::get_position()const{
	return position;
}

valarray<double> Particle::get_velocity()const{
	return velocity;
}

//==============Class Swarm=================//
Swarm::Swarm(int numbers, int dimension){
	for(int i = 0; i < numbers; i++)
		particles.push_back(Particle(dimension));
}

int Swarm::size()const{
	return particles.size();
}
 
void Swarm::mutation(){
	int size = indiviual.size();
	int r1, r2, r3;
	for(int i = 0; i < size; ++i){
		pickRand(r1,r2,r3);//this make r1 != r2 != r3;

	}
}

void Swarm::crossover(){
}

void Swarm::selection(){

}

void Swarm::set_ans(double ans){
	answer = ans;
}

double Swarm::get_ans(){
	return answer;
}

