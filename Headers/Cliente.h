#include<Headers/Celular.h>
#include<vector>
#include<string>

using namespace std;

class Cliente{

    private:
        string CPF;
        string nome;
        string endereco;
        vector<Celular> celulares;

    public:
        Cliente(int _cpf, string _nome, string _endereco);
        ~Cliente();
        void addCelular(Celular c);
        void efetuarLigacao(int celularIndex, Date timestamp, double duracao);
};