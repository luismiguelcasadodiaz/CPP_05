#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <cerrno>
#include <cstring>

// Platform-specific includes
#ifdef _WIN32
    #include <windows.h>
    #include <io.h>
#else
    #include <sys/stat.h>
    #include <sys/statvfs.h>
    #include <unistd.h>
#endif

bool fileExists(const std::string& filename) {
    std::ifstream file(filename.c_str());
    return file.good();
}

bool hasWritePermission(const std::string& directory) {
#ifdef _WIN32
    // Windows: try to create a temporary file
    return _access(directory.c_str(), 2) == 0; // 2 = write permission
#else
    // Unix/Linux: check write permission
    return access(directory.c_str(), W_OK) == 0;
#endif
}

bool hasEnoughSpace(const std::string& path, unsigned long requiredBytes) {
#ifdef _WIN32
    ULARGE_INTEGER freeBytesAvailable;
    if (GetDiskFreeSpaceExA(path.c_str(), &freeBytesAvailable, NULL, NULL)) {
        return freeBytesAvailable.QuadPart >= requiredBytes;
    }
    return false;
#else
    struct statvfs stat;
    if (statvfs(path.c_str(), &stat) == 0) {
        unsigned long availableSpace = stat.f_bavail * stat.f_frsize;
        return availableSpace >= requiredBytes;
    }
    return false;
#endif
}

bool createFileWithChecks(const std::string& filename, 
                          const std::string& content,
                          bool overwrite = false) {
    
    std::cout << "=== Pre-creation checks ===" << std::endl;
    
    // Check 1: File existence
    if (fileExists(filename)) {
        std::cout << "[WARNING] File '" << filename << "' already exists!" << std::endl;
        if (!overwrite) {
            std::cout << "[ERROR] Cannot proceed. Set overwrite=true to replace." << std::endl;
            return false;
        }
        std::cout << "[INFO] Overwrite mode enabled. Will replace existing file." << std::endl;
    } else {
        std::cout << "[OK] File does not exist." << std::endl;
    }
    
    // Check 2: Write permission on current directory
    std::string directory = "."; // Current directory
    if (hasWritePermission(directory)) {
        std::cout << "[OK] Write permission granted on current directory." << std::endl;
    } else {
        std::cout << "[ERROR] No write permission on current directory!" << std::endl;
        std::cout << "       Error: " << std::strerror(errno) << std::endl;
        return false;
    }
    
    // Check 3: Disk space (estimate content size + 1KB buffer)
    unsigned long requiredSpace = content.length() + 1024;
    if (hasEnoughSpace(directory, requiredSpace)) {
        std::cout << "[OK] Sufficient disk space available." << std::endl;
    } else {
        std::cout << "[ERROR] Insufficient disk space!" << std::endl;
        std::cout << "       Required: ~" << requiredSpace << " bytes" << std::endl;
        return false;
    }
    
    // Check 4: Validate filename (basic checks)
    if (filename.empty()) {
        std::cout << "[ERROR] Filename is empty!" << std::endl;
        return false;
    }
    
    // Check for invalid characters (basic set)
    std::string invalidChars = "<>:\"|?*";
    for (size_t i = 0; i < filename.length(); ++i) {
        if (invalidChars.find(filename[i]) != std::string::npos) {
            std::cout << "[ERROR] Filename contains invalid character: '" 
                      << filename[i] << "'" << std::endl;
            return false;
        }
    }
    std::cout << "[OK] Filename is valid." << std::endl;
    
    std::cout << "\n=== Creating file ===" << std::endl;
    
    // Create and write to file
    std::ofstream outFile(filename.c_str(), std::ios::out | std::ios::trunc);
    
    if (!outFile.is_open()) {
        std::cout << "[ERROR] Failed to open file for writing!" << std::endl;
        std::cout << "       Error: " << std::strerror(errno) << std::endl;
        return false;
    }
    
    outFile << content;
    
    // Check if write operation succeeded
    if (outFile.fail()) {
        std::cout << "[ERROR] Failed to write to file!" << std::endl;
        outFile.close();
        return false;
    }
    
    outFile.close();
    
    // Verify file was created successfully
    if (!outFile.good()) {
        std::cout << "[ERROR] Error occurred while closing file!" << std::endl;
        return false;
    }
    
    std::cout << "[SUCCESS] File created successfully!" << std::endl;
    return true;
}

int main() {
    std::string filename = "example.txt";
    
    // Prepare content to write
    std::string content;
    content += "This is the first line of text.\n";
    content += "This is the second line.\n";
    content += "Here's a third line with some numbers: 12345\n";
    content += "And a final line to complete our example.\n";
    
    std::cout << "Attempting to create file: " << filename << std::endl;
    std::cout << "Content size: " << content.length() << " bytes\n" << std::endl;
    
    // Attempt to create the file with all checks
    bool success = createFileWithChecks(filename, content, false);
    
    if (success) {
        std::cout << "\n=== File created with content ===" << std::endl;
        std::cout << content << std::endl;
        
        // Read back and display
        std::cout << "=== Reading file back ===" << std::endl;
        std::ifstream inFile(filename.c_str());
        if (inFile.is_open()) {
            std::string line;
            while (std::getline(inFile, line)) {
                std::cout << line << std::endl;
            }
            inFile.close();
        }
    } else {
        std::cout << "\nFile creation failed!" << std::endl;
        return 1;
    }
    
    return 0;
}
