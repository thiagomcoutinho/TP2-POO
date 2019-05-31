#include<ncurses.h>

using namespace std;

int main(int argc, char **arvg){

    // initilizes the screen
    // sets up memory and clears the screen
    initscr();

    int x, y;
    x = y = 10;

    // moves the cursos to the specified location
    move(y, x);

    //prints a string(const char *) to a window
    printw("Hello world\n");

    // print o lugar especifico, sem necessidade de usar o move() antes.
    mvprintw(11, 10, "TESTE");

    // Y --> Colunas verticais saindo do 0(canto superior)
    // X --> Linhas horizontais saindo do 0(canto esquerdo)

    //refreshes the screen to match whats in memory
    refresh();

    // whats for user input, returns int value of that key
    int c = getch(); // Esta em ASC II -->  Tem que fazer a funcao de conversao de ASCII para numeros/chars
    // clears the screen
    clear();

    // GET STRING FUNCTION
    /*
    std::string getstring()
    {
        std::string input;

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
    }*/


    move(0, 0);
    printw("%d", c);
    refresh();

    getch();

    endwin();
    // deallocates memory and ends ncurses

    return 0;
}