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
			minhashes[i][j] = sig;
		}
	}
}

void out_minhashes (vector<vector<uint32_t	>>& minhashes){
	for (int i = 0; i < minhashes[0].size(); ++i){
		cout << i << "->[";
		for (int j = 0; j < minhashes.size(); ++j){
			if (j == 0) cout << minhashes[i][j];
			else cout << ',' << minhashes[i][j];
		}
		cout << ']' << endl;
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

	/*int band, rows;
	cout << "introdueix el nombre de bandes" << endl;
	cin >> band;
	cout << "introdeux el nombre de files per banda" << endl;
	cin >> rows;

	map<string,vector<uint32_t> candidates;

	for (int i = 0; i < bandes; ++i){
		map<uint32_t,vector<uint32_t>> bucket;
		for (auto it = minhashes.begin(); it != minhashes.end(); ++it){
			vector<uint32_t> signatures(rows);
			for (int j = i*rows; j < i*rows + rows; ++j){

			}

		}
	}*/
}