#include "file_utils.h"
#include <iostream>
#include <fstream>
#include <filesystem>
#include <unordered_map>
#include <string>
#include <vector>
#include <regex>

// Function to create a directory for saving downloaded files
bool create_directory(const std::string& dir_name) {
    // Create a directory if it does not exist
    return std::filesystem::create_directory(dir_name);
}

// Implementation of searchFilesForKeyword
std::vector<std::pair<std::string, std::string>> searchFilesForKeyword(const std::string& keyword, const std::string& directory) {
    std::vector<std::pair<std::string, std::string>> matchingFilesURLs;

    std::regex exclude_pattern(R"(.*-[a-zA-Z]\.(png|jpg|jpeg)$)"); // exclude '-{single alphabet}

    for (const auto& entry : std::filesystem::recursive_directory_iterator(directory)) {
        if (entry.is_regular_file() && entry.path().extension() == ".txt") {
            std::ifstream file(entry.path());
            std::string line;

            while (std::getline(file, line)) {
                size_t delimiter_pos = line.find("->");
                
                if (delimiter_pos != std::string::npos) {
                    std::string key = line.substr(0, delimiter_pos - 1);
                    std::string value = line.substr(delimiter_pos + 3);

                    if (key.find(keyword) != std::string::npos && !std::regex_match(key, exclude_pattern)) {
                        matchingFilesURLs.push_back(std::make_pair(key, value)); // Add <key, value> to the vector
                    }
                }
            }
        }
    }

    return matchingFilesURLs;
}