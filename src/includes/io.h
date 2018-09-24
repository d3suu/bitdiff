struct bytesOutputWithData{	// data object for files, stores content and its size in bytes
	unsigned long long size;
	char* bufferPointer;
};

bytesOutputWithData fileToBytes(char* fileName); // opens file, reads its content, closes file 
char* buildAndPrintLine(char* bitsA, char* bitsB, unsigned long long address); // makes line with data and prints it 

