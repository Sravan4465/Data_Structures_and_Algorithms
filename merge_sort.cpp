#include<bits/stdc++.h>
using namespace std;

int merge(int a[], int s, int m, int e) {
    int n1 = m-s+1,n2 = e-m, invert = 0;
    int left[n1],right[n2];
    for(int i=0;i<n1;i++) left[i] = a[s + i];
    for(int i=0;i<n2;i++) right[i] = a[m + 1 + i];
    //  for(int i=0;i<n1;i++){
    //     cout<<left[i]<<" ";
    // }
    // cout<<endl;
    //  for(int i=0;i<n2;i++){
    //     cout<<right[i]<<" ";
    // }
    int i=0,j=0,k=s;
    while(i<n1 && j<n2) {
        if(left[i]<=right[j]){ a[k] = left[i], k++, i++;}
        else {a[k] = right[j], k++, j++, invert += m-i;}
    }
    while(i<n1) {a[k] = left[i], i++, k++;}
    while(j<n2) {a[k] = right[j], j++, k++;}
    return invert;
}
int  merge_sort(int a[], int s, int e) {
    int inversion = 0;
    if(s<e) {
        int m = (s+e)/2;
        inversion += merge_sort(a,s,m);
        inversion += merge_sort(a,m+1,e);

        inversion += merge(a,s,m,e);
    }
    return inversion;
}

int main(){
    int n;
    cin>>n;
    int v[n];
    for(int i=0;i<n;i++) {
        int p;
        cin>>p;
        v[i]=p;
    }
     for(int i=0;i<n;i++){
        cout<<v[i]<<", ";
    }
    cout<<endl;
    int ans = merge_sort(v, 0, n-1);

    for(int i=0;i<n;i++){
        cout<<v[i]<<", ";
    }
    cout<<ans<<endl;
    return 0;

}