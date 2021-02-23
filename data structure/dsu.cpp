class dsu{
    int n;
    vector<int> parent;
    vector<int> size;
public:
    //Take care of the zero indexing
    dsu(int _n):n(_n){
        parent.resize(_n);
        iota(parent.begin(),parent.end(),0);
        size.resize(_n);
    }
    int get(int v){
        return parent[v]=(v==parent[v]?v:get(parent[v]));
    }
    bool unite(int a,int b){
        a=get(a);
        b=get(b);
        if(a==b){
            return false;
        }
        if(size[a]>size[b]){
            swap(a,b);
        }
        parent[a]=b;
        return true;
    }
};