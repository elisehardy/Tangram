#include <regex>

#include <tangram/geometry/Parser.hpp>
#include <tangram/geometry/ParserException.hpp>
#include <tangram/geometry/Shape.hpp>


namespace tangram::geometry {
    
    void Parser::error(const std::string &what) const {
        throw ParserException(this->path, this->lin, this->col, what);
    }
    
    
    std::string Parser::read(const std::string &pattern, bool allowEmpty) {
        std::string tmp = std::string(1, char(this->file.get()));
        std::regex re { pattern };
        std::stringstream ss;
        
        while (std::regex_match(tmp, re)) {
            if (tmp == "\n") {
                this->lin++;
                this->col = 0;
            }
            else {
                this->col++;
            }
            
            ss << tmp;
            tmp = std::string(1, char(this->file.get()));
        }
        
        if (!allowEmpty && ss.str().empty()) {
            this->error("Next character does not match regex '" + pattern + "' (character '" + tmp + "' has been found"
            );
        }
        
        this->file.unget();
        
        return ss.str();
    }
    
    
    int16_t Parser::parseShort(uint8_t radix) {
        std::string s = this->read("\\d");
        size_t idx;
        long l;
        
        try {
            l = stol(s, &idx, radix);
        } catch (const std::invalid_argument &e) {
            this->error(e.what());
        } catch (const std::out_of_range &e) {
            this->error(e.what());
        }
        
        return int16_t(l);
    }
    
    
    geometry::Point16 Parser::parsePoint() {
        int16_t x, y;
        
        this->read("(\\s|\n)", true);
        this->read("\\(");
        
        this->read("(\\s|\n)", true);
        x = parseShort();
        this->read("(\\s|\n)", true);
        this->read(",");
        this->read("(\\s|\n)", true);
        y = parseShort();
        
        this->read("(\\s|\n)", true);
        this->read("\\)");
        
        return { x, y };
    }
    
    
    geometry::Triangle Parser::parseTriangle() {
        geometry::Point16 p1, p2, p3;
        
        this->read("(\\s|\n)", true);
        this->read("\\[");
        
        this->read("(\\s|\n)", true);
        p1 = parsePoint();
        this->read("(\\s|\n)", true);
        p2 = parsePoint();
        this->read("(\\s|\n)", true);
        p3 = parsePoint();
        
        this->read("(\\s|\n)", true);
        this->read("\\]");
        
        return { p1, p2, p3 };
    }
    
    
    geometry::Polygon Parser::parsePolygon() {
        geometry::Polygon polygon = geometry::Polygon(MLV_COLOR_GREY50);
        
        this->read("(\\s|\n)", true);
        this->read("\\{");
        
        polygon.add(this->parseTriangle());
        this->read("(\\s|\n)", true);
        while (this->file.peek() == '[') {
            polygon.add(this->parseTriangle());
            this->read("(\\s|\n)", true);
        }
        
        this->read("(\\s|\n)", true);
        this->read("\\}");
        
        return polygon;
    }
    
    
    geometry::Shape Parser::operator()(const std::string &path) {
        geometry::Shape shape;
        
        this->file = std::ifstream(path);
        this->path = path;
        this->lin = 0;
        this->col = 0;
        
        for (int i = 0; i < 7; i++) {
            shape.addPolygon(this->parsePolygon());
        }
        
        this->file.close();
        
        return shape;
    }
}
