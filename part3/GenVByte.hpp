#pragma once

#include <bitset>
#include <iostream>
#include "../part2/PackedIntegerArray.hpp"

using namespace std;

class GenVByte
{
private:
    uint64_t *encoded_integers;

public:
    GenVByte(uint64_t k, uint64_t *integers);
    ~GenVByte();
};

GenVByte::GenVByte(uint64_t k, uint64_t *integers)
{
    PackedIntegerArray pia(1, k + 1);
}

GenVByte::~GenVByte()
{
}
