#include "pso.h"

using namespace std;

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

//=============class Particle==============//
Particle::Particle(int n):position(n),velocity(n),p_best(n,0.0){
	for(int i = 0; i < n; i++){
		position[i] = (double)(X_MAX-X_MIN)*rand()/(RAND_MAX+1.0)+X_MIN;//inital position
		velocity[i] = (double)V_MAX*rand()/(RAND_MAX+1.0);//inital velocity
	}
}

void Particle::set_pbest(valarray<double> p){
	p_best = p;
}

void Particle::set_position(valarray<double> p){
	position = p;
}

void Particle::set_velocity(valarray<double> p){
	velocity = p;
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

//==============class Swarm=================//
Swarm::Swarm(int numbers, int dimension){
	for(int i = 0; i < numbers; i++)
		particles.push_back(Particle(dimension));
}

int Swarm::size()const{
	return particles.size();
}
 
void Swarm::update_velocity(){
	int size = particles.size();
	double  phi1, phi2;
	for(int i = 0; i < size; i++){
		valarray<double> vel = particles[i].get_velocity();
		valarray<double> pos = particles[i].get_position();
		valarray<double> p_best = particles[i].get_pbest();
		phi1 = (double)rand()/(RAND_MAX+1.0);
		phi2 = (double)rand()/(RAND_MAX+1.0);
		particles[i].set_velocity(INERTIA_WEIGHT*vel + LEARNING_RATE1*phi1*(p_best-pos) + LEARNING_RATE2*phi2*(g_best-pos));
	}
}

void Swarm::update_position(){
	int size = particles.size();
	for(int i = 0; i < size; i++){
		valarray<double> pos = particles[i].get_position();
		valarray<double> vel = particles[i].get_velocity();
		valarray<double> new_pos = pos + vel;
		for(int i = 0; i < size; i++){
			if(new_pos[i] > X_MAX || new_pos[i] < X_MIN)
				new_pos[i] = (double)(X_MAX-X_MIN)*rand()/(RAND_MAX+1.0)+X_MIN;//if x > X_MAX or x < X_MIN -> randomly generate a new value.
		}
		particles[i].set_position(new_pos);//update the position through the formula
	}
}

valarray<double> Swarm::get_gbest()const{
	return g_best;
}

void Swarm::set_ans(double ans){
	answer = ans;
}

void Swarm::set_gbest(valarray<double> p){
	g_best = p;
}

double Swarm::get_ans(){
	return answer;
}

