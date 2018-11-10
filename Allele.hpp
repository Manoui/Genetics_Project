#ifndef ALLELE_HPP
#define ALLELE_HPP

#include <iostream>
using namespace std;

/*!This is an allele with an allele frequency in a population. */

class Allele{
	public:
	Allele(double initial_frequence);
	
	/*!Resets the allele frequency*/
	void set_frequency(double new_f);
	
	/*!Returns the allele frequency*/
	double get_frequency() const;
	
	private:
	double frequency;
};

#endif
