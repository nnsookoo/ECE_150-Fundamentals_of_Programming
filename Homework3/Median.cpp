#include <iostream> 
#include <stdlib.h>

using namespace std;

int main(const int argc, const char* const argv[]){
    
	int rc = 0;
	
	if (argc < 1){
		cerr << "Error: Unable to compute statistics due to insufficient data" << endl;
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
	            
	//Note that you MUST have a counter for your number of objects in your array. In this case, our counter will be the int value count.
	
	int count = 0;
	float arr[valid];
    
	for (int i = 1; i < argc-1; i++){
		float num = atof(argv[i]);
		if((num > 0)&&(num < 150)){
			arr[count] = num;
			count++;
		}
	}
    
	if(valid == 0){
		cerr << "Error: Unable to compute statistics over data set because there are no valid readings" << endl;
		return -1;
	}
    
	for (int i = 1; i < argc-1 ; i++){
		//float num = atof(argv[i]);
		if(atof(argv[argc - 1]) >= 0){
			cerr << "Error: Unable to compute statistics over data set because there is no negative terminator" << endl;
			return -1;
		}
	}
	
	int somethingChanged = 1;
	
	while (somethingChanged) {
		somethingChanged = 0; //if nothing changed
		
		int i = 0;
		
		while (i < count-1){ //-1 because you have argc-1 elements. One element would be compared to argc-2 elements.
			if (arr[i] > arr[i+1]){ //Wrong order, swap them
				int tmp;
				tmp = arr[i];
				arr[i]=arr[i+1];
				arr[i+1]=tmp;
				somethingChanged = 1;
			}
			++i;
		}
	}
	
	float median;
	
	if ((count %2) == 0){
		median = (arr[count/2] + arr[(count/2)-1])/2;
	}
	else{
		median = (arr[count/2]);
	}
	
	cout << "Number of voltage readings: " << count << endl;
	cout << "Median voltage: " << median << endl;
	
	return rc;
}


/*Step 1: Look at partial results
	int main(const int argc, const char* const argv[]){
		float numbers{argc};
		
		//code to get argv into the numbers array (min.cpp)
		
		//sort this
		
		
		//while(){
			float tmp = atof(argv[index])
			if (tmp < 0)
				done = 1;
			else{
			}*/