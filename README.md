# Wikitenaur-Image-Downloader

## Overview
The C++ Image Downloader is a command-line application that searches for image URLs in a structured dictionary format stored in text files within the `_ImagesList` directory. It downloads images based on a user-provided keyword, saving them in a directory named after the keyword.

## Features
- Accepts a keyword as a command-line argument or prompts the user for input.
- Searches through text files in the `_ImagesList` directory to find matching image URLs.
- Downloads images concurrently for efficiency.
- Saves downloaded images in a directory named after the keyword.

## Project Structure
```
Wikitenaur-Image-Downloader
├── CMakeLists.txt          # CMake configuration file
├── README.md               # Project documentation
├── src                     # Source files
│   ├── main.cpp            # Entry point of the application
│   ├── downloader.cpp      # Implementation of download functions
│   ├── downloader.h        # Header file for downloader functions
│   ├── file_utils.cpp      # Utility functions for file operations
│   └── file_utils.h        # Header file for utility functions
├── include                  # Header files
│   └── config.h            # Configuration constants
└── _ImagesList             # Directory containing text files with image URLs
    ├── 0
    │   └── example.txt
    ├── 1
    │   └── example.txt
    └── ...
```

## Building the Project
1. Ensure you have CMake installed on your system.
2. Open a terminal and navigate to the project directory.
3. Create a build directory:
   ```
   mkdir build
   cd build
   ```
4. Run CMake to configure the project:
   ```
   cmake ..
   ```
5. Build the project:
   ```
   cmake --build .
   ```

## Running the Application
To run the application, use the following command:
```
./Wikitenaur-Image-Downloader <keyword>
```
Replace `<keyword>` with the desired search term. If no keyword is provided, the application will prompt you to enter one.

## Dependencies
- C++11 or later
- CMake

## License
This project is licensed under the MIT License. See the LICENSE file for more details.