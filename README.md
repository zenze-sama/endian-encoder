# endian-encoder

https://www.youtube.com/watch?v=sm_ecfMeTno


Like a week ago I saw this video by Mult, explaining a old c meme that translates a long to "urmom". The explination was good so I decided to make a encoder for this.

For Encoding, the program takes a string (atmost 7 characters) and packs its ASCII values into a 64-bit unsigned integer (uint64_t). On little-endian systems, the first character is placed in the least significant byte, the second in the next, and so on.

For example, the string "ABC" is encoded as:

'A' → 0x41

'B' → 0x42

'C' → 0x43

Null Terminator → 0x00

The resulting integer in memory looks like this: 0x00 0x43 0x42 0x41 ..., which, when read as a number, is 0x434241 in hex and 4407873 in decimal.

For Decoding, run this program with your generated number:
```
#include <stdio.h>

int main() {
    long x = 435845752186;
    puts((char*)&x);
    return 0;
}
```

I haven't checked the documentation or anything, but my guess is that this is how the puts function work:
```
void my_puts(const char *str) {
    int i = 0;
    while (str[i] != '\0') {
        putchar(str[i]);
        i++;
    }
    putchar('\n');
}
```

### Usage:
```
git clone https://github.com/zenze-sama/endian-encoder
cd endian-encoder
g++ main.cpp -o main
./main <your_string>
```

