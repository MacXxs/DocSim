#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include "MinHash.h"
using namespace std;

int main(){
    set<string> shingles;
    int numFitxers;
    cout << "Quants documents representats per shingles vols tractar?" << endl;
	cin >> numFitxers;
    vector<vector<string> > input(numFitxers, vector<string>(1));
	string nomShingle, shingle;
	ifstream fitxerShingle;
	for(int i = 0; i < numFitxers; ++i){
        nomShingle = "inputs/AQC/kShingles";
		nomShingle.append(to_string(i+1));
		nomShingle.append(".txt");
        fitxerShingle.open(nomShingle);
        while (getline(fitxerShingle, shingle)) {
            input[i].push_back(shingle);
            shingles.insert(shingle);
        }
        fitxerShingle.close();
	}

    cout << "introdueix el nombre de funcions de hash a utilitzar" << endl;
    int t;
    cin >> t;
    setT(t);
    vector<vector<uint32_t> > signatureMatrix = createSignature(input, 4,shingles.size());

    /*for(int i = 0; i < signatureMatrix.size(); ++i){
        for(int j = 0; j < signatureMatrix[i].size(); ++j){
            cout << signatureMatrix[i][j] << " ";
        }
        cout << endl;
    }*/
    vector<uint32_t> sig1(t);
    vector<uint32_t> sig2(t);
    for(int j = 1; j < numFitxers; ++j){
        for(int i= 0; i < t; ++i){
            sig1[i] = signatureMatrix[0][i];
            sig2[i] = signatureMatrix[j][i];
        }
        float simf = sim(sig1, sig2);
        cout << "Sim entre 1 i " << j << " : " << simf << endl;
    }
    //const char * aux = input[0][0].c_str();
    //cout << aux << endl;
}
