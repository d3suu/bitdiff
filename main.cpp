#include <iostream> //std::cout
#include <string.h> //memcpy, strcpy, strncpy
#include <stdio.h> //sprintf

#include "main.h" //TODO: divide functions to separate files

//TODO: documentate code for god's sake, i can't even remember what "bitsInByte" is.

bitsInByte byteToBit(char byteIn){
	unsigned char mask = 1;
	char buffer[8];
	for(int i=7; i>=0; i--){
		buffer[i] = (byteIn & mask)?'1':'0';
		mask = mask << 1;
	}
	
	bitsInByte totallyThis;
	for(int i=0; i<8; i++){
		totallyThis.bits[i] = buffer[i];
	};
	return totallyThis;
}

bytesOutputWithData fileToBytes(char* fileName){
	FILE *fp;
	fp = fopen(fileName, "r");
	fseek(fp, 0L, SEEK_END);
	unsigned long long size = ftell(fp);
	rewind(fp);
	char* buffer = new char[size];

	for(unsigned long long i=0;i<size;i++){
		buffer[i] = fgetc(fp);
	}
	fclose(fp);

	bytesOutputWithData totallyThis;
	totallyThis.size = size;
	totallyThis.bufferPointer = buffer;
	return totallyThis;
}

char* buildAndPrintLine(char* bitsA, char* bitsB, unsigned long long address){
	char* totallyThis = new char[29];
	for(int i = 0; i<29; i++){
		totallyThis[i] = ' ';
	}

	char* p_totallyThis = reinterpret_cast<char*>(totallyThis); //TODO: check if this has any sense
	
	strncpy(p_totallyThis, unsignedlonglongToFormattedHex(address), 10);
	p_totallyThis += 12;
	strncpy(p_totallyThis, bitsA, 8);
	p_totallyThis += 9;
	strncpy(p_totallyThis, bitsB, 8); //TODO: make prettier output, show which bit changed

	return totallyThis;
}

char* unsignedlonglongToFormattedHex(unsigned long long longlongIn){
	// output is formated, has to be 11 bytes in total, starts with "0x"
	char* totallyThis = new char[11];
	for(int i = 0; i<11; i++){
		totallyThis[i] = '0';
	}
	totallyThis[1] = 'x';

	char buffer[9];
	sprintf(buffer, "%0x", (int)longlongIn+1); //address offset
	
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

int main(){ //TODO: let only main() be in main.cpp
	bytesOutputWithData fileA = fileToBytes("testa.txt"); //TODO: plz use getopt
	bytesOutputWithData fileB = fileToBytes("testb.txt");

	if(fileA.size != fileB.size){
		std::cout << "size of files does not match! using size of first file.\n";
	} //TODO: use size which is longer
	  //TODO: throw some error for debuging in future
	
	int howMuch = 0; //not-TODO: How many software people does it take to screw in a light bulb? None. That's a hardware problem.

	for(unsigned long long a = 0; a<fileA.size; a++){
		if(fileA.bufferPointer[a] != fileB.bufferPointer[a]){
			bitsInByte bitsA = byteToBit(fileA.bufferPointer[a]);
			bitsInByte bitsB = byteToBit(fileB.bufferPointer[a]);
			std::cout << buildAndPrintLine(bitsA.bits, bitsB.bits, a);
			std::cout << '\n';
			howMuch++;
		}
	}
	
	std::cout << "\nTotally diffs found: " << howMuch << "\n";
	return 0;
}
