/** @file Parser.hpp
 *
 *  @brief ***Parser***'s header
 *
 *  @author Elise Hardy
 *  @author Quentin Coumes
 */
 
#ifndef PARSER_HPP
#define PARSER_HPP

#include <cstdint>
#include <string>

#include <tangram/geometry/Point.hpp>
#include <tangram/geometry/Polygon.hpp>


namespace tangram::geometry {
    
    // Here to avoid circular inclusion.
    class Shape;
    
    
    
    /**
     * Class used to parse a file containing the save of a Shape.
     */
    class Parser {
        
        private:
            std::ifstream file = {}; /**< Stream corresponding to the file being parsed. */
            std::string path;        /**< Path to the file being parsed. */
            uint16_t lin = 0;        /**< Line corresponding to the current parser's position. */
            uint16_t col = 0;        /**< Column corresponding to the current parser's position. */
            
            /**
             * Throws a ParserException corresponding to 'what', adding information about the file and the parser's
             * position.
             *
             * @param what Error occurred.
             */
            [[noreturn]] void error(const std::string &what) const;
            
            /**
             * Read characters in stream while they match pattern.
             *
             * If allowEmpty is false, the method will throw a ParserException if the next character of the stream does
             * not match pattern. An empty string will be returned if allowEmpty is true.
             *
             * @param pattern Pattern the character(s) should match.
             * @param allowEmpty false if an exception should be thrown when no character are match, true otherwise.
             *
             * @return Characters read.
             */
            std::string read(const std::string &pattern, bool allowEmpty = false);
            
            /**
             * Parse an integral type.
             *
             * @tparam I Integral type parsed.
             * @param radix Radix use when parsing the number.
             *
             * @return The parsed integral.
             */
            template<class I>
            I parseIntegral(uint8_t radix = 10);
            
            /**
             * Parse a Point<int16_t>.
             *
             * @return The parsed Point.
             */
            geometry::Point16 parsePoint();
            
            /**
             * Parse a Triangle.
             *
             * @return The parsed Triangle.
             */
            geometry::Triangle parseTriangle();
            
            /**
             * Parse a Polygon.
             *
             * @return The parsed Polygon
             */
            geometry::Polygon parsePolygon();
        
        public:
            
            /**
             * Constructor.
             */
            Parser() = default;
            
            /**
             * Parse the file corresponding to path.
             *
             * @param path Path to the file that should be parsed.
             *
             * @return The Shape parsed from the file.
             */
            geometry::Shape operator()(const std::string &path);
    };
}

#endif //PARSER_HPP
