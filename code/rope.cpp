#include <bits/extc++.h>
using namespace __gnu_cxx;
using namespace std;
int main() {
    rope<int> r, a, b;
    b += 10;        // {10}
    r += 2;         // {2}
    r += 3;         // {2, 3}
    a = r + r + b;  // {2, 3, 2, 3, 10}
    for (int i : a) cout << i << ' ';
    cout << '\n';
    b += a.substr(2, 3);  // get 3 elements from a_2
    for (int i : b) cout << i << ' ';
    cout << '\n';
    r.pop_back();       // {3}
    r.pop_front();      // empty
    r.push_back(1);     // {1}
    r.push_front(10);   // {10, 1}
    r.replace(1, 100);  // replace r_1 to 100
    r.erase(0, 1);      // erase 1 element from 0
    r.insert(0, 7);     // insert 7 at r_0
    for (int i : r) cout << i << ' ';
}