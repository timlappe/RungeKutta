//============================================================================
// Name        : RungeKutta.cpp
// Author      : lappet
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <math.h>
#include <complex>
#include <ctime>

#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>

#include "SetOfEqns.h"
#include "Algorithm.h"

using namespace std;

int main() {
	clock_t start=clock();
	unsigned int Num=2;

	vector<double> varList(Num);

	varList[0]=1.0;
	varList[1]=1.0;

	SetOfEqns setOfEqns(Num);
	SetOfEqns* setOfEqnsPtr;
	setOfEqnsPtr=&setOfEqns;

	double T=1.0;
	double delta_t=1e-5;
	unsigned int N=ceil(T/delta_t);
	cout << "Number of itreations: " << N << '\n';
	cout << '\n';


	double** data=new double*[Num];
	for (unsigned int i=0; i<Num; ++i) {
		data[i]=new double[N];
	}
	Algorithm algorithm(delta_t, Num, setOfEqnsPtr);
	for (unsigned int t=0; t<N; ++t) {

		varList=algorithm.step(varList);

		for (unsigned int i=0; i<Num; ++i) {
			if (t%100==0) {
			}
				data[i][t]=varList[i];
		}
	}

	clock_t writing=clock();
	ofstream dataStream;
	dataStream.precision(15);
	for (unsigned int i=0; i<Num; ++i) {
		string fileName="SPA_";
		ostringstream fileNameStream;
		fileNameStream << fileName << i << ".dat";
		string FileName=fileNameStream.str();
		dataStream.open(FileName.c_str());
		for (unsigned int t=0; t<N; ++t) {
			dataStream << data[i][t] << '\n';
		}
		dataStream.close();
	}

	cout << "--------------------------------" << '\n';
	cout << "Writing time: "<< float(clock() - writing)/1e6 << '\n';
	cout << "--------------------------------" << '\n';


	cout << '\n';

	cout << "--------------------------------" << '\n';
	cout << "Computation time: " << float(clock() - start)/1e6 << '\n';
	cout << "--------------------------------" << '\n';

	return 0;
}

