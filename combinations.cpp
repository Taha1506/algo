long long  mod=998244353;
long long fact[1000001];
long long inv_fact[1000001];
long long bin_pow(long long a,long long b){
    long long res=a;
    long long ans=1;
    while(b){
        if(b&1){
            ans=(ans*res)%mod;
        }
        res=(res*res)%mod;
        b>>=1;
    }
    return ans;
}
long long inv(long long a){
    return bin_pow(a,mod-2);
}
void gene(){
    fact[0]=1;
    for(int i=1;i<=1000000;i++){
        fact[i]=(fact[i-1]*i)%mod;
    }
    inv_fact[1000000]=inv(fact[1000000]);
    for(int i=999999;i>=0;i--){
        inv_fact[i]=(inv_fact[i+1]*(i+1))%mod;
    }
}
long long comb(long long a,long long b){
    if(b>a){
        return 0LL;
    }
    long long ans=fact[a];
    ans=(ans*inv_fact[b])%mod;
    ans=(ans*inv_fact[a-b])%mod;
    return ans;
}
long long permutation(long long a,long long b){
    if(b>a){
        return 0LL;
    }
    return (fact[a]*inv_fact[a-b])%mod;
}