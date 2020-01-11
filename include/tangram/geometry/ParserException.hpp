#ifndef PARSEREXCEPTION_HPP
#define PARSEREXCEPTION_HPP

#include <cstdint>
#include <string>


namespace tangram::geometry {
    
    class ParserException : public std::exception {
        
        private:
            const std::string path;
            const uint16_t lin;
            const uint16_t col;
            const std::string msg;
        
        public:
            ParserException(std::string t_path, uint16_t t_lin, uint16_t t_col, std::string t_msg);
            
            ~ParserException() override = default;
            
            [[nodiscard]] std::string getPath() const;
            
            [[nodiscard]] uint16_t getLine() const;
            
            [[nodiscard]] uint16_t getColumn() const;
            
            [[nodiscard]] std::string getMessage() const;
            
            [[nodiscard]] const char *what() const noexcept override;
    };
}

#endif // PARSEREXCEPTION_HPP
