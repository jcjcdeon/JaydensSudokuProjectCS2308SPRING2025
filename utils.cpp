#include "utils.h"
#include <filesystem>
#include <sstream>
#include <iomanip>

namespace fs = std::filesystem;

void ensureDataFolder() {
    if (!fs::exists("data")) {
        fs::create_directory("data");
    }
}

std::string generateFilename(const std::string& prefix, const std::string& ext, int index) {
    std::ostringstream ss;
    ss << "data/" << prefix << "_" << std::setw(3) << std::setfill('0') << index << "." << ext;
    return ss.str();
}
