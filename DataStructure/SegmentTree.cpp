template<class S, S (*op)(S, S), S (*e)()>
class SegmentTree{
public:
    explicit SegmentTree() = default;
    
    vector<S> table;
    long size = 1;
    SegmentTree(vector<S> &vec){
        while(size < vec.size()) size <<= 1;
        table.resize(size << 1, e());
        for(long i = 0; i < (long)vec.size(); i++) table[i + size] = vec[i];
        for(long i = size - 1; i >= 1; i--) table[i] = op(table[i<<1|0],table[i<<1|1]);
    }
    S fold(long l, long r){
        l += size; r += size;
        S Lres = e(), Rres = e();
        while(l < r){
            if(l & 1) Lres = op(Lres, table[l++]);
            if(r & 1) Rres = op(table[--r], Rres);
            l >>= 1; r >>= 1;
        }
        return op(Lres, Rres);
    }
    void set(long p, S x){
        p += size;
        table[p] = x;
        while(p >>= 1) table[p] = op(table[p<<1|0],table[p<<1|1]);
    }
    long partition_point(bool (*check)(S)){
        //i番目の要素がfold(0, i+1)である配列Vについて、std::distance(V.begin(), std::partition_point(V.begin(), V.end(), check))を返す
        if(check(table[1])) return table[0];
        long vis = 1;
        S acc = e();
        while(vis < table.size()){
            vis <<= 1;
            S tmp = op(acc, table[vis]);
            if(check[tmp]){
                acc = tmp;
                vis++;
            }
        }
        return vis - size;
    }
};
/**
 * @brief セグメント木
 * @docs docs/DataStructure/SegmentTree.md
 */
