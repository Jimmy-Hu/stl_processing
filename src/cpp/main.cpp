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
    output.resize(input.size());
    #pragma omp parallel for
    for (std::size_t index = 0; index < input.size(); ++index)
    {
        openstl::Triangle temp;
        temp = input[index];
        temp.v0.z = temp.v0.z + maximum_z - (std::sqrt(std::pow(maximum_z * 10, 2) - std::pow(temp.v0.x - maximum_location_x, 2)));
        temp.v1.z = temp.v1.z + maximum_z - (std::sqrt(std::pow(maximum_z * 10, 2) - std::pow(temp.v1.x - maximum_location_x, 2)));
        temp.v2.z = temp.v2.z + maximum_z - (std::sqrt(std::pow(maximum_z * 10, 2) - std::pow(temp.v2.x - maximum_location_x, 2)));
        if (temp.v0.z > 5000 || temp.v1.z > 5000 || temp.v2.z > 5000)
        {
            temp = input[index];
        }
        output[index] = temp;
    }
    return output;
}

auto find_max_x(openstl::Triangle& input)
{
    float maximum = std::max(input.v0.x, input.v1.x);
    maximum = std::max(maximum, input.v2.x);
    return maximum;
}

auto find_min_x(openstl::Triangle& input)
{
    float minimum = std::min(input.v0.x, input.v1.x);
    minimum = std::min(minimum, input.v2.x);
    return minimum;
}

auto find_max_y(openstl::Triangle& input)
{
    float maximum = std::max(input.v0.y, input.v1.y);
    maximum = std::max(maximum, input.v2.y);
    return maximum;
}

auto find_min_y(openstl::Triangle& input)
{
    float minimum = std::min(input.v0.y, input.v1.y);
    minimum = std::min(minimum, input.v2.y);
    return minimum;
}

auto find_max_z(openstl::Triangle& input)
{
    float maximum_z = std::max(input.v0.z, input.v1.z);
    maximum_z = std::max(maximum_z, input.v2.z);
    return maximum_z;
}

auto find_min_z(openstl::Triangle& input)
{
    float minimum_z = std::min(input.v0.z, input.v1.z);
    minimum_z = std::min(minimum_z, input.v2.z);
    return minimum_z;
}

auto find_max(std::vector<openstl::Triangle>& input, std::size_t channel)
{
    float maximum = 0;
    switch (channel)
    {
    case 0:
        maximum = input[0].v0.x;
        for (auto&& element : input)
        {
            if (maximum < find_max_x(element))
            {
                maximum = find_max_x(element);
            }
        }
        return maximum;
        break;
    case 1:
        maximum = input[0].v0.y;
        for (auto&& element : input)
        {
            if (maximum < find_max_y(element))
            {
                maximum = find_max_y(element);
            }
        }
        return maximum;
        break;
    case 2:
        maximum = input[0].v0.z;
        for (auto&& element : input)
        {
            if (maximum < find_max_z(element))
            {
                maximum = find_max_z(element);
            }
        }
        return maximum;
        break;
    default:
        break;
    }
}

auto find_min(std::vector<openstl::Triangle>& input, std::size_t channel)
{
    float minimum = 0;
    switch (channel)
    {
    case 0:
        minimum = input[0].v0.x;
        for (auto&& element : input)
        {
            if (minimum > find_min_x(element))
            {
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
