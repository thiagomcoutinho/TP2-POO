#include "./../Headers/Celular.h"

#include<iostream>

double Celular::proxNumCelular = 0;

Celular::Celular(){
}

Celular::Celular(Cliente* c, Plano* p){
    plano = p;
    cliente = c;
    numero = getProxNumCelular();
    incrementProxNumCelular();
}

Celular::~Celular(){
}

// LIGACAO SIMPLES
void Celular::ligar(Date& timestamp, double& duracao, double& numTel){
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
    Ligacao* l = new LigacaoSimples(timestamp, duracao, custo, numTel);

    ligacoes.push_back(l);
}

// LIGACAO DADOS
bool Celular::ligar(double duracao, tipoDados td, Date timestamp){
    
    double franquia = plano->getFranquia();
    double franquiaGasta = plano->getFranquiaGasta();
    double custo, diff_franquia, duracao_ate_franquia;
    bool informaFranquiaExcedida = false;

    // PLANO NAO POSSUI ASSINATURA DE DADOS
    if(franquia == 0){
        throw Excecao("O plano atual nao possui franquia de dados");
    }

    if(franquiaGasta > franquia){ // FRANQUIA TOTALMENTE CONSUMIDA, VELOCIDADE DE DOWNLOAD REDUZIDA
        if(td == download){ // DOWNLOAD
            custo = plano->getVelocAlem()*duracao;
        }else{ // UPLOAD
            custo = plano->getVelocAlem()*(0.1)*duracao;
        }
    }else{
        if(td == download){ // DOWNLOAD
            custo = plano->getVelocidade()*duracao;
            if(franquiaGasta + custo > franquia){
                diff_franquia = franquia - franquiaGasta;
                duracao_ate_franquia = diff_franquia/plano->getVelocidade();
                custo = plano->getVelocidade()*(duracao_ate_franquia) + (duracao-duracao_ate_franquia)*plano->getVelocAlem(); 
                informaFranquiaExcedida = true;
            }
        }else{ // UPLOAD
            custo = plano->getVelocidade()*0.1*duracao;
            if(franquiaGasta + custo > franquia){
                diff_franquia = franquia - franquiaGasta;
                duracao_ate_franquia = diff_franquia/plano->getVelocidade();
                custo = plano->getVelocidade()*(duracao_ate_franquia)*(0.1) + (duracao-duracao_ate_franquia)*plano->getVelocAlem()*(0.1); 
                informaFranquiaExcedida = true;
            }   
        }
    }
    // ATUALIZA FRANQUIA GASTA
    plano->setFranquiaGasta(custo);
    
    // FAZ LIGACAO
    Ligacao* l = new LigacaoDados(timestamp, duracao, custo, td);
    ligacoes.push_back(l);

    return(informaFranquiaExcedida);
}