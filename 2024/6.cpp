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
#include <Windows.h>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int i, j, k, cI, cJ, startI, startJ, sum;
    vector<vector<int>> map;
    string line;
    unordered_map<char, int> convert;
    bool notExited;

    convert['.'] = 1;
    convert['#'] = -1;
    convert['^'] = 22;

    sum = 0;
    i = 0;
    startI = 0;
    startJ = 0;

    while (getline(cin, line))
    {
        map.push_back(vector<int>());
        for (j = 0; j < line.size(); ++j)
        {
            map[i].push_back(convert[line[j]]);
            if (line[j] == '^')
            {
                startI = i;
                startJ = j;
            }
        }
        ++i;
    }

    for (k = 0; k < map.size(); ++k)
    {
        for (j = 0; j < map[k].size(); ++j)
        {
            if (!(map[k][j] % 11 == 0 || map[k][j] == -1))
            {
                vector<vector<int>> copyMap(map);
                map[k][j] = -1;
                cI = startI;
                cJ = startJ;
                i = 0;
                notExited = true;
                while (notExited)
                {
                    switch (i)
                    {
                    case 0:
                        while (cI > 0 && map[cI - 1][cJ] != -1)
                        {
                            if (map[cI - 1][cJ] % 2 == 0)
                            {
                                sum++;
                                notExited = false;
                                break;
                            }
                            map[--cI][cJ] *= 2;
                        }
                        if (cI == 0)
                        {
                            notExited = false;
                        }
                        break;
                    case 1:
                        while (cJ < map[cI].size() - 1 && map[cI][cJ + 1] != -1)
                        {
                            if (map[cI][cJ + 1] % 3 == 0)
                            {
                                sum++;
                                notExited = false;
                                break;
                            }
                            map[cI][++cJ] *= 3;
                        }
                        if (cJ == map[cI].size() - 1)
                        {
                            notExited = false;
                        }
                        break;
                    case 2:
                        while (cI < map.size() - 1 && map[cI + 1][cJ] != -1)
                        {
                            if (map[cI + 1][cJ] % 5 == 0)
                            {
                                sum++;
                                notExited = false;
                                break;
                            }
                            map[++cI][cJ] *= 5;
                        }
                        if (cI == map.size() - 1)
                        {
                            notExited = false;
                        }
                        break;
                    case 3:
                        while (cJ > 0 && map[cI][cJ - 1] != -1)
                        {
                            if (map[cI][cJ - 1] % 7 == 0)
                            {
                                sum++;
                                notExited = false;
                                break;
                            }
                            map[cI][--cJ] *= 7;
                        }
                        if (cJ == 0)
                        {
                            notExited = false;
                        }
                        break;
                    default:
                        break;
                    }
                    i = (i + 1) % 4;
                }
                map = copyMap;
            }
        }
    }

    cout << sum << endl;
}