#include<bits/stdc++.h>

using namespace std;

int power(int base,int n,long long mod){
    int result=1;
    while(n){
        if(n%2==1){
            result=(result*base)%mod;
            n--;
        }
        else{
            base=(base*base)%mod;
            n/=2;
        }
    }
    return result;
}

int main(){
    int n,m;
    cin>>n>>m;
    cout<<power(n,m,1e9)<<endl;
    return 0;
}
