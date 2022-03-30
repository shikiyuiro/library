#pragma once

template<class S, S (*op)(S, S), S (*e)()>
class SparseTable{
public:
    explicit SparseTable() = default;
    SparseTable(vector<S>& v){
        isiz = v.size();
        jsiz = 32 - __builtin_clz(isiz);
        table.resize(isiz * jsiz, e());
        for(int32_t i = 0; i < isiz; i++) table[i] = v[i];
        for(int32_t j = 1; j < jsiz; j++){
            for(int32_t i = 0; i + (1 << (j - 1)) < isiz; i++){
                table[i + isiz * j] = op(table[i + isiz * (j - 1)], table[i + (1 << (j - 1)) + isiz * (j - 1)]);
            }
        }
    }
    S fold(int32_t L, int32_t R){
        if(L == R) return e();
        int32_t b = 32 - __builtin_clz(R - L) - 1;
        return op(table[L + isiz * b], table[R - (1 << b) + isiz * b]);
    }
private:
    vector<S> table;
    int32_t isiz;
    int32_t jsiz;
};
/**
 * @brief スパーステーブル
 * @docs docs/DataStructure/SparseTable.md
 */
