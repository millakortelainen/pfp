#include <random>
#include <vector>
#include <chrono>

#include "PackedIntegerArray.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    string n = argv[1];
    string k = argv[2];
    uint int_n = stoi(n);
    uint int_k = stoi(k);

    uint64_t power_of_k = (1 << int_k)-1;

    PackedIntegerArray pia(int_n, int_k);

    vector<uint64_t> numbers(int_n);
    mt19937 g(random_device{}());
    uniform_int_distribution<uint64_t> d(0, power_of_k);
    for (size_t i = 0; i < int_n; i++)
    {
        uint64_t r = d(g);
        numbers.at(i) = r;
        pia.set(i, r);
    }

    for (size_t i = 0; i < int_n; i++)
    {
        if (numbers.at(i) != pia.get(i))
        {
            cout << "error\n";
            cout << "numbers: " << numbers.at(i) << "\n";
            cout << "class: " << pia.get(i) << "\n";
            cout << "index: " << i << "\n";
            cout << "***\n";
        }
    }

#ifdef DEBUG
    PackedIntegerArray pia_test(20, 64);
    pia_test.set(0, 1);
    pia_test.set(1, 1);
    pia_test.set(2, 1);
    pia_test.set(6, 1);
    pia_test.print();
    cout << "0: " << pia_test.get(2) << "\n";
#endif
}
