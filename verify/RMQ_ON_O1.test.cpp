#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include "../template/template.cpp"
#include "../DataStructure/SparseTable.cpp"
#include "../DataStructure/RMQ_ON_O1.cpp"

int32_t op(int32_t a, int32_t b){
    return min(a, b);
}

int32_t e(){
    return INT32_MAX;
}

int main(){
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int32_t N, Q; cin >> N >> Q;
    vector<int32_t> A(N); for(auto& e : A) cin >> e;
    RMQ_ON_O1<int32_t,op,e> sp(A);
    while(Q--){
        int32_t l, r; cin >> l >> r;
        cout << sp.fold(l, r) << '\n';
    }
}
