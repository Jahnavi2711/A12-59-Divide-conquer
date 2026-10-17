
#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        auto cmp = [](ListNode *a, ListNode *b)
        {
            return a->val > b->val;
        };

        priority_queue<ListNode *,
                       vector<ListNode *>,
                       decltype(cmp)>
            pq(cmp);

        for (ListNode *node : lists)
            if (node)
                pq.push(node);

        ListNode dummy(0);
        ListNode *tail = &dummy;

        while (!pq.empty())
        {
            ListNode *node = pq.top();
            pq.pop();

            tail->next = node;
            tail = node;

            if (node->next)
                pq.push(node->next);
        }

        tail->next = nullptr;
        return dummy.next;
    }
};

int main()
{
    int k;
    cin >> k;

    vector<ListNode *> lists(k, nullptr);

    for (int i = 0; i < k; i++)
    {
        int n;
        cin >> n;

        ListNode dummy(0);
        ListNode *tail = &dummy;

        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;

            tail->next = new ListNode(x);
            tail = tail->next;
        }

        lists[i] = dummy.next;
    }

    Solution sol;
    ListNode *result = sol.mergeKLists(lists);

    while (result)
    {
        cout << result->val << " ";
        result = result->next;
    }

    cout << '\n';
    return 0;
}
