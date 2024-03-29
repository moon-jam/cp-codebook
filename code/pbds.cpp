#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace std;

template <class T>
using Tree =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T>
using multiTree =
    tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    Tree<int> tr;
    tr.insert(1), tr.insert(8), tr.insert(3);
    // an iterator of the (k+1)th smallest element
    cout << *tr.find_by_order(1) << '\n';
    // the number of elements are less than ktyl,
    cout << tr.order_of_key(6) << '\n';
    tr.erase(8);
    return 0;
}