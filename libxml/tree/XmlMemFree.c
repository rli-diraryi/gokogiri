#include <libxml/parser.h> 
#include <libxml/tree.h> 
#include <libxml/xmlstring.h> 
#include "XmlMemFree.h"
//#include "_cgo_export.h"

void newXmlMemFree(void * ptr) {
	XmlNodeFreedByLibXml(ptr);
	xmlMemFree(ptr);
}

void newXmlMemRealloc(void * ptr, size_t size) {
	XmlNodeFreedByLibXml(ptr);
	xmlMemRealloc(ptr, size);
}

void initMemFreeCallback() {
	xmlMemSetup(newXmlMemFree, xmlMemMalloc, newXmlMemRealloc, xmlMemoryStrdup);
}
