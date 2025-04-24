# Wikitenaur-Image-Downloader

## Overview
The Wikitenaur-Image-Downloader is a command-line application that searches for image URLs in a structured dictionary format stored in text files within the `_ImagesList` directory. It downloads images based on a user-provided keyword, saving them in a directory named after the keyword.

## Features
- Accepts a keyword as a command-line argument or prompts the user for input.
- Searches through text files in the `_ImagesList` directory to find matching image URLs.
- Downloads images concurrently for efficiency.
- Saves downloaded images in a directory named after the keyword.

## Project Structure
```
Wikitenaur-Image-Downloader
├── CMakeLists.txt          # CMake configuration file
├── LICENSE                 # Basic MIT License
├── README.md               # Project documentation
├── build                   # Build directory for compiled executables
│   ├── certs               # Certificate CA bundle
│   ├── main-Windows        # Dynamic Build files for Windows Environment
│   └── _ImagesList         # Directory containing text files with image URLs
│       ├── 0
│       │   └── 00.txt
│       │   └── 0a.txt
│       │   └── 0b.txt
│       ├── 1
│       │   └── example.txt
│       │   └── 1a.txt
│       │   └── 1b.txt
│       └── ...
├── src                     # Source files
│   ├── main.cpp            # Entry point of the application
│   ├── downloader.cpp      # Implementation of download functions
│   ├── downloader.h        # Header file for downloader functions
│   ├── file_utils.cpp      # Utility functions for file operations
│   └── file_utils.h        # Header file for utility functions
└── include                 # Header files
    └── config.h            # Configuration constants
```

## Downloading Prebuilt Executables

If you prefer not to build the project manually, you can download prebuilt executables for Windows, macOS, and Linux from the GitHub Actions Artifacts:

1. Go to the **Actions** tab in the GitHub repository.
2. Select the most recent workflow run under the **Build** workflow.
3. Scroll down to the **Artifacts** section at the bottom of the workflow page.
4. Download the artifact named `main-{OSname}`.
5. Extract the downloaded file to access the executables for your operating system.

### For Windows Users
```bash
cd build/main-Windows
```
You can find main.exe and dll dependencies. Keep them in the same directory and execute the main file.

## Running the Application

You can run the application in one of the following ways:

### Option 1: Run with a keyword
```bash
./main <keyword>
```
Replace `<keyword>` with the desired search term. The application will search for matching image URLs and download them.

### Option 2: Run without a keyword
```bash
./main
```
If no keyword is provided, the application will prompt you to enter one.

### Option 3: Double-click the executable
Simply double-click the executable file. The application will prompt you to enter a keyword.

### Notes
- Ensure that the `_ImagesList` directory is in the same location as the executable.
- The application will create a directory named after the keyword to save the downloaded images.

## Building the Project

If you prefer to build the project manually, follow these steps:

### 1. Prerequisites
- Ensure you have CMake installed on your system.
- Install a C++17-compatible compiler.

### 2. Build Instructions
1. Open a terminal and navigate to the project directory.
2. Create a build directory:
   ```bash
   mkdir build
   cd build
   ```
3. Run CMake to configure the project:
   ```bash
   cmake ..
   ```
4. Build the project:
   ```bash
   cmake --build .
   ```

### 3. for Windows Users: use make instead of cmake
1. get libraries using Chocolatey:
   ```bash
   choco install make mingw curl
   ```
2. Run make to build the project:
   ```bash
   make -f Makefile
   ```

## Dependencies
- C++17 or later
- CMake
- make(for Windows)

## License
This project is licensed under the MIT License. See the LICENSE file for more details.