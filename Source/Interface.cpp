#include "./../Headers/Interface.h"

Interface::Interface(){
    // Inicializa tela
    initscr();
    // Posicoes do cursor
    x = y = 5;
    
    int c = 0;

    // Cria menu inicial
    menuInicial();
    // Loop infinito ate que o cliente saia da aplicacao
    while(c != 113){ // 'q' quit
        c = getch();
        if(c != 113){
            switchMenu(c);
        }
    }
}

Interface::~Interface(){
    endwin();
}

void Interface::print(const char* text) const{
    mvprintw(y, x, text);
}

string Interface::getString()
{
    string input;

    // let the terminal do the line editing
    nocbreak();
    echo();

    // this reads from buffer after <ENTER>, not "raw" 
    // so any backspacing etc. has already been taken care of
    int ch = getch();

    while ( ch != '\n' )
    {
        input.push_back( ch );
        ch = getch();
    }

    // restore your cbreak / echo settings here
    return input;
}

void Interface::switchMenu(const char option){

    switch (option)
    {
    case 97:
        menuCadastroCliente();
        break;
    case 98:
        menuCadastroPlano();
        break;
    case 99:
        menuCadastroCelular();
        break;
    case 100:
        menuAdicionaCreditos();
        break;
    case 101:
        menuRegistraLigacaoS();
        break;
    case 102:
        menuRegistraLigacaoD();
        break;
    case 103:
        listaDadosPacote();
        break;
    case 104:
        listaValorConta();
        break;
    case 105:
        listaCreditos();
        break;
    case 106:
        listaExtratoS();
        break;
    case 107:
        listaExtratoD();
        break;
    case 108:
        listaClientes();
        break;
    case 109:
        listaPlanos();
        break;
    case 110:
        listaCelulares();
        break;
    case 111:
        informaVencimentos();
        break;
    case 112:
        informaLimiteFranquia();
        break;
    default:
        break;
    }
}

void Interface::menuInicial(){

    print("///// OPERADORA TELEFONICA CONAUT /////");
    y++;
    print("a. Cadastro de Clientes");
    y++;
    print("b. Cadastro de Planos");
    y++;
    print("c. Cadastro de Celulares");
    y++;
    print("d. Adicionar Creditos");
    y++;
    print("e. Registro de Ligacao Simples");
    y++;
    print("f. Registro de Ligacao de Dados");
    y++;
    print("g. Informacao de Pacote de Dados");
    y++;
    print("h. Valor de Contas");
    y++;
    print("i. Saldo de Creditos");
    y++;
    print("j. Extrato de Ligacoes Simples");
    y++;
    print("k. Extrato de Ligacoes de Dados");
    y++;
    print("l. Lista de Clientes");
    y++;
    print("m. Lista de Planos");
    y++;
    print("n. Lista de Celulares");
    y++;
    print("o. Informe de Vencimentos");
    y++;
    print("p. Limite de Franquia");
    y++;
    print("Pressione q para sair");
    y++;
    print("Escolha uma opcao: ");
    refresh();
}

void Interface::menuCadastroCliente(){
    // NOME
    // ENDERECO
    // CPF
}

void Interface::menuCadastroPlano(){
    // NOME
    // VALOR MINUTO
    // VELOCIDADE
    // FRANQUIA
    // VELOC ALEM
}

void Interface::menuCadastroCelular(){
    // CLIENTE
    // PLANO
    // DATA DE VENCIMENTO CASO POS PAGO
}

void Interface::menuAdicionaCreditos(){
    // VALOR CREDITOS
}

void Interface::menuRegistraLigacaoS(){
    // DATA
    // HORA
    // DURACAO
    // CUSTO
    // NUM TELEFONE
}

void Interface::menuRegistraLigacaoD(){
    // DATA
    // HORA
    // DURACAO
    // CUSTO
    // TIPO (DOWNLOAD || UPLOAD)
}

void Interface::listaDadosPacote(){
    // TO-DO: TEM QUE RESOLVER O CELULAR --> CLIENTE.
    // CELULAR
    // RETORNA SALDO DADOS
    // RETORNA VELOCIDADE ATUAL (DOWN E UP)
}

void Interface::listaValorConta(){
    // RECEBE CELULAR
    // VALOR TOTAL DAS LIGACOES APOS O DIA DE VENCIMENTO MES ANTERIOR
    // DIA DE VENCIMENTO 
}

void Interface::listaCreditos(){
    // RECEBE CELULAR
    // LISTA OS CREDITOS 
    // DATA DE VALIDADE DOS CREDITOS
}

void Interface::listaExtratoS(){
    // RECEBE CELULAR
    // RECEBE DATA
    // IMPRIME TODAS AS LIGACOES A PARTIR DA DATA
    // DURACAO
    // VALOR
    // DATA
}

void Interface::listaExtratoD(){
    // RECEBE CELULAR E DATA
    // CONSUMO DE DADOS A PARTIR DA DATA
    // IMPRIMIR DATA, DURACAO, TIPO, E QUANTIDADE CONSUMIDA.
}

void Interface::listaClientes(){
    // LISTA CLIENTES E INFORMACOES
}

void Interface::listaPlanos(){
    // LISTA PLANOS E INFORMACOEs
}

void Interface::listaCelulares(){
    // LISTA CELULARES E INFORMACOES
}

void Interface::informaVencimentos(){
    // SEMPRE QUE UMA FATURA OU CREDITO VENCER
    // INFORMAR AO USUARIO OS DADOS DO CLIENTE E CELULAR
}

void Interface::informaLimiteFranquia(){
    // QUANDO O CONSUMO DE DADOS ALCANCAR O VALOR
    // DA FRANQUIA, INFORMAR OS DADOS DO CLIENTE E CELULAR
}

// HASH TABLE(MAP) CELULAR --> CLIENTE.