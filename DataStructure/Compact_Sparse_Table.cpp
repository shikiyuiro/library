#include "../DataStructure/SparseTable.cpp"

template<class S, S (*op)(S, S), S (*e)()>
class Compact_Sparse_Table{
public:
    long W = 8;
    vector<S> A;
    vector<S> Lfold, Rfold;
    SparseTable<S, op, e> st;
    
    explicit Compact_Sparse_Table() = default;
    
    Compact_Sparse_Table(vector<S> &A) : A(A){
        A.resize(A.size() + W - ((A.size() - 1) % W + 1), e());
        vector<long> BLOCK(A.size() / W, e());
        Lfold.resize(A.size(), e());
        Rfold.resize(A.size(), e());
        for(long b = 0; b < BLOCK.size(); b++){
            BLOCK[b] = A[W * b];
            Lfold[W * b] = A[W * b];
            Rfold[W * (b + 1) - 1] = A[W * (b + 1) - 1];
            for(long i = 1; i < W; i++){
                BLOCK[b] = op(BLOCK[b], A[W * b + i]);
                Lfold[W * b + i] = op(Lfold[W * b + i - 1], A[W * b + i]);
                Rfold[W * (b + 1) - 1 - i] = op(Rfold[W * (b + 1) - i], A[W * (b + 1) - 1 - i]);
            }
        }
        st = SparseTable<S, op, e> (BLOCK);
    }
    S query(long L, long R/*半開区間*/){
        R--;
        long lb = (L - (L % W) + W) / W;
        long rb = (R - (R % W)) / W;
        if(rb > lb){
            return op(st.query(lb, rb), op(Lfold[R],Rfold[L]));
        }
        if(rb == lb){
            return op(Lfold[R],Rfold[L]);
        }
        S res = e();
        for(long i = L; i <= R; i++) res = op(res, A[i]);
        return res;
    }
};
/**
 * @brief スパーステーブル(<O(N),O(1)>)
 * @docs docs/DataStructure/SparseTable_compact.md
 */
