#pragma once

#include <iostream>
#include <bitset>
#include <cmath>
using namespace std;

class BitArray
{
    uint n;
    uint64_t *bitarray;
    uint t = 5;
    uint64_t *partialsums;
    uint n2;

public:
    BitArray(uint n);
    ~BitArray();
    void print()
    {
        cout << "bitarray:\n";
        for (int i = 0; i < n; i++)
        {
            bitset<64> y(bitarray[i]);
            cout << y << "\n";
        }
        cout << "partialsums:\n";
        for (size_t j = 0; j < n2; j++)
        {
            cout << partialsums[j] << "\n";
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
            if (get(i) != 1)
            {
                for (size_t k = (i / t); k < n2; k++)
                {
                    partialsums[k]++;
                }
            }
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

    uint64_t sum(const uint64_t i)
    {
        //index of the partial
        uint c = (i / t);
        //remainder of the partial sum (i = c*t+r)
        uint64_t r = (i % t);
        //get the partial sum to closest index
        uint64_t f = 0;

        cout << "r:" << r << "\n";

        //if the division was even then return the partialsum
        if (r == 0)
        {
            if (i == 0)
            {
                return get(0);
            }
            return partialsums[c - 1];
        }

        if (r != 0)
        {
            if (i > t)
            {
                f += partialsums[c-1];
            }
            for (uint64_t j = (c * t); j < i; j++)
            {
                f += get(j);
            }
        }

        return f;
    }
};

BitArray::BitArray(uint i)
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
    n2 = (i / t);
    partialsums = new uint64_t[n2]();

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
