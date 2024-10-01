#include <istream>
#include <fstream>
#include <string>

std::streamoff getStreamSize(std::istream& strm) {
    std::streampos cur_pos = strm.tellg();
    if (cur_pos == -1) {
        return -1;
    }

    strm.seekg(0, std::ios_base::end);
    std::streampos end_pos = strm.tellg();
    if (end_pos == -1) {
        return -1;
    }

    strm.seekg(cur_pos);

    return end_pos - cur_pos;
}

bool read2(const std::string& path, std::string& result) {
    std::ifstream fs;
    fs.open(path);
    if (!fs) {
        return false;
    }

    std::streamoff len = getStreamSize(fs);
    if (len < 0) {
        return false;
    }

    result.resize(static_cast<std::size_t>(len));

    fs.read(&result[0], result.length());

    return true;
}
