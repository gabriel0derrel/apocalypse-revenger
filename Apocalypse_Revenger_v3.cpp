#include <iostream>
#include <iomanip>

using namespace std;


bool win=false, gameover=false; //Determina se o jogador venceu ou não
bool denovo = true, denovo2=true, denovo3=true, denovo4=true;
bool quadro=false, alcapao=false, parede=false, quebrou=false;
int inv_tam=4;
string inv[4]={"","","",""};

//Verifica se um item está no vetor
bool esta_no_inv(string item, string v[], int tam)
{
    bool esta=false;
    for(int i=0; i<tam; i++)
    {
        if(v[i]==item)
        {
            esta=true;
        }
    }

    return esta;
}

// Converte um verbo em string para um em int
int Vcon(string verbo)
{
    int verbo_int;
    string verbo_v[8]={"ver", "usar", "pegar", "abrir", "entrar", "arrastar", "lutar", "quebrar"}; //vetor dos verbos
    for (int i = 0 ; i < 8; i++) {
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


void logo()
{
    cout<<R"(
   #
  # #   #####   ####   ####    ##   #      #   # #####   ####  ######
 #   #  #    # #    # #    #  #  #  #       # #  #    # #      #
#     # #    # #    # #      #    # #        #   #    #  ####  #####
####### #####  #    # #      ###### #        #   #####       # #
#     # #      #    # #    # #    # #        #   #      #    # #
#     # #       ####   ####  #    # ######   #   #       ####  ######

######
#     # ###### #    # ###### #    #  ####  ###### #####
#     # #      #    # #      ##   # #    # #      #    #
######  #####  #    # #####  # #  # #      #####  #    #
#   #   #      #    # #      #  # # #  ### #      #####
#    #  #       #  #  #      #   ## #    # #      #   #
#     # ######   ##   ###### #    #  ####  ###### #    #

)"<<endl;
}

void intro()
{
    cout<<R"(
    Há muito tempo, em 2025, um evento catastrófico abalou a humanidade.
Uma misteriosa e mortal forma de príon, conhecida como Nizumaycks, surgiu e
causou uma epidemia devastadora que se espalhou rapidamente pelo mundo. Ao
contrário dos vírus convencionais, os príons são partículas infecciosas
compostas apenas de proteínas anormais, que têm a capacidade de converter
proteínas saudáveis em mais príons, causando uma degeneração cerebral
progressiva. Isso levou as pessoas infectadas a um estado de insanidade e
canibalismo desenfreado, transformando-as em zumbis.
    Dez anos se passaram desde o início do apocalipse zumbi. Agora estamos
em 2035, e o mundo é um lugar sombrio e desolado. A sociedade se fragmentou,
e os sobreviventes restantes lutam diariamente para encontrar suprimentos e
manter-se vivos. Entre eles está Ethan, um homem corajoso de 25 anos que se
tornou um líder improvável em um grupo de sobreviventes.
    No entanto, nem tudo é o que parece. Michael, um dos membros do grupo de
Ethan, nutria um sentimento de inveja e ressentimento em relação a ele. Ethan
era habilidoso, corajoso e inspirador, o tipo de líder que Michael sempre
desejou ser. Consumido pela inveja, Michael começou a conspirar secretamente
contra Ethan.
    Um dia, Michael viu a oportunidade perfeita para colocar seu plano em
prática. Convenceu o grupo de sobreviventes de que Ethan era um fardo, um risco
para sua própria sobrevivência. Manipulando as palavras e exagerando algumas
situações, ele os convenceu de que a única maneira de garantir sua segurança
era expulsar Ethan do grupo e prendê-lo em uma casa abandonada.
)"<<endl;
}

void tutorial()
{
    cout<<R"(
(Atenção, a ação utiliza o padrão de Verbo e Objeto. Ao escrever a ação escreva
o objeto como aparece no menu.
Por exemplo:
[No lugar há:
- porta_norte
Você pode:
- ver]
assim a ação deve ser: [ver porta_norte] com underline entre porta e norte.
As exceções à essa regra serão indicadas.)
)"<<endl;
}

