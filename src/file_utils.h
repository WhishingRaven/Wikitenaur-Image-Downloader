// file_utils.h
#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include <string>
#include <vector>

// Function to create a directory for downloaded files.
bool createDirectory(const std::string& dir_name);

// Function to search for files in the '_ImagesList' directory that match the keyword.
std::vector<std::string> searchFilesForKeyword(const std::string& keyword, const std::string& directory);

#endif // FILE_UTILS_H