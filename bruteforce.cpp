#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int costo_sub(char a,char b) {return a==b?0:2;}
int costo_ins(char b) {return 1;}
int costo_del(char a) {return 1;}
int costo_trans(char a,char b) {return a==b?0:1;}

int transform(string A, string B, int n, int m) {
    if (n==0) return m;
    if (m==0) return n;
    if (A[n-1]==B[m-1]) return transform(A.substr(0,n-1),B.substr(0,m-1),n-1,m-1);
    
    int ins = costo_ins(B[m-1])+transform(A+B[m-1],B,n+1,m);
    int del = costo_del(A[n])+transform(A.substr(0,n-1),B,n-1,m);
    int sub = costo_sub(B[m-1],A[n])+transform(A.substr(0,n-1)+B[m-1],B,n,m);
    
    if (A[n-1]==B[m-2] && A[n-2]==B[m-1]) {
        int tr = costo_trans(A[n-1],A[n-2])+transform(A.substr(0,n-2),B.substr(0,m-2),n-2,m-2);
        return min({ins,del,sub,tr});
    }

    return min({ins,del,sub});
}

int main() {
    int n,m;
    string A,B;

    cout << "Ingrese palabras (en lineas separadas):" <<endl;
    getline(cin,A);
    getline(cin,B);

    n = A.length();
    m = B.length();
    
    int minEdit = transform(A,B,n,m);
    cout << "Secuencia mínima de edición: " << minEdit << endl;
    // assassin -> embarrass?
    return 0;
}