template < typename Element = long >
class SparseTable{
private:
    function<Element(Element, Element)> opera;
public:
    vector<vector<Element>> table;
    vector<long> cf;
    
    SparseTable(vector<Element>& v, Element e, function<Element(Element, Element)> operation) {
        opera = operation;
        long isiz = v.size();
        long jsiz = 0;
        while((1 << jsiz) <= isiz) jsiz++;
        table.resize(isiz, vector<Element>(jsiz, e));
        for(long i = 0; i < isiz; i++)table[i][0] = v[i];
        for(long j = 1; j < jsiz; j++){
            for(long i = 0; i + (1 << (j - 1)) < isiz; i++){
                table[i][j] = opera(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
            }
        }
        cf.resize(isiz + 1);
        for(long i = 2; i <= isiz; i++) cf[i] = cf[i >> 1] + 1;
    }
    
    Element query(long l, long r/*半開区間*/){
        assert(l < r);
        long b = cf[r - l];
        return opera(table[l][b], table[r - (1 << b)][b]);
    }
};
/**
 * @brief スパーステーブル
 * @docs docs/DataStructure/SparseTable.md
 */
