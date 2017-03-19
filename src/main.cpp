#include <iostream>
#include <new>
#include "Document.h"

int main(){
	Document testdoc = Document("../test/foofile.txt");

	testdoc.initialize();

	return EXIT_SUCCESS;
}
