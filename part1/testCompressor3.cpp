#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{

    string fileName = argv[1];

    ifstream f(fileName, ios::binary);
    ofstream write_output(fileName + ".vb", ios::out | ios::binary);

    vector<uint8_t> encodedContent;
    while (true)
    {
        uint64_t content[1024];
        f.read(reinterpret_cast<char *>(&content), sizeof(uint64_t) * 1024);

        if (f.gcount() == 0)
        {
            break;
        }

        for (int i = 0; i < (f.gcount() / 8); i++)
        {
            uint8_t b;
            uint64_t a = content[i];
            while (a >= 128)
            {
                b = a % 128;
                encodedContent.push_back(b);
                a = a / 128;
            }
            b = a + 128;
            encodedContent.push_back(b);
        }
        write_output.write((char *)reinterpret_cast<uint64_t>(&encodedContent[0]), encodedContent.size());
        encodedContent.clear();
    }

    f.close();
    write_output.close();
}