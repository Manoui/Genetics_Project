#ifndef POPULATION_HPP
#define POPULATION_HPP

#include <iostream>
#include "Allele.hpp"
#include <vector>
using namespace std;

/*! This is a population with n individuals (nb_alleles/2) and with a certain 
	amount of different alleles, which each have an allele frequency.
	
	The population evolves during a determined number of generations and
	at each generation the alleles frequency may change (corresponding to 
	the Wright-Fisher model - an idealized model of genetic drift).
*/

class Population{
	public:

//CONSTRUCTOR	
	Population(const int nb_alleles, vector<Allele> Pop,int nb_generations, int nb_replicates);

//CONVESRION METHOD(from frequence to quantity)
/*!Computates the amount of that allele present in the population according to its frequency*/
	int frequence_to_quantity(double frequence) const; 

//SETTER	
/*! At each new generation the alleles frequency evolves according to the 
	Wright-Fischer model*/
	void set_new_values();

//GETTER	
/*! Returns the actual frequency of each allele*/
	vector<double> get_frequencies() const;

//DISPLAY FUNCTION	
/*! Displays the frequency of each allele*/
	void display_frequencies() const; 
	


	private:
	
//METHODS TO CALCULATE THE ALLELE FREQUENCY AT THE NEXT GENERATION
/*! Returns the average frequency of each allele for the next generation
	after generating several random numbers with the multinomial distribution.*/
	vector<double> calculate_average_frequency() const;

/*!Returns the new alleles frequency due to the multinomial distribution.*/
	vector<double> calculate_new_frequency() const;
	
/*!Random number distribution that produces integers int the range [0,nb_alleles]
	according to a binomial discrete distribution,*/
	int binomial(int nb_total, double percentage) const;
	
/*!Generates random numbers distributed according to a multinomial distribution.*/
	vector<double> multinomial() const;



//ATTRIBUTS	
/*!Total number of alleles present in a population. Number of individuals in
	a population equals nb_alleles/2.*/
	const int nb_alleles;

/*!Container of the different alleles of the population*/
	vector<Allele> Pop; 

/*!The number of generations during which a population evolves*/
	int nb_generations;
	
/*! To obtain an realistic evolution we will calculate the average frequency 
	of each allele after each generation. Therefore we will execute n times 
	(with n = nb_replicates) the function generating random numbers according 
	to the multinomial distribution with the same parameters.
*/
	size_t nb_replicates; 
};

#endif

