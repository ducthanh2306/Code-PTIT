#include <bits/stdc++.h>
using namespace std;

vector<char> mtr;
vector<bool> used;
string res;

bool isConsonant(char c){
    return (c=='B'||c=='C'||c=='D'||c=='F'||c=='G'||c=='H');
}
bool isVowel(char c){
    return (c=='A'||c=='E');
}

// chỉ kiểm tra phần đuôi khi thêm ký tự mới
bool validAfterPush(){
    int n = res.size();
    if(n < 3) return true;
    char a = res[n-3], b = res[n-2], c = res[n-1];
    if(isConsonant(a) && isConsonant(c) && isVowel(b)) return false;
    return true;
}

void bt(){
    if(res.size() == mtr.size()){
        cout << res << '\n';
        return;
    }
    for(int i = 0; i < mtr.size(); i++){
        if(!used[i]){
            res.push_back(mtr[i]);
            if(validAfterPush()){ // ✅ chỉ kiểm tra 3 ký tự cuối
                used[i] = true;
                bt();
                used[i] = false;
            }
            res.pop_back();
        }
    }
}

int main(){
    char target;
    cin >> target;
    for(char c = 'A'; c <= target; c++) mtr.push_back(c);
    used.assign(mtr.size(), false);
    bt();
}
