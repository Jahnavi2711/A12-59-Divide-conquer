
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxPoints(vector<vector<int>> &points)
    {
        int n = points.size();
        if (n <= 2)
            return n;

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            unordered_map<string, int> slopes;
            int duplicates = 1, best = 0;

            for (int j = i + 1; j < n; j++)
            {
                long long dx = (long long)points[j][0] - points[i][0];
                long long dy = (long long)points[j][1] - points[i][1];

                if (dx == 0 && dy == 0)
                {
                    duplicates++;
                    continue;
                }

                long long g = gcd(abs(dx), abs(dy));
                dx /= g;
                dy /= g;

                if (dx < 0 || (dx == 0 && dy < 0))
                {
                    dx = -dx;
                    dy = -dy;
                }

                string key = to_string(dx) + "," +
                             to_string(dy);

                best = max(best, ++slopes[key]);
            }

            ans = max(ans, best + duplicates);
        }

        return ans;
    }
};

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> points(n, vector<int>(2));
    for (int i = 0; i < n; i++)
        cin >> points[i][0] >> points[i][1];

    Solution sol;
    cout << sol.maxPoints(points) << '\n';

    return 0;
}
