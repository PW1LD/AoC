#include <iostream>
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

// Class representing a Point in 2D space
class Point {
public:
    int x, y;

    Point(int x_, int y_) : x(x_), y(y_) {}

    // Display function to print the coordinates of the Point
    void display() const {
        cout << "(" << x << ", " << y << ")";
    }
};

// Comparator for sorting Points by x-coordinate
bool compareByX(const Point& a, const Point& b) {
    return a.x < b.x;
}

// Comparator for sorting Points by y-coordinate
bool compareByY(const Point& a, const Point& b) {
    return a.y < b.y;
}

int main() {
    // Original examples

    // 1. <iostream>: Basic input/output
    cout << "Hello, World!" << endl;

    // 2. <string>: String manipulation
    string str = "Hello, C++!";
    cout << "String: " << str << endl;

    // 3. <cmath>: Mathematical functions
    double sqrt_val = sqrt(16.0);
    cout << "Square root of 16: " << sqrt_val << endl;

    // 4. <algorithm>: Common algorithms (e.g., sort, max, min)
    vector<int> nums = { 4, 2, 8, 5, 7 };
    sort(nums.begin(), nums.end());
    cout << "Sorted nums: ";
    for (int num : nums) cout << num << " ";
    cout << endl;

    // 5. <numeric>: Accumulate function to sum a vector
    int total = accumulate(nums.begin(), nums.end(), 0);
    cout << "Sum of nums: " << total << endl;

    // 6. <vector>: Dynamic array usage
    vector<string> words = { "hello", "world" };
    words.push_back("C++");
    cout << "Vector contents: ";
    for (const auto& word : words) cout << word << " ";
    cout << endl;

    // 7. <deque>: Double-ended queue
    deque<int> dq;
    dq.push_front(10);
    dq.push_back(20);
    cout << "Deque front: " << dq.front() << ", back: " << dq.back() << endl;

    // 8. <queue>: Queue (FIFO)
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout << "Queue front: " << q.front() << endl;

    // 9. <stack>: Stack (LIFO)
    stack<int> stk;
    stk.push(5);
    stk.push(10);
    cout << "Stack top: " << stk.top() << endl;

    // 10. <set>: Sorted set of unique elements
    set<int> s = { 1, 2, 3, 2 }; // Duplicate '2' will be ignored
    cout << "Set contents: ";
    for (int val : s) cout << val << " ";
    cout << endl;

    // 11. <map>: Key-value pairs
    map<char, int> roman = { {'I', 1}, {'V', 5}, {'X', 10} };
    cout << "Value of 'V': " << roman['V'] << endl;

    // 12. <unordered_map>: Faster key-value pairs, no guaranteed order
    unordered_map<string, int> ages = { {"Alice", 25}, {"Bob", 30} };
    cout << "Age of Bob: " << ages["Bob"] << endl;

    // 13. <unordered_set>: Set without order guarantees
    unordered_set<int> uset = { 10, 20, 30, 10 }; // Duplicate '10' will be ignored
    cout << "Unordered set contents: ";
    for (int val : uset) cout << val << " ";
    cout << endl;

    // 14. <iterator>: Iterator usage
    vector<int>::iterator it = nums.begin();
    cout << "First element in nums using iterator: " << *it << endl;

    // 15. <utility>: Pair usage
    pair<string, int> person = { "Charlie", 35 };
    cout << "Person: " << person.first << ", Age: " << person.second << endl;

    // 16. <array>: Fixed-size 1D array
    array<int, 3> arr = { 9, 8, 7 };
    cout << "Array contents: ";
    for (int val : arr) cout << val << " ";
    cout << endl;

    // 17. Fixed-size 2D array using std::array
    array<array<int, 3>, 3> matrix = { {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}} };
    cout << "2D Array (Matrix) contents:" << endl;
    for (auto& row : matrix) {
        for (auto& element : row) {
            cout << element << " ";
        }
        cout << endl;
    }

    // 18. <bitset>: Manage bits
    bitset<8> bits(42);
    cout << "Bits of 42: " << bits << endl;

    // 19. <iomanip>: Set precision for output
    double pi = 3.14159265358979;
    cout << fixed << setprecision(2) << "Pi to 2 decimal places: " << pi << endl;

    // 20. <limits>: Numeric limits
    cout << "Max int value: " << numeric_limits<int>::max() << endl;

    // 21. <cstdlib>: Random number generation and other functions
    srand(time(0));
    int random_num = rand() % 100; // Random number between 0 and 99
    cout << "Random number: " << random_num << endl;

    // 22. <random>: Modern random number generation
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 6);
    cout << "Random dice roll: " << dist(gen) << endl;

    // 23. Point class and sorting examples
    vector<Point> points = { {3, 5}, {1, 2}, {6, 3}, {2, 8}, {5, 1} };

    // Sorting points by x-coordinate
    sort(points.begin(), points.end(), compareByX);
    cout << "Points sorted by x-coordinate: ";
    for (const Point& p : points) {
        p.display();
        cout << " ";
    }
    cout << endl;

    // Sorting points by y-coordinate
    sort(points.begin(), points.end(), compareByY);
    cout << "Points sorted by y-coordinate: ";
    for (const Point& p : points) {
        p.display();
        cout << " ";
    }
    cout << endl;

    // 24. Pairs and sorting examples
    vector<pair<int, int>> pairs = { {3, 5}, {1, 2}, {6, 3}, {2, 8}, {5, 1} };

    // Sorting pairs by first element
    sort(pairs.begin(), pairs.end());
    cout << "Pairs sorted by first element: ";
    for (const auto& p : pairs) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;

    // Sorting pairs by second element
    sort(pairs.begin(), pairs.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
        });
    cout << "Pairs sorted by second element: ";
    for (const auto& p : pairs) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;

    return 0;
}