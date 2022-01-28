class PPUF{
public:
    PPUF(long size){
        Parent.resize(size); iota(Parent.begin(), Parent.end(), 0);
        Size.resize(size, 1);
        history.resize(size); for(auto &s : history) s.push_back({LONG_MIN, 1});
        United.resize(size, LONG_MAX);
    }
    long find(long u, long t){ return (United[u] > t) ? u: find(Parent[u], t); }//時刻t直後のuの根を求める。
    bool unite(long u, long v, long t){
        //tはuniteクエリごとに広義単調増加でなければならないが、連続する値である必要はない。
        long fu = find(u), fv = find(v);
        if(fu == fv) return false;
        if(Size[fu] < Size[fv]){ swap(u, v); swap(fu, fv);}
        Parent[fv] = fu;
        Size[fu] += Size[fv];
        history[fu].push_back({t, Size[fu]});
        United[fv] = t;
        return true;
    }
    bool same(long u, long v, long t){//時刻t直後にuとvが連結であるか判定する。
        return find(u, t) == find(v, t);
    }
    long size(long u, long t){//時刻t直後のuの連結成分の個数を取得する。
        long fu = find(u, t);
        return prev(upper_bound(history[fu].begin(), history[fu].end(), pair<long,long>({t, LONG_MAX})))->second;
    }
    explicit PPUF() = default;
private:
    vector<long> Parent;
    vector<long> Size;
    vector<vector<pair<long,long>>> history;//unite直後の連結成分のサイズを保存する
    vector<long> United;//何回目の結合で根ではなくなるか　ー＞ その値以下の時刻であればその頂点は根、そうでなかったらParentをたどればよい。
    long find(long u){ return (Parent[u] == u) ? u: find(Parent[u]); }
};
/**
 * @brief 部分永続UnionFind
 * @docs docs/DataStructure/UnionFind_PartiallyPersistent.md
 */
