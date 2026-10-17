
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> getSkyline(
        vector<vector<int>> &buildings)
    {

        vector<pair<int, int>> events;

        for (auto &b : buildings)
        {
            events.push_back({b[0], -b[2]});
            events.push_back({b[1], b[2]});
        }

        sort(events.begin(), events.end());

        multiset<int> active;
        active.insert(0);

        vector<vector<int>> ans;
        int prevHeight = 0;
        int i = 0, n = events.size();

        while (i < n)
        {
            int x = events[i].first;

            while (i < n && events[i].first == x)
            {
                int h = events[i].second;

                if (h < 0)
                {
                    active.insert(-h);
                }
                else
                {
                    auto it = active.find(h);
                    if (it != active.end())
                        active.erase(it);
                }
                i++;
            }

            int currHeight = *active.rbegin();

            if (currHeight != prevHeight)
            {
                ans.push_back({x, currHeight});
                prevHeight = currHeight;
            }
        }

        return ans;
    }
};

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> buildings(n, vector<int>(3));
    for (int i = 0; i < n; i++)
        cin >> buildings[i][0] >> buildings[i][1] >> buildings[i][2];

    Solution sol;
    vector<vector<int>> ans = sol.getSkyline(buildings);

    for (auto &p : ans)
        cout << "[" << p[0] << "," << p[1] << "] ";

    cout << '\n';
    return 0;
}
