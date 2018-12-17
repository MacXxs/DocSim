#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
using namespace std;

int main() {
    string directory = "inputs/15mers/AQC/";
	cout << "Indica el nom dels fitxers que vols comparar" << endl;
	string nomFitxer1, nomFitxer2;
	cin >> nomFitxer1 >> nomFitxer2;
	ifstream fitxer1;
	fitxer1.open(directory.append(nomFitxer1));
	ifstream fitxer2;
	directory = "inputs/15mers/AQC/";
	fitxer2.open(directory.append(nomFitxer2));
	set<string> paraulesEnComu;
	set<string> paraulesEnTotal;
	string paraula;
	while (getline(fitxer1, paraula)) {
		paraulesEnTotal.insert(paraula);
	}
	while(getline(fitxer2, paraula)) {
		if (!(paraulesEnTotal).insert(paraula).second) {
			paraulesEnComu.insert(paraula);
		}
	}
	cout << "Nombre d'elements en total: " << paraulesEnTotal.size() << endl;
	cout << "Nombre d'elements en comú: " << paraulesEnComu.size() << endl;
	double similitudDeJaccard = (double)((double)paraulesEnComu.size()/(double)paraulesEnTotal.size());
	cout << "Similitud de Jaccard: " << similitudDeJaccard << endl;
}
