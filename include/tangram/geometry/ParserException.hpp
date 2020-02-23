/** @file ParserException.hpp
 *
 *  @brief ***ParserException***'s header
 *
 *  @author Elise Hardy
 *  @author Quentin Coumes
 */
 
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
             * Return the line the error occurred.
             *
             * @return The line the error occurred.
             */
            [[nodiscard]] uint16_t getLine() const;
        
            /**
             * Return the column the error occurred.
             *
             * @return The column the error occurred.
             */
            [[nodiscard]] uint16_t getColumn() const;
            
            /**
             * Return the message of the error.
             *
             * @return The message of the error.
             */
            [[nodiscard]] std::string getMessage() const;
            
            [[nodiscard]] const char *what() const noexcept override;
    };
}

#endif // PARSEREXCEPTION_HPP
