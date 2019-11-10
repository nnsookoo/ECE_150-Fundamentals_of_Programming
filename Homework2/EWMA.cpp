#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main (const int argc, const char* const argv[]){
	
	int rc = 0;
	
	if ((argc - 1) < 2){
		cerr << "Error: Unable to compute statistics over data set because there is too few arguments" << endl;
		return -1;
	}

	for (int count = 1; count < argc ; count++){
	float num = atof(argv[count]);
		if(atof(argv[argc - 1]) >= 0){
			cerr << "Error: Unable to compute statistics over data set because there is no negative terminator" << endl;
			return -1;
		}
	}

	float num = atof(argv[1]);
	
	if ((num < 0) || (num > 1)){
		cerr << "Error: Unable to compute statistics over data set because there is not a valid weighting parameter" << endl;
		return -1;
	}
	
	int valid = 0;

	for (int count = 1; count < argc ; count++){
	float num = atof(argv[count]);
		if ((num > 0.0) && (num < 150.0)){
			valid = 1;
		}
	}

	if (valid == 0){
		cerr << "Error: Unable to compute statistics over data set because there were no valid readings" << endl;
		return -1;
	}

	int count = 0;
	int i = 2;
	float a = atof(argv[1]);
	float EWMA = atof(argv[i]);

	cout << "Sample" << '\t' << "Value" << '\t' << "EWMA" << endl;

	for(int i = 2; i < argc - 1; i++){
		float num = atof(argv[i]);
		if(num >= 150.0){
			cout << "Warning: invalid voltage reading " << num << " ignored in calculation" << endl;
			rc = +1;
		}

		else{
			count++;
			
			EWMA = ((a*num) + (1-a)*(EWMA));
		
			cout << i-1 << '\t' << num << '\t' << EWMA << endl;
		}
	}
	
	return 0;
}