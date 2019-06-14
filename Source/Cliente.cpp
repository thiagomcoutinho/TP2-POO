#include "./../Headers/Cliente.h"

Cliente::Cliente(){}

Cliente::~Cliente(){}

// Celular Pos-Pago
void Cliente::addCelular(const string& nomePlano, const double& vlrMinuto, const double& _franquia, const double& _velAlem, const double& _veloc, const Date& vencimento){
    Plano* ptr_plano = new PosPago(nomePlano, vlrMinuto, _franquia, _velAlem, _veloc, vencimento);
    Celular* newCel = new Celular(this, ptr_plano); // INSTANCIA NOVO CELULAR
    celulares.push_back(newCel);
}

// Celular Pre-Pago
void Cliente::addCelular(const string& nomePlano, const double& vlrMinuto, const double& _franquia, const double& _velAlem, const double& _veloc, Date& curr_date, const double& credito){
    curr_date.acrescentaTempo(); // ATUALIZA VALIDADE DOS CREDITOS
    Plano* ptr_plano = new PrePago(nomePlano, vlrMinuto, _franquia, _velAlem, _veloc, credito, curr_date);
    Celular* newCel = new Celular(this, ptr_plano); // INSTANCIA NOVO CELULAR
    celulares.push_back(newCel);
}

// LIGACAO SIMPLES
void Cliente::efetuarLigacao(const int& celularIndex, const Date& timestamp, const double& duracao, const double& numTel){
    celulares[celularIndex]->ligar(timestamp, duracao, numTel);
} 

// LIGACAO DE DADOS
void Cliente::efetuarLigacao(const int& celularIndex, const Date& timestamp, const double& duracao, const tipoDados& td){
    celulares[celularIndex]->ligar(timestamp, duracao, td);
}