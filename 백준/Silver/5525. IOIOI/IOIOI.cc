#include <iostream>
#include <string>
using namespace std;
int n, l;
string s;


int main() {
    cin >> n >> l >> s;

    int len = 2 * n + 1;
    string str;
    for (int i = 0; i < len; i++) {
        if (i % 2 == 0) str += 'I';
        else str += 'O';
    }

    int cnt = 0;


    for (int i = 0; i <= l - len; i++) {
        if (s.substr(i, len) == str) cnt++;
    }
    cout << cnt;
}