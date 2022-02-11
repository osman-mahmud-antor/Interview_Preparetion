#include<bits/stdc++.h>

using namespace std;

int power(int a,int b) {
    if(b==0){
        return 1;
    }
    int res=power(a,b/2);
    if(b%2){
        return res*res*a;
    }
    else{
        return res*res;
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    cout<<power(n,m)<<endl;
    return 0;
}
