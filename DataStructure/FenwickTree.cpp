class FenwickTree{
public:
    vector<long> table;
    long siz;
    FenwickTree(long siz) : table(siz + 1), siz(siz) {}
    long sum(long index){
        long res = 0;
        index++;//0-indexed to 1-indexed
        while(index > 0){
            res += table[index];
            index -= (index & -index);
        }
        return res;
    }
    void add(long index, long value){
        index++;//0-indexed to 1-indexed
        while(index < siz + 1){
            table[index] += value;
            index += (index & -index);
        }
    }
};
