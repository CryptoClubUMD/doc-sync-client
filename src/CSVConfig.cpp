#include <fstream>
#include <vector>
#include <string>

CSVConfig::CSVConfig(std::string rlocation){
	std::ifstream filehook;
	std::string line;
	filehook.open(rlocation.c_str());

	while(getline(filehook, line)){
		rows.push_back(commaExplode(line));
	}
}

std::string CSVConfig::getValue(unsigned int row, unsigned int column){
	return "value";
}

unsigned int CSVConfig::rowCount() const{
	return 0;
}

std::vector<std::string> commaExplode(std::string line) const{
	std::stringstream content(line);
	std::vector<std::string> values;
	std::string segment;

	while(std::getline(content, segment, ",")){
		values.push_back(segment);
	}

	return values;
}
