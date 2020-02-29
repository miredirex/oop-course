#include <iostream>

bool IsArgumentAnIntegerNumber(char* arg) {
    const uint8_t MAX_ARG_LENGTH = 3; // 0 - 255 are the only valid values

    bool hasNonZeroMet = false;
    char* firstNonZeroIndex = nullptr; // To allow entering values like this: 000000000123

    for (char* i = arg; *i != '\0'; i++) {
        char ch = *i;
        if (ch != '0' && !hasNonZeroMet) {
            hasNonZeroMet = true;
            firstNonZeroIndex = i;
        }
        if (!isdigit(ch)) {
            printf("Input value should only contain digits\n");
            return false;
        }
        if (hasNonZeroMet && (i - firstNonZeroIndex >= MAX_ARG_LENGTH)) {
            printf("Input value is too big.\n");
            return false;
        }
    }
    return true;
}

uint8_t GetByteOrFail(char* byte) {
    int received = std::stoi(byte);

    if (received < 0 || received > UINT8_MAX) {
        printf("Input value doesn't fit into a single byte\n");
        exit(1);
    } else {
        return received;
    }
}

uint8_t FlipBits(uint8_t originalByte) {
    const uint8_t NUM_OF_BITS = 8;
    uint8_t reversed = 0;

    for (uint8_t i = 0; i < NUM_OF_BITS; i++) {
        if (originalByte & (1u << i)) {
            reversed |= 1u << (NUM_OF_BITS - 1u - i);
        }
    }
    return reversed;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: flipbyte.exe <byte>\n");
        return 1;
    }

    if (IsArgumentAnIntegerNumber(argv[1])) {
        // Fail if not in 0-255 range
        uint8_t byte = GetByteOrFail(argv[1]);
        uint8_t flipped = FlipBits(byte);

        // Print value as integer
        std::cout << (unsigned int)flipped << std::endl;
    } else {
        return 1;
    }

    return 0;
}
