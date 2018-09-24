#include "math.h"
#include <stdio.h>

char* unsignedlonglongToFormattedHex(unsigned long long longlongIn){
	// output is formated, has to be 11 bytes in total, starts with "0x"
	char* totallyThis = new char[11];
	for(int i = 0; i<11; i++){
		totallyThis[i] = '0';
	}
	totallyThis[1] = 'x';

	char buffer[9];
	sprintf(buffer, "%0x", (int)longlongIn+1); //address offset [WARNING: casting unsigned long long to int, may bottleneck and overflow]

	//check where is null-terminator, calculate size
	int size = 0;
	while(buffer[size] != '\0'){
		size++;
	}

	//put hex in whole address (buffer) with 0s
	for(int i = 0; i <= size; i++){
		totallyThis[10-i] = buffer[size-i];
	}
	return totallyThis;
}

bitsInByte byteToBit(char byteIn){
	unsigned char mask = 1;
	char buffer[8];
	for(int i=7; i>=0; i--){
		buffer[i] = (byteIn & mask)?'1':'0';	// check for logical AND with mask
		mask = mask << 1;			// then, shift mask by 1
	}

	bitsInByte totallyThis;		// generate structure with bits as return object
	for(int i=0; i<8; i++){
		totallyThis.bits[i] = buffer[i];
	};
	return totallyThis;
}
