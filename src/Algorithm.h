/*
 * Algorithm.h
 *
 *  Created on: Jan 27, 2017
 *      Author: lappet
 */

#ifndef ALGORITHM_H_
#define ALGORITHM_H_

#include "SetOfEqns.h"
#include <vector>

using namespace std;


class Algorithm {
public:
	Algorithm(double, unsigned int, SetOfEqns*);
	virtual ~Algorithm();

	double delta_t;
	unsigned int numOfVars;
	SetOfEqns* eqnPtrs;
	vector<double> result;
	vector<double> k1;
	vector<double> k2;
	vector<double> k3;
	vector<double> k4;

	vector<double> step(const vector<double>&);
	void combineVars(vector<double>&, const vector<double>&, double, double);
};

#endif /* ALGORITHM_H_ */
