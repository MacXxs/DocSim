#include <iostream>
#include <vector>
#include "MinHash.h"
using namespace std;

int main(){
    vector<vector<string> > input(2, vector<string>(6));
    input[0][0] = "abac";
    input[0][1] = "bact";
    input[0][2] = "acte";
    input[0][3] = "cter";
    input[0][4] = "teri";
    input[0][5] = "eria";
    input[1][0] = "tbac";
    input[1][1] = "bact";
    input[1][2] = "acte";
    input[1][3] = "cter";
    input[1][4] = "tero";
    input[1][5] = "eroa";
    /*here goes the creation of random docs instead the stub variable input*/
    int t = 5;
    /*cin >> t; better with a parameter */
    setT(t);
    vector<vector<uint32_t> > signatureMatrix = createSignature(input, 4);

    for(int i = 0; i < signatureMatrix.size(); ++i){
        for(int j = 0; j < signatureMatrix[i].size(); ++j){
            cout << signatureMatrix[i][j] << " ";
        }
        cout << endl;
    }
    //const char * aux = input[0][0].c_str();
    //cout << aux << endl;
}
