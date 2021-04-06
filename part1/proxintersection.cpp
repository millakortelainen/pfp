#include <iostream>
#include <fstream>
#include <string>
#include "Utils.hpp"
#include <tuple>
#include <algorithm>
#include <chrono>

using namespace std;

int main(int argc, char const *argv[])
{
    int radius = stoi(argv[1]);

    string fileName = argv[2];
    vector<tuple<int, int>> *pairs = new vector<tuple<int, int>>;

    ifstream f(fileName);
    while (true)
    {

        char readChar;
        int fileA;
        int fileB;
        f >> readChar >> fileA >> readChar >> fileB >> readChar;
        if (!f.good())
        {
            break;
        }
        tuple<int, int> t1(fileA, fileB);
        pairs->push_back(t1);
    }
    f.close();

#ifdef DEBUG
    vector<uint64_t> v1 = {3, 4, 18, 28, 129};
    vector<uint64_t> v2 = {0, 2, 26, 29, 129, 132};
    int r1 = 2;
    cout << "this should be 4 : " << CalculateIntersection(&v1, &v2, r1) << "\n";
#endif
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < pairs->size(); i++)
    {

        string fileNameA = "F" + to_string(get<0>(pairs->at(i))) + ".vb";
        vector<uint8_t> *fileContentA = ReadFile<uint8_t>(fileNameA);
        vector<uint64_t> *decodedFileContentA = VByteDecoding(fileContentA);
        sort(decodedFileContentA->begin(), decodedFileContentA->end());

        string fileNameB = "F" + to_string(get<1>(pairs->at(i))) + ".vb";
        vector<uint8_t> *fileContentB = ReadFile<uint8_t>(fileNameB);
        vector<uint64_t> *decodedFileContentB = VByteDecoding(fileContentB);
        sort(decodedFileContentB->begin(), decodedFileContentB->end());

#ifdef DEBUG
        cout << fileNameA << " and " << fileNameB << " and radius " << radius << "\n";
        cout << "first five\n";
        for (int l = 0; l < 5; l++)
        {
            cout << decodedFileContentA->at(l) << " and " << decodedFileContentB->at(l) << "\n";
        }
#endif

        int intersectionSize = CalculateIntersection(decodedFileContentA, decodedFileContentB, radius);

        cout << fileNameA << " and " << fileNameB << " intersections size is "<< intersectionSize << ".\n";
    }
    auto end = std::chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed_seconds = end - start;
    cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
}
