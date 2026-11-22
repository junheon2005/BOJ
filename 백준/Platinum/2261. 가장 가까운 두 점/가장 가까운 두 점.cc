#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <climits>
using namespace std;
#define int long long

int n;
signed main() {
    cin >> n;
    vector<pair<int,int>> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].first >> p[i].second;
    }
    sort(p.begin(), p.end());

    auto dist = [](const pair<int,int>& a, const pair<int,int>& b) {
        int dx = a.first - b.first, dy = a.second - b.second;
        return dx * dx + dy * dy;
    };

    int best = dist(p[0], p[1]);
    set<pair<int,int>> cand;
    cand.insert({p[0].second, p[0].first});
    cand.insert({p[1].second, p[1].first});

    int left = 0;
    for (int i = 2; i < n; i++) {
        while (left < i) {
            long long dx = p[i].first - p[left].first;
            if (dx * dx <= best) break;
            cand.erase({p[left].second, p[left].first});
            left++;
        }
        int d = (int)sqrt((double)best) + 1;
        auto lo = cand.lower_bound({p[i].second - d, INT_MIN});
        auto hi = cand.upper_bound({p[i].second + d, INT_MAX});
        for (auto it = lo; it != hi; ++it) {
            best = min(best, dist(p[i], {it->second, it->first}));
        }
        cand.insert({p[i].second, p[i].first});
    }

    cout << best;
}