#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<ll> vll;

struct le {
    int v, l;
    bool operator > (const le& b) const { return v > b.v; }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ans = nullptr;
        ListNode* p = ans;
        priority_queue<le, vector<le>, greater<le>> q;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != nullptr) {
                q.push({lists[i]->val,i});
                lists[i] = lists[i]->next;
            }
        }

        while (!q.empty()) {
            ListNode* nextelem = new ListNode(q.top().v);
            if (ans == nullptr) {
                ans = nextelem;
                p = ans;
            }
            else {
                p->next = nextelem;
                p = p->next;
            }

            int l = q.top().l;
            q.pop();
            if (lists[l] != nullptr) {
                q.push({lists[l]->val, l});
                lists[l] = lists[l]->next;
            }
        }
        return ans;
    }
};