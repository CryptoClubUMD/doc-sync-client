#include <string>
#include <vector>
#include "Commit.h"

class Document {
private:
	// Only load the last N commits into the history.
	// This is to save RAM and not load ALL history.
	static const unsigned int cached_commit_history = 20;

	// The commit history, stored as a vector of commits
	std::vector<Commit> commit_history;

	// Local document location
	std::string document_location;

	// The head commit is the timeline hash where the document is in it's most final form
	std::string head_hash;
public:
	// Rollback the commit history to a certain point in the timeline.
	void rollback(std::string timeline_hash);

	// Build document up to latest commit
	void bringup();

	// Getter: head_hash
	std::string getHeadHash() const;

	// Getter: document_location
	std::string getDocumentLocation() const;
};
