#ifndef UTILS_H
#define UTILS_H

#include <string>

// Ensures a directory exists (e.g. "data/")
void ensureDataFolder();

// Returns a string like "data/board_001.txt"
std::string generateFilename(const std::string& prefix, const std::string& ext, int index);

#endif // UTILS_H
