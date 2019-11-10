#include <iostream>
#include <stdlib.h>

using namespace std;

int main(const int argc, const char* const argv[]){

	//int NUM_BINS = 9; //define the number of bins 
	
	int bin[9] = {};
	
	//float voltage;

	int valid = 0;
		
	for (int i = 1; i < argc-1; i++){
		float voltage = atof(argv[i]);
		if((voltage > 0)&&(voltage < 150)){
			valid++;
		}
	}

	if(valid == 0){
		cerr << "Error: Unable to compute histogram over data set because there are no valid readings" << endl;
		return -1;
	}
	
	for (int i = 1; i < argc-1; i++){
		float num = atof(argv[i]);
		if (num > 150){
			cout << "Warning: invalid voltage reading: " << num << " ignored in calculation" << endl;
		}
		else if (num < 0){
			cout << "Warning invalid voltage reading: " << num << " ignored in calculation" << endl;
		}
	}

	//Note that you MUST have a counter for your number of objects in your array. In this case, our counter will be the int value count.
		
	int count = 0;
		
	for (int i = 1; i < argc-1; i++){
		float voltage = atof(argv[i]);
		if((voltage > 0)&&(voltage < 150)){
			count++;
		}
	}
		
	for (int i = 1; i < argc-1 ; i++){
		if(atof(argv[argc - 1]) >= 0){
			cerr << "Error: Unable to compute histogram over data set because there is no negative terminator" << endl;
			return -1;
		}
	}

	for (int i =1; i < argc-1; i++){
		float voltage = atof(argv[i]);
		if (voltage > 0 && voltage < 106){
			bin[0]++;
		}
		else if (voltage >= 106 && voltage < 109){
			++bin[1];
		}
		else if (voltage >= 109 && voltage < 112){
			++bin[2];
		}
		else if (voltage >= 112 && voltage < 115){
			++bin[3];
		}
		else if (voltage >= 115 && voltage < 118){
			++bin[4];
		}
		else if (voltage >= 118 && voltage < 121){
			++bin[5];
		}
		else if (voltage >= 121 && voltage < 124){
			++bin[6];
		}
		else if (voltage >= 124 && voltage <= 127){
			++bin[7];
		}
		else if (voltage > 127 && voltage < 150){
			++bin[8];
		}
		else{
			++bin[9];
		}
	}
		
	cout << "Number of voltage readings: " << count << endl;
	cout << "Voltage readings (0-106): " << bin[0] << endl;
	cout << "Voltage readings [106-109): " << bin[1] << endl;
	cout << "Voltage readings [109-112): " << bin[2] << endl;
	cout << "Voltage readings [112-115): " << bin[3] << endl;
	cout << "Voltage readings [115-118): " << bin[4] << endl;
	cout << "Voltage readings [118-121): " << bin[5] << endl;
	cout << "Voltage readings [121-124): " << bin[6] << endl;
	cout << "Voltage readings [124-127]: " << bin[7] << endl;
	cout << "Voltage readings (127-150): " << bin[8] << endl;
	cout << "Invalid readings: " << bin[9] << endl;
	
	return 0;
}


