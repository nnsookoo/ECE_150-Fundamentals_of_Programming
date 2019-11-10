#include <iostream>
#include <stdlib.h>

using namespace std;

#define EXPECTED_ARG_COUNT 1

int main(const int argc, const char * argv[])
{
	int rc = 0;

	if (argc != EXPECTED_ARG_COUNT+1)
	{
		cerr << "Error: Expected " << EXPECTED_ARG_COUNT << " arguments; received " << argc-1 << "; ignoring extraneous arguments " << endl;
	}

	// Variables 
	float S, y, estimate, prevEstimate;

	//Have no idea how to ensure that S is a non-negative number

	S = atof (argv[1]);

	if (S < 0)
	{
		cerr << "Error: cannot compute square root of negative number" << endl;
	}

	estimate = S/2;

	//while (prevEstimate - estimate > 0.00001 * prevEstimate);
	while (((S - (estimate * estimate))/S) >= 0.00001 || ((S - (estimate * estimate))/S) <= -0.00001)

	{
		y = S/estimate;
	//prevEstimate = estimate;

	//The previous guess will be stored to perform the loop

		estimate = (estimate + y)/2;

	}
	
	//Precision of 0.001% means that estimate is within 0.001% of prevEstimate?

	cout << "The square root of " << S << " is " << estimate << endl;

	return 0;
}