#include <iostream>
#include <map>
#include <vector>
using namespace std;

void in_minhashes (map<string, vector<uint32_t>>& minhashes){

	int n, s;
	cout << "introdueix el nombre de minhashes" << endl;
	cin >> n;
	cout << "introdueix el nombre de firmes per minhash" << endl;
	cin >> s;

	uint32_t sig;
	string text;
	for (int i  = 0; i < n; ++i){

		vector<uint32_t> signatures(s);
		cout << "introdueix el identificador del minhash" << endl;
		cin >> text;
		cout << "introdueix les firmes del text " << text << endl;
		for (int j = 0; j < s; ++j){

			cin >> sig;
			signatures[j] = sig;
		}
		minhashes.insert(pair<string,vector<uint32_t>>(text,signatures));
	}
}

void out_minhashes (map<string, vector<uint32_t	>>& minhashes){
	for (map<string, vector<uint32_t>>::iterator it = minhashes.begin(); it != minhashes.end(); ++it){

		cout << it->first << "->[";
		for (int i = 0; i < it->second.size(); ++i){

			if (i == 0) cout << it->second[i];
			else cout << ',' << it->second[i];
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
	map<string, vector<uint32_t>> minhashes;
	in_minhashes(minhashes);
	out_minhashes(minhashes);

	int band, rows;
	cout << "introdueix el nombre de bandes" << endl;
	cin >> band;
	cout << "introdeux el nombre de files per banda" << endl;
	cin >> rows;

	map<string,vector<uint32_t> candidates;

	/*for (int i = 0; i < bandes; ++i){
		map<uint32_t,vector<uint32_t>> bucket;
		for (auto it = minhashes.begin(); it != minhashes.end(); ++it){
			vector<uint32_t> signatures(rows);
			for (int j = i*rows; j < i*rows + rows; ++j){

			}

		}
	}*/
}