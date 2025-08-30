#include <iostream>
#include <string>
#include <cstdint>

int main(int argc, char *argv[]) {
    if(argc != 2){
        std::cerr << "Provide a string (atmost 7 characters)\n";
        return 1;
    }

    std::string str = argv[1];

    if (str.length() > 7) {
        std::cerr << "Error: String too long. Maximum 7 characters are allowed.\n";
        return 1;
    }

    uint64_t x = 0;
    for (size_t i = 0; i < str.length(); ++i) {
        x |= static_cast<uint64_t>(static_cast<unsigned char>(str[i])) << (8 * i);
    }

    std::cout << x << "\n";
    return 0;
}