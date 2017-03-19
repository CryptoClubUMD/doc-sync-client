#include <vector>
#include <string>

class CSVConfig {
private:
	// Each row
	std::vector rows;

	// Location of the config file
	std::string location;

public:
	CSVConfig(std::string rlocation);

	// Get value at position
	std::string getValue(unsigned int row, unsigned int column) const;

	// Row count
	unsigned int rowCount() const;
};
