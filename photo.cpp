#include "photo.h"

namespace img
{
    int ImageSpecifierSize = 8;
    int ImageSpecifier[] = {0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A, 0x0A};

    std::vector<int> Read(std::string name)
    {
        std::vector<int> Data;
        std::ifstream image(name, std::ios::binary);

        short value;
        char buf[sizeof(short)];
        while (image.read(buf ,1))
        {
            std::memcpy(&value, buf, sizeof(value));
            Data.push_back((int)value);
        }

        return Data;
    }

    bool IsPng(std::vector<int> Data)
    {
        for (int  i = 0; i < ImageSpecifierSize; i++)
        {
            if(Data[i] != ImageSpecifier[i])
                return false;
        }
        return true;
    }

    //Not really neccesary function since data.size() can be used instead
    int FileSize(std::vector<int> data)
    {
        return data.size();
    }

    std::pair<ull, ull> PngSize(std::vector<int> data)
    {
        //Offset in the file IHDR to get size; 
        int Offset = 16;
        ull Width, Length;
        Width = Length = 0; 
        //Get width 
        for (int i = 4; i > 0; i--)
        {
            Width += pow(16, i-1) * (ull)data[Offset];
            Offset++;
        }

        for (int i = 4; i > 0; i--)
        {
            Length += pow(16, i-1) * (ull)data[Offset];
            Offset++;
        }

        std::pair<ull, ull> size = {Width, Length};
        return size;
    }

}


