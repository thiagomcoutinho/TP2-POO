#include "./../Headers/Interface.h"

void Interface::print(const char* text, bool breakLine = true){
    mvprintw(y, x, text);
    if(breakLine){
        y++;
        x = 5;
    }else{
        string s_text(text);
        x += s_text.size();
    }
}

Interface::Interface(){
    // Inicializa tela
    initscr();
    // Posicoes do cursor
    x = y = 5;
    
    int c = 0;
    int b, erro;

    int a = -1;
    while(a == -1){
        try{
            setMenu();

            print("///// OPERADORA TELEFONICA CONAUT /////");
            print("ENTRE COM A DATA ATUAL(dd-mm-yyyy): ", false);
            getString();
            data_atual = input;

            a = 1;
        }catch (Excecao e){
            string excecao = e.getExcecao();
            setMenu();
            print("ERRO: ", false);
            print(excecao.c_str());
            print("OPERACAO CANCELADA!");
            print("Aperte qualquer tecla para tentar novamente");
            erro = getch();

            refresh();
        }
    }
    
    //informaVencimentos();
    //informaLimiteFranquia();

    // Cria menu inicial
    menuInicial();
    // Loop infinito ate que o cliente saia da aplicacao
    while(c != 113){ // 'q' quit
        c = getch();
        if(c == 113){break;}

        b = getch(); // VARIAVEL AUXILIAR PARA ENTRADA
        if(c != 113){
            try{
                switchMenu(c);
            }catch (Excecao e){
                string excecao = e.getExcecao();
                setMenu();
                print("ERRO: ", false);
                print(excecao.c_str());
                print("OPERACAO CANCELADA!");
                print("Aperte qualquer tecla para retornar ao menu principal");
                erro = getch();

                refresh();
                menuInicial();
            }
        }
    }
}

Interface::~Interface(){

    map<std::string, Plano*>::iterator it_planos;

    for(it_planos = planos.begin(); it_planos != planos.end(); it_planos++){
        delete it_planos->second;
    }

    for(int i=0; i<ptr_celulares.size(); i++){
        delete ptr_celulares[i];
    }
    endwin();
}

void Interface::setMenu(){
    y = x = 5;
    clear();
    refresh();
}

void Interface::getString(){
    nocbreak();
    echo();

    input.clear();

    int ch = getch();

    while ( ch != '\n' )
    {
        input.push_back( ch );
        ch = getch();
    }
}

Celular* Interface::getCelular(int numeroCelular){

    Celular* c;

    if(numeroCelular < ptr_celulares.size() && numeroCelular >= 0){
        c = ptr_celulares[numeroCelular];
    }else{
        throw Excecao("Numero de celular inexistente!");
    }

    return(c);
}

void Interface::switchMenu(int option){

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
            atualizaDataAtual();
            break;
        default:
            throw Excecao("Opcao invalida");
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
    print("o. Atualizar data atual");
    print("Pressione q para sair");
    print("Escolha uma opcao: ");

    refresh();
}

void Interface::menuCadastroCliente(){

    string nome, CPF, endereco;

    setMenu();

    print("///// MENU DE CADASTRO DE CLIENTES /////");
    
    print("ENTRE COM OS DADOS DO CLIENTE: ");
    print("NOME DO CLIENTE: ");
    getString();
    nome = input;
    print("ENDERECO: ");
    getString();
    endereco = input;
    print("CPF/CNPJ: ");
    getString();
    CPF = input;

    // CRIA CLIENTE
    Cliente* c = new Cliente(CPF, nome, endereco);

    clientes.push_back(c);

    print("Cliente cadastrado com sucesso.");
    print("Pressione qualquer tecla para sair");
    int z = getch();

    refresh();
    menuInicial();
}

