#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void debug(string debugInfo, bool debugOn);

vector<vector<char>> readCharMatrix();

void printMatrix(vector<vector<char>> matrix);
void printMatrix(vector<vector<int>> matrix);



