#include <string>
#include <iostream>
#include <random>
#include <vector>
#include <chrono>

#include "BitArray.hpp"
#include "Utils.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    // construct a instance of BitArray class from user input
    string size = argv[1];
    int n = stoi(size);

    BitArray ba(n);
#ifdef DEBUG
    cout << n << "\n";
    ba.print();
#endif
    //generate random numbers
    uint64_t m = 4096;
    vector<int> *rn = GenerateRandomNumbers(m, n);
    SetValues(rn, m, n, &ba);
    GetValues(rn, m, n, &ba);
    delete rn;
    ba.clear();

    m = 32768;
    rn = GenerateRandomNumbers(m, n);
    SetValues(rn, m, n, &ba);
    GetValues(rn, m, n, &ba);
    delete rn;
    ba.clear();

    m = 262144;
    rn = GenerateRandomNumbers(m, n);
    SetValues(rn, m, n, &ba);
    GetValues(rn, m, n, &ba);
    delete rn;
    ba.clear();

    m = 2097152;
    rn = GenerateRandomNumbers(m, n);
    SetValues(rn, m, n, &ba);
    GetValues(rn, m, n, &ba);
    delete rn;
    ba.clear();

    m = 2097152;
    rn = GenerateRandomNumbers(m, n);
    SetValues(rn, m, n, &ba);
    GetValues(rn, m, n, &ba);
    delete rn;
    ba.clear();

    m = 16777216;
    rn = GenerateRandomNumbers(m, n);
    SetValues(rn, m, n, &ba);
    GetValues(rn, m, n, &ba);
    delete rn;
    ba.clear();

    m = 134217728;
    GenerateRandomNumbers(m, n);
    SetValues(rn, m, n, &ba);
    GetValues(rn, m, n, &ba);
    delete rn;
    ba.clear();

#ifdef DEBUG

    //for (int y = 0; y < m; y++)
    //{
    //    cout << rn->at(y) << ",";
    // }
    //cout << "\n";
    ba.print();
#endif
}
