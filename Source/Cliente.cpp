#include "./../Headers/Cliente.h"

Cliente::Cliente(){
}

Cliente::~Cliente(){
}

// CONSTRUTOR DE COPIA

// DUVIDA: Construtor que recebe vetor de celulares tambem?

// Celular Pos-Pago
void Cliente::addCelular(string nomePlano, double vlrMinuto, double _franquia, double _velAlem, double _veloc, Date vencimento){
    Plano* ptr_plano = new PosPago(nomePlano, vlrMinuto, _franquia, _velAlem, _veloc, vencimento);
    Celular* newCel = new Celular(this, ptr_plano);
    celulares.push_back(newCel);
}

// Celular Pre-Pago
void Cliente::addCelular(string nomePlano, double vlrMinuto, double _franquia, double _velAlem, double _veloc, Date curr_date, double credito){
    curr_date.acrescentaTempo(); // ATUALIZA VALIDADE
    Plano* ptr_plano = new PrePago(nomePlano, vlrMinuto, _franquia, _velAlem, _veloc, credito, curr_date);
    Celular* newCel = new Celular(this, ptr_plano);
    celulares.push_back(newCel);
}

// LIGACAO SIMPLES
void Cliente::efetuarLigacao(int celularIndex, Date timestamp, double duracao, double numTel){
    celulares[celularIndex]->ligar(timestamp, duracao, numTel);
} 

// LIGACAO DE DADOS
void Cliente::efetuarLigacao(int celularIndex, Date timestamp, double duracao, tipoDados td){
    celulares[celularIndex]->ligar(duracao, td, timestamp);
}

// TO-DO: quando tenho que definir o operador de atribuicao?