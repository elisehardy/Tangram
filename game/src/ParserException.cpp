#include "../include/ParserException.hpp"


using namespace tangram::game;


ParserException::ParserException(const std::string &t_path, uint16_t t_lin, uint16_t t_col, const std::string &t_msg) :
        path(std::move(t_path)), lin(t_lin), col(t_col), msg(std::move(t_msg)) {
}


std::string ParserException::getPath() const {
    return this->path;
}


uint16_t ParserException::getLine() const {
    return this->lin;
}


uint16_t ParserException::getColumn() const {
    return this->col;
}


std::string ParserException::getMessage() const {
    return this->msg;
}

//
//const char *ParserException::what() const noexcept {
//    return this->path + ":" + this->lin + ":" + this->col + ": error: " + this->msg;
//}
