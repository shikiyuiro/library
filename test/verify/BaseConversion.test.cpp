#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0306"

#include "../../template/template.cpp"

#include "../../NumberTheory/BaseConversion.cpp"

int main(){
    BaseConversion bc;
    long w; cin >> w;
    long t = 1;
    while(w >= t){
        t *= 3;
        t += 1;
    }
    string S = bc.from10(w + t, 3);
    long siz = S.size();
    for(long i = 0; i < siz; i++){
        if(S[i] == '2') cout << "+";
        if(S[i] == '1') cout << "0";
        if(S[i] == '0') cout << "-";
    }
}
