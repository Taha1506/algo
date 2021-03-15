class segtree{
public:
    struct node{
        int sum,si;
        void apply(int x,int lx,int rx,int  v){
            sum=v;
            si=1;
        }
    };
    node merge(const node& a,const node& b)const{
        node res;
        res.si=a.si+b.si;
        if(a.si%2==0){
            res.sum=a.sum+b.sum;
        }
        else{
            res.sum=a.sum-b.sum;
        }
        return res;
    }
    int size;
    vector<node> tree;
    template<typename T>
    void build(int x,int lx,int rx,const vector<T>& a){
        if(lx==rx){
            tree[x].apply(x,lx,rx,a[lx]);
            return ;
        }
        int m=(lx+rx)/2;
        int y=(m-lx+1)*2+x;
        build(x+1,lx,m,a);
        build(y,m+1,rx,a);
        tree[x]=merge(tree[x+1],tree[y]);
    }
    template <typename... T>
    void modify(int x,int lx,int rx,int i,const T&... v){
        if(rx==lx){
            tree[x].apply(x,lx,rx,v...);
            return ;
        }
        int m=(lx+rx)/2;
        int y=(m-lx+1)*2+x;
        if(i<=m){
            modify(x+1,lx,m,i,v...);
        }
        else{
            modify(y,m+1,rx,i,v...);
        }
        tree[x]=merge(tree[x+1],tree[y]);
    }
    void modify(int i,int v){
        return modify(0,0,size-1,i,v);
    }
    node get(int x,int lx,int rx,int l,int r){
        if(l<=lx&&rx<=r){
            return tree[x];
        }
        int m=(lx+rx)/2;
        int y=(m-lx+1)*2+x;
        if(l>m){
            return get(y,m+1,rx,l,r);
        }
        if(r<=m){
            return get(x+1,lx,m,l,r);
        }
        return merge(get(x+1,lx,m,l,r),get(y,m+1,rx,l,r));
    }
    node get(int l,int r){
        return get(0,0,size-1,l,r);
    }
    explicit segtree(int n){
        size=n;
        tree.resize(2*n-1);
    }
    explicit segtree(const vector<int> &a){
        size=a.size();
        tree.resize(2*size-1);
        build(0,0,size-1,a);
    }
/*    int find_kth_first(int x,int lx,int rx,int k){
        if(lx==rx){
            return lx;
        }
        int m=(lx+rx)/2;
        int y=(m-lx+1)*2+x;
        if(tree[x+1].order>k){
            return find_kth_first(x+1,lx,m,k);
        }
        return find_kth_first(y,m+1,rx,k-tree[x+1].order);
    }
    int find_kth_first(int k){
        return find_kth_first(0,0,size-1,k);
    }*/
    int find_first_global(int x,int lx,int rx,const function<bool(const node& a)>& f){
        if(lx==rx){
            return lx;
        }
        int m=(lx+rx)/2;
        int y=(m-lx+1)*2+x;
        if(f(tree[x+1])){
            return find_first_global(x+1,lx,m,f);
        }
        return find_first_global(y,m+1,rx,f);
    }
    int find_first(int x,int lx,int rx,int l,int r,const function<bool(const node& a)>& f){
        if(lx==rx){
            if(!f(tree[x])){
                return -1;
            }
            return find_first_global(x,lx,rx,f);
        }
        int m=(lx+rx)/2;
        int y=(m-lx+1)*2+x;
        int ans=-1;
        if(l<=m){
            ans=find_first(x+1,lx,m,l,r,f);
        }
        if(r>m&&ans==-1){
            ans=find_first(y,m+1,rx,l,r,f);
        }
        return ans;
    }
    int find_first(int l,int r,const function<bool(const node&)> &f){
        return find_first(0,0,size-1,l,r,f);
    }
};