#include <string>

class Commit {
private:
	// The actual text contained by the line
	std::string line_content;

	// The line number that was affected
	unsigned int line_number;

	// Hash of the line content
	std::string content_hash;

	// The time created
	time_t at_time;

	// Hash of the previous commit timeline hash plus this commit's content hash.
	// SHA-2(previous_timeline_hash + this_content_hash)
	// If first commit, SHA-2("timelinebegin" + this_content_hash)
	std::string timeline_hash;

	// Next commit pointer
	Commit* next_commit = nullptr;

	// Prev commit pointer
	Commit* prev_commit = nullptr;
public:
	Commit();

	// Getter: line_content
	std::string getLineContent() const;

	// Getter: line_number
	unsigned int getLineNumber() const;

	// Getter: content_hash
	std::string getContentHash() const;

	// Getter: timeline_hash
	std::string getTimelineHash() const;

	// Gets a formatted string of the time that the commit was created
	std::string creationTime() const;
};
