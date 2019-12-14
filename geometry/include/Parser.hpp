#ifndef PARSER_HPP
#define PARSER_HPP

#include <cstdint>
#include <string>

#include "Point.hpp"


namespace tangram::geometry {
    
    class Shape;
    class Polygon;
    
    class Parser {
        private:
            std::string path ={};
            uint16_t lin = 0;
            uint16_t col = 0;
            
            [[noreturn]] void error(const std::string &what) const;
        
            long parseLong(const std::string &s, uint8_t radix = 10);
            
            bool parseBool(const std::string &s);
            
            geometry::Point16 parsePoint(const std::string &s);
        
            geometry::Polygon parsePolygon(const std::string &s);
        
        public:
            
            Parser() = default;
        
            geometry::Shape operator()(std::string);
    };
}

#endif //PARSER_HPP
