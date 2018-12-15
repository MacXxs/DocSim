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
float sim(vector<int> a, vector<int> b);
vector<vector<uint32_t> > createSignature(vector<vector<string> > kshingles, int k);

#endif // MINHASH_H_INCLUDED
