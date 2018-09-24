#include "io.h"
#include "math.h"
#include <string.h>
#include <stdio.h>

bytesOutputWithData fileToBytes(char* fileName){
	FILE *fp;
	fp = fopen(fileName, "r");

	fseek(fp, 0L, SEEK_END);		// check size of file (in bytes)
	unsigned long long size = ftell(fp);
	rewind(fp);
	
	char* buffer = new char[size];

	for(unsigned long long i=0;i<size;i++){
		buffer[i] = fgetc(fp);		// get file content to memory, byte by byte
	}
	fclose(fp);

	bytesOutputWithData totallyThis;	// return object
	totallyThis.size = size;
	totallyThis.bufferPointer = buffer;
	return totallyThis;
}

char* buildAndPrintLine(char* bitsA, char* bitsB, unsigned long long address){
	char* totallyThis = new char[29];

	for(int i = 0; i<29; i++){		// clear memory
		totallyThis[i] = ' ';
	}

	char* p_totallyThis = totallyThis; 	// make pointer to buildAndPrintLine return object to paste address and bits 
		
	strncpy(p_totallyThis, unsignedlonglongToFormattedHex(address), 10);
	p_totallyThis += 11;			// <- offset
	strncpy(p_totallyThis, bitsA, 8);	// <- paste with offset
	p_totallyThis += 9;
	strncpy(p_totallyThis, bitsB, 8);
	p_totallyThis += 8;
	strncpy(p_totallyThis, "\0", 1); 	// this fixes random character on the end
	
	return totallyThis;
}
