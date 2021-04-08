#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include "Utils.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    string fileName = argv[1];

    vector<uint8_t> *content = ReadFile<uint8_t>(fileName);

    vector<uint64_t> *decodedContent = VByteDecoding(content);
    delete content;
#ifdef DEBUG
    for (int i = 0; i < 7; i++)
    {
        cout << decodedContent->at(i) << "\n";
    }
#endif

    WriteFile<uint64_t, true>(decodedContent, fileName + ".dec");
    delete decodedContent;
}
