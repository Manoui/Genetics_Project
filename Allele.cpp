#include "Allele.hpp"
#include <iostream>
using namespace std;

//CONSTRUCTOR
	Allele::Allele(double initial_frequence)
		:frequency(initial_frequence)
	{}

//SETTERS	
	void Allele::set_frequency(double new_f){
		frequency= new_f;
	}
	
//GETTERS	
	double Allele::get_frequency() const{
		return frequency;
	}
