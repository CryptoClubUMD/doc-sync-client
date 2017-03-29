#include <cassert>
#include <iostream>
#include <fstream>
#include <json/json.h>

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
