#include <iostream>
#include <map>
#include <vector>
using namespace std;

void in_minhashes (vector<vector<uint32_t>>& minhashes){
	uint32_t sig;
	string text;
	for (int i  = 0; i < minhashes[0].size(); ++i){
		cout << "introdueix les firmes del text " << i << endl;
		for (int j = 0; j < minhashes.size(); ++j){
			cin >> sig;
			minhashes[j][i] = sig;
		}
	}
}

void out_minhashes (const vector<vector<uint32_t>>& minhashes){
	for (int i = 0; i < minhashes[0].size(); ++i){
		cout << i << "->[";
		for (int j = 0; j < minhashes.size(); ++j){
			if (j == 0) cout << minhashes[j][i];
			else cout << ',' << minhashes[j][i];
		}
		cout << ']' << endl;
	}
}

//per debugar
void out_vec(const vector<uint32_t> &vec){
	for (int i = 0; i < vec.size(); ++i)
		cout << vec[i] << ' ';
	cout << endl;
}

//ens retorna true si el document doc es similar a y superant o igualant el threshold
bool is_candidate(const int& doc, const int& y, const vector<vector<uint32_t>>& candidates, double & sim, const double& threshold){
	int equal = 0;
	for (int b = 0; b < candidates.size(); ++b){
		if (candidates[b][doc] == candidates[b][y]) ++equal;
	}
	if ((equal/candidates.size()) >= threshold){
		sim = (double(equal)/double(candidates.size()));
		return true;
	}
	return false;
}

//busca un possible candidat en la mateixa banda
void search_candidate(const int& band, const int& doc, const vector<vector<uint32_t>>& candidates, const double& threshold){
	for (int y = doc + 1; y < candidates[0].size(); ++y){
		if (candidates[band][doc] == candidates[band][y]){
			double sim;
			if (is_candidate(doc,y,candidates, sim,threshold)){
				cout << "el document " << doc << " i el docmuent " << y << " son similars en un " << sim << endl;
			}
		}
	}
}

//funcio de hash per obtenir una posició en el map
class Hash {

	public :

	size_t operator()(std::vector<uint32_t> const& vec) const {
	  size_t seed = vec.size();
	  for(auto& i : vec) {
	    seed ^= i + 0x9e3779b9 + (seed << 6) + (seed >> 2);
	  }
	  return seed;
	}
};

int main() {

	Hash hash;
	int n, s;
	cout << "introdueix el nombre de minhashes" << endl;
	cin >> n;
	cout << "introdueix el nombre de firmes per minhash" << endl;
	cin >> s;
	vector<vector<uint32_t>> minhashes(s,vector<uint32_t> (n));
	in_minhashes(minhashes);
	out_minhashes(minhashes);

	int band, rows;
	double threshold;
	cout << "introdueix el nombre de bandes" << endl;
	cin >> band;
	cout << "introdeux el nombre de files per banda" << endl;
	cin >> rows;
	cout << "introdueix un threshold" << endl;
	cin >> threshold;

	vector<vector<uint32_t>> candidates(band,vector<uint32_t>(n));

	for (int b = 0; b < band; ++b){

		for (int i = 0; i < n; ++i){
			vector<uint32_t> signatures(rows);
			int r = 0;
			for (int j = b*rows; j < b*rows + rows; ++j){
				signatures[r] = minhashes[j][i];
				++r;
			} 
			candidates[b][i] = hash(signatures);
		}
	}

	//això ens retorna una matriu a on per cada doc té tants elements
	//com bandes, on cada element és el vector de firmes, com rows, al qual
	//se li ha aplicat una funció de hash per obtenir un identificador únic
	for (int x = 0; x < n; ++x){
		cout << "doc" << x << " -> ";
		for (int y = 0; y < band; ++y){
			cout << candidates[y][x] << ' ';
		}
		cout << endl;
	}

	//agafem cada identificador de cada banda i comparem amb les següents
	//en busca d'un candidat
	int aux_i, aux_j;
	for (int x = 0; x < band; ++x){
		for (int y = 0; y < n; ++y){
			if (y != n-1){
				aux_i = x;
				aux_j = y;
				search_candidate(aux_i, aux_j, candidates, threshold);
			}
		}
	}
}