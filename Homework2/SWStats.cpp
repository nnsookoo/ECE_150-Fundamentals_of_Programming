#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main (const int argc, const char* const argv[]){
	
	int rc = 0;

	for (int count = 1; count < argc ; count++){
		float num = atof(argv[count]);
		if(atof(argv[argc - 1]) >= 0){
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
	int count = 1;
	int window = atoi(argv[1]);
	
	window = window-1;
	
	if (window <= 0){
		cerr << "Error: Unable to compute statistics over data set because there is a non-positive window size" << endl;
		return -1;
	}
	
	else {
		cout << "Window Size: " << window << endl;
	}

	cout << "Sample" << '\t' << "Value" << '\t' << "SWMinimum" << '\t' << "SWMaximum" << endl;
	
	int i = 2; 

	while (i < argc-1){
		float num = atof(argv[i]);
		if(num >= 150.0){
			cout << "Warning: invalid voltage reading " << num << " ignored in calculation" << endl;
			rc = -1;
		}

		else{
			if(count < window+1){
				if(num > max){
					max = num;
				}
				if(num < min){
					min = num;
				}
			}

			else{
				int start = 0;
				min = num;
				max = num;
				while(start < window){
					if (atof(argv[count-start]) < min){
						min = atof(argv[count-start]);
					}
					if (atof(argv[count-start]) > max){
						max = atof(argv[count-start]);
					}
					start++;
				}
			}

			cout << count << '\t' << num << '\t' << min << '\t' << '\t' << max << endl;
		
			count++;
			
		}
		i++;
	}

	return 0;
}



