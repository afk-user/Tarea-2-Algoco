#include <iostream>
#include <chrono>
#include <algorithm>
#include <string>
#include "costos.hpp"
using namespace std;

int transform(string A, string B, int n, int m) {
    vector<vector<int>> t (n+1,vector<int>(m+1,0));
    int i,j,ins,del,sub,tr;

    for (i=1;i<=n;i++) {
        t[i][0] = costo_del(A[i-1])+t[i-1][0];
    }
    for (j=1;j<=m;j++) {
        t[0][j] = costo_ins(B[j-1])+t[0][j-1];
    }

    for (i=1;i<=n;i++){
        for (j=1;j<=m;j++){
            ins = costo_ins(B[j])+t[i][j-1];
            del = costo_del(A[i])+t[i-1][j];
            sub = costo_sub(A[i-1],B[j-1])+t[i-1][j-1];
            t[i][j] = min({ins,del,sub});

            if (A[i-1]==B[j-2] && A[i-2]==B[j-1]) {
                tr = costo_trans(A[i-1],A[i-2])+t[i-2][j-2];
                t[i][j] = min({ins,del,sub,tr});
            }
        }
    }

    return t[n][m];
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
    int minEdit = transform(A,B,n,m);
    end = chrono::system_clock::now();
    elapsed_seconds = end - start;

    cout << "Secuencia mínima de edición: " << minEdit << endl << "Tiempo transcurrido: " << elapsed_seconds.count() << " segundos" << endl;
    
    return 0;
}