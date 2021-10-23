#include <iostream>
#include<string>
#include <fstream>
#include<list>
#include <unordered_map>

using namespace std;


list<string> separa(string texto) {
    list<string>palavra;
    string sep =" ";
    if (texto != "") {
        string nova;
        int pos1 = 0, pos2 = 0, i = 0, cont = 0;
        int n1 = 0, n2 = 0;
        for (int i = 0; i <= texto.size(); i++) {
            if (n2 != string::npos) {
                n1 = n2;
                n2 = texto.find(sep, n1 + 1);
                cont++;
            }
        }
        for (i = 0; i < cont; i++) {
            pos2 = texto.find(sep, pos1);
            nova = texto.substr(pos1, pos2 - pos1);
            palavra.push_back(nova);
            pos1 = pos2 + sep.size();
        }

    }
    return palavra;
}

int main(int argc, char *argv[]) {

    ifstream arq(argv[1]);
    if (!arq.is_open()) {
        perror("Ao abrir ");
        return errno;
    }
    string linha;

    while (getline(arq, linha)) {
        list<string> nova = (separa(linha));
        for (auto &w: nova) {
            cout << w << endl;
        }
    }
}




