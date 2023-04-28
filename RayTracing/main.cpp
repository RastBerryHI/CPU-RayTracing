#include <fstream>
#include "Graphics/FVector.h"

int main(int argc, char* argv[])
{
    std::ofstream writestream("gradient.ppm");
    if (!writestream.is_open())
    {
        return EXIT_FAILURE;
    }
    
    int nx = 200;
    int ny = 100;
    
    writestream<< "P3\n" << nx << " " << ny << "\n255\n";
    
    for (int j = ny-1; j >= 0; j--)
    {
        for (int i = 0; i < nx; i++)
        {
            Graphics::FVector Color(
                static_cast<float>(i) / static_cast<float>(nx),
                static_cast<float>(j) / static_cast<float>(ny),
                0.2f
            );
            
            int ir = static_cast<int>(255.99f * Color[0]);
            int ig = static_cast<int>(255.99f* Color[1]);
            int ib = static_cast<int>(255.99f * Color[2]);
            
            writestream<< ir << " " << ig << " " << ib << "\n";
        }
    }

    writestream.close();
    
    return EXIT_SUCCESS;
}
