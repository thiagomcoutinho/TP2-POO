#include "./../Headers/Celular.h"
#include "./../Headers/Date.h"
#include "./../Headers/LigacaoSimples.h"
#include "./../Headers/LigacaoDados.h"
#include "./../Headers/PosPago.h"

Celular::Celular(){
}

Celular::Celular(Cliente* c, Plano& p){
    plano = &p;
    cliente = c;
    numero = proxNumCelular;
    proxNumCelular++;
}

Celular::~Celular(){
}

// LIGACAO SIMPLES
void Celular::ligar(Date timestamp, double duracao, double numTel){
    // VERIFICA VALIDADE(PRE PAGO) || VENCIMENTO(POS PAGO)
    plano->verificaData(timestamp);

    double custo;
    custo = duracao*plano->getValorMinuto();

    // VERIFICA CREDITO CELULAR PRE PAGO
    PosPago* ptr_plano = dynamic_cast<PosPago*>(plano);
    if( ptr_plano == nullptr){ 
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

    // PLANO NAO POSSUI ASSINATURA DE DADOS
    if(franquia == 0){
        throw exception::exception();
    }

    if(franquiaGasta > franquia){
        if(td == download){ // DOWNLOAD
            custo = plano->getVelocAlem*duracao;
        }else{ // UPLOAD
            custo = plano->getVelocAlem*0.1*duracao;
        }
    }else{ // FRANQUIA TOTALMENTE CONSUMIDA, VELOCIDADE DE DOWNLOAD REDUZIDA
        if(td == download){ // DOWNLOAD
            custo = plano->getVelocidade*duracao;
        }else{ // UPLOAD
            custo = plano->getVelocidade*0.1*duracao;
        }
    }
    // ATUALIZA FRANQUIA GASTA
    plano->setFranquiaGasta(custo);
    
    // FAZ LIGACAO
    LigacaoDados l(timestamp, duracao, custo, td);
    ligacoes.push_back(l);
}