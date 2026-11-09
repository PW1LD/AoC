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

bool isR(long long a, long long b)
{
    int c = b;
    int p = 1;
    while (c != 0)
    {
        p *= 10;
        c /= 10;
    }
    return a - b == ((a - b) / p) * p;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int i;
    long long sum, num;
    bool gone_back, gone_back_back;
    string line;

    sum = 0;
  
    while (getline(cin, line))
    {
        vector<long long> numbers;
        vector<long long> targets;
        vector<int> go_back;
        vector<int> go_back_back;

        auto it = line.begin();
        gone_back = false;
        gone_back_back = false;

        num = 0;
        while (it != line.end() && isdigit(*it))
        {
            num = 10 * num + *it - '0';
            ++it;
        }
        targets.push_back(num);

        while (it != line.end())
        {
            while (it != line.end() && !isdigit(*it))
            {
                ++it;
            }
            num = 0;
            while (it != line.end() && isdigit(*it))
            {
                num = 10 * num + *it - '0';
                ++it;
            }
            numbers.insert(numbers.begin(), num);
        }
        
        i = 0;

        //cout << line << endl;
        //cout << targets[0] << endl;

        while (i != numbers.size())
        {
            if (!gone_back && numbers[i] != 0 && targets[i] != 0 && targets[i] % numbers[i] == 0)
            {
                targets.push_back(targets[i] / numbers[i]);
                go_back.push_back(i);
                //cout << "/" << numbers[i] << " at " << i << endl;
            }
            else if (!gone_back_back)
            {
                targets.push_back(targets[i] - numbers[i]);
                gone_back = false;
                go_back_back.push_back(i);
                //cout << "-" << numbers[i] << " at " << i << endl;
            }
            else if (i != numbers.size() - 1 && isR(targets[i], numbers[i]))
            {
                targets.push_back(targets[i] - numbers[i]);
                num = numbers[i];
                while (num > 0)
                {
                    targets[i + 1] /= 10;
                    num /= 10;
                }
                gone_back = false;
                gone_back_back = false;
                //cout << "||" << numbers[i] << " at " << i << endl;
            }
            else
            {
                targets.push_back(targets[i] - numbers[i]);
                gone_back = false;
                gone_back_back = false;
                
                //cout << "-" << numbers[i] << " at " << i << endl;
            }

            ++i;
            //cout << targets[i] << endl;
                
            if (i == numbers.size())
            {
                if (targets[i] == 0)
                {
                    sum += targets[0];
                    break;
                }
                else if (go_back.size() != 0 && go_back_back.size() != 0)
                {
                    if (go_back_back[go_back_back.size() - 1] < go_back[go_back.size() - 1])
                    {
                        i = go_back[go_back.size() - 1];
                        go_back.pop_back();
                        targets.resize(i + 1);
                        gone_back = true;
                    }
                    else
                    {
                        i = go_back_back[go_back_back.size() - 1];
                        go_back_back.pop_back();
                        targets.resize(i + 1);
                        gone_back = true;
                        gone_back_back = true;
                    }
                }
                else if (go_back_back.size() != 0)
                {
                    i = go_back_back[go_back_back.size() - 1];
                    go_back_back.pop_back();
                    targets.resize(i + 1);
                    gone_back = true;
                    gone_back_back = true;
                }
                else if (go_back.size() != 0)
                {
                    i = go_back[go_back.size() - 1];
                    go_back.pop_back();
                    targets.resize(i + 1);
                    gone_back = true;
                }
            }
        }
        //cout << endl;
    }
    cout << sum << endl;
}