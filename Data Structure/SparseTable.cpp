#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include<bits/stdc++.h>
using namespace std;

class SparseTable{
private:
    function<long(long, long)> opera;
public:
    vector<vector<long>> table;
    vector<long> cf;
    
    SparseTable(vector<long>& v, long e, function<long(long, long)> operation) {
        opera = operation;
        long isiz = v.size();
        long jsiz = 0;
        while((1 << jsiz) <= isiz) jsiz++;
        table.resize(isiz, vector<long>(jsiz, e));
        for(long i = 0; i < isiz; i++)table[i][0] = v[i];
        for(long j = 1; j < jsiz; j++){
            for(long i = 0; i + (1 << (j - 1)) < isiz; i++){
                table[i][j] = opera(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
            }
        }
        cf.resize(isiz + 1);
        for(long i = 2; i <= isiz; i++) cf[i] = cf[i >> 1] + 1;
    }
    
    long query(long l, long r/*半開区間*/){
        assert(l < r);
        long b = cf[r - l];
        return opera(table[l][b], table[r - (1 << b)][b]);
    }
};

int main(){
    long N, Q; cin >> N >> Q;
    vector<long> A(N);
    for(long i = 0; i < N; i++) cin >> A[i];
    
    SparseTable STA(A, INT_MAX, [](long a, long b){return min(a, b);});
    while(Q--){
        long v, u; cin >> u >> v;
        cout << STA.query(u, v) << endl;
    }
}
