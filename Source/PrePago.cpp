#include "./../Headers/PrePago.h"

PrePago::PrePago(){}

void PrePago::adicionaCreditos(int creditos, Date dataAtual){
    credito += creditos;
    validade.acrescentaTempo();
}

void PrePago::verificaCredito(const double& custo) const{
    if(credito - custo < 0){
        throw exception::exception();
    }
}

void PrePago::verificaData(const Date& dataLigacao) const{
    if(dataLigacao > validade){
        throw exception::exception();
    }
}

void PrePago::cobraCusto(const double& custo){
    credito -= custo;
}