#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include "../../template/template.cpp"

#include "../../DataStructure/SparseTable.cpp"

int main(){
    long N, Q; cin >> N >> Q;
    vector<long> A(N);
    for(long i = 0; i < N; i++) cin >> A[i];
    
    SparseTable<> STA(A, INT_MAX, [](long a, long b){return min(a, b);});
    while(Q--){
        long u, v; cin >> u >> v;
        cout << STA.query(u, v) << endl;
    }
}
