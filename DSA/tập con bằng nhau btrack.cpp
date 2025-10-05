#include <bits/stdc++.h>
using namespace std;

int n, ok;
vector<int> mtr;

void bt(int i, int sum1, int sum2) {
    if (i == n) {
        if (sum1 == sum2) ok = 1;
        return;
    }
    // nhánh 1: phần tử i thuộc nhóm 1
    bt(i + 1, sum1 + mtr[i], sum2);
    // nhánh 2: phần tử i thuộc nhóm 2
    bt(i + 1, sum1, sum2 + mtr[i]);
}
void bt(int i, long long diff) {
    if (ok) return;                  // cắt sớm khi đã tìm thấy
    if (i == n) { ok = (diff == 0); return; }
    bt(i + 1, diff + a[i]);          // cho a[i] vào nhóm 1
    bt(i + 1, diff - a[i]);          // cho a[i] vào nhóm 2
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        mtr.resize(n);
        for (int &x : mtr) cin >> x;
        ok = 0;
        bt(0, 0, 0);
        cout << (ok ? "YES" : "NO") << '\n';
    }
}
