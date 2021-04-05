#include <iostream>
#include <fstream>
#include <cmath>
#include <bitset>
#include <algorithm>
#include <vector>
#include "Utils.hpp"

using namespace std;

int main(int argc, char *argv[])
{
  string fileName = argv[1];
  vector<uint64_t> *array = ReadFile<uint64_t>(fileName);
  vector<uint64_t> *differences = new vector<uint64_t>((array->size() - 1));
  sort(array->begin(), array->end());
  for (int j = 1; j < array->size(); j++)
  {
    uint64_t diff = array->at(j) - array->at(j - 1);
    differences->at(j - 1) = diff;
  }
#ifdef DEBUG
  for (int i = 0; i < 5; i++)
  {
    cout << "array: " << array->at(i) << "\n";
    cout << "diff: " << differences->at(i) << "\n";
  }
#endif
  vector<uint8_t> *encodedContent = VByteEncoding(differences);
  WriteFile<uint8_t>(encodedContent, (fileName + ".sorted.vb"));
}