void prologo()
{
    cout<<R"(
Agora, Ethan esté livre e determinado a encontrar Michael e responsabilizá-lo
por sua traição. O mundo é vasto e perigoso, mas ele não tem medo. A vingança
pulsa em suas veias, alimentando sua determinação de sobreviver e lutar contra
os zumbis que infestam as ruas.
)"<<endl;
}


void mapa1()
{
    if(denovo && !quadro)
    {
        cout<<R"(
 =:::::::::::::::::+===========+::::::::::::::=
 =                 +-----------+              =
 =                  Porta Norte             +++
 =                                          + =
 +++                                Espelho + =
 = +                                        + =
 = + Quadro                                 +++
 = +                                          =
 +++                                          =
 -.                                           =
 -.                                           =
 :.                                           =
 :.                                           =
 :.                                         +++
 ::                                         + =
 .:                                         + =
 .=----+                        Porta leste + =
 .-    =                                    + =
  -    =                                    +++
  -    +Guarda-                               =
  -    +Roupa        Janela                   =
  =    =           +-------+                  =
  +::::+:::::::::::+=======+-:::::::::::::::::+
)"<<endl;
        denovo=false;
    }
    if(quadro && denovo)
    {
        cout<<R"(
 =:::::::::::::::::+===========+::::::::::::::=
 =                 +-----------+              =
 =                  Porta Norte             +++
 =                                          + =
 +++                                Espelho + =
 = +                                        + =
 = + Cofre                                  +++
 = +                                          =
 +++                                          =
 -.                                           =
 -.                                           =
 :.                                           =
 :.                                           =
 :.                                         +++
 ::                                         + =
 .:                                         + =
 .=----+                        Porta leste + =
 .-    =                                    + =
  -    =                                    +++
  -    +Guarda-                               =
  -    +Roupa        Janela                   =
  =    =           +-------+                  =
  +::::+:::::::::::+=======+-:::::::::::::::::+
)"<<endl;
        denovo = false;
    }

}

void mapa2()
{
    if(denovo2)
    {
        cout<<R"(
 =:::::::::::::=-:::::::::::::::::::::::::::::=
 =             :                              =
 =             : Cama                 :::::   =
 =.............:                  TV #    :   =
 =                                   #    :   =
 =                                    :::::   =
 =---+                                        =
 -   =                                      +++
 -   = Guarda-                        Porta + =
 -   = Roupa                          Leste + =
 -   =                                      + =
 :---+                                      + =
 :                                          +++
 +++                                          =
 = +                                          =
 = + Porta                                    =
 = + Oeste                               .....=
 = +                               Mesa =     =
 +++                                    =     =
 =                   Porta              =     =
 =                    Sul               =     =
 =                 +-------+            =     =
+::::::::::::::::::+=======+-:::::::::::+:::::+
)"<<endl;
        denovo2=false;
    }
}

