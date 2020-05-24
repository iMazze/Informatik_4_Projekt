#pragma once

#include <vector>

class xml_io
{
public:
	xml_io();
	~xml_io();

	static void doxml();
	void writexml();
private: 
	std::vector<int> list;
};

