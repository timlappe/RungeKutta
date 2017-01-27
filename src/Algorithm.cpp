/*
 * Algorithm.cpp
 *
 *  Created on: Jan 27, 2017
 *      Author: lappet
 */

#include "Algorithm.h"

Algorithm::Algorithm(double dt, unsigned int num, SetOfEqns* ptr) {
	delta_t=dt;
	numOfVars=num;
	eqnPtrs=ptr;
	result.resize(numOfVars);
	k1.resize(numOfVars);
	k2.resize(numOfVars);
	k3.resize(numOfVars);
	k4.resize(numOfVars);
}

Algorithm::~Algorithm() {
	// TODO Auto-generated destructor stub
}


vector<double> Algorithm::step(const vector<double>& varList) {

	vector<double> tmpV=(*eqnPtrs).eqns(varList);
	for (unsigned int i=0; i<numOfVars; ++i) {
		k1[i]=tmpV[i];
		result[i]=k1[i];
	}

	combineVars(k1, varList, 0.5*delta_t, 1.0);

	tmpV=(*eqnPtrs).eqns(k1);
	for (unsigned int i=0; i<numOfVars; ++i) {
		k2[i]=tmpV[i];
	}

	combineVars(result, k2, 1.0, 2.0);
	combineVars(k2, varList, 0.5*delta_t, 1.0);

	tmpV=(*eqnPtrs).eqns(k2);
	for (unsigned int i=0; i<numOfVars; ++i) {
		k3[i]=tmpV[i];
	}

	combineVars(result, k3, 1.0, 2.0);
	combineVars(k3, varList, delta_t, 1.0);

	tmpV=(*eqnPtrs).eqns(k3);
	for (unsigned int i=0; i<numOfVars; ++i) {
		k4[i]=tmpV[i];
	}

	combineVars(result, k4, 1.0, 1.0);
	combineVars(result, varList, (delta_t/6.0), 1.0);


	return result;
}

void Algorithm::combineVars(vector<double>& vars, const vector<double>& k, double x, double y) {
	for (unsigned int i=0; i<numOfVars; ++i) {
		vars[i]=x*vars[i] + y*k[i];
	}
}
