#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main(const int argc, const char * const argv[])
{
	int rc = 0;

	float x1 = atof (argv[1]);
	float y1 = atof (argv[2]);
	float x2 = atof (argv[3]);
	float y2 = atof (argv[4]);
	float x3 = atof (argv[5]);
	float y3 = atof (argv[6]);

	float a = sqrt(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)));
	float b = sqrt(((x1 - x3) * (x1 - x3)) + ((y1 - y3) * (y1 - y3)));
	float c = sqrt(((x3 - x2) * (x3 - x2)) + ((y3 - y2) * (y3 - y2)));

	cout << "The triangle formed by points ("<<x1<<", "<<y1<<"), ("<<x2<<", "<<y2<<"), and ("<<x3<<", "<<y3<<") is: ";
	
	if ((fabs(a - b) < 0.01) && (fabs(b - c) < 0.01) && (fabs(a - c) < 0.01)){
		cout << "equilateral ";
	}
	else if ((a != b) && (b != c) && (a != c)){
		cout << "scalene ";
	}
	//if
	else if (((fabs(a - c) < 0.01) && (a != b) && (c != b)) || ((fabs(b - c) < 0.01) && (b != a) && (c != a)) || ((fabs(a - b) < 0.01) && (a != c) && (b != c))){
		cout << "isosceles ";
	}
	
	//if a is the largest
	if ( a >= b && a >= c){
		if ( ((b*b) + (c*c) - (a*a)) > 0.01){
			cout << "acute" << endl;
		}
		else if ( ((b*b) + (c*c) - (a*a)) < -0.01){
			cout << "obtuse" << endl;
		}
		else{
			cout << "right" << endl;
		}
	}
	
	//if b is the largest
	else if ( b >= a && b >= c){
		if ( ((a*a) + (c*c) - (b*b)) > 0.01){
			cout << "acute" << endl;
		}
		else if ( ((a*a) + (c*c) - (b*b)) < -0.01){
			cout << "obtuse" << endl;
		}
		else{
			cout << "right" << endl;
		}
	}
	
	//if c is the largest
	else if (c >= a && c >= b){
		if ( ((b*b) + (a*a) - (c*c)) > 0.01){
			cout << "acute" << endl;
		}
		else if ( ((b*b) + (a*a) - (c*c)) < -0.01){
			cout << "obtuse" << endl;
		}
		else{
			cout << "right" << endl;
		}
	}
	
	
/*
	if (((a * a) + (b * b) - (c * c) < -0.01) || ((c * c) + (b * b) - (a * a) < -0.01) || ((a * a) + (c * c) - (b * b) < -0.01)){
		type2 = "obtuse";
	}
	else if (((a * a) + (b * b) - (c * c) > 0.01) || ((c * c) + (b * b) - (a * a) > 0.01) || ((a * a) + (c * c) - (b * b) > 0.01)){
		type2 = "acute";
	}
	else{
		type2 = "right";
	}*/

	

	float s = ((a + b + c)/2);

	float area = sqrt(s * (s - a) * (s - b) * (s - c));

	cout << "The area of the triangle formed by points ("<<x1<<","<<y1<<"), ("<<x2<<","<<y2<<"), and ("<<x3<<","<<y3<<") is: " << area << endl;

	return rc; 
}