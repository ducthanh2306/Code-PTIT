#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> ori, vec;

void bt(int i){
    // In trước nếu đủ k phần tử
    if ((int)vec.size() == k){
        for (int x : vec) cout << x << ' ';
        cout << '\n';
        return;
    }
    // Hết phần tử thì dừng
    if (i == n) return;

    // Nhánh CHỌN ori[i] (chỉ chọn nếu giữ được không giảm)
    if (vec.empty() || ori[i] >= vec.back()){
        vec.push_back(ori[i]);
        bt(i + 1);
        vec.pop_back();
    }

    // Nhánh BỎ ori[i]
    bt(i + 1);
}
void bt2(int start){
    if(vec.size() == k) {
        for(int x : vec) cout << x << " ";
        cout << endl;
        return;
    }
    for(int idx = start; idx < n;idx++){
        if(vec.empty() || ori[idx] >= vec.back() ){
            vec.push_back(ori[idx]);
            bt(idx + 1);
            vec.pop_back();
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    ori.resize(n);
    for (int i = 0; i < n; ++i) cin >> ori[i];
    bt2(0);
}
