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
//the matrix is numDocs * numHashes so each row is a signature
vector<vector<uint32_t> > createSignature(vector<vector<string> > kShingles, int k, int numShingles){
    char kmer[k];
    const char *aux;
    uint32_t kmerHash;
    vector<vector<uint32_t> > signatureMatrix(kShingles.size(), vector<uint32_t>(numHashes, UINT_MAX)); //stores the minHash signature of the document, must be initialized at +infinity
    //for each hash function generate a random seed
    vector<int> seeds(numHashes);
    for(int i = 0; i < numHashes; ++i){
        seeds[i] = rand();
    }
    //cout << "numShingles: " << numShingles << endl << endl;
    //for each doc
    for(int i = 0; i < kShingles.size(); ++i){
        //for each hash function
        for(int j = 0; j < numHashes; ++j){
            //for each shingle
            for(int k = 0; k < kShingles[i].size(); ++k){
                //here we compute the minHash for each Set of kShingles
                aux = kShingles[i][k].c_str();
                kmerHash = XXH32(aux,k,seeds[j])%numShingles;
                //cout << aux << ":" << kmerHash << " ";
                if(kmerHash < signatureMatrix[i][j]) signatureMatrix[i][j] = kmerHash;
            }
            //cout << endl;
        }
        //cout << endl << endl;
    }
    return signatureMatrix;
}

//calculates the approximation of Jaccard similarity using minHash signatures
//currently it gets two separate signatures we should use a signatureMatrix?
float sim(vector<uint32_t> a, vector<uint32_t> b){
    float sim = 0;
    for(int i = 0; i < numHashes; ++i){
        if(a[i] == b[i]) ++sim;
    }
    cout << "SIM: " << sim << endl;
    return sim/numHashes;
}
