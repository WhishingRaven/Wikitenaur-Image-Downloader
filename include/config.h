#ifndef CONFIG_H
#define CONFIG_H

#include <string>

// Configuration constants for the image downloader project

// Maximum number of download attempts for each file
const int MAX_DOWNLOAD_ATTEMPTS = 5;

// Base directory for image lists
const std::string IMAGES_LIST_DIR = "_ImagesList";

// Directory where downloaded images will be saved
const std::string DOWNLOAD_DIR = "downloads";

// File extension for text files containing URLs
const std::string URL_FILE_EXTENSION = ".txt";

// Timeout duration for downloading files (in seconds)
const int DOWNLOAD_TIMEOUT = 10;

// Maximum number of concurrent downloads
const int MAX_CONCURRENT_DOWNLOADS = 10;

#endif // CONFIG_H