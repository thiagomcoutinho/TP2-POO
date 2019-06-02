#include "./Headers/Interface.h"

using namespace std;

int main(int argc, char **arvg){

    Interface i;

    i.getString();



    /*
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

    move(0, 0);
    printw("%d", c);
    refresh();

    getch();

    endwin();
    // deallocates memory and ends ncurses

    /* FUNCAO DE SALVAR E LER OBJETOS ( SALVAR UM VECTOR, MELHOR )


        // C++ program to demonstrate read/write of class 
        // objects in C++. 
        #include <iostream> 
        #include <fstream> 
        using namespace std; 
        
        // Class to define the properties 
        class Contestant { 
        public: 
            // Instance variables 
            string Name; 
            int Age, Ratings; 
        
            // Function declaration of input() to input info 
            int input(); 
        
            // Function declaration of output_highest_rated() to 
            // extract info from file Data Base 
            int output_highest_rated(); 
        }; 
        
        // Function definition of input() to input info 
        int Contestant::input() 
        { 
            // Object to write in file 
            ofstream file_obj; 
        
            // Opening file in append mode 
            file_obj.open("Input.txt", ios::app); 
        
            // Object of class contestant to input data in file 
            Contestant obj; 
        
            // Feeding appropriate data in variables 
            string str = "Micheal"; 
            int age = 18, ratings = 2500; 
        
            // Assigning data into object 
            obj.Name = str; 
            obj.Age = age; 
            obj.Ratings = ratings; 
        
            // Writing the object's data in file 
            file_obj.write((char*)&obj, sizeof(obj)); 
        
            // Feeding appropriate data in variables 
            str = "Terry"; 
            age = 21; 
            ratings = 3200; 
        
            // Assigning data into object 
            obj.Name = str; 
            obj.Age = age; 
            obj.Ratings = ratings; 
        
            // Writing the object's data in file 
            file_obj.write((char*)&obj, sizeof(obj)); 
        
            return 0; 
        } 
        
        // Function definition of output_highest_rated() to 
        // extract info from file Data Base 
        int Contestant::output_highest_rated() 
        { 
            // Object to read from file 
            ifstream file_obj; 
        
            // Opening file in input mode 
            file_obj.open("Input.txt", ios::in); 
        
            // Object of class contestant to input data in file 
            Contestant obj; 
        
            // Reading from file into object "obj" 
            file_obj.read((char*)&obj, sizeof(obj)); 
        
            // max to store maximum ratings 
            int max = 0; 
        
            // Highest_rated stores the name of highest rated contestant 
            string Highest_rated; 
        
            // Checking till we have the feed 
            while (!file_obj.eof()) { 
                // Assigning max ratings 
                if (obj.Ratings > max) { 
                    max = obj.Ratings; 
                    Highest_rated = obj.Name; 
                } 
        
                // Checking further 
                file_obj.read((char*)&obj, sizeof(obj)); 
            } 
        
            // Output is the highest rated contestant 
            cout << Highest_rated; 
            return 0; 
        } 
        
        // Driver code 
        int main() 
        { 
            // Creating object of the class 
            Contestant object; 
        
            // Inputting the data 
            object.input(); 
        
            // Extracting the max rated contestant 
            object.output_highest_rated(); 
        
            return 0; 
        } 


    */

    return 0;
}