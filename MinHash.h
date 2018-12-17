#include <vector>
#include <string>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
using namespace std;

#ifndef MINHASH_H_INCLUDED
#define MINHASH_H_INCLUDED

float sim(vector<uint32_t> a, vector<uint32_t> b, int t);
vector<vector<uint32_t> > createSignature(vector<vector<string> > kshingles, int merLength, int t);

#endif // MINHASH_H_INCLUDED
