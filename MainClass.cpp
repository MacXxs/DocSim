#include <iostream>
#include <fstream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <stdint.h>
#include <chrono>
#include "xxHash/xxhash.h"
#include <string>
#include <vector>
#include <set>
#include "MinHash.h"
using namespace std;
using namespace std::chrono;

int main(){
    int numFitxers;
    int merLength = 0;
    cout << "Quants documents representats per shingles vols tractar?" << endl;
	cin >> numFitxers;
    vector<vector<string> > input(numFitxers, vector<string>(1));
	string nomShingle, shingle;
	ifstream fitxerShingle;
	for(int i = 0; i < numFitxers; ++i){
        nomShingle = "inputs/15mers/concerning_hobbits/kShingles";
		nomShingle.append(to_string(i+1));
		nomShingle.append(".txt");
        fitxerShingle.open(nomShingle);
        while (getline(fitxerShingle, shingle)) {
            if(merLength == 0) merLength = shingle.length();
            input[i].push_back(shingle);
        }
        fitxerShingle.close();
	}

    cout << "introdueix el nombre de funcions de hash a utilitzar" << endl;
    int t;
    cin >> t;
    setT(t);

    high_resolution_clock::time_point t1 = high_resolution_clock::now();

    vector<vector<uint32_t> > signatureMatrix = createSignature(input, merLength);

    high_resolution_clock::time_point t2 = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>( t2 - t1 ).count();

    cout << "MinHash computation: " << duration/1000 << endl;
    //for(int i = 0; i < signatureMatrix.size(); ++i){
    //    for(int j = 0; j < signatureMatrix[i].size(); ++j){
    //        cout << signatureMatrix[i][j] << " ";
    //    }
    //    cout << endl;
    //}
    high_resolution_clock::time_point t3 = high_resolution_clock::now();
    vector<uint32_t> sig1(t);
    vector<uint32_t> sig2(t);
    ofstream fitxerSortida;
    fitxerSortida.open("SimFile.csv");
    for(int j = 1; j < numFitxers; ++j){
        for(int i= 0; i < t; ++i){
            sig1[i] = signatureMatrix[0][i];
            sig2[i] = signatureMatrix[j][i];
        }
        float simf = sim(sig1, sig2);
        fitxerSortida << simf << endl;
    }
    fitxerSortida.close();

    //const char * aux = input[0][0].c_str();
    //cout << aux << endl;
}
