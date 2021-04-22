#pragma once

#include <iostream>
#include <bitset>
#include <cmath>
using namespace std;

class BitArray
{
    int n;
    uint64_t *bitarray;

public:
    BitArray(int n);
    ~BitArray();
    void print()
    {
        for (int i = 0; i < n; i++)
        {
            bitset<64> y(bitarray[i]);
            cout << y << "\n";
        }
    }
    void set(uint i, uint64_t b)
    {
        uint row = i / 64;
        uint r = i % 64;
        uint64_t value = bitarray[row];
        uint64_t shift = 0;
        if (b == 0)
        {
            shift = (b + 1) << r;
            bitarray[row] = value ^ shift;
        }
        else
        {
            shift = b << r;
            bitarray[row] = value | shift;
        }
    }

    uint64_t get(uint64_t i) const
    {
        uint row = i / 64;
        uint r = i % 64;
        uint64_t value = bitarray[row];
        return (value >> r) & 1;
    }

    void clear()
    {
        for (int i = 0; i < n; i++)
        {
            bitarray[i] = 0;
        }
    }
};

BitArray::BitArray(int i)
{
    uint64_t remainder = i % 64;
    if (remainder == 0)
    {
        n = (i / 64);
    }
    else
    {
        n = (i / 64) + 1;
    }

    bitarray = new uint64_t[n]();

    /* for (int j = 0; j < (i / 64); j++)
    {
        bitarray[j] = ~0;
    }
    if (remainder > 0)
    {
        bitarray[n - 1] = (uint64_t(1) << remainder) - 1;
    }*/
}

BitArray::~BitArray()
{
    delete bitarray;
}
