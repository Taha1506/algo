template<typename T,class F=function<T(const T&,const T&)> >
class Stack{
    F func;
    stack<pair<T,T> > st;
public:
    Stack(F f):func(f){};
    bool empty(){
        return st.empty();
    }
    int size(){
        return st.size();
    }
    void push(T nw){
        if(empty()){
            st.emplace(nw,nw);
            return;
        }
        T prev=st.top().second;
        prev=func(prev,nw);
        st.emplace(nw,prev);
    }
    T pop(){
        assert(!empty());
        T x=st.top().first;
        st.pop();
        return x;
    }
    T getval(){
        return st.top().second;
    }
};
template<typename T,class F=function<T(const T&,const T&)> >
class Queue{
    F func;
    Stack<T> right;
    Stack<T> left;
public:
    explicit Queue(F f): func(f),left(f),right(f){};
    void push(T nw){
        right.push(nw);
    }
    void pop(){
        if(left.empty()){
            while(!right.empty()){
                left.push(right.pop());
            }
        }
        assert(!left.empty());
        left.pop();
    }
    T getval(){
        if(right.empty()){
            return left.getval();
        }
        if(left.empty()){
            return right.getval();
        }
        return func(right.getval(),left.getval());
    }
};