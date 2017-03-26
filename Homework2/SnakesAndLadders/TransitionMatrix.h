#include <iostream>
#include <sstream>
#include <string>
//using namespace std;
int size = 101;  //TODO
Eigen::MatrixXf TransitionMatrix(size, size);
Eigen::VectorXf v(size);

unsigned int ROLLS = 10; //TODO

double prob = 1.0/6.0 ;  //TODO


void SetTransitionMatrix()
{
	TransitionMatrix.setZero();

	//TODO
	std::string str;                      // This will store your tokens
	std::ifstream file("c:/null_export.txt");		// Null state
//	std::ifstream file("c:/snakes_export.txt");		// Snakes and Ladders

	int counter_row = 0;
	int counter_column = 0;
	while (getline(file, str, ','))   // You can have a different delimiter
	{
		// Process your data
		std::cout << counter_column << " " << counter_row << "  -" << str << std::endl;
		TransitionMatrix(counter_column, counter_row) = stof(str);

		counter_row++;
		if (counter_row == TransitionMatrix.rows() + 1)
		{
			counter_row = 0;
			counter_column++;
		}

	}



	std::cout << TransitionMatrix << std::endl;

}