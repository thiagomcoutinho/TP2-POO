#include "./../Headers/Celular.h"

double Celular::proxNumCelular = 0;

Celular::Celular(){}

Celular::Celular(Cliente* c, Plano* p){
    plano = p;
    cliente = c;
    numero = getProxNumCelular();
    incrementProxNumCelular();
}

Celular::~Celular(){}

// LIGACAO SIMPLES
void Celular::ligar(const Date& timestamp, const double& duracao, const double& numTel){
    double custo;
    custo = duracao*plano->getValorMinuto(); // CALCULA O CUSTO DA LIGACAO

    PosPago* ptr_plano = dynamic_cast<PosPago*>(plano); // VERIFICA QUAL TIPO DE PLANO
    if( ptr_plano == nullptr){ 
        plano->verificaData(timestamp); // VERIFICA VALIDADE DOS CREDITOS
        plano->verificaCredito(custo);  // VERIFICA CREDITO CELULAR PRE PAGO
    }
    plano->cobraCusto(custo); // COBRA CUSTO

    Ligacao* l = new LigacaoSimples(timestamp, duracao, custo, numTel); // LIGA
    ligacoes.push_back(l);
}

// LIGACAO DADOS
bool Celular::ligar(const Date& timestamp, const double& duracao, const tipoDados& td){
    
    double franquia = plano->getFranquia();
    double franquiaGasta = plano->getFranquiaGasta();
    double custo, diff_franquia, duracao_ate_franquia;
    bool informaFranquiaExcedida = false;

    if(franquia == 0){ // O PLANO NAO POSSUI ASSINATURA DE DADOS
        throw Excecao("O plano atual nao possui franquia de dados");
    }

    if(franquiaGasta > franquia){ // FRANQUIA TOTALMENTE CONSUMIDA, VELOCIDADE DE DOWNLOAD REDUZIDA
        if(td == download){ // DOWNLOAD
            custo = plano->getVelocAlem()*duracao;
        }else{ // UPLOAD
            custo = plano->getVelocAlem()*(0.1)*duracao;
        }
    }else{ // AINDA TEM FRANQUIA PARA SER GASTA
        if(td == download){ // DOWNLOAD
            custo = plano->getVelocidade()*duracao;
            if(franquiaGasta + custo > franquia){ // O CUSTO DA LIGACAO EXCEDE A FRANQUIA
                diff_franquia = franquia - franquiaGasta;
                duracao_ate_franquia = diff_franquia/plano->getVelocidade();
                // CUSTO COMPOSTO
                custo = plano->getVelocidade()*(duracao_ate_franquia) + (duracao-duracao_ate_franquia)*plano->getVelocAlem(); 
                informaFranquiaExcedida = true;
            }
        }else{ // UPLOAD
            custo = plano->getVelocidade()*0.1*duracao;
            if(franquiaGasta + custo > franquia){
                diff_franquia = franquia - franquiaGasta;
                duracao_ate_franquia = diff_franquia/plano->getVelocidade();
                // CUSTO COMPOSTO
                custo = plano->getVelocidade()*(duracao_ate_franquia)*(0.1) + (duracao-duracao_ate_franquia)*plano->getVelocAlem()*(0.1); 
                informaFranquiaExcedida = true;
            }   
        }
    }
    // ATUALIZA FRANQUIA GASTA
    plano->setFranquiaGasta(custo);
    
    // LIGA
    Ligacao* l = new LigacaoDados(timestamp, duracao, custo, td);
    ligacoes.push_back(l);

    return(informaFranquiaExcedida);
}