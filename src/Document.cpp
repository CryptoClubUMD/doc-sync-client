#include <iostream>
#include <string>

#include "Document.h"
#include "CSVConfig.h"

Document::Document(std::string rdocument_location){
	document_location = rdocument_location;
}

void Document::initialize(){
	// Attempting to initialize more than once may yield unexpected behavior
	if(!initialized){
		if(documentIsTracked()){
			// Fill in document variables from file
			// Make sure cached correctly
			// Load commits for that file
		}else{
			// Create an add commit for each line already existing
			// Cache the document in the compare folder
			// Add the document to the tracked list
		}
		initialized = true;
	}
}

bool Document::documentIsTracked() const{
	// Load the tracked document list
	CSVConfig tracked_docs = CSVConfig("../data/tracked_docs.csv");
	bool is_tracked(false);

	// We don't want to be checking unless the file url for this document is defined
	// TODO: Error if the document location is empty
	if(!document_location.empty()){
		// For each file entry in the list of tracked documents
		for(unsigned int i = 0; i < tracked_docs.rowCount(); ++i){
			if(document_location == tracked_docs.getValue(i, 0)){
				// The document location is found in the CSV document list
				is_tracked = true;
			}
			// TODO: If there are duplicate entries found for one file URL, throw an error
		}
	}
	
	return is_tracked;
}

bool Document::cachedIsLastCommit() const{
	return false;
}

void Document::cacheDoc() const{
	if(!cachedIsLastCommit()){

	}
}

void Document::rollback(std::string timeline_hash){

}

void Document::bringup(){

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

}
