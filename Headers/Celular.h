#include<Headers/Plano.h>
#include<Headers/Ligacao.h>

class Celular{

    private:
        double numero;
        Cliente cliente;
        Plano* plano;
        vector<Ligacao> ligacoes;
        static double proxNumCelular;

    public:
        Celular(Cliente c, Plano& p);
        Celular(Cliente c, Plano& p, Date vencimento);
        ~Celular();



};
static double proxNumCelular = 0;