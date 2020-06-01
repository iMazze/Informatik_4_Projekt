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
	_list.~vector();
}

void XML_Writer::writeCalculationsToXML(const std::string &filename)
{
	xmlDocPtr doc;
	xmlNodePtr root_node;

	//new document instance
	doc = xmlNewDoc(BAD_CAST "1.0");

	//set root node
	root_node = xmlNewNode(NULL, BAD_CAST "root");
	xmlDocSetRootElement(doc, root_node);

	//create a comment
	xmlNodePtr comment = xmlNewComment(BAD_CAST "All Calculations made in complex_calculator");
	xmlAddChild(root_node, comment);

	int counter=1;
	for (auto i : _list)
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

		// Add Calculation to XML
		xmlNodePtr content = xmlNewText(BAD_CAST operation.c_str());
		xmlAddChild(root_node, node);
		xmlAddChild(node, content);
		xmlNodePtr grandson = xmlNewNode(NULL, BAD_CAST "zahl1");
		xmlAddChild(node, grandson);
		xmlNewProp(grandson, BAD_CAST"karthesisch", BAD_CAST i.getNumber1().toString().c_str());
		xmlNewProp(grandson, BAD_CAST"polar", BAD_CAST i.getNumber1().toPolarString().c_str());
		xmlAddChild(node, content);
		grandson = xmlNewNode(NULL, BAD_CAST "zahl2");
		xmlAddChild(node, grandson);
		xmlNewProp(grandson, BAD_CAST"karthesisch", BAD_CAST i.getNumber2().toString().c_str());
		xmlNewProp(grandson, BAD_CAST"polar", BAD_CAST i.getNumber2().toPolarString().c_str());
		xmlAddChild(node, content);
		grandson = xmlNewNode(NULL, BAD_CAST "Ergebnis");
		xmlAddChild(node, grandson);
		xmlNewProp(grandson, BAD_CAST"karthesisch", BAD_CAST i.getResult().toString().c_str());
		xmlNewProp(grandson, BAD_CAST"polar", BAD_CAST i.getResult().toPolarString().c_str());

		counter++;
	}




	//save the document
	int nRel = xmlSaveFile(filename.c_str(), doc);
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
	_list.push_back(calc);
}

