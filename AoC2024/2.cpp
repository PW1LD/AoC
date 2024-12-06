#include <iostream>
#include <iterator>
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

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int i, j, k, num, correct, no_correct, change;
    string line;
    

    no_correct = 0;

    while (getline(cin, line))
    {
        istringstream iss(line);
        vector<int> vecv;
        while (iss >> num)
        {
            vecv.push_back(num);
        }

        // part 2

        for (k = 0; k < vecv.size(); k++) {
            vector<int> vec;
            for (j = 0; j < vecv.size(); j++) {
                if (j != k)
                {
                    vec.push_back(vecv[j]);
                }
            }

            // part 1

            correct = 1;

            change = vec[1] - vec[0];


            for (i = 0; i < vec.size() - 1; i++) {
                if (abs(vec[i + 1] - vec[i]) > 3)
                {
                    correct = 0;
                    break;
                }
                else if (vec[i + 1] == vec[i])
                {
                    correct = 0;
                    break;
                }
                else if (change > 0 && vec[i + 1] < vec[i])
                {
                    correct = 0;
                    break;
                }
                else if (change < 0 && vec[i + 1] > vec[i])
                {
                    correct = 0;
                    break;
                }
            }
            if (correct) {
                no_correct++;
                break;
            }
        }

    }

    cout << no_correct << endl;

    return 0;
}