void Interface::menuCadastroPlano(){

    setMenu();

    Date vencimento_ou_validade;

    string nome_plano;
    double vlrMinuto, franquia, veloc, velocAlem, credito;
    Plano* p;

    print("///// MENU DE CADASTRO DE PLANOS /////");
    print("NOME DO PLANO: ");
    getString();
    nome_plano = input;
    print("VALOR DO MINUTO(REAIS): ");
    getString();
    vlrMinuto = stod(input);
    print("VELOCIDADE DO PACOTE DE DADOS(Mbps): ");
    getString();
    veloc = stod(input);
    print("FRANQUIA(Mb): ");
    getString();
    franquia = stod(input);
    print("VELOCIDADE ALEM DA FRANQUIA(Mbps): ");
    getString();
    velocAlem = stod(input);
    print("TIPO DO PLANO(PosPago ou PrePago): ");
    getString();
    if(input == "PosPago"){ // Pós-Pago
        vencimento_ou_validade = "01-01-0000";
        p = new PosPago(nome_plano, vlrMinuto, franquia, velocAlem, veloc, vencimento_ou_validade);
    }else if(input == "PrePago"){ // Pŕe-Pago
        vencimento_ou_validade = "01-01-0000";

        p = new PrePago(nome_plano, vlrMinuto, franquia, velocAlem, veloc, 0, vencimento_ou_validade);
    }else{
        throw Excecao("Tipo de plano nao existente!");
    }
    planos.insert(make_pair(nome_plano, p));

    print("Plano cadastrado com sucesso.");

    print("Pressione qualquer tecla para sair");
    int z = getch();

    refresh();
    menuInicial();
}

void Interface::menuCadastroCelular(){

    Date vencimento_ou_validade;
    Cliente* ptr_cliente;
    Celular* ptr_celular;
    string nome_plano;
    double n_cliente, vlr_minuto, franquia, velocAlem, veloc, credito;

    setMenu();

    print("///// MENU DE CADASTRO DE CELULARES /////");
    print("NUMERO DO CLIENTE(A PARTIR DE 0): ");
    getString();
    n_cliente = stoi(input);
    if(n_cliente < clientes.size() && n_cliente >= 0){
        ptr_cliente = clientes[n_cliente];
    }else{
        throw Excecao("Numero de cliente nao existente!");
    }

    print("NOME DO PLANO: ");
    getString();
    nome_plano = input;
    if(planos.find(nome_plano) == planos.end()){
        throw Excecao("Plano inexistente");
    }else{
        Plano* p = planos.find(nome_plano)->second;
        PosPago* ptr_posPago = dynamic_cast<PosPago*>(p);

        vlr_minuto = p->getValorMinuto();
        franquia = p->getFranquia();
        velocAlem = p->getVelocAlem();
        veloc = p->getVelocidade();
        if(ptr_posPago != nullptr){ // Pós-Pago
            print("DATA DE VENCIMENTO: ");
            getString();
            vencimento_ou_validade = input;
            ptr_cliente->addCelular(nome_plano, vlr_minuto, franquia, velocAlem, veloc, vencimento_ou_validade);
        }else{ // Pre-Pago
            print("CREDITO INICIAL: ");
            getString();
            credito = stod(input);
            vencimento_ou_validade = data_atual;
            ptr_cliente->addCelular(nome_plano, vlr_minuto, franquia, velocAlem, veloc, vencimento_ou_validade, credito);
        }
    }
    vector<Celular*> celulares_cliente = ptr_cliente->getCelulares();
    ptr_celular = celulares_cliente[celulares_cliente.size()-1];
    ptr_celulares.push_back(ptr_celular);

    print("Celular cadastrado com sucesso.");

    print("Pressione qualquer tecla para sair");
    int z = getch();

    refresh();
    menuInicial();
}

void Interface::menuAdicionaCreditos(){

    double creditos;
    int numeroCelular;
    Date validade;

    setMenu();

    print("///// MENU DE CREDITOS /////");
    print("NUMERO DO CELULAR(A PARTIR DE 0): ");
    getString();
    numeroCelular = stoi(input);
    Celular* c = getCelular(numeroCelular);

    print("VALOR DE CREDITOS: ");
    getString();
    creditos = stod(input);

    validade = data_atual;

    Plano* p = c->getPlano();
    PrePago* sub_p = dynamic_cast<PrePago*> (p);

    if(sub_p != nullptr){
        sub_p->adicionaCreditos(creditos, data_atual);
    }else{
        throw Excecao("O celular escolhido nao possui plano Pre Pago!");
    }

    print("Creditos adicionados.");
    
    print("Pressione qualquer tecla para sair");
    int z = getch();

    refresh();
    menuInicial();
}

void Interface::menuRegistraLigacaoS(){

    int numeroCelular;
    Date data_ligacao;
    double duracao, telefone;

    setMenu();

    print("///// MENU DE REGISTRO DE LIGACOES SIMPLES /////");
    print("CELULAR: ");
    getString();
    numeroCelular = stoi(input);
    Celular* c = getCelular(numeroCelular);

    print("DATA: ");
    getString();
    data_ligacao = input;
    print("DURACAO(MIN): ");
    getString();
    duracao = stod(input);
    print("# TELEFONE: ");
    getString();
    telefone = stod(input);
    
    c->ligar(data_ligacao, duracao, telefone);

    print("Ligacao efetuada.");

    print("Pressione qualquer tecla para sair");
    int z = getch();

    refresh();
    menuInicial();
}

