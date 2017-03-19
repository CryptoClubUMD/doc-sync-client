#include <string>
#include <vector>
#include <memory>
#include "Commit.h"

class Document {
private:
	// Only load the last N commits into the history.
	// This is to save RAM and not load ALL history.
	static const unsigned int cached_commit_history = 20;

	bool initialized = false;

	// Local document location
	std::string document_location;

	// The head commit is the timeline hash where the document is in it's most final form
	std::shared_ptr<Commit> head_commit;

	// Where the old file cache is stored
	//static std::string old_cache_dir;

	// Determines whether the last cached version of this file is in line with the last known commit
	bool cachedIsLastCommit() const;

	// Commit count
	unsigned int commit_count;

	// Creates the cache file at latest commit in the 'oldcache' directory.
	// Name of the file is "old_[latest commit full hash]_[document name].[document_extension]"
	void cacheDoc() const;
public:
	Document();

	Document(std::string rdocument_location);

	// Rollback the commit history to a certain point in the timeline.
	void rollback(std::string timeline_hash);

	// Build document up to latest commit
	void bringup();

	// Initialize the document for tracking
	void initialize();

	// Gets document hash at the head commit
	std::string getHeadHash() const;

	// Save document tracking metadata
	void saveDocMeta() const;

	// Getter: document_location
	std::string getDocumentLocation() const;

	// Getter: head_commit
	std::shared_ptr<Commit> getHeadCommit() const;

	// Sets the head commit
	void setHeadCommit(std::shared_ptr<Commit> new_head);

	// Find differences and add them as commits
	void scanDiff();
};
