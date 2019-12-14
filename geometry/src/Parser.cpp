#include "../include/Parser.hpp"

#include <regex>

#include "../include/ParserException.hpp"
#include "../include/Shape.hpp"


using namespace tangram;
using namespace tangram::geometry;


void Parser::error(const std::string &what) const {
    throw "not yet implemented";
}


long Parser::parseLong(const std::string &s, uint8_t radix) {
    return 0;
}


bool Parser::parseBool(const std::string &s) {
    return false;
}


geometry::Point16 Parser::parsePoint(const std::string &s) {
    return {0,0};
}

/*
geometry::Polygon Parser::parsePolygon(const std::string &s) {
  return Polygon(0);
}*/


geometry::Shape Parser::operator()(std::string) {
    return Shape();
}
