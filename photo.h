#ifndef PHOTO_LIB
#define PHOTO_LIB

#include<fstream>
#include<vector>
#include<cstring>
#include<cmath>

namespace img
{
    typedef unsigned long long ull;

    bool IsPng(std::vector<int>);
    int FileSize(std::vector<int>);

    // std::pair<int, int> SmallPngSize(std::vector<int>);
    std::pair<ull, ull> PngSize(std::vector<int>);
    std::vector<int> Read(std::string);
    void ClearMemory(std::vector<int>);

}


#endif