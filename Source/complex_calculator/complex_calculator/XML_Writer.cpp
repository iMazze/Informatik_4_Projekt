#include "XML_Writer.h"


#include <stdio.h>
#include <string.h>
#include <libxml/encoding.h>
#include <libxml/xmlwriter.h>



XML_Writer::XML_Writer()
{
	

}


XML_Writer::~XML_Writer()
{
}



static xmlNodePtr get_child(xmlNodePtr parent, xmlChar* name, xmlChar** content, xmlChar* attr, xmlChar** attrVal);

#define XML_FILE_NAME "test2.xml"
void create_xmldoc()

{

	xmlDocPtr doc;
	xmlNodePtr root_node;

	//new document instance
	doc = xmlNewDoc(BAD_CAST"1.0");
	
	//set root node
	root_node = xmlNewNode(NULL, BAD_CAST"root");
	xmlDocSetRootElement(doc, root_node);

	//create a comment and cdata section
	xmlNodePtr cdata = xmlNewCDataBlock(doc, BAD_CAST "This is a CData block", xmlStrlen(BAD_CAST "This is a CData block"));
	xmlAddChild(root_node, cdata);
	xmlNodePtr comment = xmlNewComment(BAD_CAST "This is a comment node");
	xmlAddChild(root_node, comment);
	
	//create a node with content and attribute, add to root
	xmlNodePtr node = xmlNewNode(NULL, BAD_CAST"rechnung1");
	xmlNodePtr content = xmlNewText(BAD_CAST"Addition");
	xmlAddChild(root_node, node);
	xmlAddChild(node, content);
	xmlNodePtr grandson = xmlNewNode(NULL, BAD_CAST "zahl1");
	xmlAddChild(node, grandson);
	xmlNewProp(grandson, BAD_CAST"karthesisch", BAD_CAST "12+j10");
	xmlNewProp(grandson, BAD_CAST"polar", BAD_CAST "12*e^32");
	xmlAddChild(node, content);
	grandson = xmlNewNode(NULL, BAD_CAST "zahl2");
	xmlAddChild(node, grandson);
	xmlNewProp(grandson, BAD_CAST"karthesisch", BAD_CAST "12+j10");
	xmlNewProp(grandson, BAD_CAST"polar", BAD_CAST "12*e^32");
	xmlAddChild(node, content);
	grandson = xmlNewNode(NULL, BAD_CAST "Ergebnis");
	xmlAddChild(node, grandson);
	xmlNewProp(grandson, BAD_CAST"karthesisch", BAD_CAST "12+j10");
	xmlNewProp(grandson, BAD_CAST"polar", BAD_CAST "12*e^32");

	

	//save the document
	int nRel = xmlSaveFile(XML_FILE_NAME, doc);
	if (nRel != -1)
	{
		xmlChar *docstr;
		int len;
		xmlDocDumpMemory(doc, &docstr, &len);
	}

	//memory free
	xmlFreeDoc(doc);

}

void read_xmldoc()

{

	xmlDocPtr doc;

	xmlNodePtr curNode;

	xmlChar *szKey;

	xmlChar *szAttr;

	xmlChar *content;

	xmlChar *attrVal;



	// parsing the xml file and return the doc handler(xmlDocPtr)

	doc = xmlParseFile(XML_FILE_NAME);

	if (NULL == doc)

	{


	}



	//get root element

	curNode = xmlDocGetRootElement(doc);

	if (NULL == curNode)

	{


	}

	if (xmlStrcmp(curNode->name, BAD_CAST "root"))

	{

		xmlFreeDoc(doc);

	}



	// search children by node name

	szKey = BAD_CAST "node2";

	szAttr = BAD_CAST "attribute";

	get_child(curNode, szKey, &content, szAttr, &attrVal);



	xmlFree(content);

	xmlFree(attrVal);



	szKey = BAD_CAST "son";

	curNode = get_child(curNode, BAD_CAST "son", &content, NULL, NULL);


	xmlFree(content);

	szKey = BAD_CAST "grandson";

	get_child(curNode, BAD_CAST "grandson", &content, NULL, NULL);


	xmlFree(content);



	xmlFreeDoc(doc);

}

static xmlNodePtr get_child(xmlNodePtr parent, xmlChar* name, xmlChar** content, xmlChar* attr, xmlChar** attrVal)

{

	xmlNodePtr curNode;

	xmlChar *szContent;

	xmlChar* szAttr;



	curNode = parent->xmlChildrenNode;

	while (curNode != NULL)

	{

		// get content of node

		if (!xmlStrcmp(curNode->name, name))

		{

			szContent = xmlNodeGetContent(curNode);

			*content = szContent;

			break;

		}

		curNode = curNode->next;

	}



	// get value of attribute if exists

	if (curNode != NULL &&

		attr != NULL &&

		xmlHasProp(curNode, attr))

	{

		szAttr = xmlGetProp(curNode, attr);

		*attrVal = szAttr;

	}



	return curNode;

}

void XML_Writer::doxml()
{

	xmlTextWriterPtr writer;
	writer = xmlNewTextWriterFilename("test.xml", 0);
	xmlTextWriterStartDocument(writer, NULL, "UTF-8", NULL);
	xmlTextWriterStartElement(writer, (const xmlChar *)"Powersettings");
	xmlTextWriterWriteElement(writer, (const xmlChar *)"PowderScheme", (const xmlChar *) "Testing"); 
	xmlTextWriterEndElement(writer);
	xmlTextWriterWriteElement(writer, (const xmlChar *)"CPUSpeed", (const xmlChar *) "Adaptive"); 
	xmlTextWriterEndElement(writer);
	/* ... etc ... */
	xmlTextWriterEndElement(writer);
	xmlTextWriterEndDocument(writer);
	xmlFreeTextWriter(writer);

	create_xmldoc();
}

