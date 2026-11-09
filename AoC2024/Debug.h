#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class DebugStream {
    ostringstream os;
    bool debugFlag;

public:
    DebugStream(bool debug) : debugFlag(debug) {}

    // Overload << to capture any streamable input
    template <typename T>
    DebugStream& operator<<(const T& value) {
        if (debugFlag) {
            os << value;
        }
        return *this;
    }

    // Overload << for manipulators like std::endl
    DebugStream& operator<<(ostream& (*manip)(ostream&)) {
        if (debugFlag) {
            os << manip;
        }
        return *this;
    }

    // Output the final string when done
    ~DebugStream() {
        if (debugFlag) {
            cout << os.str();
        }
    }
};

void printMatrix(vector<vector<char>> matrix, bool debug = true, string delimeter = "");
void printMatrix(vector<vector<int>> matrix, bool debug = true, string delimeter = ",");
void printVector(vector<char> vec, bool debug = true, string delimeter = "");
void printVector(vector<int> vec, bool debug = true, string delimeter = ",");