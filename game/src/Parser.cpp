#include "../include/Parser.hpp"

#include <regex>

#include "../include/ParserException.hpp"


using namespace tangram;
using namespace tangram::game;


void Parser::error(const std::string &what) const {
    throw ParserException(this->path, this->lin, this->col, what);
}


long Parser::parseLong(const std::string &s, uint8_t radix) {
    size_t idx;
    long l;
    
    try {
        l = stol(s, &idx, radix);
        col += idx + 1;
    } catch (const std::invalid_argument &e) {
        col += idx + 1;
        this->error(e.what());
    } catch (const std::out_of_range &e) {
        col += idx + 1;
        this->error(e.what());
    }
    
    return l;
}


bool Parser::parseBool(const std::string &s) {
    size_t idx;
    int i;
    
    try {
        i = stoi(s, &idx, 10);
        col += idx + 1;
    } catch (const std::exception &e) {
        col += idx + 1;
        this->error(e.what());
    } catch (const std::out_of_range &e) {
        col += idx + 1;
        this->error(e.what());
    }
    
    return i;
}

//
//geometry::Point16 Parser::parsePoint(const std::string &s) {
//    return nullptr;
////}
//
//
//geometry::Polygon Parser::parsePolygon(const std::string &s) {
//    static const std::regex pattern_color { R"(color: (\d+) (\d+) (\d+))" };
//    static const std::regex pattern_shadow { R"(shadow: (\d))" };
//    static const std::regex pattern_point { R"((\d+) (\d+))" };
//    static const std::regex pattern_triangle { R"((\d+ \d+, \d+ \d+, \d+ \d+))" };
//    std::smatch match, point, axis;
//    std::stringstream sstream(s);
//    std::string line, found;
//    MLV_Color color;
//
//
//    int i = 0;
//    while (std::getline(sstream, line, '\n')) {
//        if (i > 1) {
//            std::regex_search(line, match, pattern_triangle);
//            if (!match.size()) {
//                std::cerr << "Error loading polygon : Line '" << line << "' does not match a valid triangle"
//                          << std::endl;
//                exit(EXIT_FAILURE);
//            }
//        }
//        else if (i == 1) {
//            std::regex_search(line, match, pattern_shadow);
//        }
//        else {
//            std::regex_search(line, match, pattern_color);
//            long size = match.size();
//
//            if (size == 3) {
//            }
//            else {
//                std::cerr << "Error loading polygon : Line '" << line << "' does not match a valid color"
//                          << std::endl;
//                exit(EXIT_FAILURE);
//            }
//        }
//        i++;
//    }
//
//    return Polygon(0);
//}
//
//
//geometry::Shape Parser::operator()(std::string) {
//    return nullptr;
//}
