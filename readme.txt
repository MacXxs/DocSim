
---------------------------------------------------------------------------------------
||||||||||||||||||||||||||||||INSTRUCCIONS DE COMPILACIÓ|||||||||||||||||||||||||||||||
---------------------------------------------------------------------------------------

Podeu trobar tot el codi a aquest repositori públic de github: https://github.com/marticosala/DocSim.git

Els fitxers permutacions.cpp i kShingles.cpp contenen el codi per a generar permutacions aleatòries d'un document de text i els respectius shingles
no és indispensable comiplar-los ja que us proporcionem els quatre jocs de prova que hem generat.


///////////////////////SIMILITUD DE JACKARD PER  K-SHINGLES\\\\\\\\\\\\\\\\\\\\\\\\\\\\
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/////////////////////////////////////////////
Per provar el algorisme de LSH amb signatures de Minhash només cal utiltizar la comanda "g++ --std=c++11 -o nom_del_executable similitudJaccard.cc"
Un cop compilat només restaria invocar al executable amb ./nom_del_executable i seguir les instruccions indicades per consola.


////APROXIMACIÓ SIMILITUD DE JACKARD VIA SIGNATURES MINHASH AMB T FUNCIONS DE HASH\\\\\
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/////////////////////////////////////////////
Per a compilar l'algorisme s'ha de compilar el fitxer MainClass i linkar-lo amb el MinHash.o i el xxhash.o (s'han de generar previament)
g++ --std=c++11 -g  -c MainClass.cpp -o MainClass.o
g++ -o nomexEcutable.exe MainClass.o MinHash.o xxHash\xxhash.o


////////////////////////////////////LHS MINHASH\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/////////////////////////////////////////////
Per provar el algorisme de LSH amb signatures de Minhash només cal utiltizar la comanda "g++ --std=c++11 -o nom_del_executable lsh.cc"
Un cop compilat només restaria invocar al executable amb ./nom_del_executable i seguir les instruccions indicades per consola.