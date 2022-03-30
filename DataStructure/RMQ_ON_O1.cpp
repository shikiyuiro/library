#include "../DataStructure/SparseTable.cpp"

template<class S, S (*op)(S, S), S (*e)()>
class RMQ_ON_O1{
    int32_t Bsiz = 5;
    int32_t Bcmpl = 31;
public:
    explicit RMQ_ON_O1() = default;
    RMQ_ON_O1(vector<S> &_v) : v(_v){
        v.resize((v.size() | Bcmpl) + 1, e());
        b.resize(v.size());
        for(int32_t i = 0; i < (int32_t)v.size(); i++){
            stack<int32_t> st;
            while(true){
                while(not st.empty()){
                    if(op(v[i], v[st.top()]) != v[i]) break;
                    st.pop();
                }
                b[i] = st.empty() ? 0 : b[st.top()] | (1 << (st.top() & Bcmpl));
                if((i & Bcmpl) == Bcmpl) break;
                st.push(i++);
            }
            v_mini.push_back(fold_mini(i-Bcmpl,i+1));
        }
        sp = SparseTable<S,op,e>(v_mini);
    }
    S fold(int32_t L, int32_t R){
        int32_t Lu = (L | Bcmpl) + 1;
        int32_t Rd = (R & ~Bcmpl);
        if(Lu > Rd) return fold_mini(L, R);
        S res = e();
        res = op(res, fold_mini(L, Lu));
        res = op(res, sp.fold(Lu>>Bsiz, Rd>>Bsiz));
        res = op(res, fold_mini(Rd, R));
        return res;
    }
private:
    vector<S> v;
    vector<S> v_mini;
    vector<int32_t> b;
    SparseTable<S,op,e> sp;
    S fold_mini(int32_t L, int32_t R){
        if(L == R) return e();
        int32_t masked = (b[R-1] >> (L & Bcmpl)) << (L & Bcmpl);
        int32_t lsb = __builtin_ctz(masked);
        if(masked == 0) return v[R-1];
        else return v[lsb + (L & ~Bcmpl)];
    }
};
/**
 * @brief 区間最小値( 構築$\mathrm{O}(N)$・クエリ$\mathrm{O}(1)$ )
 * @docs docs/DataStructure/RMQ_ON_O1.md
 */
