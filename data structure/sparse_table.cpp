template<typename T,class F=function<T(const T&,const T&)> >
class sparse_table{
public:
    vector<vector<T> > pre_calculations;
    F func;
    sparse_table(const vector<T>& a,const F &f): func(f){
        int n=a.size();
        pre_calculations.resize(32-__builtin_clz(n-1));
        pre_calculations[0]=a;
        for(int i=1;i<pre_calculations.size();i++){
            pre_calculations[i].resize(n-(1<<i)+1);
            for(int j=0;j<pre_calculations[i].size();j++){
                pre_calculations[i][j]=func(pre_calculations[i-1][j],pre_calculations[i-1][j+(1<<(i-1))]);
            }
        }
    }
    int query(int l,int r){
        int log=31-__builtin_clz(r-l);
        return func(pre_calculations[log][l],pre_calculations[log][r-(1<<log)+1]);
    }
};
