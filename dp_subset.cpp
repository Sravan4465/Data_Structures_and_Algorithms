#include<bits/stdc++.h>
using namespace std;

class solution {
    public:
        bool subsetSum(int n, int t, vector<int>& v) {
            if(t == 0) return 1;
            if(n == 0) return (v[0] == t);
            bool a1 = subsetSum(n-1,t,v);
            bool a2 = 0;
            if(v[n] <= t) a2 = subsetSum(n-1,t-v[n],v);
            return (a1||a2);
        }
};

int main() {
    vector <int> v = {1,2,3,4};
    int target = 9;
    int n = v.size();
    vector <vector<bool>> dp(n,vector<bool>(target+1, 0));
    solution obj;
    bool ans = obj.subsetSum(n-1, target, v);
    if(ans) cout<<"recurssion "<<"True"<<endl;
    else cout<<"recurssion "<<"False"<<endl;
    for(int i=0;i<n-1;i++) {
        dp[i][0] = true;
    }
    dp[0][v[0]] = true;
    for(int i = 1;i<n;i++) {
        for(int j = 1;j<=target;j++) {
           bool a1 = dp[i-1][j];
           bool a2 = false;
           if(v[i] <= j) a2 = dp[i-1][j-v[i]];
           dp[i][j] = a1|a2;
        }
    }
    cout<<"DP solution "<<dp[n-1][target]<<endl;
    return 0;
}