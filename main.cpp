#include<iostream>
#include<fstream>
#include<cstring>
#include<stdio.h>
#include<assert.h>
#include "photo.h"

int main()
{   

    std::vector<int> image = img::Read("Images/Sprite-0011.png");

    for (int i = 0; i < image.size(); i++)
    {
    //    printf("%x ", image[i]);
    }
    
    if (img::IsPng(image))
    {
        std::cout << "It's an image\n";
    }else
    {
        std::cout << "Is not an image\n";
    }
    
    std::pair<int, int> size = img::PngSize(image);
    std::cout << size.first << " " << size.second << "\n";

    return 0;
}