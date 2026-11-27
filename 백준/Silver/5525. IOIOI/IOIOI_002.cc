#include <iostream>
#include <string>
using namespace std;
int n, l;
string s;


int main() {
    cin >> n >> l >> s;

    int cnt = 0;
    int k = 0;


    for (int i = 1; i < l - 1; i++) {
        if (s[i - 1] == 'I' && s[i] == 'O' && s[i + 1] == 'I') {
            k++;
            if (k == n) {
                cnt++;
                k--;
            }
            i++;
        }
        else k = 0;
    }

    cout << cnt;
}