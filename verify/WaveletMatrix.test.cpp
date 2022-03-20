#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"

#include "../template/template.cpp"
#include "../DataStructure/WaveletMatrix.cpp"

class Compless{
public:
    explicit Compless() = default;
    Compless(vector<int64_t> &v){
        st = v;
        sort(st.begin(), st.end());
        st.erase(unique(st.begin(), st.end()), st.end());
        for(auto& e : v) e = comp(e);
    }
    int64_t comp(int64_t val){
        return distance(st.begin(), lower_bound(st.begin(), st.end(), val));
    }
    int64_t fix(int64_t val){
        return st[val];
    }
private:
    vector<int64_t> st;
};

int main(){
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int64_t N, Q; cin >> N >> Q;
    vector<int64_t> A(N); for(int64_t i = 0; i < N; i++) cin >> A[i];
    Compless cmp(A);
    WaveletMatrix wm(A);
    while(Q--){
        int64_t l, r, k; cin >> l >> r >> k;
        cout << cmp.fix(wm.range_Kth_min(l, r, k)) << '\n';
    }
}
