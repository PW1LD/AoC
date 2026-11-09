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

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int i, index, sum, no_digits;
    bool active;
    char c;
    string s, sdo, sdont;
    vector<int> factors;


    index = 0;
    sum = 0;
    no_digits = 0;
    active = true;
    s = "mul(0,1)";
    sdo = "do()";
    sdont = "don't()";
    factors = { 0, 0 };

    cin >> noskipws;

    while (cin >> c)
    {
        if (active)
        {
            if (isdigit(c) && isdigit(s[index]))
            {
                i = s[index] - '0';
                factors[i] = 10 * factors[i] + c - '0';

                if (++no_digits == 3)
                {
                    index++;
                    no_digits = 0;
                }
            }
            else if (c == ',' && index == 4 && no_digits)
            {
                index += 2;
                no_digits = 0;
            }
            else if ((c == ')' && index == 6 && no_digits) || (c == ')' && index == 7))
            {
                sum += factors[0] * factors[1];

                index = 0;
                no_digits = 0;
                factors[0] = 0;
                factors[1] = 0;
            }
            else if (c == s[index])
            {
                index++;
            }
            else
            {
                if (c == 'd') {
                    index = 1;
                }
                else if (c == sdont[index])
                {
                    if (++index == 7)
                    {
                        active = false;
                        index = 0;
                    }
                }
                else {
                    index = 0;
                }
                no_digits = 0;
                factors[0] = 0;
                factors[1] = 0;
            }
        }
        else
        {
            if (c == sdo[index]) {
                if (++index == 4)
                {
                    active = true;
                    index = 0;
                }
            }
            else
            {
                index = 0;
            }
        }
    }

    cout << sum << endl;


    return 0;
}