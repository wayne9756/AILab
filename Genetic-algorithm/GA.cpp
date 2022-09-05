#include "GA.h"

using namespace std;

Indiviual::Indiviual(int n):bit_len(n),bits(n){
	for(int i = 0; i < n; i++)
		bits[i] = rand()%2;
}

void display(Indiviual &vec,int bit_len){
	for(int i = 0; i < bit_len;i++)
		cout << vec.bits[i];
	cout << endl;
}

int bestFitness(int best,  const Group& group){
	for(unsigned int i = 0; i < group.size()-1; i++){
		best = max(best,max(group[i].fitness(),group[i+1].fitness()));
	}
	return best;
}

/*
void selection(Group &vec){ //Roulette
	Group temp;
	int group_size = vec.size();
	int sum  = 0;
	for(int i = 0; i < group_size; i++)
	 	sum += vec[i].fitness();
	for(int i = 0; i < group_size; i++)
		vec[i].probability = (float)vec[i].fitness()/sum;
	for(int i = rand()%group_size, j = 0;j < 10 ; i++){
		float r = (float)rand()/RAND_MAX;
		if(r >= vec[i].probability ){
			temp.push_back(vec[i]);
			vec[i].probability = 0;
			j++;
		};//return the ith Indiviual
		i %= group_size-1;
	}
	vec = temp;
}*/

void selection(Group &vec){//compete
	Group temp;
	int group_size = vec.size();
	int sum  = 0;
	for(int i = 0; i < group_size; i++)
	 	sum += vec[i].fitness();
	for(int i = 0; i < group_size; i++)
		vec[i].probability = (float)vec[i].fitness()/sum;
	sort(vec.begin(),vec.end(),std::greater<Indiviual>());
	vec.erase(vec.begin()+10,vec.end());
}

bool Indiviual::operator>(const Indiviual &right)const{
	if((*this).probability <= right.probability)return false;
	return true;
}

void crossover(Group &group, int n){//return a new Indiviual,i.e. their childern. and which one is father or mom doesn't matter
	int group_size = group.size();
	int times = 0;
	while(times < 10){
		int i = rand()%group_size;
		int j = rand()%group_size;
		if(i == j)continue;
		int rear = (rand()%n)+1;//rear at least 1;
		int front = rand()%(rear);//so that front < rear;
		Indiviual temp(group[i]);
		for(int k = front; k < rear; k++){
			temp.bits[k] = group[j].bits[k];
		}
		group.push_back(temp);
		times++;
	}
}


Group mutation(Group &group, int n){
	int group_size = group.size();
	for(int i = 0; i < group_size; i++){
		float r = (float)rand()/RAND_MAX;
		int k = rand()%n;
		if(r < mutation_rate){
			group[i].bits[k] ^= 1;
		}
	}
	return group;
}

int Indiviual::fitness()const{
	int sum = 0;
	for(int i = 0; i < bit_len; i++)
		sum += bits[i];
	return sum;
}
