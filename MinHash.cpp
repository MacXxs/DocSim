#include <iostream>
#include <vector>
#include <climits>
#include <string.h>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <stdint.h>
#include <time.h>
#include "xxHash/xxhash.h"
#include "MinHash.h"
using namespace std;

int numHashes;

int getT(){
    return numHashes;
}

void setT(int t){
    numHashes = t;
}

//creates the signature matrix of the docs represented as the vector of kShingles
vector<vector<uint32_t> > createSignature(vector<vector<string> > kShingles, int k){
    int seed;
    char kmer[k];
    const char *aux;
    uint32_t kmerHash;
    vector<vector<uint32_t> > signatureMatrix(numHashes, vector<uint32_t>(kShingles.size(), UINT_MAX)); //stores the minHash signature of the document, must be initialized at +infinity
    //for each hash function
    vector<int> seeds(numHashes);
    for(int i = 0; i < numHashes; ++i){
        seed = rand();
        cout << "seed: " << seed << endl;
        //for each doc
        for(int j = 0; j < kShingles.size(); ++j){
            //for each shingle
            for(int k = 0; k < kShingles[j].size(); ++k){
                //here we compute the minHash for each Set of kShingles
                aux = kShingles[j][k].c_str();
                //cout << "aux: " <<  << endl;
                //memcpy(kmer,&aux[0],k);
                kmerHash = XXH32(aux,k,seed);
                cout << aux << " " << kmerHash << endl;
                if(kmerHash < signatureMatrix[i][j]) signatureMatrix[i][j] = kmerHash;
            }
        }
    }
    return signatureMatrix;
}

//calculates the approximation of Jaccard similarity using minHash signatures
//currently it gets two separate signatures we should use a signatureMatrix?
float sim(vector<int> a, vector<int> b){
    float sim = 0;
    for(int i = 0; i < numHashes; ++i){
        if(a[i] == b[i]) ++sim;
    }
    return sim/numHashes;
}
