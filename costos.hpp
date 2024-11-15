#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
using namespace std;

map<const char*,int> letter2num;

vector<int> tableDel (26,0);
vector<int> tableIns (26,0);
vector<vector<int>> tableSub (26,vector<int>(26,0));
vector<vector<int>> tableTrans (26,vector<int>(26,0));

void fillTables() {
    ifstream fileDel,fileIns,fileSub,fileTrans;
    string str;
    int i=0,j=0;

    fileDel.open("costos/cost_delete.txt");
    if (fileDel.is_open()) {
        while (fileDel >> str) {
            tableDel[i] = stoi(str);
            i++;
        }
        fileDel.close();
    }

    fileIns.open("costos/cost_insert.txt");
    if (fileIns.is_open()) {
        i=0;
        while (fileIns >> str) {
            tableIns[i] = stoi(str);
            i++;
        }
        fileIns.close();
    }
    
    fileSub.open("costos/cost_replace.txt");
    if (fileSub.is_open()) {
        i=0,j=0;
        while (fileSub >> str) {
            tableSub[i][j] = stoi(str);
            j++;
            if (j==26) {
                j=0;
                i++;
            }
        }
        fileSub.close();
    }

    fileTrans.open("costos/cost_transpose.txt");
    if (fileTrans.is_open()) {
        i=0,j=0;
        while (fileTrans >> str) {
            tableTrans[i][j] = stoi(str);
            j++;
            if (j==26) {
                j=0;
                i++;
            }
        }
        fileTrans.close();
    }
}

int costo_del(char a) {
    int pos = a-'a';
    return tableDel[pos];
}
int costo_ins(char b) {
    int pos = b-'a';
    return tableIns[pos];
}
int costo_sub(char a,char b) {
    int row = a-'a';
    int col = b-'a';
    return tableSub[row][col];
}
int costo_trans(char a,char b) {
    int row = a-'a';
    int col = b-'a';
    return tableTrans[row][col];
}