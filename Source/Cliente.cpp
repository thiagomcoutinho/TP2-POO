#include<Headers/Cliente.h>

Cliente::Cliente(int _CPF, string _nome, string _endereco){
    CPF = _CPF;
    nome = _nome;
    endereco = _endereco;
}

void Cliente::addCelular(Celular c){
    celulares.push_back(c);
}
