#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include "../../template/template.cpp"

#include "../../DataStructure/FenwickTree.cpp"

int main(){
    long N, Q; cin >> N >> Q;
    FenwickTree bit(N);
    vector<long> A(N);
    
    for(long i = 0; i < N; i++){
        cin >> A[i];
        bit.add(i, A[i]);
    }
    
    while(Q--){
        long q, a, b; cin >> q >> a >> b;
        if(q == 0){
            bit.add(a, b);
        }else{
            cout << bit.sum(b - 1) - bit.sum(a - 1) << endl;
        }
    }
}
