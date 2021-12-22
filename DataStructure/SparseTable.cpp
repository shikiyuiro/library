#define IGNORE
template < typename elm >
class SparseTable{
public:
    explicit SparseTable() = default;
    
    SparseTable(vector<elm>& v, elm e, function<elm(elm, elm)> operation) : operation(operation){
        long isiz = v.size();
        long jsiz = 0;
        while((1 << jsiz) <= isiz) jsiz++;
        table.resize(isiz, vector<elm>(jsiz, e));
        for(long i = 0; i < isiz; i++)table[i][0] = v[i];
        for(long j = 1; j < jsiz; j++){
            for(long i = 0; i + (1 << (j - 1)) < isiz; i++){
                table[i][j] = operation(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
            }
        }
        cf.resize(isiz + 1);
        for(long i = 2; i <= isiz; i++) cf[i] = cf[i >> 1] + 1;
    }
    
    elm query(long l, long r/*半開区間*/){
        assert(l < r);
        long b = cf[r - l];
        return operation(table[l][b], table[r - (1 << b)][b]);
    }
private:
    function<elm(elm, elm)> operation;
    vector<vector<elm>> table;
    vector<long> cf;
};
/**
 * @brief スパーステーブル
 * @docs docs/DataStructure/SparseTable.md
 */
