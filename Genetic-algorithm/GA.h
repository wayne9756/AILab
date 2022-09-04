#include<iostream>
#include<cstdlib>
#include<vector>
#include<ctime>
#include<algorithm>

using namespace std;

const float mutation_rate = 0.23;//突變率
const float crossover_rate = 0.75;//交配率

class Indiviual;
typedef vector<Indiviual> Group;

void selection(Group&);//Roulette wheel method.如果當indiviual數變多時扁平化
void crossover(Group&, int);//change randomly by picking a point
void display(Indiviual&,int);
int bestFitness(int, Group&);
Group mutation(Group&, int);//when rand() < 0.1 then mutate

class Indiviual{
	public:
		Indiviual(int);
		Indiviual(){};
		int bit_len;
		vector<int> bits;
		int fitness()const;
		float probability = 0;
		bool operator>(const Indiviual&)const;
};


