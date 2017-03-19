#include <fstream>
#include <vector>
#include <string>
#include <sstream>

#include "CSVConfig.h"

CSVConfig::CSVConfig(std::string rlocation){
	std::ifstream filehook;
	std::string line;
	filehook.open(rlocation.c_str());

	while(std::getline(filehook, line)){
		rows.push_back(commaExplode(line));
	}
}

std::string CSVConfig::getValue(unsigned int row, unsigned int column) const{
	return rows[row][column];
}

unsigned int CSVConfig::rowCount() const{
	return rows.size();
}

std::vector<std::string> CSVConfig::commaExplode(std::string line) const{
	std::stringstream rawcontent(line);
	std::vector<std::string> values;
	std::string segment;

	while(std::getline(rawcontent, segment, ',')){
		values.push_back(segment);
	}

	return values;
}
