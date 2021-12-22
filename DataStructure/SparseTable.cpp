template < typename elm >
class SparseTable{
public:
    explicit SparseTable() = default;
    
    SparseTable(vector<elm>& v, elm e, function<elm(elm, elm)> op) : op(op){
        long isiz = v.size();
        long jsiz = 0;
        while((1 << jsiz) <= isiz) jsiz++;
        table.resize(isiz, vector<elm>(jsiz, e));
        for(long i = 0; i < isiz; i++)table[i][0] = v[i];
        for(long j = 1; j < jsiz; j++){
            for(long i = 0; i + (1 << (j - 1)) < isiz; i++){
                table[i][j] = op(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
            }
        }
        cf.resize(isiz + 1);
        for(long i = 2; i <= isiz; i++) cf[i] = cf[i >> 1] + 1;
    }
    
    elm query(long L, long R/*[L, R)*/){
        assert(L < R);
        long b = cf[R - L];
        return op(table[L][b], table[R - (1 << b)][b]);
    }
private:
    function<elm(elm, elm)> op;
    vector<vector<elm>> table;
    vector<long> cf;
};
/**
 * @brief スパーステーブル
 * @docs docs/DataStructure/SparseTable.md
 */
