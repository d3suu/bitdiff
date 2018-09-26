#include "math.h"
#include <stdio.h> //sprintf
#include <string.h> //strcpy

/*
// ====================== THE DEBUG-ME WALL ===========================

char* unsignedlonglongToHex(unsigned long long longlongIn){ // WIP POC
	unsigned long long a, last_a;
	int r;
	char buffer[8]; // actually max of ULL in hex is "10000000000000000" so 17 places, TODO reimplement that in output format
	int b = 7;
	char out;
	a = longlongIn; // just in case function doesnt create copy of argument and starts editing its source
	
	for(int i = 0; i<8; i++){
		buffer[i] = '0';
	}

	while(a>0){
		last_a = a;
		a = a/16;
		r = last_a - (a*16);

		if(r<=9){
			out = (int)r;
		}else{
			switch(r){
				case 10:
					out = 'a';
					break;
				case 11:
					out = 'b';
					break;
				case 12:
					out = 'c';
					break;
				case 13:
					out = 'd';
					break;
				case 14:
					out = 'e';
					break;
				case 15:
					out = 'f';
					break;
				default:
					out = '0';
					break;
			}
		}
		buffer[b] = out;
		b--;
	}

	return buffer;
}

// ===================== THE END OF DEBUG-ME WALL ========================
*/

char* unsignedlonglongToFormattedHex(unsigned long long longlongIn){
	// output is formated, has to be 11 bytes in total, starts with "0x"
	char* totallyThis = new char[11];
	for(int i = 0; i<11; i++){
		totallyThis[i] = '0';
	}
	totallyThis[1] = 'x'; // "0x00000000"

	//char* buffer = unsignedlonglongToHex(longlongIn); // WIP WARNING TODO <-- IM HERE, DEBUG ME

	char buffer[9];
	sprintf(buffer, "%0x", (int)longlongIn+1);	//address offset [WARNING: casting unsigned long long to int, may overflow]
							// "Believing in something can help you do amazing things. But if that belief is based on a lie, eventually, it's gonna lead to real trouble." ~Applejack

	
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
