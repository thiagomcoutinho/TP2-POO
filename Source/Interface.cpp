#include "./../Headers/Interface.h"

Interface::Interface(){
    // Inicializa tela
    initscr();
    // Posicoes do cursor
    x = y = 10;
    // Cria menu inicial
    menuInicial();
}

Interface::~Interface(){
    endwin();
}

void Interface::menuInicial(){

    mvprintw(y, x, "TESTE");
    refresh();

    // PARA FAZER OS INPUTS NO LUGAR CERTO.
    move(y+1, x);

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