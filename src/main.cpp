#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include <future>
#include <algorithm>
#include "downloader.h"
#include "file_utils.h"
#include <curl/curl.h> 

// Function to display a prompt for the user to enter a keyword
std::string getKeywordFromUser() {
    std::string keyword;
    std::cout << "Enter keyword to search and download images: ";
    std::getline(std::cin, keyword);
    return keyword;
}

// Function to download files with a concurrency limit and retry logic
bool downloadWithConcurrencyLimit(
    const std::vector<std::pair<std::string, std::string>>& files,
    const std::string& downloadDir,
    size_t maxConcurrency
) {
    int successCount = 0;
    int failureCount = 0;
    int maxRetries = 3;

    std::vector<std::pair<std::string, std::string>> remainingFiles = files;

    for (int attempt = 1; attempt <= maxRetries && !remainingFiles.empty(); ++attempt) {
        std::cout << "\nStarting download attempt " << attempt << "...\n";
        size_t index = 0;
        std::vector<std::pair<std::string, std::string>> nextFailures;

        while (index < remainingFiles.size()) {
            std::vector<std::future<bool>> futures;
            std::vector<std::pair<std::string, std::string>> batch;

            for (size_t i = 0; i < maxConcurrency && index < remainingFiles.size(); ++i, ++index) {
                const auto& [filename, url] = remainingFiles[index];
                futures.push_back(downloadFileAsync(filename, url, downloadDir));
                batch.push_back({filename, url});
            }

            for (size_t i = 0; i < futures.size(); ++i) {
                bool success = futures[i].get();
                if (success) {
                    std::cout << batch[i].first << " downloaded." << std::endl;
                    successCount++;
                } else {
                    std::cout << batch[i].first << " failed to download." << std::endl;
                    nextFailures.push_back(batch[i]);
                }
            }
        }

        remainingFiles = nextFailures;
    }

    failureCount = remainingFiles.size();
    std::cout << "\nFinal result: " << successCount << " succeeded, " << failureCount << " failed." << std::endl;
    return failureCount == 0;
}

// Main function: Entry point of the application
int main(int argc, char* argv[]) {
    // Set the current working directory to the directory of the executable
    std::filesystem::path exePath = std::filesystem::current_path();
    std::cout << "Current working directory: " << exePath << std::endl;

    // Check if _ImagesList exists
    if (!std::filesystem::exists("_ImagesList")) {
        std::cerr << "Error: _ImagesList directory not found in " << exePath << std::endl;
        return 1; // Exit with an error code
    }

    std::string keyword;

    // Check if a command-line argument is provided
    if (argc > 1) {
        keyword = argv[1]; // Use the provided argument as the keyword
    } else {
        keyword = getKeywordFromUser(); // Prompt user for keyword
    }

    int maxConcurrency = 10;
    if (argc > 2) {
        try {
            maxConcurrency = std::stoi(argv[2]);
        } catch (const std::exception& e) {
            std::cerr << "Invalid concurrency value. Using default (10)." << std::endl;
        }
    }

    // Search for files in the _ImagesList directory that match the keyword
    std::vector<std::pair<std::string, std::string>> matchingFilesURLs = searchFilesForKeyword(keyword, "_ImagesList");

    // Sort matchingFilesURLs
    std::sort(matchingFilesURLs.begin(), matchingFilesURLs.end(),
          [](const std::pair<std::string, std::string>& a, const std::pair<std::string, std::string>& b) {
              return a.first < b.first; // Sort in ascending order of the key
          });

    // Check if any files were found
    if (matchingFilesURLs.empty()) {
        std::cout << "No files found containing the keyword: " << keyword << std::endl;
        return 1; // Exit with an error code
    }

    // Create a directory for saving downloaded files
    std::string downloadDir = "./" + keyword;
    std::filesystem::create_directory(downloadDir);

    // Download the files corresponding to the matching keywords
    downloadWithConcurrencyLimit(matchingFilesURLs, downloadDir, maxConcurrency);

    return 0; // Exit successfully
}