#include<bits/stdc++.h>
using namespace std;


class solution {
    public:
    int CoinChange(vector<int> &c, int n, int t) {
            int res = 0;

            if(t == 0) return 1;
            if(n == 0) return 0;

            res = CoinChange(c, n-1, t);
            if(c[n-1] <= t) res += CoinChange(c, n, t-c[n-1]);
            return res;
    }
};
int main(){
    vector <int> coin = {1,2,3};
    int n = coin.size();
    int sum = 4;
    solution obj;
    int ans = obj.CoinChange(coin, n, sum);
    cout<<ans<<endl;
}