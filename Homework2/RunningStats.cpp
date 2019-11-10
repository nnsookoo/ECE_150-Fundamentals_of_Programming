#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main (const int argc, const char* const argv[]){
	
	int rc = 0;

	for (int count = 1; count < argc ; count++){
		float num = atof(argv[count]);
		if(atof(argv[argc-1]) >= 0){
			cerr << "Error: Unable to compute statistics over data set because there is no negative terminator" << endl;
			return -1;
		}
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

	float min = 150.0;
	float max = 0.0;
	float sum = 0.0;
	int count = 0;

	cout << "Sample" << '\t' << "Value" << '\t' << "Minimum" << '\t' << "Average" << '\t' << "Maximum" << endl;

	for(int i = 1; i < argc - 1; i++){
		float num = atof(argv[i]);
		if(num >= 150.0){
			cout << "Warning: invalid voltage reading " << num << " ignored in calculation" << endl;
			rc = -1;
		}

		else{
			count++;
			sum += num;

			if(num > max){
				max = num;
			}
			if(num < min){
				min = num;
			}
			
			float avg = sum / count;

			cout << i << '\t' << num << '\t' << min << '\t' << avg << '\t' << max << endl;
		}
	}

	return 0;
}
