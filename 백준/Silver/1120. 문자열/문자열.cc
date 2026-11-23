#include <iostream>
#include <string>
#include <climits>
using namespace std;


int main() {
    string a, b;
    cin >> a >> b;

    int dif = b.size() - a.size();
    int res = INT_MAX;
    for (int i = 0; i <= dif; i++) {
        int count = 0;
        for (int j = 0; j < a.size(); j++) {
            if (a[j] != b[i + j]) count++;
        }
        res = min(res, count);
        //cout << res << "\n";

    }
    cout << res;
}