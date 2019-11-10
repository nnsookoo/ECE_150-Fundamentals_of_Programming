#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

//three points
#define EXPECTED_ARG_COUNT 6

int main(const int argc, const char * argv[])
{
    
	int rc = 0;

	// Check argument count
	if (argc < EXPECTED_ARG_COUNT+1){
		cerr << "Error: Expected " << EXPECTED_ARG_COUNT << " arguments; received " << argc-1 << "; exiting" << endl;
		return -1;
	}
	if (argc > EXPECTED_ARG_COUNT+1){
		cerr << "Warning: Expected " << EXPECTED_ARG_COUNT << " arguments; received " << argc-1 << "; ignoring extraneous arguments" << endl;
	}
    
	float x1 = atof (argv[1]);
	float y1 = atof (argv[2]);
	float x2 = atof (argv[3]);
	float y2 = atof (argv[4]);
	float x3 = atof (argv[5]);
	float y3 = atof (argv[6]);

	float slope1 = (y2 - y1)/(x2 - x1);
	float slope2 = (y3 - y1)/(x3 - x1);
	float slope3 = (y3 - y2)/(x3 - x2);
	
	if ((x1 == x2) && (x2 == x3) && (x1 == x3) && (y1 == y2) && (y2 == y3) && (y1 == y3){
		cout << "The points ("<<x1<<", "<<y1<<"), ("<<x2<<", "<<y2<<"), and ("<<x3<<", "<<y3<<") overlap; they do not form a triangle" << endl;
		return rc;
	}
	if ((slope1 == slope2) & (slope2 == slope3)){
		cout << "The points ("<<x1<<", "<<y1<<"), ("<<x2<<", "<<y2<<"), and ("<<x3<<", "<<y3<<") form a line with slope: " << slope1 << endl;
		return rc;
	} 
	if ((x1 == x2) & (y1 == y2)){
		cout << "The points ("<<x1<<", "<<y1<<"), ("<<x2<<", "<<y2<<"), and ("<<x3<<", "<<y3<<") form a line with slope: " << slope3 << endl;
		return rc;
	}
	else if ((x1 == x3) & (y1 == y3)){
		cout << "The points ("<<x1<<", "<<y1<<"), ("<<x2<<", "<<y2<<"), and ("<<x3<<", "<<y3<<") form a line with slope: " << slope1 << endl;
		return rc;
	}
	else if ((x2 == x3) & (y2 == y3)){
		cout << "The points ("<<x2<<", "<<y2<<"), ("<<x2<<", "<<y2<<"), and ("<<x3<<", "<<y3<<") form a line with slope: " << slope2 << endl;
		return rc;
	}
	
	float s1 = sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)));
	float s2 = sqrt(((x1-x3)*(x1-x3))+((y1-y3)*(y1-y3)));
	float s3 = sqrt(((x3-x2)*(x3-x2))+((y3-y2)*(y3-y2)));
	
	float s = ((s1 + s2 + s3)/2);

	float a = sqrt(s*(s-s1)*(s-s2)*(s-s3));

	cout << "The area of the triangle formed by points ("<<x1<<", "<<y1<<"), ("<<x2<<", "<<y2<<"), and ("<<x3<<", "<<y3<<") is: " << a << endl;

	return rc;
}