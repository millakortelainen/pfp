#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

template <typename T>
vector<T> *ReadFile(string fileName)
{

    ifstream f(fileName, ios::binary);

    streampos begin, end;
    begin = f.tellg();
    f.seekg(0, ios::end);
    end = f.tellg();

    int n = (end - begin) / sizeof(T);

    vector<T> *content = new vector<T>(n);

    f.seekg(0, ios::beg);

    int i = 0;

    while (true)
    {
        T a;
        f.read(reinterpret_cast<char *>(&a), sizeof(a));

        if (!f.good())
        {
            break;
        }
        content->at(i) = a;

        i++;
    }

    f.close();
    return content;
}

vector<uint8_t> *VByteEncoding(vector<uint64_t> *content)
{
    vector<uint8_t> *encodedContent = new vector<uint8_t>;

    for (unsigned i = 0; i < content->size(); i++)
    {
        uint64_t a = content->at(i);
        while (true)
        {
            uint8_t b = a % 128;
            if (a < 128)
            {
                b = b + 128;
                encodedContent->push_back(b);
                break;
            }
            encodedContent->push_back(b);
            a = a / 128;
        }
    }

    return encodedContent;
}

vector<uint64_t> *VByteDecoding(vector<uint8_t> *content)
{
    uint64_t sum = 0;
    int j = 0;
    vector<uint64_t> *decodedContent = new vector<uint64_t>;
    for (unsigned i = 0; i < content->size(); i++)
    {
        uint8_t a = content->at(i);
        if (a > 128)
        {
            sum += ((a - 128) * pow(128, j));
            decodedContent->push_back(sum);
            sum = 0;
            j = 0;
        }
        else
        {
            sum += a * pow(128, j);
            j += 1;
        }
    }
    return decodedContent;
}

template <typename T, bool lineBreak>
void WriteFile(vector<T> *content, string fileName)
{
    ofstream write_output(fileName);
    for (int i = 0; i < content->size(); i++)
    {
        if constexpr (lineBreak)
        {
            write_output << content->at(i) << "\n";
        }
        else
        {
            write_output << content->at(i);
        }
    }
    write_output.close();
}

int CalculateIntersection(vector<uint64_t> *v1, vector<uint64_t> *v2, int r)
{
    int sum = 0;
    int i1 = 0;
    int i2 = 0;

#ifdef DEBUG
    cout << "sum: " << sum << ", i1: " << i1 << ", i2:" << i2 << "\n";
    int i = 0;
    cout << UINT64_MAX << "\n";
#endif

    while (i1 < v1->size() && i2 < v2->size())
    {
        uint64_t lowerBound = 0;
        if (r < v1->at(i1))
        {
            lowerBound = v1->at(i1) - r;
        }
        uint64_t upperBound = UINT64_MAX;
        if (v1->at(i1) + r < UINT64_MAX)
        {
            upperBound = v1->at(i1) + r;
        }

        uint64_t b = v2->at(i2);

        if (b < lowerBound)
        {
            i2++;
        }
        if (b > upperBound)
        {
            i1++;
        }
        if (lowerBound <= b && b <= upperBound)
        {
            sum++;
            i2++;
        }
#ifdef DEBUG
        if (i < 5)
        {
            cout << "lowebound: " << lowerBound << ", upperBound " << upperBound << ", b " << b << "\n";
        }
        i++;
#endif
    }
    return sum;
}