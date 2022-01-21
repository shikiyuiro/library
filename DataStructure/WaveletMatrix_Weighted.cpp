class WeightedWaveletMatrix{
public:
    WeightedWaveletMatrix(vector<pair<long,long>> table){
        long MOV = max_element(table.begin(), table.end())->first;
        while(MOV >>= 1) DIGIT++;
        vector<bool> VBL(table.size());
        vector<long> weight(table.size());
        for(long k = 1; k <= DIGIT; k++){
            for(long i = 0; i < (long)table.size(); i++) VBL[i] = (table[i].first >> (DIGIT - k)) & 1;
            MAT.push_back(cmpBV(VBL));
            for(long i = 0; i < (long)table.size(); i++) weight[i] = table[i].second;
            PSUM.push_back(PrefixSum(weight));
            stable_sort(table.begin(), table.end(), [&](auto a, auto b){ return (a.first >> (DIGIT - k) & 1) < (b.first >> (DIGIT - k) & 1);});
        }
        table_sorted = table;
        for(long i = 0; i < (long)table.size(); i++) weight[i] = table[i].second;
        PSUM.push_back(PrefixSum(weight));
    }
    
    long range_freq(long L, long R, long lower, long upper){
        return range_freq(L, R, upper) - range_freq(L, R, lower);
    }
    
    long weighted_range_freq(long L, long R, long lower, long upper){
        return weighted_range_freq(L, R, upper) - weighted_range_freq(L, R, lower);
    }
private:
    
    struct cmpBV{
        long size;
        vector<long> prefix;
        cmpBV(vector<bool> &v) : size(v.size()), prefix(v.size()+1,0){
            for(long i = 1; i <= (long)v.size(); i++) prefix[i] = prefix[i-1] + v[i-1];
        }
        long rank(long L, long R) { return prefix[R] - prefix[L];}
    };
    struct PrefixSum{
        vector<long> prefix;
        PrefixSum(vector<long> &v) : prefix(v.size()+1,0){
            for(long i = 1; i <= (long)v.size(); i++) prefix[i] = prefix[i-1] + v[i-1];
        }
        long get(long L, long R) { return prefix[R] - prefix[L];}
    };
    
    long DIGIT = 1;
    vector<cmpBV> MAT;
    vector<PrefixSum> PSUM;
    vector<pair<long,long>> table_sorted;
    
    pair<pair<long,long>,pair<long,long>> decomp(pair<long,long> p, long k){
        //MAT[k]における半開区間[L, R)をMAT[k+1]の二つの半開区間に分解する。ウェーブレット行列の本質部分
        auto [L, R] = p;
        long allfreq_0 = MAT[k].size - MAT[k].rank(0, MAT[k].size);
        long rank_origin_1 = MAT[k].rank(0, L);
        long rank_origin_0 = L - rank_origin_1;
        long rank_1 = MAT[k].rank(0, R);
        long rank_0 = R - rank_1;
        return {{rank_origin_0, rank_0}, {allfreq_0 + rank_origin_1, allfreq_0 + rank_1}};
    }
    
    long range_freq(long L, long R, long upper){
        if(upper >= (1L << DIGIT)) return R - L;
        if(upper < 0) return 0;
        long res = 0;
        long visL = L; long visR = R;
        for(long k = 1; k <= DIGIT; k++){
            long bit_o_upper = upper >> (DIGIT - k) & 1;
            auto [p0, p1] = decomp({visL, visR}, k-1);
            if(bit_o_upper == 0){
                visL = p0.first;
                visR = p0.second;
            }else{
                res += p0.second - p0.first;
                visL = p1.first;
                visR = p1.second;
            }
        }
        return res;
    }
    
    long weighted_range_freq(long L, long R, long upper){
        if(upper >= (1L << DIGIT)) return PSUM[0].get(L, R);
        if(upper < 0) return 0;
        long res = 0;
        long visL = L; long visR = R;
        for(long k = 1; k <= DIGIT; k++){
            long bit_o_upper = upper >> (DIGIT - k) & 1;
            auto [p0, p1] = decomp({visL, visR}, k-1);
            if(bit_o_upper == 0){
                visL = p0.first;
                visR = p0.second;
            }else{
                res += PSUM[k].get(p0.first, p0.second);
                visL = p1.first;
                visR = p1.second;
            }
        }
        return res;
    }
};
/**
 * @brief 重み付きウェーブレット行列
 * @docs docs/DataStructure/WaveletMatrix_Weighted.md
 */
