#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int costo_sub(char a,char b) {return a==b?0:2;}
int costo_ins(char b) {return 1;}
int costo_del(char a) {return 1;}
int costo_trans(char a,char b) {return a==b?0:1;}

int evaluate(string w1,string w2,int minEdit) {
    cout << w1 << " " << w2 << endl;
    
    cout << w2 << endl;
    return minEdit;
}

void filterSame(string &w1,string &w2) {
    string sub1=w1;
    string sub2=w2;
    int front=0, i;

    int minWord = min(w1.length(),w2.length());
    bool i1Small = w1.length()<w2.length();

    //encontrar patrones en palabras
    if (w1 != w2) {
        for (i=0;i<minWord;i++) {
            if (w1[i]!=w2[i]) {
                front = i;
                sub1=w1.substr(i,w1.length());
                sub2=w2.substr(i,w2.length());
                break;
            }
        }
        if (front==0){
            for (i=minWord;i>=0;i--) {
                if (i1Small) {
                    if (w1[i]!=w2[i+w2.length()-w1.length()]) {
                        sub1=w1.substr(0,i+1);
                        sub2=w2.substr(0,i+1);
                        break;
                    }
                } else if (w1[i+w1.length()-w2.length()]!=w2[i]) {
                    sub1=w1.substr(0,i+1);
                    sub2=w2.substr(0,i+1);
                    break;
                }
            }
        }
    }
    w1=sub1;
    w2=sub2;
}

int main() {
    string input1,input2;
    int minEdit = 0;

    cout << "Ingrese palabras:" << endl;
    cin >> input1 >> input2;
    
    filterSame(input1,input2);
    minEdit = evaluate(input1,input2,minEdit);
    cout << "Secuencia mínima de edición: " << minEdit << endl;
    // assassin -> embarrass?
    return 0;
}