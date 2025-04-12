#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <string>
#include <vector>
#include <future>

// Function to download a file from a given URL and save it to a specified directory.
// Parameters:
// - url: The URL of the file to download.
// - save_dir: The directory where the downloaded file will be saved.
// Returns: A boolean indicating success or failure of the download operation.
bool downloadFile(const std::string& filename, const std::string& url, const std::string& save_dir);

// Download file 병렬
std::future<bool> downloadFileAsync(const std::string& filename, const std::string& url, const std::string& savePath);

// Function to download multiple files from a list of URLs.
// Parameters:
// - urls: A vector of URLs to download.
// - save_dir: The directory where the downloaded files will be saved.
// Returns: A vector of booleans indicating the success or failure of each download.
std::vector<bool> downloadFiles(const std::vector<std::string>& urls, const std::string& save_dir);

// Function to create a directory if it does not already exist.
// Parameters:
// - dir: The directory path to create.
// Returns: A boolean indicating success or failure of the directory creation.
bool createDirectory(const std::string& dir);

#endif // DOWNLOADER_H