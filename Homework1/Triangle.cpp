#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

//three points
#define EXPECTED_ARG_COUNT 6

int main(const int argc, const char * argv[])
{
    
	int rc = 0;
    
    //cout << "argc is:" << argc << endl;
    //cout << "argv [0] is:" << argv[0]<<endl;
 
	 /*   
		if (argc != 7)
	{
		cerr << argv[0] << "usage error: expected 6 arguments; received" << argc-1 <<"existing"<<endl;
		
		return -1;
	}

	*/

	// Check argument count
	if (argc < EXPECTED_ARG_COUNT+1){
		cerr << argv[0] << "error: Expected " << EXPECTED_ARG_COUNT << " argument received " << argc-1 << " existing " << endl;
		return -1;
	}
	if (argc > EXPECTED_ARG_COUNT+1){
		cerr << argv[0] << "error: Expected " << EXPECTED_ARG_COUNT << " argument received " << argc-1 << " existing " << endl;
		return +1;
	}
    
	float x1 = atof (argv[1]);
	float y1 = atof (argv[2]);
	float x2 = atof (argv[3]);
	float y2 = atof (argv[4]);
	float x3 = atof (argv[5]);
	float y3 = atof (argv[6]);

	float s1 = sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)));
	float s2 = sqrt(((x1-x3)*(x1-x3))+((y1-y3)*(y1-y3)));
	float s3 = sqrt(((x3-x2)*(x3-x2))+((y3-y2)*(y3-y2)));
	float s = ((s1 + s2 + s3)/2);

	float a = sqrt(s*(s-s1)*(s-s2)*(s-s3));

	//cout << "The area of ("<<x1<<","<<y1<<"), ("<<x2<<","<<y2<<"), ("<<x3<<","<<y3<<") is " << a << endl;
	cout << "The area of the triangle formed by points ("<<x1<<","<<y1<<"), ("<<x2<<","<<y2<<"), and ("<<x3<<","<<y3<<") is: " << a << endl;

	return rc;
}

