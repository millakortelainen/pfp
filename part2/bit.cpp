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
    uint n = stoi(size);

    BitArray ba(n);
#ifdef DEBUG
    cout << n << "\n";
    ba.print();
#endif
    //generate random numbers
    uint64_t m = 4096;
    vector<int> *rn = GenerateRandomNumbers(m, n);
    SetValues(rn, m, n, &ba);
    cout << "sum was\n";
    cout << ba.sum(8) << "\n";
    GetValues(rn, m, n, &ba);
    delete rn;
    /*
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
*/
#ifdef DEBUG
    //for testing
    cout << "***TESTING THE SUM***\n";

    BitArray test1(10);
    test1.set(0, 1);
    test1.set(5, 1);
    test1.set(9, 1);
    uint64_t test1_sum = test1.sum(10);
    cout << "this should be 3: " << test1_sum << "\n";

    BitArray test2(100);
    test2.set(99, 1);
    for (size_t i = 22; i < 32; i++)
    {
        test2.set(i, 1);
    }
    uint64_t test2_sum = test2.sum(10);
    cout << "this should be 0: " << test2_sum << "\n";
    uint64_t test2_sum2 = test2.sum(30);
    cout << "this should be 8: " << test2_sum2 << "\n";
    uint64_t test2_sum3 = test2.sum(100);
    cout << "this should be 11: " << test2_sum3 << "\n";

    BitArray test3(156);
    for (size_t i = 60; i < 80; i++)
    {
        test3.set(i, 1);
    }
    uint64_t test3_sum = test3.sum(64);
    cout << "this should be 4: " << test3_sum << " \n";
    uint64_t test3_sum2 = test3.sum(156);
    cout << "this should be 20:" << test3_sum2 << "\n";

    cout << "***TESTING THE SUM ENDED***\n";
    cout << __builtin_popcount (6) << "\n";
#endif
}
