struct bytesOutputWithData{
	unsigned long long size;
	char* bufferPointer;
};

struct bitsInByte{
	char bits[8];
};

bitsInByte byteToBit(char byteIn);
bytesOutputWithData fileToBytes(char* fileName, char* bytesOut);
char* unsignedlonglongToFormattedHex(unsigned long long longlongIn);
char* buildAndPrintLine(char* bitsA, char* bitsB, unsigned long long address);

