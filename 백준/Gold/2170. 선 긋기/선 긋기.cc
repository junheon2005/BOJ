#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define int long long

int n;
vector<pair<int, int>> v;
signed main() {
    cin >> n;

    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end());

    int left = v[0].first;
    int right = v[0].second;

    int best = right - left;

    for (int i = 1; i < n; i++) {
        if (v[i].first <= right) {
            best = best + max((v[i].second - right), (long long)0);
            right = max(right, v[i].second);
        }
        else {
            left = v[i].first;
            right = v[i].second;
            best = best + right - left;
        }

    }

    cout << best;
}