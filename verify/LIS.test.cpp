#define PROBLEM "https://atcoder.jp/contests/chokudai_S001/tasks/chokudai_S001_h"

#include "../template/template.cpp"
#include "../Classic/LIS.cpp"

int main(){
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int64_t N; cin >> N;
    vector<int64_t> a(N); for(auto& e : a) cin >> e;
    cout << LIS(a).size() << '\n';
}
