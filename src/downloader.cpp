#include "downloader.h"
#include <iostream>
#include <fstream>
#include <curl/curl.h>
#include <sys/stat.h>
#include <future>
#include <string>

// Callback function to write data received from the server into a file
size_t WriteCallback(void* contents, size_t size, size_t nmemb, FILE* userp) {
    size_t totalSize = size * nmemb;
    fwrite(contents, size, nmemb, userp);
    return totalSize;
}

// Function to download a file from a given URL and save it to the specified path
bool downloadFile(const std::string& filename, const std::string& url, const std::string& savePath) {
    std::string fullPath = savePath + "/" + filename;

    CURL* curl;
    FILE* file;
    CURLcode res;

    curl = curl_easy_init(); // Initialize a CURL session
    if (curl) {
        file = fopen(fullPath.c_str(), "wb"); // Open the file for writing
        if (file) {
            curl_easy_setopt(curl, CURLOPT_URL, url.c_str()); // Set the URL to download
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback); // Set the write callback
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, file); // Set the file pointer to write data
            curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L); // Follow redirects
            curl_easy_setopt(curl, CURLOPT_ACCEPT_ENCODING, ""); // allow all kind of encoding(e.g. gzip, deflate)
            curl_easy_setopt(curl, CURLOPT_TCP_NODELAY, 1L); //Reduce Socket Delay
            curl_easy_setopt(curl, CURLOPT_USERAGENT, "Mozilla/5.0"); //User-Agent
            curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
            curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);

            res = curl_easy_perform(curl); // Perform the file download

            if (res != CURLE_OK) { //Debug
                // std::cout << "Downloading from URL: " << url << std::endl;
                // std::cout << "filename: " << filename << std::endl;
                // std::cerr << "Error downloading file: " << curl_easy_strerror(res) << "\n" << std::endl;
                std::cerr << "[ERROR] curl_easy_perform failed: " << curl_easy_strerror(res) << std::endl;
                std::cerr << "URL: " << url << std::endl;
                fclose(file);
                curl_easy_cleanup(curl);
                return false; // Return false if download fails
            }

            fclose(file); // Close the file after download
        } else {
            std::cerr << "Error opening file for writing: " << savePath << std::endl;
            curl_easy_cleanup(curl);
            return false; // Return false if file cannot be opened
        }

        curl_easy_cleanup(curl); // Clean up CURL session
    }
    return true; // Return true if download is successful
}

std::future<bool> downloadFileAsync(const std::string& filename, const std::string& url, const std::string& savePath) {
    return std::async(std::launch::async, [=]() {
        return downloadFile(filename, url, savePath);
    });
}

// Function to create a directory if it does not exist
bool createDirectory(const std::string& dirPath) {
    struct stat info;
    if (stat(dirPath.c_str(), &info) != 0) { // Check if directory exists
#ifdef _WIN32
    // Windows 환경에서는 두 번째 인수를 제거
    if (mkdir(dirPath.c_str()) != 0) { // Create directory
#else
    if (mkdir(dirPath.c_str(), 0777) != 0) { // Create directory (Linux/Mac)
#endif
        std::cerr << "Failed to create directory: " << dirPath << std::endl;
        return false;
    }
    } else if (!(info.st_mode & S_IFDIR)) { // Check if it's not a directory
        std::cerr << dirPath << " is not a directory" << std::endl;
        return false; // Return false if path is not a directory
    }
    return true; // Return true if directory exists or is created successfully
}