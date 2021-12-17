class WaveletMatrix{
public:
    long bitsize;
    vector<long> table_origin;
    vector<long> table_sorted;
    
    WaveletMatrix(vector<long> table) : table_origin(table){
        long table_max = *max_element(table.begin(), table.end());
        tablesize = table.size();
        bitsize = 0;
        while(table_max){
            bitsize++;
            table_max >>= 1;
        }
        assert(bitsize);
        matrix.resize(bitsize, vector<bool>(tablesize));
        zero_count.resize(bitsize, vector<long>(tablesize + 1, 0));
        for(long i = 0; i < bitsize; i++){
            for(long j = 0; j < tablesize; j++){
                matrix[i][j] = (table[j] >> (bitsize - i - 1)) & 1;
                if(not matrix[i][j]) zero_count[i][j + 1]++;
                zero_count[i][j + 1] += zero_count[i][j];
            }
            stable_sort(table.begin(), table.end(), [&](auto a, auto b){return ((a >> (bitsize - i - 1)) & 1) < ((b >> (bitsize - i - 1)) & 1);});
        }
        table_sorted = table;
    }
    
    long rank(long r, long x){
        //count x in [0, r)
        long L = 0; long R = r;//たぶんここLをlとして、引数にできる
        for(long level = 0; level < bitsize; level++){
            long same;//matrix[level][L, R)の中に、(x>>(bitsize-level-1)&1 と一致するのはいくつあるか?
            bool x_at_level = (x >> (bitsize - level - 1) & 1);
            if(x_at_level == 0){
                same = zero_count[level][R] - zero_count[level][L];
                L = zero_count[level][L]; R = L + same;
            }else{
                same = (R - zero_count[level][R]) - (L - zero_count[level][L]);
                L = zero_count[level][tablesize] + (L - zero_count[level][L]); R = L + same;
            }
        }
        return R - L;
    }
    
    long kth_min(long l, long r, long k/*0-indexed*/){
        long L = l; long R = r;
        for(long level = 0; level < bitsize; level++){
            auto [Lcount0, Lcount1] = counts(0, L, level);
            auto [count0, count1] = counts(L, R, level);
            if(k < count0){
                L = Lcount0;
                R = L + count0;
            }else{
                L = zero_count[level][tablesize] + Lcount1;
                R = L + count1;
                k -= count0;
            }
        }
        return table_sorted[L];
    }
    
    long range_freq(long l, long r, long lower, long upper){
        //count i s.t. l <= i < r and lower <= table[i] < upper
        return range_freq(l, r, upper) - range_freq(l, r, lower);
    }
    
private:
    vector<vector<bool>> matrix;
    vector<vector<long>> zero_count;//count 0 in matrix[i][0, r)
    long tablesize;
    
    pair<long,long> counts(long l, long r, long level){
        //{0の個数, 1の個数} in matrix[level][l, r)を返す
        return {zero_count[level][r] - zero_count[level][l], (r - zero_count[level][r]) - (l - zero_count[level][l])};
    }
    
    long range_freq(long l, long r, long upper){
        //count i s.t. l <= i < r and table[i] < upper
        if(upper >= (1 << bitsize)) return r - l;
        if(upper < 0) return 0;
        long res = 0;
        long L = l; long R = r;
        for(long level = 0; level < bitsize; level++){
            auto [Lcount0, Lcount1] = counts(0, L, level);
            auto [count0, count1] = counts(L, R, level);
            if(((upper >> (bitsize - level - 1)) & 1) == 0){
                //matrix[level][i] = 1　なら　必ず upper < table[i]
                L = Lcount0;
                R = L + count0;
            }else{
                //matrix[level][i] = 0　なら　必ず table[i] < upper
                res += count0;
                L = zero_count[level][tablesize] + Lcount1;
                R = L + count1;
            }
        }
        return res;
    }
};
/**
 * @brief ウェーブレット行列
 * @docs docs/DataStructure/WaveletMatrix.md
 */