void XML_Writer::writexml()
{
	xmlDocPtr doc;
	xmlNodePtr root_node;

	//new document instance
	doc = xmlNewDoc(BAD_CAST"1.0");

	//set root node
	root_node = xmlNewNode(NULL, BAD_CAST"root");
	xmlDocSetRootElement(doc, root_node);

	//create a comment and cdata section
	xmlNodePtr cdata = xmlNewCDataBlock(doc, BAD_CAST "This is a CData block", xmlStrlen(BAD_CAST "This is a CData block"));
	xmlAddChild(root_node, cdata);
	xmlNodePtr comment = xmlNewComment(BAD_CAST "This is a comment node");
	xmlAddChild(root_node, comment);

	for (auto i : list)
	{
		//create a node with content and attribute, add to root
		xmlNodePtr node = xmlNewNode(NULL, BAD_CAST"rechnung1");
		xmlNodePtr content = xmlNewText(BAD_CAST"Addition");
		xmlAddChild(root_node, node);
		xmlAddChild(node, content);
		xmlNodePtr grandson = xmlNewNode(NULL, BAD_CAST "zahl1");
		xmlAddChild(node, grandson);
		xmlNewProp(grandson, BAD_CAST"karthesisch", BAD_CAST "12+j10");
		xmlNewProp(grandson, BAD_CAST"polar", BAD_CAST "12*e^32");
		xmlAddChild(node, content);
		grandson = xmlNewNode(NULL, BAD_CAST "zahl2");
		xmlAddChild(node, grandson);
		xmlNewProp(grandson, BAD_CAST"karthesisch", BAD_CAST "12+j10");
		xmlNewProp(grandson, BAD_CAST"polar", BAD_CAST "12*e^32");
		xmlAddChild(node, content);
		grandson = xmlNewNode(NULL, BAD_CAST "Ergebnis");
		xmlAddChild(node, grandson);
		xmlNewProp(grandson, BAD_CAST"karthesisch", BAD_CAST "12+j10");
		xmlNewProp(grandson, BAD_CAST"polar", BAD_CAST "12*e^32");
	}
	



	//save the document
	int nRel = xmlSaveFile(XML_FILE_NAME, doc);
	if (nRel != -1)
	{
		xmlChar *docstr;
		int len;
		xmlDocDumpMemory(doc, &docstr, &len);
	}

	//memory free
	xmlFreeDoc(doc);
	
}

void XML_Writer::writeCalculationsToXML()
{
	xmlDocPtr doc;
	xmlNodePtr root_node;

	//new document instance
	doc = xmlNewDoc(BAD_CAST"1.0");

	//set root node
	root_node = xmlNewNode(NULL, BAD_CAST"root");
	xmlDocSetRootElement(doc, root_node);

	//create a comment and cdata section
	xmlNodePtr comment = xmlNewComment(BAD_CAST "All Calculations made in complex_calculator");
	xmlAddChild(root_node, comment);

	int counter=1;
	for (auto i : list)
	{
		//create a node with content and attribute, add to root
		xmlNodePtr node = xmlNewNode(NULL, BAD_CAST ("calculation_" + std::to_string(counter)).c_str());
		
		std::string operation;
		switch (i.getLastOperation())
		{
			case E_Operation::ADD:
				operation = "Addition";
				break;
			case E_Operation::SUBTRACT:
				operation = "Subtraction";
				break;
			case E_Operation::MULTIPLY:
				operation = "Multiplication";
				break;
			case E_Operation::DIVIDE:
				operation = "Division";
				break;
		}

		xmlNodePtr content = xmlNewText(BAD_CAST operation.c_str());
		xmlAddChild(root_node, node);
		xmlAddChild(node, content);
		xmlNodePtr grandson = xmlNewNode(NULL, BAD_CAST "zahl1");
		xmlAddChild(node, grandson);
		xmlNewProp(grandson, BAD_CAST"karthesisch", BAD_CAST i.getNumber1().ComplexToString().c_str());
		xmlNewProp(grandson, BAD_CAST"polar", BAD_CAST i.getNumber1().ComplexToPolarString().c_str());
		xmlAddChild(node, content);
		grandson = xmlNewNode(NULL, BAD_CAST "zahl2");
		xmlAddChild(node, grandson);
		xmlNewProp(grandson, BAD_CAST"karthesisch", BAD_CAST i.getNumber2().ComplexToString().c_str());
		xmlNewProp(grandson, BAD_CAST"polar", BAD_CAST i.getNumber2().ComplexToPolarString().c_str());
		xmlAddChild(node, content);
		grandson = xmlNewNode(NULL, BAD_CAST "Ergebnis");
		xmlAddChild(node, grandson);
		xmlNewProp(grandson, BAD_CAST"karthesisch", BAD_CAST i.getResult().ComplexToString().c_str());
		xmlNewProp(grandson, BAD_CAST"polar", BAD_CAST i.getResult().ComplexToPolarString().c_str());

		counter++;
	}




	//save the document
	int nRel = xmlSaveFile(XML_FILE_NAME, doc);
	if (nRel != -1)
	{
		xmlChar *docstr;
		int len;
		xmlDocDumpMemory(doc, &docstr, &len);
	}

	//memory free
	xmlFreeDoc(doc);
}

void XML_Writer::addComplexCalculation(const Calculation<Complex>& calc)
{
	list.push_back(calc);
}

