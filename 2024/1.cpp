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
               
    int n, m, l;
    list<int> l1, l2;

    m = 1; // switch l1 or l2

    // reading input
    while (cin >> n)
    {
        if (m)
        {
            l1.push_back(n);
            m = 0;
        }
        else 
        {
            l2.push_back(n);
            m = 1;
        }
    }

    l1.sort();
    l2.sort();

    m = 0; // m and n are sum and temp sum resp.
    n = 0;

    // part 1
    /*while (!l1.empty()) {
        m += abs(l1.front() - l2.front());  // adding diff
        l1.pop_front();                     // removing compared elements
        l2.pop_front();
    }*/
    

    // part 2
    while (!l1.empty() && !l2.empty()) 
    {
        // if l2 is ahead of l1 the front of l1 will not appear again in l2
        if (l1.front() < l2.front()) 
        {
            l = l1.front();
            l1.pop_front();
            n = m - n;                              // how much m increased for the previous front of l1
            while (!l1.empty() && l == l1.front())  // if l1 has repeated elements they should add equally to m
            {
                m += n;
                l1.pop_front();
            }
            n = m;
        }
        else // l2.front() <= l1.front()
        {
            if (l2.front() == l1.front()) // here just increasing m by the front of whenever l1.front() == l2.front()
            {
                m += l1.front();
            }
            l2.pop_front();
        }
    }

    cout << m << endl;


    return 0;
}