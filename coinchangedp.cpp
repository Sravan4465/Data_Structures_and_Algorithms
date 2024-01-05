#include<bits/stdc++.h>
using namespace std;

class solution {
    public:
        int f(vector<int>& c, int i, int t) {
            if(i==0) return(t % c[0] == 0);
            int count1 = f(c,i-1,t);
            int count2 = 0;
            if(t >= c[i]) count2 = f(c,i,t-c[i]);
            return (count1+count2);
            }
        
        int totalWays(vector<int>& c, int t) {
            int n = c.size();
            int a = f(c,n-1,t);
            vector<vector<int>> dp(n,vector<int>(t+1,0));
            for(int i=0;i<=t;i++) dp[0][i] = (i%c[0]==0);
            for(int i = 1;i<n;i++) {
                for(int j = 0;j<=t;j++) {
                    int count1  = dp[i-1][j];
                    int count2 = 0;
                    if(j >= c[i]) count2 = dp[i][j-c[i]];
                    dp[i][j] = count1 + count2;
                }
            } 
            cout<<"DP solution: "<<dp[n-1][t]<<endl;
            return a;
        }
};

int main() {
    vector<int> c = {1,2,3};
    int target = 4;
    solution obj;
    int ans = obj.totalWays(c,target);
    cout<<"recursion solution "<<ans<<endl;
    return 0;
}