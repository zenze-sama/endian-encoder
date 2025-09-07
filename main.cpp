#include <iostream>
#include <string>
#include <cstdint>
#include <vector>
#include <sstream>

uint64_t encode_string(const std::string& str, size_t start, size_t length) {
    uint64_t x = 0;
    for (size_t i = 0; i < length && (start + i) < str.length(); i++) {
        x |= static_cast<uint64_t>(static_cast<unsigned char>(str[start + i])) << (8 * i);
    }
    return x;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " \"string to encode\"\n";
        std::cerr << "Provide a string to encode in double quotes.\n";
        return 1;
    }

    std::ostringstream oss;
    for (int i = 1; i < argc; i++) {
        if (i > 1) oss << " ";
        oss << argv[i];
    }
    std::string str = oss.str();
    
    if (str.empty()) {
        std::cout << "0\n";
        return 0;
    }

    const size_t MAX_CHARS_PER_ENCODING = 7;
    std::vector<uint64_t> encodings;
    
    for (size_t i = 0; i < str.length(); i += MAX_CHARS_PER_ENCODING) {
        size_t chunk_length = std::min(MAX_CHARS_PER_ENCODING, str.length() - i);
        uint64_t encoded = encode_string(str, i, chunk_length);
        encodings.push_back(encoded);
    }

    for (uint64_t encoded : encodings) {
        std::cout << encoded << " ";
    }

    return 0;
}