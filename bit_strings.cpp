#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int binexp(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b&1) {
            res = res * a % mod;
        }
        b >>= 1;
        a = a * a % mod;
    }
    return res;
}

int main() {
 long n;
 cin>>n;
 cout<<binexp(2,n)<<endl;


return 0;
}