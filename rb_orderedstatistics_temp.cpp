#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#ifdef __mr__
    #include "prettyprint.hpp"
#endif
#define endl                        ('\n')
using namespace __gnu_pbds;
using namespace std;

template<typename T>
using orderset = tree<
    T, null_type, less<T>, rb_tree_tag,
    tree_order_statistics_node_update>;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    int32_t q;
    cin >> q;
    orderset<int32_t> os;
    while(q--) {
        char op;
        int32_t k;
        cin >> op >> k;
        switch(op) {
            case 'I':
                os.insert(k);
                break;
            case 'D':
                os.erase(k);
                break;
            case 'K':
                if (k > os.size())
                    cout << "invalid" << endl;
                else
                    cout << *os.find_by_order(k - 1) << endl;
                break;
            case 'C':
                cout << os.order_of_key(k) << endl;
                break;
        }
    }
    return 0;
}
