#ifndef PARSEREXCEPTION_HPP
#define PARSEREXCEPTION_HPP

#include <cstdint>
#include <string>


namespace tangram::game {
    
    class ParserException : public std::exception {
        
        private:
            const std::string path;
            const uint16_t lin;
            const uint16_t col;
            const std::string msg;
        
        public:
            ParserException(const std::string &t_path, uint16_t t_lin, uint16_t t_col, const std::string &t_msg);
            
            std::string getPath() const;
            
            uint16_t getLine() const;
            
            uint16_t getColumn() const;
            
            std::string getMessage() const;
            
            const char *what() const noexcept;
    };
}

#endif // PARSEREXCEPTION_HPP
