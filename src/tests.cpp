#include <cassert>
#include <iostream>
#include <fstream>
#include "json/json.h"
#include <sodium.h>

void testJson(){
	Json::Value root;
	Json::Reader reader;
	const std::string DEFAULT_STR_VALUE = "Unknown";

	std::ifstream test("../test/json-test.json");
	bool parsingSuccessful = reader.parse(test, root, false);

	if (!parsingSuccessful){
		std::cout  << reader.getFormattedErrorMessages() << "\n";
	}

	std::string my_name = root.get("my_name", DEFAULT_STR_VALUE).asString();
	int fav_num = root.get("fav_num", DEFAULT_STR_VALUE).asInt();
	bool awesome = root.get("awesome", DEFAULT_STR_VALUE).asBool();
	assert(my_name == "slim shady");
	assert(fav_num == 42);
	assert(awesome == true);
	std::cout << "JSON read test completed successfully.\n";
}

void testCrypto(){
	std::string message_string = "test";
	const unsigned char* message_raw = message_string.c_str();
	unsigned char hash[crypto_generichash_BYTES];

	crypto_generichash(hash, sizeof hash, message_raw, 4, NULL, 0);

	assert(hash == "a94a8fe5ccb19ba61c4c0873d391e987982fbbd3");
}
