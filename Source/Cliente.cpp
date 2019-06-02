#include "./../Headers/Cliente.h"

Cliente::Cliente(){
    CPF = -1;
    nome = "";
    endereco = "";
}

Cliente::Cliente(int _CPF, string _nome, string _endereco){
    CPF = _CPF;
    nome = _nome;
    endereco = _endereco;
}

Cliente::~Cliente(){
    
}

// DUVIDA: Construtor que recebe vetor de celulares tambem?

// Celular Pos-Pago
void Cliente::addCelular(string nomePlano, double vlrMinuto, double _franquia, double _velAlem, Date vencimento){
    PosPago p(nomePlano, vlrMinuto, _franquia, _velAlem, vencimento);
    Celular newCel(this, p);
    celulares.push_back(newCel);
}

// Celular Pre-Pago
void Cliente::addCelular(string nomePlano, double vlrMinuto, double _franquia, double _velAlem, Date curr_date, double credito){
    PrePago p(nomePlano, vlrMinuto, _franquia, _velAlem, credito, curr_date);
    Celular newCel(this, p);
    celulares.push_back(newCel);
}

// LIGACAO SIMPLES
void Cliente::efetuarLigacao(int celularIndex, Date timestamp, double duracao, double numTel){
    celulares[celularIndex].ligar(timestamp, duracao, numTel);
} 

// LIGACAO DE DADOS
void Cliente::efetuarLigacao(int celularIndex, Date timestamp, double duracao, tipoDados td){
    celulares[celularIndex].ligar(timestamp, duracao, td);
}