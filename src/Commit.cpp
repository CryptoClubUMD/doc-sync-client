#include "Commit.h"

Commit::Commit(unsigned int commit_id){

}
	
Commit::Commit(std::string line_content, unsigned int line_number, unsigned int document_id):
	line_content(line_content),	
	line_number(line_number),
	document_id(document_id){
	
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
