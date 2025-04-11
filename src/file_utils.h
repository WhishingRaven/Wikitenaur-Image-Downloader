// file_utils.h
#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include <string>
#include <vector>

// Function to load URLs from text files in the specified directory.
// It searches through all subdirectories of the _ImagesList folder
// and populates a vector with filenames that contain the specified keyword.
// Returns a vector of strings containing the URLs.
std::vector<std::string> load_urls(const std::string& keyword);

// Function to parse a single text file and extract key-value pairs.
// The key is the filename and the value is the corresponding URL.
// It takes the path of the text file as input and returns a vector of strings
// containing the URLs found in the file.
std::vector<std::string> parse_file(const std::string& file_path);

// Function to search for a keyword in a list of filenames.
// It takes a vector of filenames and a keyword as input,
// and returns a vector of filenames that contain the keyword.
std::vector<std::string> search_for_keyword(const std::vector<std::string>& filenames, const std::string& keyword);

#endif // FILE_UTILS_H