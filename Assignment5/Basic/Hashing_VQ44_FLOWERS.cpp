
#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> a;


vector<int> get_ans(const vector<int>& A,int K){
	map<int,int> Hash;
	vector<int> res;
	for(int i : A){
		Hash[i]++;
	}
	while(res.size() < K){
		for(auto& x : Hash){
			if(res.size() < K && Hash[x.first] > 0){
				res.push_back(x.first);
				Hash[x.first]--;
			}
			else if (res.size() >= K) break;
		}
	}
	return res;
}

int main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
    if (fopen("TASK.INP", "r"))
    {
        freopen("TASK.INP", "r", stdin);
        freopen("TASK.OUT", "w", stdout);
    }
	cin >> n >> k;
	
	a.resize(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	
	vector<int> ans = get_ans(a,k);
	
	for (const int& x: ans) cout << x << ' ';
	return 0;
}
