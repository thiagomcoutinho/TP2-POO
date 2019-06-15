#include "./../Headers/PrePago.h"

PrePago::PrePago(){}

PrePago::~PrePago(){}

void PrePago::adicionaCreditos(const int& creditos, const Date& dataAtual){
    credito += creditos;
    validade = dataAtual;
    validade.acrescentaTempo();
}

void PrePago::verificaCredito(const double& custo) const{
    if(credito - custo < 0){
        throw Excecao("Creditos insuficientes");
    }
}

void PrePago::verificaData(const Date& dataLigacao) const{
    if(dataLigacao > validade){
        throw Excecao("Validade dos creditos expirada");
    }
}