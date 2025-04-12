#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include "downloader.h"
#include "file_utils.h"

// Function to display a prompt for the user to enter a keyword
std::string getKeywordFromUser() {
    std::string keyword;
    std::cout << "Enter keyword to search and download images: ";
    std::getline(std::cin, keyword);
    return keyword;
}

// Main function: Entry point of the application
int main(int argc, char* argv[]) {
    std::string keyword;

    // Check if a command-line argument is provided
    if (argc > 1) {
        keyword = argv[1]; // Use the provided argument as the keyword
    } else {
        keyword = getKeywordFromUser(); // Prompt user for keyword
    }

    // Search for files in the _ImagesList directory that match the keyword
    std::vector<std::string> matchingFilesURLs = searchFilesForKeyword(keyword, "_ImagesList");

    // Check if any files were found
    if (matchingFilesURLs.empty()) {
        std::cout << "No files found containing the keyword: " << keyword << std::endl;
        return 1; // Exit with an error code
    }

    // Create a directory for saving downloaded files
    std::string downloadDir = "./" + keyword;
    std::filesystem::create_directory(downloadDir);

    // Download the files corresponding to the matching keywords
    for (const auto& file : matchingFilesURLs) {
        // std::string url = getUrlFromFile(file); // Get the URL from the file
        // if (!url.empty()) {
            downloadFile(file, downloadDir); // Download the file
        // }
    }

    std::cout << "Download process completed." << std::endl;
    return 0; // Exit successfully
}