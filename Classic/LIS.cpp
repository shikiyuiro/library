vector<int64_t> LIS(vector<int64_t>& v, bool non_strict = false, bool decrease = false){
    if(decrease) for(auto& e : v) e = (e == INT64_MIN ? INT64_MAX : -e-1);
    vector<int64_t> res;
    vector<int64_t> DP;
    vector<int64_t> index(v.size());
    vector<int64_t> trace(v.size());
    for(int64_t i = 0; i < v.size(); i++){
        auto itr = (non_strict ? upper_bound(DP.begin(), DP.end(), v[i]) : lower_bound(DP.begin(), DP.end(), v[i]));
        index[distance(DP.begin(), itr)] = i;
        trace[i] = (itr == DP.begin() ? -1 : index[distance(DP.begin(), itr) - 1]);
        if(itr == DP.end()) DP.emplace_back(v[i]); else *itr = v[i];
    }
    for(int64_t vis = index[DP.size() - 1]; vis >= 0; vis = trace[vis]) res.push_back(v[vis]);
    reverse(res.begin(), res.end());
    if(decrease) for(auto& e : v) e = (e == INT64_MIN ? INT64_MAX : -e-1);
    if(decrease) for(auto& e : res) e = (e == INT64_MIN ? INT64_MAX : -e-1);
    return res;
}
/**
 * @brief 最長増加部分列
 * @docs docs/template/template.md
 */
