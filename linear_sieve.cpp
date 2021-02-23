class factor{
    int size;
    vector<int> primes;
    vector<int> lp;
public:
    explicit factor(int n): size(n){
        lp.assign(n+1,-1);
        for(int i=2;i<=n;i++){
            if(lp[i]==-1){
                primes.push_back(i);
                lp[i]=i;
            }
            for(int j=0;primes[j]<=lp[i]&&primes[j]*i<=n&&j<static_cast<int>(primes.size());j++){
                lp[primes[j]*i]=primes[j];
            }
        }
    }
    vector<pair<int,int> > get(int n){
        vector<pair<int,int> > ans;
        while(n>1){
            int p=lp[n];
            int cnt=0;
            while(n%p==0){
                cnt++;
                n/=p;
            }
            ans.emplace_back(p,cnt);
        }
        return ans;
    }
};

