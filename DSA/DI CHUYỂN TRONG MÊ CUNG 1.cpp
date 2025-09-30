#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> mecung;
stack<char> st;
int n;
int found = 0;
void dfs(int x,int y){
    if(x > n || y > n) return;
    if(mecung[x][y] == 0) return;
    if(x == n && y == n){
        found = 1;
        string s;
        stack<char> tmp = st;
        while(!tmp.empty()){
            s += tmp.top();
            tmp.pop();
        }
        reverse(s.begin(),s.end());
        cout << s << " ";
        return;
    }
    if(x + 1 <= n && mecung[x + 1][y] == 1 ){
        st.push('D');
        dfs(x + 1,y);
        st.pop();
    }
    if(y + 1<= n && mecung[x][y + 1] == 1 ){
        st.push('R');
        dfs(x ,y+1);
        st.pop();
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        mecung.assign(n + 1,vector<int>(n + 1));
        for(int i =1 ; i <= n;i++){
            for(int j = 1; j <= n;j++){
                cin >> mecung[i][j];
            }
        }
        dfs(1,1);
        if(!found) cout << -1;
        found = 0;
        while(!st.empty())st.pop();
        cout << endl;
    }
}
