#ifndef FILE_H
#define FILE_H

#include <string>


// true = success , false = failure.
bool copyFileContent(const std::string &inFilename, const std::string &outFilename);

#endif 