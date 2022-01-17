template<class S, S (*op)(S, S), S (*e)()>
class SparseTable{
public:
    vector<vector<S>> table;
    vector<long> cf;
    
    explicit SparseTable() = default;
    
    SparseTable(vector<S>& v){
        long isiz = v.size();
        long jsiz = 0;
        while((1 << jsiz) <= isiz) jsiz++;
        table.resize(isiz, vector<S>(jsiz, e()));
        for(long i = 0; i < isiz; i++) table[i][0] = v[i];
        for(long j = 1; j < jsiz; j++){
            for(long i = 0; i + (1 << (j - 1)) < isiz; i++){
                table[i][j] = op(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
            }
        }
        cf.resize(isiz + 1);
        for(long i = 2; i <= isiz; i++) cf[i] = cf[i >> 1] + 1;
    }
    
    S query(long l, long r/*半開区間*/){
        if(l == r) return e();
        long b = cf[r - l];
        return op(table[l][b], table[r - (1 << b)][b]);
    }
};
/**
 * @brief スパーステーブル
 * @docs docs/DataStructure/SparseTable.md
 */