void Interface::menuRegistraLigacaoD(){

    tipoDados td;
    int numeroCelular;
    Date data_ligacao;
    double duracao;
    bool informaFranquiaExcedida;

    setMenu();

    print("///// MENU DE REGISTRO DE LIGACOES DE DADOS /////");
    print("CELULAR: ");
    getString();
    numeroCelular = stoi(input);
    Celular* c = getCelular(numeroCelular);

    print("DATA: ");
    getString();
    data_ligacao = input;
    print("DURACAO(MIN): ");
    getString();
    duracao = stod(input);
    print("TIPO(download ou upload): ");
    getString();
    if(input == "download"){
        td = download;
    }else if(input == "upload"){
        td = upload;
    }else{
        throw Excecao("Tipo de dados incorreto!");
    }

    informaFranquiaExcedida = c->ligar(duracao, td, data_ligacao);

    print("Ligacao efetuada.");

    print("Pressione qualquer tecla para sair");
    int z = getch();

    if(informaFranquiaExcedida){
        refresh();
        informaLimiteFranquia(c);
    }else{
        refresh();
        menuInicial();
    }
}

void Interface::listaDadosPacote(){

    int numeroCelular;
    string aux;

    setMenu();
    
    print("///// CONSULTA DE DADOS DO PACOTE /////");
    print("CELULAR: ");
    getString();
    numeroCelular = stoi(input);
    Celular* c = getCelular(numeroCelular);

    Plano* p = c->getPlano();

    print("FRANQUIA: ", false);
    aux = to_string(p->getFranquia());
    print(aux.c_str());
    print("FRANQUIA GASTA: ", false);
    aux = to_string(p->getFranquiaGasta());
    print(aux.c_str());
    print("VELOCIDADE ATUAL: ");

    print("DOWNLOAD: ", false);

    if(p->getFranquiaGasta() > p->getFranquia()){ // FRANQUIA TOTALMENTE GASTA, VELOCIDADE REDUZIDA
        aux = to_string(p->getVelocAlem());
        print(aux.c_str());

        aux = to_string(p->getVelocAlem()*0.1);
        print("UPLOAD: ", false);
        print(aux.c_str());
    }else{ // FRANQUIA DISPONIVEL, VELOCIDADE CONTRATADA
        aux = to_string(p->getVelocidade());
        print(aux.c_str());

        aux = to_string(p->getVelocidade()*0.1);
        print("UPLOAD: ", false);
        print(aux.c_str());
    }

    print("Pressione qualquer tecla para sair");
    int z = getch();

    refresh();
    menuInicial();
}

void Interface::listaValorConta(){

    int numeroCelular;
    vector<int> limitesMes;
    vector<Ligacao*> ligacoes;
    Date data_ligacao;
    double valorConta = 0;

    setMenu();

    print("///// CONSULTA DE CONTAS /////");
    print("CELULAR : ");
    getString();
    numeroCelular = stoi(input);

    Celular* c = getCelular(numeroCelular);

    Plano* p = c->getPlano();
    PosPago* sub_p = dynamic_cast<PosPago*> (p);

    if(sub_p != nullptr){ // Plano Pos-Pago
        limitesMes = data_atual.getLimitesMes();

        Date inicioMes(data_atual.getAno(), data_atual.getMes(), limitesMes[0]);
        Date fimMes(data_atual.getAno(), data_atual.getMes(), limitesMes[1]);

        ligacoes = c->getLigacoes();

        print(data_atual.convertDateToString(false).c_str());
        print(inicioMes.convertDateToString(false).c_str());
        print(fimMes.convertDateToString(false).c_str());
        refresh();

        for(int i=0; i<ligacoes.size(); i++){

            data_ligacao = ligacoes[i]->getDate();

            if(data_ligacao >= inicioMes && data_ligacao <= fimMes){
                print(data_ligacao.convertDateToString(false).c_str());
                refresh();
                valorConta += ligacoes[i]->getCusto();
            }
        }

        print("VALOR DA CONTA ATUAL EM ABERTO: ", false);
        print(to_string(valorConta).c_str());
    }else{
        throw Excecao("O celular escolhido nao possui plano pos pago!");
    }

    print("Pressione qualquer tecla para sair");
    int z = getch();

    refresh();
    menuInicial();
}

