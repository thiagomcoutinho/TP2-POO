#ifndef DATE
#define DATE

class Date{

    private:
        int seg;
        int min;
        int hora;
        int dia;
        int mes;
        int ano;

    public:
        Date();
        Date(int _ano, int _mes, int _dia);
        Date(int _hora, int _min, int _seg, int aux);
        ~Date();

        void acrescentaTempo();
        Date operator > (const Date& b);
};
#endif