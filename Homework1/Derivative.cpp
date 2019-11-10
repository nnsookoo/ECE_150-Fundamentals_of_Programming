#include <iostream>
#include <math.h>
#include <stdlib.h>

//#define EXPECTED_ARG_COUNT 1

using namespace std;

extern float f(float t);

int main (const int argc, const char * const argv[])
{
	
	if (argc < 2){
		cerr << "Error: Expected 1 argument; received " << argc-1 << "; exiting" << endl;
		return -1;
	}
	if (argc > 2){
		cerr << "Warning: Expected 1 arguments; received " << argc-1 << "; ignoring extraneous arguments" << endl;
	}

	const float delta = 0.0001;

	float t = atof(argv[1]);
	
	/*float t1 = t - 0.0001;
	float t2 = t + 0.0001;*/
	
	float slope = (f(t + delta) - f(t - delta))/(2*delta);
	
	cout << "The slope of f(t) at t = " << t << "is " << slope << endl;

	return 0;
}

