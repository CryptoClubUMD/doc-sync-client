#include "Document.h"

bool cachedIsLastCommit() const{
	
}

void cacheDoc() const{
	if(!cachedIsLastCommit()){

	}
}

void Document::rollback(std::string timeline_hash){

}

void Document::bringup(){

}

std::string Document::getHeadHash() const{
	return head_hash;
}

std::string Document::getDocumentLocation() const{
	return document_location;
}

Commit* Document::getHeadCommit() const{
	return head_commit;
}

void Document::setHeadCommit(Commit* new_head){
	head_commit = new_head;
}

void Document::scanDiff(){

}
