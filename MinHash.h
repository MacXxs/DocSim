#include <vector>
#include <string>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
using namespace std;

#ifndef MINHASH_H_INCLUDED
#define MINHASH_H_INCLUDED

extern int numHashes;

void setT(int t);
int getT();
float sim(vector<uint32_t> a, vector<uint32_t> b);
vector<vector<uint32_t> > createSignature(vector<vector<string> > kshingles, int k, int numShingles);

#endif // MINHASH_H_INCLUDED
