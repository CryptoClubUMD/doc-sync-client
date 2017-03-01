#include "Document.h"

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
