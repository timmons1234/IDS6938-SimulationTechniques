#include <iostream>
#include <sstream>
#include <string>
//using namespace std;
int size = 101;  //TODO
Eigen::MatrixXf TransitionMatrix(size, size);
Eigen::VectorXf v(size);

unsigned int ROLLS = 30; //TODO

double prob = 1.0/6.0 ;  //TODO

void SetTransitionMatrix()
{
	TransitionMatrix.setZero();

	for (int i = 0; i < TransitionMatrix.rows() - 6; i++) //from class on 3/21  -6 omits last 6 rows
	{
		TransitionMatrix(i, i + 1) = prob;
		TransitionMatrix(i, i + 2) = prob;
		TransitionMatrix(i, i + 3) = prob;
		TransitionMatrix(i, i + 4) = prob;
		TransitionMatrix(i, i + 5) = prob;
		TransitionMatrix(i, i + 6) = prob;
	}
	// A markov chain defines the probability from state i to state j by a transition matrix, T
	
// row 95 sucks
	TransitionMatrix(95, 96) = prob;
	TransitionMatrix(95, 97) = prob;
	TransitionMatrix(95, 98) = prob;
	TransitionMatrix(95, 99) = prob;
	TransitionMatrix(95, 100) = prob*2;

	// row 96 sucks
	TransitionMatrix(96, 97) = prob;
	TransitionMatrix(96, 98) = prob;
	TransitionMatrix(96, 99) = prob;
	TransitionMatrix(96, 100) = prob*3;

	// row 97 sucks
	TransitionMatrix(97, 98) = prob;
	TransitionMatrix(97, 99) = prob;
	TransitionMatrix(97, 100) = prob*4;

	// row 98 sucks
	TransitionMatrix(98, 99) = prob;
	TransitionMatrix(98, 100) = prob*5;

	// row 99 sucks
	TransitionMatrix(99, 100) = 1;

	// row 100 sucks
	TransitionMatrix(100, 100) = 1;

	// row 100 sucks
	TransitionMatrix(100, 101) = 1;

	// row 101 sucks
	TransitionMatrix(101, 101) = 1;


//	std::cout << TransitionMatrix << std::endl;
//	std::cout << "100:" << TransitionMatrix(101, 101) << std::endl;
//	std::cout << "101:" << TransitionMatrix(100, 100) << std::endl;
}
