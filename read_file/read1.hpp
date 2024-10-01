#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>

bool read1(const std::string& path, std::string& result) {
    std::ifstream fs;
    fs.open(path);
    if (!fs) {
        return false;
    }

    std::stringstream ss;
    std::copy(std::istreambuf_iterator<char>(fs.rdbuf()), std::istreambuf_iterator<char>(), std::ostreambuf_iterator<char>(ss));
    result = ss.str();

    return true;
}