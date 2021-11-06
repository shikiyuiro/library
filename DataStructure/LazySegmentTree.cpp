template < typename Element = long >
class LazySegmentTree {
private:
    Element e;
    long vsiz;
    long tsiz;
    long queryL = -1, queryR = -1, queryV = -1;
    vector<Element> Table;
    vector<long> TableL, TableR;
    vector<Element> lazy;
    vector<bool> lazyFlag;
    function<Element(Element)> lazyDeal;
    function<Element(Element, Element)> operation;
    
    long opera_rec(long vis = 1){
        if(queryR <= TableL[vis] or TableR[vis] <= queryL){
            return e;
        }
        lazyEval(vis);
        if(queryL <= TableL[vis] and TableR[vis] <= queryR){
            return Table[vis];
        }
        return operation(opera_rec(vis * 2), opera_rec(vis * 2 + 1));
    }
    
    void update_rec(long vis = 1){
        lazyEval(vis);
        if(queryR <= TableL[vis] or TableR[vis] <= queryL){
            return;
        }
        if(queryL <= TableL[vis] and TableR[vis] <= queryR){
            lazy[vis] = queryV;
            lazyFlag[vis] = true;
            lazyEval(vis);
            return;
        }
        update_rec(vis * 2);
        update_rec(vis * 2 + 1);
        Table[vis] = operation(Table[vis * 2], Table[2 * vis + 1]);
    }
    
    void lazyEval(long vis) {
        if (not lazyFlag.at(vis)) return;
        Table[vis] = lazy[vis];
        if (vis < tsiz / 2) {
            lazy[2 * vis + 1] = lazy[2 * vis] = lazyDeal(lazy[vis]);
            lazyFlag[2 * vis + 1] = lazyFlag[2 * vis] = true;
        }
        lazyFlag[vis] = false;
    }
    
public:
    LazySegmentTree(vector<Element> v, Element e, function<Element(Element, Element)> operation, function<Element(Element)> lazyDeal = [](Element a){return a;}) : e(e), operation(operation), lazyDeal(lazyDeal){
        vsiz = v.size();
        tsiz = 1;
        while(tsiz < vsiz) tsiz *= 2;
        tsiz *= 2;
        Table.resize(tsiz, e);
        TableL.resize(tsiz, e);
        TableR.resize(tsiz, e);
        lazy.resize(tsiz, e);
        lazyFlag.resize(tsiz, false);
        for(long vi = 0; vi < tsiz / 2; vi++){
            if(vi < vsiz) Table[vi + tsiz / 2] = v[vi];
            TableL[vi + tsiz / 2] = vi;
            TableR[vi + tsiz / 2] = vi + 1;
        }
        for(long p = tsiz / 2 - 1; p >= 1; p--){
            Table[p] = operation(Table[p * 2], Table[p * 2 + 1]);
            TableL[p] = TableL[p * 2];
            TableR[p] = TableR[p * 2 + 1];
        }
    }
    
    Element query_opera(long l, long r/*半開区間*/){
        queryL = l; queryR = r;
        return opera_rec();
    }
    
    void query_update(long l, long r/*半開区間*/, Element value){
        queryL = l; queryR = r; queryV = value;
        return update_rec();
    }
};
/**
 * @brief セグメント木・遅延評価
 * @docs docs/DataStructure/LazySegmentTree.md
 */
