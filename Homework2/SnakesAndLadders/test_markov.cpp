#include <iostream>
#include <functional>   
#include <numeric> 
#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <Eigen\dense>

#include "markov.h"
#include "TransitionMatrix.h"

int main(){

	SetTransitionMatrix();
	double onesix = (1.0 / 6.0);
	double twosix = (2.0 / 6.0);
	double thrsix = (3.0 / 6.0);
	double fousix = (4.0 / 6.0);
	double fivsix = (5.0 / 6.0);


	//Output Vector
	v.setZero();
	v(0) = 1.0;

	// Print Results to File
	std::ofstream myfile;
	myfile.open("markov_results.txt");

	
   // TODO add Markov vector - Matrix multiplication
	v = v.transpose() * TransitionMatrix; //V(K+1) = v(k) T.

	std::cout <<  v << std::endl;
	//myfile << v << std::endl;  //this is just a sample, be careful how you print to file so you can mine useful stats
	
	myfile.close();


  return 1;
}