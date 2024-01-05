#include<bits/stdc++.h>
using namespace std;

class solution {
    public:
      int f(vector<int>& p, int i, int t) {
        if(i==1) return(t*p[i-1]);
        int a1 = 0 + f(p,i-1,t);
        int a2 = INT_MIN;
        if(t>=i) a2 = p[i-1] + f(p,i,t-i);
        return max(a1,a2);
      }
      int maxEarning(vector<int>& p, int t) {
        int n = p.size();
        int a = f(p,n,t);
        vector<vector<int>> dp(n,vector<int>(t+1,0));
        for(int i = 0;i <= t;i++) dp[0][i] = i*p[0];
        for(int i = 1;i < n;i++) {
            for(int j = 0;j <= t;j++) {
                int m1 = dp[i-1][j];
                int m2 = INT_MIN;
                if(j>=(i+1)) m2 = p[i] + dp[i][j-i-1];
                dp[i][j] = max(m1,m2); 
            }
        }
        cout<<"DP solution: "<<dp[n-1][t]<<endl;
        return a;
      }
};

int main() {
    vector<int> p = {2,5,7,8,9};
    int target = 5;
    solution obj;
    int ans = obj.maxEarning(p,target);
    cout<<"Recursive solution: "<<ans<<endl;
return 0;
}