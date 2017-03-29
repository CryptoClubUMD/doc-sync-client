#define DEBUG_MODE

#include <new>
#include <iostream>
#include "Document.h"

#ifdef DEBUG_MODE
#include "tests.h"
#endif

int main(){
	testJson();
	
	//Document testdoc = Document("../test/foofile.txt");
	
	return EXIT_SUCCESS;
}
