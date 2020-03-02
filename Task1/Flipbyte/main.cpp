#include <iostream>
#include <optional>

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

std::optional<uint8_t> GetByte(char* byte) {
    int received = std::stoi(byte);

    if (received < 0 || received > UINT8_MAX) {
        printf("Input value doesn't fit into a single byte\n");
        return std::nullopt;
    } else {
        return received;
    }
}

uint8_t FlipBits(uint8_t originalByte) {
    uint8_t reversed = originalByte;
    reversed = (reversed & 0xF0) >> 4u | (reversed & 0x0F) << 4;
    reversed = (reversed & 0xCC) >> 2u | (reversed & 0x33) << 2;
    reversed = (reversed & 0xAA) >> 1u | (reversed & 0x55) << 1;
    return reversed;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: flipbyte.exe <byte>\n");
        return 1;
    }

    if (IsArgumentAnIntegerNumber(argv[1])) {
        // nullopt if not in 0-255 range
        std::optional<uint8_t> byte = GetByte(argv[1]);
        if (byte.has_value()) {
            uint8_t flipped = FlipBits(*byte);

            // Print value as integer
            std::cout << (unsigned int)flipped << std::endl;
        } else {
            return 1;
        }
    } else {
        return 1;
    }

    return 0;
}
