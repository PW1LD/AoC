#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <iterator>
#include <utility>
#include <array>
#include <bitset>
#include <iomanip>
#include <limits>
#include <cstdlib>
#include <random>
#include <sstream>

using namespace std;

bool isXmas(char first, char second, char third, char fourth)
{
    string xmas = "XMAS";
    string samx = "SAMX";

    return (first == xmas[0] && second == xmas[1] && third == xmas[2] && fourth == xmas[3]) || (first == samx[0] && second == samx[1] && third == samx[2] && fourth == samx[3]);

}

bool isMas(char first, char second, char third)
{
    string mas = "MAS";
    string sam = "SAM";

    return (first == mas[0] && second == mas[1] && third == mas[2]) || (first == sam[0] && second == sam[1] && third == sam[2]);

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int i, j, found, foundMas;
    vector<vector<char>> vecvec;
    string line;

    i = 0;
    found = 0;
    foundMas = 0;

    while (getline(cin, line))
    {
        vecvec.push_back(vector<char>(3, '-')); // padding
        for (j = 0; j < line.size(); j++)
        {
            vecvec[i].push_back(line[j]);
        }
        if (i == 0) {
            for (j = 0; j < 3; j++)
            {
                vecvec[i].push_back('-'); // padding
            }
        }
        else {
            while (j < vecvec[i - 1].size() - 3)
            {
                vecvec[i].push_back('-'); // padding
                j++;
            }
        }
        
        i++;
    }

    for (j = 0; j < 3; j++)
    {
        vecvec.push_back(vector<char>(vecvec[i - 1].size(), '-')); // padding
    }

    for (i = 0; i < vecvec.size() - 3; i++)
    {
        for (j = 3; j < vecvec[i].size() - 3; j++)
        {
            if (isXmas(vecvec[i][j], vecvec[i][j + 1], vecvec[i][j + 2], vecvec[i][j + 3]))
            {
                found++;
            }
            if (isXmas(vecvec[i][j], vecvec[i + 1][j + 1], vecvec[i + 2][j + 2], vecvec[i + 3][j + 3]))
            {
                found++;
            }
            if (isXmas(vecvec[i][j], vecvec[i + 1][j], vecvec[i + 2][j], vecvec[i + 3][j]))
            {
                found++;
            }
            if (isXmas(vecvec[i + 3][j - 3], vecvec[i + 2][j - 2], vecvec[i + 1][j - 1], vecvec[i][j]))
            {
                found++;
            }
            if (isMas(vecvec[i][j], vecvec[i + 1][j + 1], vecvec[i + 2][j + 2]) && isMas(vecvec[i + 2][j], vecvec[i + 1][j + 1], vecvec[i][j + 2]))
            {
                foundMas++;
            }
        }
    }

    cout << found << endl;
    cout << foundMas << endl;

    return 0;
}