
int mode(const int dataset[], const int size, int modes[])
{
	int myData[size];
	
	int i = 0;
	
	if(size < 0){
		return -1;
	}
	
	while(i < size){
		myData[i] = dataset[i];
		++i;
	}

	int somethingChanged = 1;
	
	while (somethingChanged) {
		somethingChanged = 0; //if nothing changed
		
		int i = 0;
		
		while (i < size-1){ //-1 because you have argc-1 elements. One element would be compared to argc-2 elements.
			if (myData[i] > myData[i+1]){ //Wrong order, swap them
				int tmp;
				tmp = myData[i];
				myData[i]=myData[i+1];
				myData[i+1]=tmp;
				somethingChanged = 1;
			}
			++i;
		}
	}
	
	//You must count for the highest number of occurrences
	/*
	int num = dataset[0];
	int mode = 0;
	int count = 1;
	int maxcount = 0;

	for (int i = 1; i < size; i++){
		if (dataset[i] == num){ // counting how many times this current number occurs
			count++;
		}
		else{ // a different number
			if (count > maxcount){
				maxcount = count; // mode is the biggest ocurrences
				mode = num;
			}
		}
		
		count = 1; // reset count for the new number
		num = dataset[i];
	}
	
	int modeIndex = 0;
	
	int modes[modeIndex] = num;
	
	modeIndex++;*/
	
	/*
	int currentMode = myData[0];
	int modeFrequency = -1;
	int item = myData[0];
	int numofitem = 0;
	
	while(i < size+1){
		if(modeFrequency < 0){
			item = myData[0];
		}
		if(myData[i] == item){
			++numofitem;
		}
		else{
			if(modeFrequency < 0){
				currentMode = item;
				modeFrequency = numofitem;
			}
			else{
				if(numofitem > modeFrequency){
					currentMode = item;
					modeFrequency = numofitem;
				}
			}
		}
				
		item = myData[i];
		numofitem = 1;
		i++;
	}
				
	
	return item;*/
	
	int count = 1;
	int maxcount = 0;
	//int j = 0;
	int z = 0;
	int number = 1;
    
	for (int i=0; i < size; i++) {
		if (myData[i] == myData[i+1]) {
			count++;
		}
		else {
			if (count == maxcount) {
				modes[++z] = myData[i];
				count = 1;
				number++;
			}
            
			if (count > maxcount) {
				for (int j = 0; j <size; j++) {
					modes[j] = 0;
				}
				z = 0;
				number = 1;
				maxcount = count;
				modes[number] = myData[i];
				count = 1;
			}
            
			if (count<maxcount) {
				count = 1;
				z = 0;
				number = 1;
			}
		}
	}
    
	return number;
}


#ifndef MARMOSET_TESTING

/*
 * Marmoset doesn't see anything in here
 *
 * Use this space to test your code
 */

#include <cstdlib>  // atoi
#include <iostream> // cout, endl

using namespace std;

#define MIN_ARGS 2

int main(const int argc, const char* const argv[])
{
	if (argc < MIN_ARGS)              // not enough inputs
		return -1;

	int sz = argc - 1;                // 1 for name
	int input[sz];                    // to hold inputs

	for (int i = 0; i < sz; ++i)      // loop over all inputs, store in array
		input[i] = atoi(argv[i + 1]);   // atoi = string to integer

	int modes[sz];                    // there will be at most as many modes
                                    // as there are numbers

	int ret = mode(input, sz, modes); // call the function

	cout << "Function returned: " << ret << " modes" << endl;

	cout << "Modes were:";
	for (int i = 0; i < ret; ++i)     // loop over and print all modes
		cout << ' ' << modes[i];
	cout << endl;

	return 0;
}

#endif
