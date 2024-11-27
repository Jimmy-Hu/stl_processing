// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#define CGAL_USE_BASIC_VIEWER
#include <chrono>
#include <iostream>
#include "image.h"
#include "image_io.h"
#include "basic_functions.h"
#include "image_operations.h"

#include "../../stl_reader/stl_reader.h"     //  https://github.com/sreiter/stl_reader
//  https://github.com/Innoptech/OpenSTL
#include "../../OpenSTL/modules/core/include/openstl/core/stl.h"

std::vector<openstl::Triangle> stl_processor(std::vector<openstl::Triangle>& input)
{
    std::vector<openstl::Triangle> output;
    float maximum_z = input[0].v0.z;
    float maximum_location_x = input[0].v0.x, maximum_location_y = input[0].v0.y;
    for (std::size_t index = 0; index < input.size(); ++index)
    {
        if (maximum_z < input[index].v0.z)
        {
            maximum_z = input[index].v0.z;
            maximum_location_x = input[index].v0.x;
            maximum_location_y = input[index].v0.y;
        }
    }
    std::cout << "maximum_z = " << maximum_z << "\n";
    std::cout << "maximum_location_x = " << maximum_location_x << "\n";
    std::cout << "maximum_location_y = " << maximum_location_y << "\n";
}

int main()
{
    auto start = std::chrono::system_clock::now();
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    if (elapsed_seconds.count() != 1)
    {
        std::cout << "Computation finished at " << std::ctime(&end_time) << "elapsed time: " << elapsed_seconds.count() << " seconds.\n";
    }
    else
    {
        std::cout << "Computation finished at " << std::ctime(&end_time) << "elapsed time: " << elapsed_seconds.count() << " second.\n";
    }
    
    return EXIT_SUCCESS;
}
