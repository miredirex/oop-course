#include <iostream>
#include <optional>

uint8_t GetByteFromArgument(char* arg)
{
    int number = std::stoi(arg);
    if (number > UINT8_MAX || number < 0)
    {
        throw std::out_of_range("Value should be in range of 0-255");
    }
    return (uint8_t)number;
}

uint8_t FlipBits(uint8_t originalByte)
{
    uint8_t reversed = originalByte;
    reversed = (reversed & 0xF0u) >> 4u | (reversed & 0x0Fu) << 4u;
    reversed = (reversed & 0xCCu) >> 2u | (reversed & 0x33u) << 2u;
    reversed = (reversed & 0xAAu) >> 1u | (reversed & 0x55u) << 1u;
    return reversed;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: flipbyte.exe <byte>\n");
        return 1;
    }

    try
    {
        uint8_t byte = GetByteFromArgument(argv[1]);
        uint8_t flipped = FlipBits(byte);
        std::cout << (unsigned int)flipped << std::endl;
    }
    catch (const std::exception& e)
    {
        printf("Input value is incorrect: it should fit into a 0-255 range and be a number.\n");
        return 1;
    }

    return 0;
}
