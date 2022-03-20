#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include "../template/template.cpp"
#include "../DataStructure/SparseTable.cpp"

int64_t op(int64_t a, int64_t b){
    return min(a, b);
}

int64_t e(){
    return INT64_MAX;
}

int main(){
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int64_t N, Q; cin >> N >> Q;
    vector<int64_t> A(N);
    for(int64_t i = 0; i < N; i++) cin >> A[i];
    SparseTable<int64_t, op, e> sp(A);
    while(Q--){
        int64_t l, r; cin >> l >> r;
        cout << sp.fold(l, r) << '\n';
    }
}

