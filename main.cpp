#include <iostream>
#include "Population.cpp"
#include "Allele.cpp"
#include <vector>
using namespace std;

int main(){
	Allele allele1(0.5);
	Allele allele2(0.25);
	Allele allele3(0.25);
	
	vector<Allele> alleles= {allele1, allele2, allele3};
	Population population(10,alleles,1,3);
	
	population.display_frequencies();
	
	population.set_new_values();
	
	cout<<"ALLELE FREQUENCY AT THE NEXT GENEREATION: "<<endl;
	population.display_frequencies();
	
	
	return 0;
}