void mapa3()
{
   if(denovo3 && !alcapao)
   {
        cout<<R"(
  =:::::::::::::::::::::=::::::::::::--::::-:::::::::::::::::::::-
  *                     +------------+.                          *
  *                       Porta Norte                            *
  +                                                              *
  *                                                              *
  *                                                              *
  *----*                                                         *
  *    *                                                         *
  +    *                                                         *
  *    * Armário 1                                             +:*
  +    *                                                       + *
  *    *                                           Porta Leste + *
  *    *                                                       + *
  *::::*                                                       + *
  +.                                                           =:*
  +.....                                                         *
  +:...*                                                         *
  +    *                                                         *
  =.   * Armário 2                                               *
  =.   *                                                         *
  =.   *                                                         *
  ==:::*                                                         *
  -:                                                             *
  -:                                                             *
  -:                                                        .....*
  -=:+                                                     =:....*
  :- =                                                     =.    +
  :- =  Porta Oeste                                        =.    *
  :- =                                           Armário 3 =.    *
  .+:+                                                     =.    *
  .=                                                       =.    *
  .=                                                       =.    *
   =:::::::::::::::::::::::::::::::::::::::::::::::::::::::=-::::-
)"<<endl;
        denovo3=false;
   }
   if(denovo3 && alcapao)
   {
        cout<<R"(
  =:::::::::::::::::::::=::::::::::::--::::-:::::::::::::::::::::-
  *                     +------------+.                          *
  *                       Porta Norte                            *
  +                                                              *
  *                                                              *
  *                                                              *
  *----*                                                         *
  *    *                                                         *
  +    *                                                         *
  *    * Armário 1                                             +:*
  +    *                                                       + *
  *    *                                          Porta Leste  + *
  *    *                                                       + *
  *::::*                                                       + *
  +.                                                           =:*
  +.....                                                         *
  +:...*                                                         *
  +    *                                                         *
  =.   * Armário 2                                               *
  =.   *                                                         *
  =.   *                                                         *
  ==:::*                                                         *
  -:                                                             *
  -:                                                             *
  -:                                  Armário 3                  *
  -=:+                                 *::::+:                   *
  :- =                                 *    -:                   +
  :- = Porta Oeste                     *    -:                   *
  :- =                                 *    -:             ......*
  .+:+                                 *    -:            :=.....*
  .=                                   *    -:    Alçapão :-     *
  .=                                   *    -:            :-     *
   =:::::::::::::::::::::::::::::::::::=::::--::::::::::::-=-::::-
)"<<endl;
        denovo3=false;
   }
}

void mapa4()
{
   if(denovo4 && !quebrou)
   {
        cout<<R"(
  =::::::::::::::-=:::::::::::::::::::::::::::::::::::::::--:::::-
  *               +                                       .=     +
  *               + Caixa                         Alçapão .=     +
  +               +                                       .+:::::+
  *::::::::::::::-+                                              *
  *                                                              *
  *                                                              *
  *                                                              *
  +                                                              *
  *                                                              *
  +                                                              *
  *:::::::-                                     Cadeira .        *
  *       +                                     ::::::*.*        *
  *       +                                     +     * *        *
  +       +                                     +     * *        *
  +       + Baú                                 *.....* *        *
  +       +                                     ......+-+        *
  +       +                                                      *
  =.      +                                                      *
  ==:::::::                                                      *
  =.                                                             *
  =:                                                             *
  -:                                                             *
  -:                                                             *
  -=--=                                                          *
  --  +                                                          *
  :-  +                                                          +
  :-  + Adega                                                    *
  :-  +                                                -**=:---::*
  .=..*                                              :%###++@*=. *
  .+...                                      Entulho #*@%@%*%@#=.*
  .=                           Parede                +:=*--%%=+#-*
   =:::::::::::::::::::::::::::::::::::::::::::::::::=-=::=-+--=:-
)"<<endl;
        denovo4=false;
   }
   if(denovo4 && quebrou)
   {
        cout<<R"(
  =::::::::::::::-=:::::::::::::::::::::::::::::::::::::::--:::::-
  *               +                                       .=     +
  *               + Caixa                         Alçapão .=     +
  +               +                                       .+:::::+
  *::::::::::::::-+                                              *
  *                                                              *
  *                                                              *
  *                                                              *
  +                                                              *
  *                                                              *
  +                                                              *
  *:::::::-                                     Cadeira .        *
  *       +                                     ::::::*.*        *
  *       +                                     +     * *        *
  +       +                                     +     * *        *
  +       + Baú                                 *.....* *        *
  +       +                                     ......+-+        *
  +       +                                                      *
  =.      +                                                      *
  ==:::::::                                                      *
  =.                                                             *
  =:                                                             *
  -:                                                             *
  -:                                                             *
  -=--=                                                          *
  --  +                                                          *
  :-  +                                                          +
  :-  + Adega                                                    *
  :-  +                                                -**=:---::*
  .=..*                                              :%###++@*=. *
  .+...                                      Entulho #*@%@%*%@#=.*
  .=                           Buraco                +:=*--%%=+#-*
   =:::::::::::::::::::::::::           :::::::::::::=-=::=-+--=:-
)"<<endl;
        denovo4=false;
   }
}


