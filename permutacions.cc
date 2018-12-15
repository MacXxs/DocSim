#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cout << "Indica el fitxer del que vols fer permutacions aleatòries" << endl;
	string nomFitxer;
	cin >> nomFitxer;
	cout << "Indica quantes permutacions en vols" << endl;
	int numPermutacions;
	cin >> numPermutacions;
	ifstream fitxer;
	fitxer.open(nomFitxer);
	vector<string> fitxerOriginal(1);
	int i = 0;
	string paraula;
	while(fitxer >> paraula) {
		if (fitxerOriginal.size() <= i) {
			fitxerOriginal.push_back(paraula);
			++i;
		}
		else {
			fitxerOriginal[i] = paraula;
			++i;	
		}
	}
	fitxer.close();
	for(int j = 0; j < numPermutacions; ++j) {
		string nom = "permutacio";
		nom.append(to_string(j+1));
		nom.append(".txt");
		ofstream fitxerPermutacio;
		fitxerPermutacio.open(nom);
		random_shuffle(fitxerOriginal.begin(), fitxerOriginal.end());
		for(int k = 0; k < fitxerOriginal.size(); ++k)  {
			fitxerPermutacio << fitxerOriginal[k];
			fitxerPermutacio << " ";
		}

		fitxerPermutacio.close();
	}
}