void Interface::listaCreditos(){

    int numeroCelular;
    string str_validade;
    double creditos;
    Date validade;

    setMenu();

    print("///// CONSULTA DE CREDITOS /////");
    print("CELULAR : ");
    getString();
    numeroCelular = stoi(input);

    Celular* c = getCelular(numeroCelular);

    Plano* p = c->getPlano();

    PrePago* sub_p = dynamic_cast<PrePago*> (p);

    if(sub_p != nullptr){ // Celular com plano PrePago
        validade = sub_p->getValidade();
        str_validade = validade.convertDateToString(false);
        creditos = sub_p->getCredito();
        print("CREDITOS DISPONIVEIS: ", false);
        print(to_string(creditos).c_str());
    }else{
        throw Excecao("O celular escolhido nao possui plano pre pago!");
    }

    print("Pressione qualquer tecla para sair");
    int z = getch();

    refresh();
    menuInicial();
}

void Interface::listaExtratoS(){

    int numeroCelular;
    Date data_inicial;
    Celular* c;
    int count = 0;
    LigacaoSimples* ls;

    setMenu();

    print("///// CONSULTA DE EXTRATO SIMPLES /////");
    print("CELULAR: ");
    getString();
    numeroCelular = stoi(input);
    c = getCelular(numeroCelular);
    print("DATA INICIAL(dd-mm-yyyy): ");
    getString();
    data_inicial = input;

    vector<Ligacao*> vec_ligacoes = c->getLigacoes();

    for(int i=0; i<vec_ligacoes.size(); i++){
        
        ls = dynamic_cast<LigacaoSimples*> (vec_ligacoes[i]);
        if(ls != nullptr){
            if(ls->getDate() >= data_inicial){
            count++;
            print("///// LIGACAO #", false);
            print(to_string(count).c_str(), false);
            print(" /////");
            print("DATA: ", false);
            print(ls->getDate().convertDateToString(false).c_str());
            print("DURACAO: ", false);
            print(to_string(ls->getDuracao()).c_str());
            print("VALOR: ", false);
            print(to_string(ls->getCusto()).c_str());
            }
        }
    }

    print("Pressione qualquer tecla para sair");
    int z = getch();

    refresh();
    menuInicial();
}

void Interface::listaExtratoD(){

    int numeroCelular;
    Date data_inicial;
    Celular* c;
    int count = 0;
    LigacaoDados* ld;

    setMenu();

    print("///// CONSULTA DE EXTRADO DE DADOS /////");
    print("CELULAR: ");
    getString();
    numeroCelular = stoi(input);
    c = getCelular(numeroCelular);
    print("DATA INICIAL(dd-mm-yyyy): ");
    getString();
    data_inicial = input;

    vector<Ligacao*> vec_ligacoes = c->getLigacoes();

    for(int i=0; i<vec_ligacoes.size(); i++){
        ld = dynamic_cast<LigacaoDados*> (vec_ligacoes[i]);
        if(ld != nullptr){
            if(ld->getDate() >= data_inicial){
            count++;
            print("");
            print("///// LIGACAO #", false);
            print(to_string(count).c_str(), false);
            print(" /////");
            print("DATA: ", false);
            print(ld->getDate().convertDateToString(false).c_str());
            print("DURACAO: ", false);
            print(to_string(ld->getDuracao()).c_str());
            print("TIPO: ", false);
            if(ld->getTipoDados() == download){
                print("DOWNLOAD");
            }else{
                print("UPLOAD");
            }
            print("QUANTIDADE CONSUMIDA: ", false);
            print(to_string(ld->getCusto()).c_str());
            }
        }
    }

    print("Pressione qualquer tecla para sair");
    int z = getch();

    refresh();
    menuInicial();
}

void Interface::listaClientes(){

    setMenu();

    vector<Celular*> aux;

    for(int i=0; i<clientes.size(); i++){
        print("///// Cliente #", false);
        print(to_string(i).c_str(), false);
        print(" /////");
        print("CPF: ", false);
        print(clientes[i]->getCPF().c_str());
        print("NOME: ", false);
        print(clientes[i]->getNome().c_str());
        print("ENDERECO: ", false);
        print(clientes[i]->getEndereco().c_str());
        print("Numero de celulares: ", false);
        aux = clientes[i]->getCelulares();
        print(to_string(aux.size()).c_str());
    }

    print("Pressione qualquer tecla para sair");
    int z = getch();

    refresh();
    menuInicial();
}

