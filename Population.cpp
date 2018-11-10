#include "Population.hpp"
#include <random>
#include <iostream>
using namespace std;


//CONSTRUCTOR	
	Population::Population(const int nb_alleles, vector<Allele> Pop,int nb_generations, int nb_replicates)
		: nb_alleles(nb_alleles), Pop(Pop), nb_generations(nb_generations), nb_replicates(nb_replicates)
	{}

//CONVESRION METHOD(from frequence to quantity)
	int Population::frequence_to_quantity(double frequence) const{
		return frequence*nb_alleles;
	} 
	
//SETTER	
	void Population::set_new_values(){
		vector<double> average_frequencies(calculate_average_frequency());
		
		for(size_t i(0); i < Pop.size(); ++i){
			Pop[i].set_frequency(average_frequencies[i]);
		}
	}
	
//GETTER	
	vector<double> Population::get_frequencies() const{
		vector<double> result;
		
		for(size_t i(0); i<Pop.size(); ++i){
			result.push_back(Pop[i].get_frequency());
		}
		return result;
	}
	
	
//DISPLAY FUNCTION
	void Population::display_frequencies() const{
		vector<double> pop_frequencies(get_frequencies());
		
		for(size_t i(0); i<pop_frequencies.size(); ++i){
			cout<<"Frequency of allele "<<i<<" : "<< pop_frequencies[i] <<endl;
		}
		cout<<endl;
	}	
	
	
//METHODES TO CALCULATE THE ALLELE FREQUENCY AT THE NEXT GENERATION			
	vector<double> Population::calculate_average_frequency() const{
			vector<vector<double> > frequencies(nb_replicates, vector<double>(nb_alleles));
			double mean(0);
			
			for(size_t i(0); i < nb_replicates; ++i){
					frequencies[i]=calculate_new_frequency();
			}
			
			vector<double> average_frequencies;
			
			for(size_t i(0); i < Pop.size(); ++i){
				mean = 0;
				for(size_t j(0); j < nb_replicates; ++j){
					mean += frequencies[j][i];
				}
				average_frequencies.push_back(mean/nb_replicates);
			}
			return average_frequencies;
	}
	
	
	
	vector<double> Population::calculate_new_frequency() const{
		vector<double> result(multinomial());
		
		for(size_t j(0); j<result.size(); ++j){
			result[j]=result[j]/nb_alleles;
		}
		return result;
	}
	
	
	int Population::binomial(int nb_total, double percentage) const{
		random_device rd;
		mt19937 generator(rd());
		binomial_distribution<int> distribution(nb_total, percentage);
		
		int result(distribution(generator));
		
		return result;	
	}
	
	
	vector<double> Population::multinomial() const{
		vector<double> multi;
	
		multi.push_back(binomial(nb_alleles,Pop[0].get_frequency()));
		double new_population(nb_alleles);
		double new_allele_pool(nb_alleles);
		
		for(size_t i(1); i<(Pop.size()-1); ++i){
			double frequence(Pop[i].get_frequency());
			new_allele_pool -= multi[i-1];
			new_population -= frequence_to_quantity(Pop[i-1].get_frequency());
			double probability;
			
			if(new_population!= 0){
				probability=frequence_to_quantity(frequence) / new_population;
			}else{
				probability=0;
			}
			multi.push_back(binomial(new_allele_pool,probability));
		}
		multi.push_back(new_allele_pool- multi.back());
		return multi;
	}
	


