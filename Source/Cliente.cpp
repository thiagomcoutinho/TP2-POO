#include<Headers/Cliente.h>

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

// DUVIDA: Construtor que recebe vetor de celulares tambem?

// Celular Pos-Pago
void Cliente::addCelular(string nomePlano, double vlrMinuto, double _franquia, double _velAlem, Date vencimento){
    PosPago p(nomePlano, vlrMinuto, _franquia, _velAlem, vencimento);
    Celular newCel(*this, p);
}

// Celular Pre-Pago
void Cliente::addCelular(string nomePlano, double vlrMinuto, double _franquia, double _velAlem, Date curr_date, double credito){
    PrePago p(nomePlano, vlrMinuto, _franquia, _velAlem, credito, curr_date);
    Celular newCel(*this, p);
}

/*
void Celular::efetuarLigacao(Date timestamp, double duracao, double numTel){

    /* TODO: Verificar se o plano é da classe 
        PosPago. Caso verdadeiro throw exception.

        TYPE* dynamic_cast<TYPE*> (object); --> Retorna NULL. (TESTAR)
    */

    /* TODO: Verificar se o plano é da classe 
        PosPago e entao utilizar a data de vencimento.
    */

    /*
        TODO: Verificar o plano atual e se a ligacao pode
        ser feita. Caso possivel, execute abaixo. Caso contrario,
        throw exception.
    */
    
    /*
    double custo = duracao*plano->getValorMinuto();
    LigacaoSimples l(timestamp, duracao, custo, numTel);
    ligacoes.push_back(l);
} 

void Celular::efetuarLigacao(Date timestamp, double duracao, tipoDados td){

    double franquia = plano->getFranquia();

} */