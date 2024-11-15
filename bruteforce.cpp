#include <iostream>
#include <chrono>
#include <algorithm>
#include <string>
#include "costos.hpp"
using namespace std;

int transform(string::iterator A, string::iterator B, int n, int m) {
    if (n==0) return m;
    else if (m==0) return n;
    
    int ins = costo_ins(*(B-1))+transform(A,B-1,n,m-1);
    int del = costo_del(*(A-1))+transform(A-1,B,n-1,m);
    int sub = costo_sub(*(B-1),*(A-1))+transform(A-1,B-1,n-1,m-1);
    int minEdit = min({ins,del,sub});
    
    if (*(A-1)==*(B-2) && *(A-2)==*(B-1)) {
        int tr = costo_trans(*(A-1),*(A-2))+transform(A-2,B-2,n-2,m-2);
        minEdit = min({ins,del,sub,tr});
    }

    return minEdit;
}

int main() {
    int n,m;
    string A,B;
    fillTables();
    chrono::time_point<chrono::system_clock> start, end;
    chrono::duration<double> elapsed_seconds;

    cout << "Ingrese palabras (en lineas separadas):" <<endl;
    getline(cin,A);
    getline(cin,B);

    n = A.length();
    m = B.length();
    
    start = chrono::system_clock::now();
    int minEdit = transform(A.end(),B.end(),n,m);
    end = chrono::system_clock::now();
    elapsed_seconds = end - start;

    cout << "Secuencia mínima de edición: " << minEdit << endl << "Tiempo transcurrido: " << elapsed_seconds.count() << " segundos" << endl;
    return 0;
}