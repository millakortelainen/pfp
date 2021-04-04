#include <iostream>
#include <vector>
#include "Utils.hpp"

using namespace std;

int main(int argc, char *argv[])
{
  string fileName = argv[1];

  vector<uint64_t> *array = ReadFile<uint64_t>(fileName);

#ifdef DEBUG
  cout << "first 5 items in file\n";
  for (int j = 0; j < 5; j++)
  {
    cout << array->at(j) << "\n";
  }
#endif

  vector<uint8_t> *encodedContent = VByteEncoding(array);
  WriteFile<uint8_t>(encodedContent, (fileName + ".vb"));
}
