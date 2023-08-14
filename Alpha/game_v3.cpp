#include <iostream>
#include <iomanip>
#include <charconv>

using namespace std;


// Converte um verbo em string para um em int
int Vcon(string verbo)
{
    int verbo_int;
    string verbo_v[6]={"ver", "usar", "pegar", "abrir", "entrar", "lutar"}; //vetor dos verbos
    for (int i = 0 ; i < 6; i++) {
        if (verbo == verbo_v[i]) {verbo_int = i + 1;};};

    return verbo_int;
}
// Converte um objeto em string para um em int
int Ocon(string obj, string obj_v[], int tam)
{
    int obj_int;
    for (int i = 0 ; i < tam; i++) {
        if (obj == obj_v[i]) {obj_int = i + 1;};};

    return obj_int;
}

void mensagem_quarto1(bool s_quadro, bool aux, int espelho_cont)
{
    if(espelho_cont==0)
    {
        cout<<R"(

)"<<endl;
    }
    if(s_quadro == false && aux)
    {
        cout<<R"(Na sala há os seguintes itens:
- guarda-roupa
- quadro
- espelho
- porta_norte
- porta_leste
- janela
(Você pode:
- ver
- abrir
- entrar))"<<endl;
    }
    else
    {
        cout<<R"(Na sala há os seguintes itens:
- guarda-roupa
- cofre
- espelho
- porta_norte
- porta_leste
- janela
)
(Você pode:
- ver
- usar
- abrir
- entrar))"<<endl;
    }
}

int quarto1(int espelho_cont, bool s_quadro, int lq)
{
    bool aux=false;
    string verbo, obj, aux_v, obj2;
    string obj_v[7]={"guarda-roupa", "quadro", "espelho", "porta_norte", "porta_leste", "janela"}; //Vetor dos Objetos da sala 1
    string gr_v[3]={"papel", "fruta", "lapis"}; //Vetor dos objetos do guarda-roupa

    if(s_quadro){obj_v[6]="cofre";};
    mensagem_quarto1(s_quadro, aux, espelho_cont);
    cout<<"O que deseja fazer?"<<endl;
    cin>>verbo;
    cin>>obj;
    switch(Vcon(verbo)) {
        case 1:
            {
                switch(Ocon(obj, obj_v, 7)){
                    case 1:
                        cout<<"\nO guarda-roupa é de madeira.\n"<<endl;
                        break;
                    case 2:
                        cout<<"\nVocê vê um quadro cubista, embora não entenda o que está representado o aprecia.\n"<<endl;
                        break;
                    case 3:
                        cout<<"\nVocê vê um espelho com uma moldura de ferro cafona.\n"<<endl;
                        break;
                    case 4:
                        cout<<"\nVocê vê uma porta grossa de ferro e percebe que não e possível derruba-la.\n"<<endl;
                        break;
                    case 5:
                        cout<<"\nVocê vê uma porta preta de madeira.\n"<<endl;
                        break;
                    case 6:
                        cout<<"\nVocê vê uma janela trancada com cadeado.\n"<<endl;
                        break;
                    case 7:
                        cout<<"\nVocê vê um cofre de ferro na parede.\n"<<endl;
                        break;
                    default:
                        cout<<"\nSua escolha é incosistente!\n"<<endl;
                        break;
                    }
            }
            break;
        case 2:
            {
                switch(Ocon(obj, obj_v, 7))
                {
                    case 3:
                        if(espelho_cont>=9)
                        {
                            cout<<"\nVocê usou o espelho e pelo reflexo percebeu que há algo estranho com o quadro"<<endl;
                            cout<<"Você percebeu que o quadro não estava rente à parede e decide retira-lo, ao fazer isso um cofre é descoberto.\n"<<endl;
                            aux = true;
                        }
                        else
                        {
                            cout<<"\nVocê usou o espelho e se viu.\n"<<endl;
                        }
                        break;
                    default:
                        cout<<"\nSua escolha é incosistente!\n"<<endl;
                        break;
                }
            }
            break;
        case 4:
            {
                switch(Ocon(obj, obj_v, 7))
                {
                    case 1:
						cout<<R"(
No guarda-roupas há os seguintes itens:
- papel
- fruta
- lapiz
(Você pode:
- ver))"<<endl;
                        cin>>verbo;
                        cin>>obj2;
                        switch(Vcon(verbo))
                        {
							case 1:
								{
									switch(Ocon(obj2, gr_v, 3))
									{
										case 1:
											cout<<"\nVocê vê uma carta endereçada à você.\n"<<endl;
											cout<<R"(“Ethan, se você está lendo esta carta, é porque finalmente decidimos colocar um ponto final em toda essa farsa.
Suas ações traiçoeiras e egoístas nos mostraram seu verdadeiro caráter.
Não importa quantos anos compartilhamos juntos, você conseguiu destruir a confiança que tínhamos em você.
Suas mentiras e manipulações nos fizeram questionar tudo o que acreditávamos ser verdade.
Sua hipocrisia é nauseante, pois você sempre se apresentou como um membro leal e dedicado do grupo.
Agora vemos a sua verdadeira face.
Esperamos sinceramente que você enfrente as consequências de suas escolhas e que siga daqui em diante sozinho.
Agora sabemos que Michael sempre teve razão sobre você!
Não temos mais nada a dizer para você.“
)"<<endl;
											break;
										case 2:
											cout<<"\nVocê vê uma laranja, mas percebe que é de plástico.\n"<<endl;
											break;
										case 3:
											cout<<"\nVocê vê um lápis quebrado.\n"<<endl;
											break;
										default:
											cout<<"\nEscolha Inconsistente\n"<<endl;
											break;
									}
								}
						}
                        break;
                    case 4:
                        cout<<"\nA porta norte está trancada.\n"<<endl;
                        break;
                    case 5:
                        cout<<"\nVocê abriu a Porta Leste e viu um quarto.\n"<<endl;
                        break;
                    case 7:
                        cout<<"\nVocê não conseguiu abrir o cofre pois está trancado.\n"<<endl;
                        break;
                    default:
                        cout<<"\nEscolha inconsistente.\n"<<endl;
                        break;
                }
            }
            break;
        case 5:
            {
                switch(Ocon(obj, obj_v, 7))
                {
                    case 5:
                        lq = 2;
                        break;
                    default:
						cout<<"\nSua escolha é inconsistente!\n"<<endl;
                }
            }
            break;
        default:
            cout<<"\nSua escolha é inconsistente.";
            break;
    }

    return lq;
}


int main()
{
    bool s_q3=false, s_q4=false, s_q5=false; //Determina se uma passagem para a determinada sala está aberta ou fechada
    bool win=false; //Determina se o jogador venceu ou não
    bool s_quadro = false;
    int lq = 1;
    int espelho_cont = 0;
    string inv[5];
    cout<<R"(Você acordou em um quarto escuro após levar um golpe na cabeça.
Após tatear as parede finalmente encontra um interruptor e consegue ascender a luz.
)"<<endl;
    while(win==false)
    {
        if(lq==1)
        {
            lq = quarto1(espelho_cont, s_quadro, lq);
            espelho_cont++;
            if(espelho_cont>=9){s_quadro=true;};
        }
        if(lq==2){cout<<"\nVocê entrou no quarto.\n"<<endl;};
    }
    return 0;
}