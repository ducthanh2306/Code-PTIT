#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> res;

void generate(string s, int len, int target) {
    if (len == target) {
        res.push_back(s);
        return;
    }
    generate(s + '6', len + 1, target);
    generate(s + '8', len + 1, target);
}

int main() {
    int t; cin >> t;
    while (t--) {
        cin >> n;
        res.clear();

        for (int len = 1; len <= n; len++) {
            generate("", 0, len);
        }

        cout << res.size() << "\n";
        for (string &s : res) cout << s << " ";
        cout << "\n";
    }
}
