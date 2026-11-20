#include <iostream>
#include <vector>
using namespace std;
#define int long long

vector<int> arr;
vector<int> best;
int n, v = 0, temp = 0;


signed main() {
    cin >> n;
    arr.resize(n);
    best.resize(n);


    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] > temp) {
            temp = arr[i];
        }
        best[i] = temp;

        v = v + best[i];
    }
    if (v % 3 == 0) cout << "Delicious!";
    else cout << "Oh My God!";

}


