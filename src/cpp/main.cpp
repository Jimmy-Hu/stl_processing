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
