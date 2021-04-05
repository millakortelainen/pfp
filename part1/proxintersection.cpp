#include <iostream>
#include <fstream>
#include "Utils.hpp"
#include <tuple>

using namespace std;

int main(int argc, char const *argv[])
{
    int radius = stoi(argv[1]);

    string fileName = argv[2];

    ifstream f(fileName);
    char a;
    f >> a;
    cout << a;
    int b;
    f >> b;
    cout << b;
    char c;
    f >> c;
    cout << c;
    int d;
    f >> d;
    cout << d;
    f.close();
    return 0;
}
