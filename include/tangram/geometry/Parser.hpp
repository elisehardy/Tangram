#ifndef PARSER_HPP
#define PARSER_HPP

#include <cstdint>
#include <string>

#include <tangram/geometry/Point.hpp>
#include <tangram/geometry/Polygon.hpp>


namespace tangram::geometry {
    
    class Shape;
    
    
    
    class Parser {
        private:
            const std::string PATTERN_POINT = R"(\s*\((.|\n)+\)\s*)";
            const std::string PATTERN_TRIANGLE = R"((\s|\n)*\[(.|\n)+\])";
            const std::string PATTERN_POLYGON = R"((\s|\n)*\{(.|\n)+\})";
        
        private:
            std::ifstream file = {};
            std::string path = {};
            uint16_t lin = 0;
            uint16_t col = 0;
            
            [[noreturn]] void error(const std::string &what) const;
            
            std::string read(const std::string &pattern, bool allowEmpty = false);
        
            int16_t parseShort(uint8_t radix = 10);
            
            geometry::Point16 parsePoint();
            
            geometry::Triangle parseTriangle();
            
            geometry::Polygon parsePolygon();
        
        public:
            
            Parser() = default;
            
            geometry::Shape operator()(const std::string& path);
    };
}

#endif //PARSER_HPP
