#include "DE.h"

using namespace std;

double ackleyFunc(valarray<double> array, int dimension){//answer & g_best = min(p_best)
    double answer = (double) -20.0 * exp(-0.2*sqrt((double)sumOfSquare(array,dimension))) - exp(sumOfCos(array,dimension)) + 20.0 + exp(1);
    return answer;
}


double sumOfSquare(valarray<double> array,int dimension){
	double sum = 0;
		sum += (array * array).sum(); 
	return (double)sum/dimension;
}

double sumOfCos(valarray<double> array, int dimension){
	double sum = 0;
	for(int i = 0; i < dimension; i++){
		sum += cos((double) 2 * PI * array[i]);
	}
	return (double)sum/dimension;
}	

void randomPick(int &r1, int &r2, int &r3, int size){
    r3 = rand()%size;	
    while((r1 = rand()%size) == (r2 = rand()%size));
	while((r3 == r1)||(r3 == r2))r3 = rand()%size;
}

//=============Class Particle==============//

Particle::Particle(int n):dimension(n),target_vector(dimension),donor_vector(dimension),trial_vector(dimension){
	for(int i = 0; i < dimension; i++){
		target_vector[i] = (double)(x_max-x_min)*rand()/(RAND_MAX+1.0)+x_min;//inital target_vector
	}
}

void Particle::set_target_vector(valarray<double> array){
    target_vector = array;
}

void Particle::set_donor_vector(valarray<double> array){
    donor_vector = array;
}

void Particle::set_trial_vector(int i, double value){
    trial_vector[i] = value;

}

void Particle::set_donor_vector(int i, double value){
    donor_vector[i] = value;
}

valarray<double>& Particle::get_target_vector(){
    return target_vector;
}

valarray<double>& Particle::get_donor_vector(){
    return donor_vector;
}

valarray<double>& Particle::get_trail_vector(){
    return trial_vector;
}

//==============Class Swarm=================//
Swarm::Swarm(int numbers, int dimensions):answer(RAND_MAX),size(numbers),dimension(dimensions){
	for(int i = 0; i < numbers; i++)
		particles.push_back(Particle(dimension));
}

void Swarm::mutation(){
	int r1, r2, r3;
	for(int i = 0; i < size; ++i){
		randomPick(r1,r2,r3,size);//this make r1 != r2 != r3
        Particle &pi = particles[i];//this method will not spend any memory
        Particle &pr1 = particles[r1];
        Particle &pr2 = particles[r2];
        Particle &pr3 = particles[r3];
        pi.set_donor_vector(pr1.get_target_vector() + mutation_factor * (pr2.get_target_vector() - pr3.get_target_vector()));
        for(int j = 0; j < dimension; j++){
            if(pi.get_donor_vector()[j] >= x_max or pi.get_donor_vector()[j] <= x_min){
                double rand_num = (double)(x_max-x_min)*rand()/(RAND_MAX+1.0)+x_min;
                pi.get_donor_vector()[j] = rand_num;
            }
        }
    }
}

void Swarm::crossover(){
    for(int i = 0; i < size; i++){
        Particle &pi = particles[i];
        int I = rand()%dimension;
        for(int j = 0; j < dimension; j++){
            pi.get_trail_vector()[j] = (((double)rand()/(RAND_MAX+1.0) <= crossover_rate or j == I)?pi.get_donor_vector()[j]:pi.get_target_vector()[j]);
        }
    }
}

void Swarm::selection(){
        for(int i = 0; i < size; i++){
            Particle &pi = particles[i];
            if(ackleyFunc(pi.get_trail_vector(),dimension) <= ackleyFunc(pi.get_target_vector(),dimension)){
                pi.set_target_vector(pi.get_trail_vector());
            }
            if(answer >= ackleyFunc(pi.get_target_vector(),dimension)){
                answer = ackleyFunc(pi.get_target_vector(),dimension);
                target = pi.get_target_vector();
            }
        }
}

valarray<double> Swarm::get_target(){
    return target;
}

double Swarm::get_answer(){
    return answer;
}

void Swarm::output(){
    cout << "the best answer (x1,x3,....,x" << dimension << ") = (";
    for(int i = 0; i < dimension; i++){
        cout << target[i] ;
        if(i != dimension -1) cout << ", ";
    }
    cout << ")" << endl;
}
