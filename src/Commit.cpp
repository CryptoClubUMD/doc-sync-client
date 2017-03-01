#include "Commit.h"

Commit::Commit(){

}

std::string Commit::getLineContent() const{
	return line_content;
}

unsigned int Commit::getLineNumber() const{
	return line_number;
}

std::string Commit::getContentHash() const{
	return content_hash;
}

std::string Commit::getTimelineHash() const{
	return timeline_hash;
}

std::string Commit::creationTime() const{
	return "TIME";
}
