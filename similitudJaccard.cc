#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
using namespace std;

int main() {
	cout << "Indica el nom dels fitxers que vols comparar" << endl;
	string nomFitxer1, nomFitxer2;
	cin >> nomFitxer1 >> nomFitxer2;
	ifstream fitxer1;
	fitxer1.open(nomFitxer1);
	ifstream fitxer2;
	fitxer2.open(nomFitxer2);
	set<string> paraulesEnComu;
	set<string> paraulesEnTotal;
	string paraula;
	while (fitxer1 >> paraula) {
		paraulesEnTotal.insert(paraula);
	}
	while(fitxer2 >> paraula) {
		if (!(paraulesEnTotal).insert(paraula).second) {
			paraulesEnComu.insert(paraula);
			cout << paraula << endl;
		}
	}
	cout << "Nombre d'elements en total: " << paraulesEnTotal.size() << endl;
	cout << "Nombre d'elements en comú: " << paraulesEnComu.size() << endl;
	double similitudDeJaccard = (double)((double)paraulesEnComu.size()/(double)paraulesEnTotal.size());
	cout << "Similitud de Jaccard: " << similitudDeJaccard << endl;
}