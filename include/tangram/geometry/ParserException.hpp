#ifndef PARSEREXCEPTION_HPP
#define PARSEREXCEPTION_HPP

#include <cstdint>
#include <string>


namespace tangram::geometry {
    
    /**
     * Exception the Parser use in case of error.
     */
    class ParserException : public std::exception {
        
        private:
            const std::string path; /**< Path of the file being parsed. */
            const uint16_t lin;     /**< Line the error occurred. */
            const uint16_t col;     /**< Column the error occurred. */
            const std::string msg;  /**< Message corresponding to the error. */
        
        public:
            
            /**
             * Constructor.
             *
             * @param path Path of the file being parsed.
             * @param lin Line the error occurred.
             * @param col Column the error occurred.
             * @param msg Message corresponding to the error.
             */
            ParserException(std::string path, uint16_t lin, uint16_t col, std::string msg);
            
            /**
             * Destructor.
             */
            ~ParserException() override = default;
            
            /**
             * Return the path of the file being parsed.
             *
             * @return the path of the file being parsed.
             */
            [[nodiscard]] std::string getPath() const;
            
            /**
             *
             * @return
             */
            [[nodiscard]] uint16_t getLine() const;
            
            /**
             *
             * @return
             */
            [[nodiscard]] uint16_t getColumn() const;
            
            /**
             *
             * @return
             */
            [[nodiscard]] std::string getMessage() const;
            
            [[nodiscard]] const char *what() const noexcept override;
    };
}

#endif // PARSEREXCEPTION_HPP
