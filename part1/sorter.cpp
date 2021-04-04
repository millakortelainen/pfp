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

  sort(array->begin(), array->end());
  ofstream write_output(file_name += ".sorted.vb", ios::binary);
  for (int j = 1; j < n; j++)
  {
    int diff = array[j] - array[j - 1];
    while (true)
    {
      int b = fmod(diff, 128);
      if (diff < 128)
      {
        b = b + 128;
        write_output << char(b);
        break;
      }
      write_output << char(b);
      diff = diff / 128;
    }
  }
  write_output.close();
}
