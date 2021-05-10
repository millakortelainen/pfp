#pragma once

#include <bitset>
#include <iostream>

using namespace std;

class PackedIntegerArray
{
private:
    uint64_t size;
    uint64_t size_of_integer;
    uint64_t *integers;

public:
    PackedIntegerArray(uint64_t n, uint64_t k);
    ~PackedIntegerArray();
    void set(uint64_t i, uint64_t v)
    {
        if (v == 0)
        {
            clear(i);
            return;
        }

        if (get(i) != 0)
        {
            clear(i);
        }
        uint64_t row = (i * size_of_integer) / 64;
        uint64_t remainder = (i * size_of_integer) % 64;

        if ((remainder + size_of_integer) >= 64)
        {
            uint64_t right_shift = v >> (64 - remainder);
            integers[row + 1] = integers[row + 1] | right_shift;
        }
        uint64_t left_shift = v << remainder;
        integers[row] = integers[row] | left_shift;
    }

    void clear(uint64_t i)
    {
        uint64_t mask = (1 << size_of_integer) - 1;
        uint64_t index = i * size_of_integer;
        uint64_t row = index / 64;
        uint64_t remainder = index % 64;
        uint64_t shift_mask = mask << remainder;
        uint64_t value = integers[row];

        if ((remainder + size_of_integer) >= 64)
        {
            if (size_of_integer == 64)
            {
                integers[row] = 0;
                return;
            }
            uint64_t right_mask = mask >> (64 - remainder);
            integers[row + 1] = integers[row + 1] & ~right_mask;
        }

        integers[row] = integers[row] & ~shift_mask;
    }

    uint64_t get(uint64_t b)
    {
        uint64_t index = b * size_of_integer;
        uint64_t row = index / 64;
        uint64_t remainder = index % 64;
        uint64_t value = integers[row];
        uint64_t mask = (1 << size_of_integer) - 1;
        uint64_t shift_left = 0;
        uint64_t shift_right = 0;
        uint64_t result = 0;
        if (size_of_integer + remainder <= 64)
        {
            if (size_of_integer == 64)
            {
                return integers[row];
            }
            shift_left = value << (64 - size_of_integer - remainder);
            shift_right = shift_left >> (64 - size_of_integer);
            result = shift_right & mask;
        }
        else
        {
            shift_right = value >> (remainder);
            uint64_t mask2 = mask >> (64 - remainder);
            uint64_t rest = integers[row + 1] & mask2;
            uint64_t shift_rest = rest << (64 - remainder);
            result = shift_rest | shift_right;
        }

        return result;
    }
    void print()
    {
        cout << "array:\n";
        for (size_t i = 0; i < size; i++)
        {
            bitset<64> y(integers[i]);
            cout << y << "\n";
        }
    }
};

PackedIntegerArray::PackedIntegerArray(uint64_t n, uint64_t k)
{
    uint64_t a = 64;
    size = (n * k) / a;
    uint64_t remainder = (n * k) % a;
    if (remainder == 0)
    {
        integers = new uint64_t[size]();
    }
    else
    {
        integers = new uint64_t[(size + 1)]();
        size++;
    }
    size_of_integer = k;
}

PackedIntegerArray::~PackedIntegerArray()
{
    delete integers;
}
