#ifndef BYTEOPS_H
#include <chrono>
#include <iostream>
#include <string>
#include <sstream>
#define BYTEOPS_H



class ByteOps
{

    public:
        ByteOps(bool timer_based, unsigned time, unsigned char *xor_sequence, bool hex_values);
        ~ByteOps();
        void set_new_values(bool timer_based, unsigned time, unsigned char *xor_sequence, bool hex_values);
        void xor_bytes(unsigned char* sourceBytes, size_t bytes_quantity) const noexcept; // Прототип для выполнения операции XOR над массивом
        unsigned get_bytes_quantity();
        bool getTimerBased();
        unsigned getTimerValue();
        void hexStringToBytes(const unsigned char *hexString, unsigned char *bytes) const;

    private:
        bool timerBased; // Работает с использованием таймера или нет
        unsigned time; // Опциональная переменная для времени таймера
        unsigned char *xor_sequence; // Последовательность байт для XOR
        bool hex_values;

};

#endif // BYTEOPS_H
