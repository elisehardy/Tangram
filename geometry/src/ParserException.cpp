#include "../include/ParserException.hpp"

#include <sstream>
#include <utility>


using namespace tangram::geometry;


ParserException::ParserException(std::string t_path, uint16_t t_lin, uint16_t t_col, std::string t_msg) :
        path(std::move(t_path)), lin(t_lin), col(t_col), msg(std::move(t_msg)) {
}

std::string ParserException::getPath() const {
    return "";
}


uint16_t ParserException::getLine() const {
    return 0;
}


uint16_t ParserException::getColumn() const {
    return 0;
}


std::string ParserException::getMessage() const {
    return "";
}

const char *ParserException::what() const noexcept {
    return "";
}
