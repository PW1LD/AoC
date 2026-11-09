#pragma once

#include <iostream>
#include <sstream>
#include <vector>
#include <string>

#include "Debug.h"

using namespace std;

// input
vector<vector<char>> readCharMatrix(bool debug = false);
vector<int> readIntVector(bool debug = false);


// math
long long artithmeticSum(long long start, long long stop, long long n, bool debug = false);