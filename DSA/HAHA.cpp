#include <bits/stdc++.h>
using namespace std;
int n;

void bt(int i,string s) {
	string tmp;
	if(i == n){
		cout << s << endl;
		return;
	}
	if(s[i - 1] == 'H' ){
		for(int j = 1; j <= n - i;j++){
			tmp += 'A';
			
	}
		for(int j = n - i; j >= 1;j--){
			bt(i + j,s + tmp);
			tmp.pop_back();
		}
	
	}else{
		if(i < n - 1){
			bt(i + 1,s + 'H');
		}
	}
	
}

int main() {
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		bt(1,"H");

	}
}
