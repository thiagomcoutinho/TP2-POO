#include "./../Headers/Interface.h"

Interface::Interface(){
    // Inicializa tela
    initscr();
    // Posicoes do cursor
    x = y = 5;
    
    int c = 0;
    int b;

    // Cria menu inicial
    menuInicial();
    // Loop infinito ate que o cliente saia da aplicacao
    while(c != 113){ // 'q' quit
        c = getch();
        if(c == 113){break;}

        b = getch(); // VARIAVEL AUXILIAR PARA ENTRADA
        if(c != 113){
            switchMenu(c);
        }
    }
}

Interface::~Interface(){
    endwin();
}

void Interface::print(const char* text, bool breakLine = true){
    mvprintw(y, x, text);
    if(breakLine){
        y++;
    }
}

void Interface::setMenu(){
    y = x = 5;
    clear();
}

void Interface::getString()
{
    nocbreak();
    echo();

    int ch = getch();

    while ( ch != '\n' )
    {
        input.push_back( ch );
        ch = getch();
    }
}

void Interface::switchMenu(int option){

    switch (option)
    {
        case 97:
            menuCadastroCliente(option);
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

    setMenu();

    print("///// OPERADORA TELEFONICA CONAUT /////");
    print("a. Cadastro de Clientes");
    print("b. Cadastro de Planos");
    print("c. Cadastro de Celulares");
    print("d. Adicionar Creditos");
    print("e. Registro de Ligacao Simples");
    print("f. Registro de Ligacao de Dados");
    print("g. Informacao de Pacote de Dados");
    print("h. Valor de Contas");
    print("i. Saldo de Creditos");
    print("j. Extrato de Ligacoes Simples");
    print("k. Extrato de Ligacoes de Dados");
    print("l. Lista de Clientes");
    print("m. Lista de Planos");
    print("n. Lista de Celulares");
    print("o. Informe de Vencimentos");
    print("p. Limite de Franquia");
    print("Pressione q para sair");
    print("Escolha uma opcao: ");

    refresh();
}

void Interface::menuCadastroCliente(int option){

    setMenu();

    print("///// MENU DE CADASTRO DE CLIENTES /////");
    
    print("ENTRE COM OS DADOS DO CLIENTE: ");
    print("NOME DO CLIENTE: ");
    getString();
    print("ENDERECO: ");
    getString();
    print("CPF/CNPJ: ");
    getString();
    
    refresh();

    // CRIA CLIENTE

    menuInicial();
}

void Interface::menuCadastroPlano(){

    setMenu();

    print("///// MENU DE CADASTRO DE PLANOS /////");
    print("NOME DO PLANO: ");
    getString();
    print("TIPO DO PLANO: ");
    getString();
    print("VALOR DO MINUTO: ");
    getString();
    print("VELOCIDADE DO PACOTE DE DADOS: ");
    getString();
    print("FRANQUIA: ");
    getString();
    print("VELOCIDADE ALEM DA FRANQUIA: ");
    getString();

    refresh();
    menuInicial();
}

void Interface::menuCadastroCelular(){

    setMenu();

    print("///// MENU DE CADASTRO DE CELULARES /////");
    print("NUMERO DO CLIENTE: ");
    getString();
    print("NOME DO PLANO: ");
    getString();
    // IF PLANO É POS PAGO
    print("DATA DE VENCIMENTO: ");
    getString();
    
    refresh();
    menuInicial();
}

void Interface::menuAdicionaCreditos(){

    setMenu();

    print("///// MENU DE CREDITOS /////");
    print("NUMERO DO CELULAR: ");
    getString();
    print("VALOR DE CREDITOS: ");
    getString();
    
    refresh();
    menuInicial();
}

void Interface::menuRegistraLigacaoS(){

    setMenu();

    
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