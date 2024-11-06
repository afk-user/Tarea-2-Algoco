#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string word1,word2;
int maxop;

int costo_sub(char a,char b) {return a==b?0:2;}
int costo_ins(char b) {return 1;}
int costo_del(char a) {return 1;}
int costo_trans(char a,char b) {return a==b?0:1;}

int transform(string::iterator A, string::iterator B) {
    if (A == word1.end() || B == word2.end()) {
        int len1 = word1.length();
        int len2 = word2.length();
        int result = (max(len1,len2)-min(len1,len2))*costo_ins(*B);
        return result;
    }

    int del = transform(A+1,B)+costo_del(*A);
    int ins = transform(A,B+1)+costo_ins(*A);
    int sub = transform(A+1,B+1)+costo_sub(*A,*B);
    int tr = maxop;

    if (*(A+1) == *(B) && *A == *(B+1)) {
        tr = transform(A+2,B+2)+costo_trans(*A,*(A+1));
    }

    return min({ins,del,sub,tr});
}

int main() {
    int minEdit = 0;

    cout << "Ingrese palabras:" << endl;
    cin >> word1 >> word2;
    maxop = word1.length()+word2.length();
    
    minEdit = transform(word1.begin(),word2.begin());
    cout << "Secuencia mínima de edición: " << minEdit << endl;
    // assassin -> embarrass?
    return 0;
}