void Interface::listaPlanos(){

    setMenu();

    map<string, Plano*>::iterator it;
    Plano* p;
    PosPago* pos;

    for(it = planos.begin(); it != planos.end(); it++){
        print("Nome do Plano: ", false);
        print(it->first.c_str());
        
        p = it->second;

        print("Valor do minuto: ", false);
        print(to_string(p->getValorMinuto()).c_str());
        print("Velocidade: ", false);
        print(to_string(p->getVelocidade()).c_str());
        print("FRANQUIA: ", false);
        print(to_string(p->getFranquia()).c_str());
        print("Velocidade alem do limite: ", false);
        print(to_string(p->getVelocAlem()).c_str());
        
        PosPago* pos = dynamic_cast<PosPago*> (p);
        if(pos != nullptr){ // Pos-Pago
            print("TIPO: POS PAGO");
        }else{ // PrePago
            print("TIPO: PRE PAGO");
        }
    }

    print("Pressione qualquer tecla para sair");
    int z = getch();

    refresh();
    menuInicial();
}

void Interface::listaCelulares(){

    setMenu();

    vector<Ligacao*> aux;
    Plano* p;
    string nome_plano;

    for(int i=0; i<ptr_celulares.size(); i++){
        print("NUMERO DO CELULAR: ", false);
        print(to_string(ptr_celulares[i]->getNumero()).c_str());

        aux = ptr_celulares[i]->getLigacoes();
        print("NUMERO DE LIGACOES: ", false);
        print(to_string(aux.size()).c_str()); 
        
        p = ptr_celulares[i]->getPlano();
        print("PLANO: ", false);
        print(p->getNomePlano().c_str());
    }

    print("Pressione qualquer tecla para sair");
    int z = getch();

    refresh();
    menuInicial();
}

void Interface::informaVencimentos(){

   setMenu();

    print("///// FATURAS VENCIDAS /////");

    Plano* p;
    PosPago* sub_p;
    Date vencimento;
    Cliente* c;
    Celular* curr_cel;
    string nome_cliente;

    for(int i = 0; i<ptr_celulares.size(); i++){

        curr_cel = ptr_celulares[i];

        p = curr_cel->getPlano();
        sub_p = dynamic_cast<PosPago*> (p);
        if(sub_p != nullptr){ // Plano Pos Pago
            vencimento = sub_p->getVencimento();
            if(data_atual > vencimento){
                
                c = curr_cel->getCliente();
                nome_cliente = c->getNome();
                print("Cliente: ", false);
                print(nome_cliente.c_str());
                print("Numero de celular: ", false);
                print(to_string(curr_cel->getNumero()).c_str());
                print("VALOR DO PLANO: ", false);
                print(to_string(sub_p->getValor()).c_str());
                print("DATA DE VENCIMENTO: ", false);
                print(vencimento.convertDateToString(false).c_str());
            }
        }
    }

    print("Pressione qualquer tecla para sair");
    int z = getch();

    refresh();
    menuInicial();
}

void Interface::informaLimiteFranquia(Celular* c){
    Cliente* cliente = c->getCliente();
    Plano* plano_celular = c->getPlano();

    setMenu();

    print("///// INFORME DE FRANQUIA EXCEDIDA /////");
    print("CLIENTE: ", false);
    print(cliente->getNome().c_str());
    print("CELULAR #", false);
    print(to_string(c->getNumero()).c_str());
    print("FRANQUIA DO PLANO: ", false);
    print(to_string(plano_celular->getFranquia()).c_str());
    print("FRANQUIA GASTA: ", false);
    print(to_string(plano_celular->getFranquiaGasta()).c_str());

    print("Pressione qualquer tecla para sair");
    int z = getch();

    refresh();
    menuInicial();
}

void Interface::atualizaDataAtual(){

    setMenu();

    print("///// ATUALIZACAO DE DATA /////");
    print("ENTRE COM A DATA ATUAL: ", false);
    getString();
    data_atual = input;

    print("");
    print("Data atualizada.");
    print("");

    print("Pressione qualquer tecla para sair");
    int z = getch();

    refresh();
    informaVencimentos();
}

// TO-DO: Exceções: Plano nao existente. Celular não existente. Cliente não existente.