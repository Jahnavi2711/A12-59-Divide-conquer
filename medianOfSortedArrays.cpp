
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& a,
                                  vector<int>& b) {
        if (a.size() > b.size())
            return findMedianSortedArrays(b, a);

        int m = a.size(), n = b.size();
        int low = 0, high = m;
        int half = (m + n + 1) / 2;

        while (low <= high) {
            int i = low + (high - low) / 2;
            int j = half - i;

            int l1 = (i == 0) ? INT_MIN : a[i - 1];
            int r1 = (i == m) ? INT_MAX : a[i];
            int l2 = (j == 0) ? INT_MIN : b[j - 1];
            int r2 = (j == n) ? INT_MAX : b[j];

            if (l1 <= r2 && l2 <= r1) {
                if ((m + n) % 2)
                    return max(l1, l2);

                return ((double)max(l1, l2) +
                        min(r1, r2)) / 2.0;
            }

            if (l1 > r2)
                high = i - 1;
            else
                low = i + 1;
        }

        return 0.0;
    }
};

int main() {
    int m, n;
    cin >> m;

    vector<int> a(m);
    for (int &x : a) cin >> x;

    cin >> n;
    vector<int> b(n);
    for (int &x : b) cin >> x;

    Solution sol;
    cout << fixed << setprecision(5)
         << sol.findMedianSortedArrays(a, b) << '\n';

    return 0;
}
