// Feito por Lorenzzo Pagotti. 
// https://github.com/LorenzzoPagotti/JogoAdivinhacao

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void iniciojogo ()
{
    printf ("\n\n");  
printf ("                P  /_\\  P                                    \n");         
printf ("               /_\\_|_|_/_\\                                \n");
printf ("           n_n | ||. .|| | n_n         Bem vindo ao        \n");
printf ("           |_|_|nnnn nnnn|_|_|     Jogo de Adivinhacao!    \n");
printf ("           |" "  |  |_|  |"  " |                           \n");
printf ("           |_____| ' _ ' |_____|                           \n");
printf ("                 \\__|_|__/                                 \n");
printf ("\n\n");
}

void mensagemacertou ()
{
    printf ("\n\n");        
    printf("                      OOOOOOOOOOO                     \n");      
    printf("                  OOOOOOOOOOOOOOOOOOO                 \n");
    printf("               OOOOOO  OOOOOOOOO  OOOOOO               \n");
    printf("           OOOOOO      OOOOO      OOOOOO               \n");
    printf("         OOOOOOOO  #   OOOOO  #   OOOOOOOO           \n");
    printf("        OOOOOOOOOO    OOOOOOO    OOOOOOOOOO         \n");
    printf("       OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO       \n");
    printf("       OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO       \n");
    printf("        OOOO  OOOOOOOOOOOOOOOOOOOOOOOOO  OOOO       \n");
    printf("         OOOO  OOOOOOOOOOOOOOOOOOOOOOO  OOOO        \n");
    printf("          OOOO   OOOOOOOOOOOOOOOOOOOO  OOOO         \n");
    printf("           OOOOO   OOOOOOOOOOOOOOO   OOOO           \n");
    printf("            OOOOOO   OOOOOOOOO   OOOOOO             \n");
    printf("              OOOOOO         OOOOOO                 \n");
    printf("                    OOOOOOOOOOOO                        \n");
    printf ("\n\n");
}

void mensagemperdeu ()
{
    printf ("\n\n");
    printf("        \\|/ ____ \\|/      \n");  
    printf("        @~/ ,. \\~@          \n");  
    printf("       /_( \\__/ )_\\       \n");  
    printf("          \\__U_/            \n");  
    printf("\n\n");
}

int ConfiguracaoJogo (int *numerosecreto, int *numerodetentativas)
{

    int segundos = time(0);
    srand (segundos);
    *numerosecreto = rand() % 100;

    int nivel;
    printf ("Qual o nivel de dificuldade?\n");
    printf ("(1) Facil (2) Medio (3) Dificil\n\n");
    printf ("Escolha: ");
    scanf ("%d", &nivel);

    switch (nivel)
    {
        case 1:
        *numerodetentativas = 20;
        break;

        case 2:
        *numerodetentativas = 15;
        break;

        default:
        *numerodetentativas = 6;
        break;
    }
}

int ConfereChute (int chute, int numerosecreto, int *tentativa, double *pontos)
{
    if (chute < 0)
    {
        printf ("Voce nao pode digitar um numero negativo!\n");
        return;
    }

    if (chute == numerosecreto)
    {
        return;
    }
    else if (chute > numerosecreto)
    {
        printf ("Voce errou. O seu chute foi maior que o numero secreto.\n\n");
    }
    else
    {
            printf ("Voce errou. O seu chute foi menor que o numero secreto.\n\n");
    }
        double pontosperdidos = abs(chute - numerosecreto) / (double)2;
        *pontos -= pontosperdidos;
        (*tentativa)++;
        return 0;
}

void resultado (int chute, int numerosecreto, int tentativa, double pontos)
{

    printf ("Fim de jogo!\n");
    if (chute == numerosecreto)
    {
        mensagemacertou ();
        printf ("Parabens! Voce acertou!\n");
        printf ("Voce acertou em %d tentativas!\n", tentativa);
        printf ("Total de pontos: %.1lf\n", pontos);
    }
    else
    {
        printf ("Voce perdeu! Tente novamente.\n");
        mensagemperdeu ();
    }
    printf ("O jogo terminou. Digite qualquer coisa para fechar.\n");
    char fechar[99];
    scanf ("%s", fechar);
}


int main ()
{

    iniciojogo ();

    int numerosecreto, numerodetentativas;
    ConfiguracaoJogo (&numerosecreto, &numerodetentativas);

    int tentativa = 1;
    double pontos = 1000.0;
    int chute;

    for (int i = 1 ; i <= numerodetentativas ; i++)
    {
        printf("Tentativa %d de %d\n", tentativa, numerodetentativas);
        printf("Chute um numero: ");
        scanf("%d", &chute);

        ConfereChute (chute, numerosecreto, &tentativa, &pontos);

        if (chute == numerosecreto)
        {
            break;
        }
    }
        resultado (chute, numerosecreto, tentativa, pontos);
}