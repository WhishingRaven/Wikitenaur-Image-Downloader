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
├── build                   # Source files
│   └── _ImagesList         # Directory containing text files with image URLs
│       ├── 0
│       │   └── 00.txt
│       │   └── 0a.txt
│       │   └── 0b.txt
│       ├── 1
│       │   └── example.txt
│       │   └── 1a.txt
│       │   └── 1b.txt
        └── ...
├── src                     # Source files
│   ├── main.cpp            # Entry point of the application
│   ├── downloader.cpp      # Implementation of download functions
│   ├── downloader.h        # Header file for downloader functions
│   ├── file_utils.cpp      # Utility functions for file operations
│   └── file_utils.h        # Header file for utility functions
└── include                 # Header files
    └── config.h            # Configuration constants
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

## Downloading Prebuilt Executables

If you prefer not to build the project manually, you can download prebuilt executables for Windows, macOS, and Linux from the GitHub Actions Artifacts:

1. Go to the **Actions** tab in the GitHub repository.
2. Select the most recent workflow run under the **Build** workflow.
3. Scroll down to the **Artifacts** section at the bottom of the workflow page.
4. Download the artifact named `main-{OSname}`.
5. Extract the downloaded file to access the executables for your operating system.

You can then run the executable directly from your terminal or command prompt.

## Running the Application
To run the application, use the following command:
```
./main <keyword> <maxConcurrency>
```
Replace `<keyword>` with the desired search term. If no keyword is provided, the application will prompt you to enter one.

You can set the maximum number of concurrent downloads using the second argument. Replace `<maxConcurrency>` with the desired number of threads. You can omit this second argument. Then it is 10 by default.

## Dependencies
- C++17 or later
- CMake

## License
This project is licensed under the MIT License. See the LICENSE file for more details.