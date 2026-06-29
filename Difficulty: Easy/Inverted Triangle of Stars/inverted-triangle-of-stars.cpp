#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    // code here
    int c =0;
    int gap = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<gap;j++) cout<<" ";
        for(int j=0;j<2*n-c-1;j++) cout<<"*";
        cout<<endl;
        c+=2;
        gap++;
    }

    return 0;
}