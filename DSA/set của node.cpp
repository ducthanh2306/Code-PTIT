#include <bits/stdc++.h>
using namespace std;
struct item{
    vector<int> vec;
    int sum;
    bool operator <(const item &other) const{
        if(sum != other.sum) return sum < other.sum;
        return vec < other.vec;
    }
};
int n,k;
set<item> res;
vector<int> tmp;
vector<int> a;
void bt(int i, int sum,int limit){
    if(i == limit){
        if(!tmp.empty() && sum <= k) res.insert({tmp,sum});
        return;
    }
    tmp.push_back(a[i]);
    bt(i + 1, sum + a[i] , limit);
    tmp.pop_back();

    bt(i + 1, sum , limit);
}
int main() {
    cin >> n >> k;
    a.resize(n);
    for(int &x : a) cin >> x;
    bt(0,0,n);
    vector<item> cc(res.begin(),res.end());
    sort(cc.begin(),cc.end(),[](item one, item two){
        if(one.sum != two.sum) return one.sum < two.sum;
        return one.vec < two.vec;
    });
    for(auto x : cc){
        for(auto y : x.vec){
            cout << y << " ";
        }
        cout << endl << "Sum = " << x.sum << endl;
    }
}
