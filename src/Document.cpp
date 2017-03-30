#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>

#include "Document.h"

Document::Document(std::string rdocument_location){
	document_location = rdocument_location;
	initialize();
}

Document::Document(unsigned int rtracked_id){
	tracked_id = rtracked_id;
	loadDocumentMeta();	
}


void Document::initialize(){
	// Attempting to initialize more than once may yield unexpected behavior
	if(!initialized){
		// TODO: Create an add commit for each line already existing
		// TODO: Cache the document in the compare folder
		// TODO: Add the document to the tracked list
		initialized = true;
	}
}

void Document::loadDocumentMeta() const{
	// TODO: Error if the document location is empty
	// TODO: If there are duplicate entries found for one file URL, throw an error
}

std::string Document::filename() const{
	std::stringstream rawcontent(document_location);
	std::vector<std::string> values;
	std::string segment;
	
	// TODO: "/" may not work on non-unix environments due to file urls being stored differently
	while(std::getline(rawcontent, segment, '/')){
		values.push_back(segment);
	}

	return values[values.size() - 1];
}

bool Document::cachedIsLastCommit() const{
	return false;
}

void Document::cacheDoc() const{
	if(!cachedIsLastCommit()){
		// TODO: Consider implementing better security here... copying without checking URL could be risky
		std::ifstream src(document_location, std::ios::binary);
		// TODO: Will need to make a unique way to store this file... what if there are multiple files tracked with same file name?
    std::ofstream dst("../data/compare/old_"+filename(), std::ios::binary);

    dst << src.rdbuf();
	}
}

void Document::rollback(std::string timeline_hash){
	// TODO: Implement this function
}

void Document::bringup(){
	// TODO: Implement this function
}

std::string Document::getHeadHash() const{
	std::string head_hash = "DOC_HASH_AT_HEAD";
	return head_hash;
}

std::string Document::getDocumentLocation() const{
	return document_location;
}

std::shared_ptr<Commit> Document::getHeadCommit() const{
	return head_commit;
}

void Document::setHeadCommit(std::shared_ptr<Commit> new_head){
	head_commit = new_head;
}

void Document::scanDiff(){
	// Only scan for differences if the compare document contains the last known commit.
	if(cachedIsLastCommit()){
		
	}
}

std::shared_ptr<Commit> Document::commitLine(unsigned int line_num, commit_type_t commit_type){
	std::ifstream file_handle;
	file_handle.open(document_location.c_str());
	unsigned int line_counter(1);
	std::string the_line;
	bool line_found(false);
	
	while(!line_found && getline(file_handle, the_line)){
		if(line_counter == line_num){
			line_found = true;
		}else{
			++line_counter;
		}
	}

	if(!line_found){
		// TODO: Exception upon line not being found.
		throw 1;
	}

	auto new_commit = std::make_shared<Commit>(the_line, line_num, tracked_id);

	return new_commit;
}
