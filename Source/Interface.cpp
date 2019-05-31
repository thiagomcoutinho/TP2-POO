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
        informaVencimentos();
        break;
    case 110:
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
    print("m. Informe de Vencimentos");
    y++;
    print("n. Limite de Franquia");
    y++;
    print("Pressione q para sair");
    y++;
    print("Escolha uma opcao: ");
    refresh();
}

void Interface::menuCadastroCliente(){

}

void Interface::menuCadastroPlano(){

}

void Interface::menuCadastroCelular(){

}

void Interface::menuAdicionaCreditos(){

}

void Interface::menuRegistraLigacaoS(){

}

void Interface::menuRegistraLigacaoD(){

}

void Interface::listaDadosPacote(){

}

void Interface::listaValorConta(){

}

void Interface::listaCreditos(){

}

void Interface::listaExtratoS(){

}

void Interface::listaExtratoD(){

}

void Interface::listaClientes(){

}

void Interface::informaVencimentos(){

}

void Interface::informaLimiteFranquia(){

}