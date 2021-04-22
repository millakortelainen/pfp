#include <random>
#include <vector>
#include <chrono>

#include "BitArray.hpp"

using namespace std;

vector<int> *GenerateRandomNumbers(uint64_t m, int n)
{
    vector<int> *randomNumbers = new vector<int>(m);
    mt19937 g(random_device{}());
    uniform_int_distribution<int> d(0, n);
    for (size_t i = 0; i < m; i++)
    {
        randomNumbers->at(i) = d(g);
    }
    return randomNumbers;
}

void SetValues(vector<int> *rn, uint64_t m, int n, BitArray* ba)
{
    auto start = std::chrono::high_resolution_clock::now();

    for (size_t i = 0; i < n; i++)
    {
        ba->set(rn->at(i), 1);
    }
    auto end = std::chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed_seconds = end - start;
    cout << "m: " << m << "\n";
    cout << "set elapsed time: " << elapsed_seconds.count() << "s\n";
    cout << "\n";
}


void GetValues(vector<int> *rn, uint64_t m, int n, BitArray* ba)
{
    auto start = std::chrono::high_resolution_clock::now();

    for (size_t i = 0; i < n; i++)
    {
        ba->get(rn->at(i));
    }
    auto end = std::chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed_seconds = end - start;
    cout << "m: " << m << "\n";
    cout << "get elapsed time: " << elapsed_seconds.count() << "s\n";
    cout << "\n";
}