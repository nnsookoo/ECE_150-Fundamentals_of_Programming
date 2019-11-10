#include <iostream> 
#include <stdlib.h>
#include <math.h>

using namespace std;

int main(const int argc, const char* const argv[]){
    
	int rc = 0;
	
	if (argc < 1){
		cerr << "Error: Unable to compute standard deviations over data set because of insufficient data" << endl;
		return -1;
	}
	
	for (int i = 1; i < argc-1; i++){
		float num = atof(argv[i]);
		if (num > 150){
			cout << "Warning: invalid voltage reading: " << num << " ignored in calculation" << endl;
			rc = 1;
		}
		else if (num < 0){
			cout << "Warning invalid voltage reading: " << num << " ignored in calculation" << endl;
			rc = 1;
		}
	}
	
	int valid = 0;
	
	for (int i = 1; i < argc-1; i++){
		float num = atof(argv[i]);
		if((num > 0)&&(num < 150)){
			valid++;
		}
	}

	if(valid == 0){
		cerr << "Error: Unable to compute standard deviations over data set because there are no valid readings" << endl;
		return -1;
	}
    
	for (int i = 1; i < argc-1 ; i++){
		if(atof(argv[argc - 1]) >= 0){
			cerr << "Error: Unable to compute standard deviations over data set because there is no negative terminator" << endl;
			return -1;
		}
	}
	
    //Note that you MUST have a counter for your number of objects in your array. In this case, our counter will be the int value count.
	
	int count = 0;
	float sum;
    
	for (int i = 1; i < argc-1; i++){
		float num = atof(argv[i]);
		if((num > 0)&&(num < 150)){
			count++;
			
			sum += num;
		}
	}
	
	float avg = sum / count;
	
	float diff;
	float square;
	float total;
	
	for (int i =1; i < argc-1; i++){
		float num = atof(argv[i]);
		if((num > 0)&&(num < 150)){
	        
			diff = num - avg;
	        
			square = (diff*diff);
	        
			total += square;
		}
	}
    
	float bpsd = (total/count);
    
	float psd = sqrt(bpsd);
	
	float element = (count-1);
    
	float bssd = (total/(element));
    
	float ssd = sqrt(bssd);
	
	cout << "Number of voltage readings: " << count << endl;
	
	cout << "Population standard deviation: " << psd << endl;
	
	if ((element == 0)&&(total == 0)){
		cout << "Sample standard deviation: undefined" << endl;
	}
	else if(element == 0){
		cout << "Sample standard deviation: infinity" << endl;
	}
	else{
		cout << "Sample standard deviation: " << ssd << endl;
	}
	
	return rc;
}
