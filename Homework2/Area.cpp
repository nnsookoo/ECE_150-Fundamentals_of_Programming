#include <iostream>
#include <stdlib.h>

using namespace std;

extern float f(float t);

int main (const int argc, const char * const argv[])
{ 
	int rc = 0;
	
	if (argc < 3){
		cerr << "Error: Expected 2 arguments; received " << argc-1 << "; exiting" << endl;
		return -1;
	}
	if (argc > 3){
		cerr << "Warning: Expected 2 arguments; received " << argc-1 << "; ignoring extraneous arguments" << endl;
		rc = 1;
	}

	const float dx = 0.01;

	float A = atof(argv[1]);
	float B = atof(argv[2]);
	
	float x = A;
	float area = 0;
	
	if (A > B){
		cerr << "Error: Cannot compute area" << endl;
		return -1;
	}
	
	while (x <= B){
		area = (dx * ((f(x + dx) + f(x))/2)) + area;
		x+=dx;
	}
	
	/*
	for (x = A; x <= B; x+=dx){
		area = (dx * ((f(x + dx) + f(x))/2)) + area;
	}*/
	
	cout << "The area under f(x) from " << A << " to " << B << " is " << area << endl;

	return rc;
}