void mensagem_quarto1()
{
    if(denovo){mapa1();};
    if(quadro == false)
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

void mensagem_quarto2()
{
    if(denovo2){mapa2();};
    cout<<R"(Você veio pela porta oeste.
No quarto há:
- cama
- tv
- mesa
- guarda-roupa
- porta_oeste
- porta_leste
- porta_sul
(Você pode:
- ver
- usar
- abrir
- entrar))"<<endl;
}

void mensagem_quarto3()
{
    if(denovo3){mapa3();};
    if(alcapao)
    {
        cout<<R"(Você veio pela porta norte.
No armazém há:
- armario_1
- armario_2
- armario_3
- alcapao
- porta_norte
- porta_leste
- porta_oeste
(Você pode:
- ver
- abrir
- entrar))"<<endl;
    }
    else
    {
        cout<<R"(Você veio pela porta norte.
No armazém há:
- armario_1
- armario_2
- armario_3
- porta_norte
- porta_leste
- porta_oeste
(Você pode:
- ver
- abrir
- entrar))"<<endl;
    }

}

void mensagem_quarto4()
{
    if(denovo4){mapa4();};
    if(parede && !quebrou)
    {
        cout<<R"(Você veio pelo alçapão.
No porão há:
- alcapao
- caixa
- bau
- adega
- cadeira
- entulho
- parede
(Você pode:
- ver
- usar
- abrir
- entrar
- quebrar))"<<endl;
    }
    if(parede && quebrou)
    {
        cout<<R"(Você veio pelo alçapão.
No porão há:
- alcapao
- caixa
- bau
- adega
- cadeira
- entulho
- buraco
(Você pode:
- ver
- usar
- abrir
- entrar))"<<endl;
    }
    if(!parede && !quebrou)
    {
        cout<<R"(Você veio pelo alçapão.
No porão há:
- alcapao
- caixa
- bau
- adega
- cadeira
- entulho
- parede
(Você pode:
- ver
- usar
- abrir
- entrar))"<<endl;
    }
}


