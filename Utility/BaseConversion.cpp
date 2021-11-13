class BaseConversion {
public:
    string symbol = "0123456789ABCDEF";
    long to_num[128];
    
    BaseConversion(){
        long basemax = symbol.length();
        for(long i = 0; i < basemax; i++) to_num[(long)symbol[i]] = i;
    }
    
    string from10(long num, long base) {
        if(num == 0) return "0";
        string res = "";
        while(num > 0){
            res = symbol[num % base] + res;
            num /= base;
        }
        return res;
    }
    
    long to10(string num, long base) {
        long res = 0;
        long numsize = num.length();
        for(long i = 0; i < numsize; ++i) res = res * base + to_num[(long)num[i]];
        return res;
    }
};
/**
 * @brief 進数変換
 * @docs docs/Utility/BaseConversion.md
 */
