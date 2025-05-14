#ifndef PARSER_H
#define PARSER_H

#include "Graph.h"
#include <string>

class Parser {
public:
    static Graph parse(const std::string& filename); 
};

#endif 
