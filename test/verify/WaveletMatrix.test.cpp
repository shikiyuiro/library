#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"

#include "../../template/template.cpp"

#include "../../DataStructure/WaveletMatrix.cpp"

int main(){
  long N, Q; cin >> N >> Q;
    vector<long> A(N); for(long i = 0; i < N; i++) cin >> A[i];
    WaveletMatrix wm(A);
    while(Q--){
        long l, r, k; cin >> l >> r >> k;
        cout << wm.kth_min(l, r, k) << '\n';
    }
}
