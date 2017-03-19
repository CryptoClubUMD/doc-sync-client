#include <vector>
#include <string>

class CSVConfig {
private:
	// Each row
	std::vector<std::vector<std::string>> rows;

	// Location of the config file
	std::string location;

	// Explode string by commas
	std::vector<std::string> commaExplode(std::string) const;
public:
	CSVConfig(std::string rlocation);

	// Get value at position
	std::string getValue(unsigned int row, unsigned int column) const;

	// Row count
	unsigned int rowCount() const;
};
