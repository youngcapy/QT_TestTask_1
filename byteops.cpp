#include "byteops.h"

ByteOps::ByteOps(bool timer_based, unsigned time, unsigned char *xor_sequence, bool hex_values)
{
    this->timerBased = timer_based;
    this->time = time;
    this->xor_sequence = xor_sequence;
    this->hex_values = hex_values;
}

void ByteOps::set_new_values(bool timer_based, unsigned time, unsigned char *xor_sequence, bool hex_values)
{
    this->timerBased = timer_based;
    this->time = time;
    this->xor_sequence = xor_sequence;
    this->hex_values = hex_values;
}


bool ByteOps::getTimerBased(){

    return timerBased;

}

unsigned ByteOps::getTimerValue(){

    return time;

}

ByteOps::~ByteOps(){

    delete[] xor_sequence;

}

void ByteOps::hexStringToBytes(const unsigned char *hexString, unsigned char *bytes) const{

    const unsigned char* p1 = hexString;
    const unsigned char* p2 = p1;

    for (size_t i{}; i < 8; i++) {
        unsigned short byte;

        ++p2;
        if (*p2 != NULL) {
            ++p2;
        }

        std::stringstream sstm(std::string(p1, p2));

        sstm.flags(std::ios_base::hex);
        sstm >> byte;

        bytes[i] = byte;

        p1 += 2;
    }

}

void ByteOps::xor_bytes(unsigned char* sourceBytes, size_t bytes_quantity) const noexcept {
        for(size_t i{}; i < bytes_quantity; i++)
            sourceBytes[i] ^= xor_sequence[i % 8]; // Производим операцию XOR над произвольной последовательностью байт


}

