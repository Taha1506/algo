class point {
public:
    long long  x, y;
    point() {}
    point(long long x, long long y): x(x), y(y) {}
    void get(){
        cin>>x>>y;
    }
    point& operator+=(const point &t) {
        x += t.x;
        y += t.y;
        return *this;
    }
    point& operator-=(const point &t) {
        x -= t.x;
        y -= t.y;
        return *this;
    }
    point& operator*=(long long t) {
        x *= t;
        y *= t;
        return *this;
    }
    point& operator/=(long long t) {
        x /= t;
        y /= t;
        return *this;
    }
    point operator+(const point &t) const {
        return point(*this) += t;
    }
    point operator-(const point &t) const {
        return point(*this) -= t;
    }
    point operator*(long long t) const {
        return point(*this) *= t;
    }
    point operator/(long long t) const {
        return point(*this) /= t;
    }
    long long operator*(const point& p)const{
        return x*p.y-y*p.x;
    }
    long long triangle(point a,point b)const{
        a-=*this;
        b-=*this;
        return a*b;
    }
    bool operator<(const point& p){
        return make_pair(x,y)<make_pair(p.x,p.y);
    }
    bool operator >(const point& p){
        return make_pair(x,y)>make_pair(p.x,p.y);
    }
    bool operator==(const point &p){
        return make_pair(x,y)==make_pair(p.x,p.y);
    }
    static vector<point> hull(vector<point> p){
        int n=p.size();
        sort(p.begin(),p.end());
        vector<point> convex_hull;
        for(int rep=0;rep<2;rep++){
            const int s=convex_hull.size();
            for(int i=0;i<n;i++){
                while(convex_hull.size()>=s+2){
                    point a=convex_hull.end()[-1];
                    point b=convex_hull.end()[-2];
                    point c=p[i];
                    if(b.triangle(a,c)<=0){
                        break;
                    }
                    convex_hull.pop_back();
                }
                convex_hull.push_back(p[i]);
            }
            convex_hull.pop_back();
            reverse(p.begin(),p.end());
        }
        return convex_hull;
    }
    //Pick's theorem:Area=(Interiorpoints)+(boundrypoints/2)-1
};