int quarto1(int espelho_cont, bool s_quadro, int lq)
{
    string verbo, obj, aux_v, obj2;
    string obj_v[7]={"guarda-roupa", "quadro", "espelho", "porta_norte", "porta_leste", "janela"}; //Vetor dos Objetos da sala 1
    string gr_v[3]={"papel", "fruta", "lapis"}; //Vetor dos objetos do guarda-roupa

    if(s_quadro){obj_v[6]="cofre";};
    mensagem_quarto1();
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
                            quadro = true;
                            denovo = true;
                            mapa1();
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
                        if(esta_no_inv("chave", inv, inv_tam))
                        {
                            cout<<"\nAo abrir o cofre você vê um pé de cabra e decide pegar.\n"<<endl;
                            inv[1]="pe_de_cabra";
                        }
                        else
                        {
                            cout<<"\nVocê não conseguiu abrir o cofre pois está trancado.\n"<<endl;
                        }
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
                        cout<<"\nVocê entrou no quarto.\n"<<endl;
                        denovo2=true;
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

int quarto2(int lq, int tv_cont)
{
    int tam = 7;
    string verbo, obj, alvo;
    string obj_v[7]={"cama","tv","mesa","guarda-roupa","porta_oeste","porta_leste","porta_sul"};

    mensagem_quarto2();
    cout<<"O que deseja fazer?"<<endl;
    cin>>verbo;
    cin>>obj;
    switch(Vcon(verbo))
    {
        case 1:
            switch(Ocon(obj, obj_v, 7))
            {
				case 1:
					cout<<"\nvocê vê uma cama mal arrumada.\n"<<endl;
					break;
				case 2:
					cout<<"\nVocê vê uma TV quebrada.\n"<<endl;
					if(tv_cont>=4)
					{
                        cout<<"Ao analisar a TV você vê que há uma chave e decide pegar.\n"<<endl;
                        inv[0]="chave";
					}
					break;
				case 3:
                    cout<<"\nVocê vê uma mesa de madeira, na mesa há um papel em branco, um copo de vidro, uma garrafa vazia, uma caixa de lápis, um livro do Senhor dos Anéis e um ábaco quebrado.\n"<<endl;
                    break;
				case 4:
                    cout<<"\nVocê vê um guarda-roupa de madeira.\n"<<endl;
                    break;
                case 5:
                    cout<<"\nVocê vê uma porta de madeira.\n"<<endl;
                    break;
                case 6:
                    cout<<"\nVocê vê uma porta de madeira.\n"<<endl;
                    break;
                case 7:
                    cout<<"\nVocê vê uma porta de madeira.\n"<<endl;
                    break;
				default:
                    cout<<"\nEscolha inconsistente.\n"<<endl;
                    break;
            }
            break;
        case 2:
            switch(Ocon(obj, obj_v, 7))
            {
                case 1:
                    cout<<"\nVocê deitou na cama e dormiu."<<endl;
                    cout<<"Se passou 8 horas.\n"<<endl;
                    break;
                default:
                    cout<<"\nEscolha inconsitente.\n"<<endl;
                    break;
            }
            break;
        case 4:
            switch(Ocon(obj, obj_v, 7))
            {
                case 4:
                    cout<<"\nVocê abriu o guarda-roupa, ele está vazio.\n"<<endl;
                    break;
                case 5:
                    cout<<"\nVocê abre a porta da sala.\n"<<endl;
                    break;
                case 6:
                    cout<<"\nVocê não consegue abrir a porta, ela está trancada.\n"<<endl;
                    break;
                case 7:
                    cout<<"\nVocê abre a porta, ela dá à um armazém.\n"<<endl;
                    break;
                default:
                    cout<<"\nEscolha inconsistente.\n"<<endl;
                    break;
            }
            break;
        case 5:
            switch(Ocon(obj, obj_v, 7))
            {
                case 4:
                    cout<<"\nVocê estrou no guarda-roupa, mas ao invés de ir para Nárnia, você bateu a cabeça.\n"<<endl;
                    break;
                case 5:
                    cout<<"\nVocê estrou na sala denovo.\n"<<endl;
                    lq = 1;
                    denovo = true;
                    break;
                case 7:
                    cout<<"\nVocê estrou no armazém.\n"<<endl;
                    denovo3=true;
                    lq = 3;
                    break;
                default:
                    cout<<"\nEscolha inconsistente.\n"<<endl;
                    break;
            }
            break;
        default:
            cout<<"\nSua escolha é inconsistente.\n"<<endl;
            break;
    }

    return lq;
}

int quarto3(int lq, int alcapao_cont)
{
    string verbo, obj;
    string obj_v[7]={"armario_1", "armario_2", "armario_3", "porta_norte", "porta_leste", "porta_oeste"};

    if(alcapao){obj_v[6]="alcapao";};
    mensagem_quarto3();
    cout<<"O que deseja fazer?"<<endl;
    cin>>verbo;
    cin>>obj;
    switch(Vcon(verbo))
    {
        case 1:
            switch(Ocon(obj, obj_v, 7))
            {
                case 1:
                    cout<<"\nVocê vê um armário de madeira.\n"<<endl;
                    break;
                case 2:
                    cout<<"\nVocê vê um armário de madeira.\n"<<endl;
                    break;
                case 3:
                    cout<<"\nVocê vê um armário de madeira.\n"<<endl;
                    if(alcapao_cont>=4)
                    {
                        cout<<"Você percebe que há algo debaixo do armário."<<endl;
                        cout<<"([apenas verbo] Você pode: - arrastar)"<<endl;
                        cin>>verbo;
                        switch(Vcon(verbo))
                        {
                            case 6:
                                cout<<"\nVocê arrasta o armário e vê um alçapão.\n"<<endl;
                                alcapao=true;
                                denovo3=true;
                                mapa3();
                                break;
                            default:
                                cout<<"\nEscolha Inconsistente.\n"<<endl;
                                break;
                        }
                    }
                    break;
                case 4:
                    cout<<"\nVocê vê uma porta de madeira.\n"<<endl;
                    break;
                case 5:
                    cout<<"\nVocê vê uma porta de madeira.\n"<<endl;
                    break;
                case 6:
                    cout<<"\nVocê vê uma porta de madeira.\n"<<endl;
                    break;
                case 7:
                    cout<<"\nVocê vê um alçapão de madeira no chão.\n"<<endl;
                    break;
                default:
                    cout<<"\nSua escolha é inconsistente.\n"<<endl;
                    break;
            }
            break;
        case 4:
            switch(Ocon(obj, obj_v, 7))
            {
                case 1:
                    cout<<"\nAo abrir o armário você vê nada.\n"<<endl;
                    break;
                case 2:
                    cout<<"\nAo abrir o armário você vê uma marreta de decide pegar.\n"<<endl;
                    inv[2]="marreta";
                    break;
                case 3:
                    cout<<"\nO armário está trancado\n"<<endl;
                    break;
                case 4:
                    cout<<"\nAo abrir a porta você vê o quarto.\n"<<endl;
                    break;
                case 5:
                    cout<<"\nA porta está trancada.\n"<<endl;
                    break;
                case 6:
                    cout<<"\nA porta está trancada.\n"<<endl;
                    break;
                case 7:
                    cout<<"\nAo abrir o alçapão você vê um porão.\n"<<endl;
                    break;
                default:
                    cout<<"\nSua escolha é inconsistente.\n"<<endl;
                    break;
            }
            break;
        case 5:
            switch(Ocon(obj, obj_v, 7))
            {
                case 4:
                    cout<<"\nVocê voltou ao quarto.\n"<<endl;
                    lq = 2;
                    denovo2=true;
                    break;
                case 7:
                    cout<<"\nVocê entrou no porão\n"<<endl;
                    denovo4=true;
                    lq = 4;
                    break;
                default:
                    cout<<"\nSua escolha é inconsistente.\n"<<endl;
                    break;
            }
            break;
        default:
            cout<<"\nEscolha Inconsistente.\n"<<endl;
            break;
    }

    return lq;
}

int quarto4(int lq, int porao_cont)
{
    string verbo, obj;
    string obj_v[8]={"alcapao","caixa","bau","adega","cadeira","entulho","parede"};

    if(quebrou){obj_v[7]="buraco";};
    mensagem_quarto4();
    cout<<"O que deseja fazer?"<<endl;
    cin>>verbo;
    cin>>obj;
    switch(Vcon(verbo))
    {
        case 1:
            switch(Ocon(obj, obj_v, 8))
            {
                case 1:
                    cout<<"\nVocê vê o alçapão de madeira no teto.\n"<<endl;
                    break;
                case 2:
                    cout<<"\nVocê vê uma caixa grande de papelão com vários objetos.\n"<<endl;
                    if(porao_cont>=19)
                    {
                        cout<<"\nAo mexer na caixa você acha um pokebola e decide pegar.\n"<<endl;
                        inv[3]="pokebola";
                    }
                    break;
                case 3:
                    cout<<"\nVocê vê um baú.\n"<<endl;
                    break;
                case 4:
                    cout<<"\nVocê vê uma adega vazia.\n"<<endl;
                    break;
                case 5:
                    cout<<"\nVocê vê uma cadeira de praia.\n"<<endl;
                    break;
                case 6:
                    cout<<"\nVocê vê um entulho de telhas, latas, garrafas, tijolos, e etc.\n"<<endl;
                    break;
                case 7:
                    cout<<"\nVocê vê uma parede de tijolos.\n"<<endl;
                    if(porao_cont>=4)
                    {
                        cout<<"\nVocê percebe que alguns tijolos da parede estão rachados ou quebrados.\n"<<endl;
                        parede=true;
                    }
                    break;
                case 8:
                    cout<<"\nVocê vê um buraco que dá na rede de esgoto.\n"<<endl;
                    break;
                default:
                    cout<<"\nEscolha inconsistente.\n"<<endl;
                    break;
            }
            break;
        case 2:
            switch(Ocon(obj, obj_v, 8))
            {
                case 5:
                    cout<<"\nVocê sentou na cadeira.\n"<<endl;
                    break;
                default:
                    cout<<"\nEscolha inconsistente.\n"<<endl;
                    break;
            }
            break;
        case 4:
            switch(Ocon(obj, obj_v, 8))
            {
                case 3:
                    cout<<"\nO baú está trancado.\n"<<endl;
                    break;
                default:
                    cout<<"\nEscolha inconsistente.\n"<<endl;
                    break;
            }
            break;
        case 5:
            switch(Ocon(obj, obj_v, 8))
            {
                case 1:
                    cout<<"\nVocê subiu as escadas e voltou ao armazém.\n"<<endl;
                    denovo3=true;
                    lq = 3;
                    break;
                case 8:
                    cout<<"\nVocê entrou na rede de esgoto.\n"<<endl;
                    lq = 5;
                    break;
                default:
                    cout<<"\nEscolha inconsistente.\n"<<endl;
                    break;
            }
            break;
        case 8:
            switch(Ocon(obj, obj_v, 8))
            {
                case 7:
                    if(esta_no_inv("marreta", inv, inv_tam))
                    {
                        cout<<"\nVocê quebrou a parede com a marreta e percebe que o buraco dá para uma rede de esgoto seca.\n"<<endl;
                        quebrou=true;
                        denovo4=true;
                    }
                    else
                    {
                        cout<<"\nVocê deu um soco na parede e machuca a mão.\n"<<endl;
                    }
                    break;
                default:
                    cout<<"\nEscolha inconsistente.\n"<<endl;
                    break;
            }
            break;
        default:
            cout<<"\nEscolha inconsistente.\n"<<endl;
            break;
    }

    return lq;
}

int quarto5()
{
    string verbo;

    cout<<"Ao andar pela rede de esgoto você escuta um grunido no fim do tunel, ao checar o barulho um zumbi te ataca."<<endl;
    cout<<"([apenas verbo] Você pode: - lutar)"<<endl;
    cin>>verbo;
    switch(Vcon(verbo))
    {
        case 7:
            if(esta_no_inv("pokebola", inv, inv_tam))
            {
                cout<<"\nVocê jogou uma pokebola no zumbi e conseguiu capturar ele.\n"<<endl;
                win = true;
            }
            else
            {
                if(esta_no_inv("pe_de_cabra", inv, inv_tam))
                {
                    cout<<"\nVocê bateu no zumbi com o pé de cabra e conseguiu matar ele.\n"<<endl;
                    win = true;
                }
                else
                {
                    cout<<"\nVocê tentou socar o zumbi, entretanto o soco não foi muito efetivo e ele te mordeu.\n"<<endl;
                    gameover = true;
                }
            }
            break;
        default:
            cout<<"\nA sua escolha foi inválida, devido à falta de tempo de resposta o zumbi te atacou.\n"<<endl;
            gameover = true;
            break;
    }

    return 6;
}


int main()
{
    bool s_quadro = false;
    int lq = 1; //Indica em que lugar o personagem está.
    int espelho_cont = 0, tv_cont = 0, alcapao_cont=0, porao_cont=0;

    logo();
    intro();
    tutorial();
    cout<<R"(Você acordou em um quarto escuro após levar um golpe na cabeça.
Após tatear as parede finalmente encontra um interruptor e consegue ascender a luz.
)"<<endl;
    while(win==false && gameover==false)
    {
        if(lq==1)
        {
            lq = quarto1(espelho_cont, s_quadro, lq);
            espelho_cont++;
            if(espelho_cont>=9){s_quadro=true;};
        }
        if(lq==2)
        {
            lq = quarto2(lq, tv_cont);
            tv_cont++;

        }
        if(lq==3)
        {
            lq = quarto3(lq, alcapao_cont);
            alcapao_cont++;
        }
        if(lq==4)
        {
            lq = quarto4(lq, porao_cont);
            porao_cont++;
        }
        if(lq==5)
        {
            lq = quarto5();
        }

        if(win)
        {
            cout<<"Parabéns, você conseguiu fugir!!!"<<endl;
            prologo();
        }
        if(gameover)
        {
            cout<<"Você morreu. Boa sorte na proxima."<<endl;
        }
    }
    return 0;
}
