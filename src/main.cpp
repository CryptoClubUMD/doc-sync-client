#include <iostream>
#include "Document.h"

int main(){
	Document testdoc = new Document("../test/foofile.txt");

	testdoc.initialize();

	return EXIT_SUCCESS;
}
