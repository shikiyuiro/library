template < typename Element = long >
class CoordinateCompless{
private:
    long index = 0;
    vector<Element> uniq;
public:
    vector<long> After;
    map<Element, long> BtoA;
    map<long, Element> AtoB;
    
    CoordinateCompless(vector<Element>& Before){
        uniq = Before;
        sort(uniq.begin(), uniq.end());
        uniq.erase(unique(uniq.begin(), uniq.end()), uniq.end());
        for(auto &e : uniq){
            BtoA.insert(make_pair(e, index));
            AtoB.insert(make_pair(index, e));
            index++;
        }
        for(auto &e : Before) After.push_back(BtoA.at(e));
    }
};
/**
 * @brief 座標圧縮
 * @docs docs/Utility/CoordinateCompless.md
 */
