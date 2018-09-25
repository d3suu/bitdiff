#include <unistd.h> //getopt
#include <stdlib.h> //abort

#include "exceptions.h"
#include "bitdiff.h"

int main(int argc, char** argv){
	int c;
	char* fileAName = (char*)"testa.txt"; // WIP static constants until no file testing in bitdiff() function
	char* fileBName = (char*)"testb.txt";

	while((c = getopt(argc, argv, "a:b:h")) != -1){ // TODO make arguments for type of output size type (normally hex), output method (stdout, file output), formatting of output (human readable, easy-scraping type, machine type)
		switch(c){
			case 'a':
				fileAName = optarg;
				break;
			case 'b':
				fileBName = optarg;
				break;
			case 'h':
				//help(); WIP
				// TODO help should output some help text and kill process
				break;
			default:
				abort();
		}
	}

	bitdiff(fileAName, fileBName);
	return 0;
}
