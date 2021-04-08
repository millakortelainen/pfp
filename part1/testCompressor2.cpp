#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char const *argv[])
{

    string fileName = argv[1];

    ifstream f(fileName, ios::binary);
    ofstream write_output(fileName + ".vb");
    while (true)
    {
        uint64_t a;
        f.read(reinterpret_cast<char *>(&a), sizeof(a));

        if (!f.good())
        {
            break;
        }

        while (true)
        {
            uint8_t b = a % 128;
            if (a < 128)
            {
                b = b + 128;
                write_output << b;
                break;
            }
            write_output << b;
            a = a / 128;
        }
    }

    f.close();
    write_output.close();
}
