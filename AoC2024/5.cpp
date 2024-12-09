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

bool inOrder(list<int> line, int a, int b)
{
    bool foundB = false;

    for (auto it = line.begin(); it != line.end(); ++it)
    {
        if (*it == a)
        {
            if (foundB)
            {
                return false;
            }
            return true;
        }
        if (*it == b)
        {
            foundB = true;
        }
    }
    return true;
}

bool inOrderLine(list<int> line, vector<vector<int>> pairs)
{
    for (auto it = pairs.begin(); it != pairs.end(); ++it)
    {
        if (!inOrder(line, (*it)[0], (*it)[1]))
        {
            return false;
        }
    }
    return true;
}

bool sort(list<int> &line, int a, int b)
{
    auto itB = line.end();

    for (auto it = line.begin(); it != line.end(); ++it)
    {
        if (*it == a)
        {
            if (itB != line.end())
            {
                line.erase(it);
                line.insert(itB, a);
                return true;
            }
            return false;
        }
        if (*it == b)
        {
            itB = it;
        }
    }
    return false;
}

void sort(list<int> &line, vector<vector<int>> pairs)
{
    bool sorted = false;

    while (!sorted)
    {
        sorted = true;
        for (auto it = pairs.begin(); it != pairs.end(); ++it)
        {
            if (sort(line, (*it)[0], (*it)[1]))
            {
                sorted = false;
            }
        }
    }
}

void printLine(list<int> line)
{
    for (auto it = line.begin(); it != line.end(); ++it)
    {
        cout << *it << endl;
    }
    cout << endl;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int i, a, b, sum;
    vector<vector<int>> pairs;
    char c;

    i = 0;
    sum = 0;

    cin >> noskipws;

    while (cin >> c)
    {
        if (!isdigit(c))
        {
            break;
        }
        pairs.push_back(vector<int>());
        a = 0;
        b = 0;
        while (isdigit(c))
        {
            a = 10 * a + c - '0';
            cin >> c;
        }
        pairs[i].push_back(a);

        cin >> c;

        while (isdigit(c))
        {
            b = 10 * b + c - '0';
            cin >> c;
        }
        pairs[i].push_back(b);

        i++;
    }

    while (cin >> c)
    {
        list<int> line;
        while (isdigit(c))
        {
            a = 0;
            while (isdigit(c))
            {
                a = 10 * a + c - '0';
                if (!(cin >> c))
                {
                    break;
                }
                    
            }
            line.push_back(a);
            if (c == ',')
            {
                cin >> c;
            }
            else
            {
                break;
            }
        }
        if (!inOrderLine(line, pairs))
        {
            sort(line, pairs);
            auto it = line.begin();
            i = 0;
            while (i < line.size() / 2)
            {
                ++it;
                ++i;
            }
            sum += *it;
        }

    }

    cout << sum << endl;
}