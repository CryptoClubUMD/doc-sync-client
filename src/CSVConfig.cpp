#include <fstream>
#include <vector>
#include <string>

CSVConfig::CSVConfig(std::string rlocation){
	std::ifstream filehook;
	std::string line;
	filehook.open(rlocation.c_str());

	std::vector<std::string> row_contents;

	while(getline(filehook, line)){
		row_contents = commaExplode(line);
	}
}

std::string CSVConfig::getValue(unsigned int row, unsigned int column){
	return "value";
}

unsigned int CSVConfig::rowCount() const{
	return 0;
}

std::vector<std::string> commaExplode(std::string) const{
	std::vector<std::string> values;

	return values;
}
