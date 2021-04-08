#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Utils.hpp"

using namespace std;

int main(int argc, char *argv[])
{
  string fileName = argv[1];
  vector<uint64_t> *content = ReadFile<uint64_t>(fileName);
  vector<uint64_t> *differences = new vector<uint64_t>((content->size() - 1));
  sort(content->begin(), content->end());
  for (int j = 1; j < content->size(); j++)
  {
    uint64_t diff = content->at(j) - content->at(j - 1);
    differences->at(j - 1) = diff;
  }
  delete content;
#ifdef DEBUG
  for (int i = 0; i < 5; i++)
  {
    cout << "content: " << content->at(i) << "\n";
    cout << "diff: " << differences->at(i) << "\n";
  }
#endif
  vector<uint8_t> *encodedContent = VByteEncoding(differences);
  delete differences;
  WriteFile<uint8_t, false>(encodedContent, (fileName + ".sorted.vb"));
  delete encodedContent;
}
