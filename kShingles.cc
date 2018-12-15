#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main() {
	cout << "Indica el valor de k que vols per fer els k-Shingles" << endl;
	int k;
	cin >> k;
	cout << "Introdueix el nombre de fitxers 'permutacioi.txt' dels que se n'ha de fer els k-Shingles" << endl;
	int numFitxers;
	cin >> numFitxers;
	for(int i = 0; i < numFitxers; ++i) {
		string nomEntrada = "permutacio";
		nomEntrada.append(to_string(i+1));
		nomEntrada.append(".txt");
		ifstream fitxerEntrada;
		fitxerEntrada.open(nomEntrada);
		string dades;
		getline(fitxerEntrada,dades);
		fitxerEntrada.close();
		string nomSortida = "kShingles";
		nomSortida.append(to_string(i+1));
		nomSortida.append(".txt");
		ofstream fitxerSortida;
		fitxerSortida.open(nomSortida);
		for(int j = 0; j < dades.size() - k -1; ++j) {
			fitxerSortida << dades.substr(j,k) << endl;
		}
		fitxerSortida.close();
	}
}