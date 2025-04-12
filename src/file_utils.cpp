#include "file_utils.h"
#include <iostream>
#include <fstream>
#include <filesystem>
#include <unordered_map>
#include <string>
#include <vector>

// Function to load key-value pairs from text files into a dictionary
std::unordered_map<std::string, std::string> load_files(const std::string& directory) {
    std::unordered_map<std::string, std::string> data;
    
    // Iterate through all files in the specified directory and its subdirectories
    for (const auto& entry : std::filesystem::recursive_directory_iterator(directory)) {
        if (entry.is_regular_file() && entry.path().extension() == ".txt") {
            std::ifstream file(entry.path());
            std::string line;
            // Read each line in the file
            while (std::getline(file, line)) {
                // Split the line into key and value based on the delimiter '->'
                size_t delimiter_pos = line.find("->");
                if (delimiter_pos != std::string::npos) {
                    std::string key = line.substr(0, delimiter_pos);
                    std::string value = line.substr(delimiter_pos + 2); // Skip the delimiter
                    data[key] = value; // Store in the dictionary
                }
            }
        }
    }
    return data; // Return the populated dictionary
}

// Function to search for filenames containing the specified keyword
std::vector<std::string> search_files(const std::unordered_map<std::string, std::string>& data, const std::string& keyword) {
    std::vector<std::string> results;
    
    // Iterate through the dictionary to find matching keys
    for (const auto& pair : data) {
        if (pair.first.find(keyword) != std::string::npos) {
            results.push_back(pair.first); // Add matching keys to the results
        }
    }
    return results; // Return the list of matching filenames
}

// Function to create a directory for saving downloaded files
bool create_directory(const std::string& dir_name) {
    // Create a directory if it does not exist
    return std::filesystem::create_directory(dir_name);
}

std::vector<std::string> searchFilesForKeyword(const std::string& keyword, const std::string& directory);
std::string getUrlFromFile(const std::string& filepath);

// Implementation of searchFilesForKeyword
std::vector<std::string> searchFilesForKeyword(const std::string& keyword, const std::string& directory) {
    std::vector<std::string> matchingFiles;
    for (const auto& entry : std::filesystem::recursive_directory_iterator(directory)) {
        if (entry.is_regular_file()) {
            const std::string filename = entry.path().filename().string();
            if (filename.find(keyword) != std::string::npos) {
                matchingFiles.push_back(entry.path().string());
            }
        }
    }
    return matchingFiles;
}

// Implementation of getUrlFromFile
std::string getUrlFromFile(const std::string& filepath) {
    std::ifstream file(filepath);
    std::string url;
    if (file.is_open()) {
        std::getline(file, url); // Assumes the URL is on the first line
        file.close();
    }
    return url;
}