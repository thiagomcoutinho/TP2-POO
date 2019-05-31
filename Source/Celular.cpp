#include<Headers/Celular.h>
#include<Headers/Date.h>
#include<Headers/LigacaoSimples.h>
#include<Headers/LigacaoDados.h>

Celular::Celular(){
}

Celular::Celular(Cliente client, Plano& p){
    plano = &p;
    numero = proxNumCelular;
    proxNumCelular++;
}

// LIGACAO SIMPLES
void Celular::ligar(Date timestamp, double duracao, double numTel){
    // VERIFICA VALIDADE(PRE PAGO) || VENCIMENTO(POS PAGO)
    plano->verificaData(timestamp);

    double custo;
    custo = duracao*plano->getValorMinuto();

    // VERIFICA CREDITO CELULAR PRE PAGO
    if(dynamic_cast<PosPago*>(plano) == nullptr){ 
        plano->verificaCredito(custo);
    }

    // COBRA CUSTO
    plano->cobraCusto(custo);

    // FAZ LIGACAO
    LigacaoSimples l(timestamp, duracao, custo, numTel);
    ligacoes.push_back(l);
}

// LIGACAO DADOS
void Celular::ligar(Date timestamp, double duracao, tipoDados td){
    
    double franquia = plano->getFranquia();
    double franquiaGasta = plano->getFranquiaGasta();
    double custo;

    if(franquiaGasta > franquia){
        custo = plano->getVelocAlem*duracao;
    }else{
        custo = plano->getVelocidade*duracao;
    }
    plano->setFranquiaGasta(custo);
    
}