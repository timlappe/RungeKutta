/*
 * SetOfEqns.h
 *
 *  Created on: Nov 28, 2016
 *      Author: lappet
 */

#ifndef SETOFEQNS_H_
#define SETOFEQNS_H_

#include <vector>
#include <complex>

using namespace std;

class SetOfEqns {
public:
	SetOfEqns(unsigned int);
	virtual ~SetOfEqns();

	unsigned int numOfEqns;

	vector<double> eqns(const vector<double>&);

	double eqn1(const vector<double>&);
	double eqn2(const vector<double>&);

};

#endif /* SETOFEQNS_H_ */
