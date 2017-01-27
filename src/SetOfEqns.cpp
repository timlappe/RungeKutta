/*
 * SetOfEqns.cpp
 *
 *  Created on: Nov 28, 2016
 *      Author: lappet
 */

#include "SetOfEqns.h"

SetOfEqns::SetOfEqns(unsigned int num) {
	numOfEqns=num;
}

SetOfEqns::~SetOfEqns() {
	// TODO Auto-generated destructor stub
}

vector<double> SetOfEqns::eqns(const vector<double>& v) {
	vector<double> result(numOfEqns);
	result[0]=eqn1(v);
	result[1]=eqn2(v);

	return result;
}

double SetOfEqns::eqn1(const vector<double>& v) {
	return v[1]*v[1];
}

double SetOfEqns::eqn2(const vector<double>& v) {
	return -v[0];
}
