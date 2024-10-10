#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define grupo_animais 5

// estrutura que armazena informações sobre os animais
typedef struct {
    char nome[50];  
    char dicas[3][100];  // array de dicas
    char tipo[20];  
} animal;

// função para selecionar um animal aleatoriamente
animal escolher_animal(int dificuldade) {
    animal animais[15] = {
        {"Cavalo", {"Gosta de pastar na grama.", "Usado em competições e passeios.", "É um animal muito rápido."}, "Herbívoro"},
        {"Vaca", {"Tomamos o leite que é produzido.", "Vive normalmente em fazendas", "Berra."}, "Herbívoro"},
        {"Elefante", {"É o maior mamífero terrestre.", "Possui uma tromba longa.", "Tem grandes orelhas."}, "Herbívoro"},
        {"Girafa", {"Tem um pescoço longo.", "Come folhas das árvores altas.", "É o animal terrestre mais alto."}, "Herbívoro"},
        {"Coelho", {"Adora cenouras.", "Possui orelhas longas.", "É conhecido por correr rápido"}, "Herbívoro"},
        {"Leão", {"Rei da selva.", "Vive em grupos", "É um predador."}, "Carnívoro"},
        {"Tigre", {"Tem listras.", "É um predador solitário.", "Pode ser encontrado na Ásia."}, "Carnívoro"},
        {"Lobo", {"Vive em matilhas.", "É conhecido por uivar.", "É um excelente caçador."}, "Carnívoro"},
        {"Águia", {"É uma ave de rapina.", "Tem visão aguçada.", "É símbolo de força."}, "Carnívoro"},
        {"Tubarão", {"É um predador marinho.", "Tem dentes afiados.", "Pode ser encontrado em oceanos."}, "Carnívoro"},
        {"Urso", {"Come mel e peixes.", "É encontrado em florestas.", "Hiberna no inverno."}, "Onívoro"},
        {"Porco", {"Oinca", "Gosta de rolar na lama.", "Pode ser um animal doméstico."}, "Onívoro"},
        {"Gato", {"É um animal de estimação popular.", "Gosta de caçar pequenos animais.", "É muito independente."}, "Onívoro"},
        {"Cão", {"Famoso por ser o melhor amigo do homem.", "É muito leal.", "Existem muitas raças diferentes."}, "Onívoro"}
    };

   // nível de dificuldade
    int inicio = 0;
    int quantidade = 0;

    if (dificuldade == 1) { // fácil
        inicio = 0;
        quantidade = 5;
    } else if (dificuldade == 2) { // médio
        inicio = 5;
        quantidade = 5;
    } else { // difícil
        inicio = 10;
        quantidade = 5;
    }

    return animais[inicio + (rand() % quantidade)];
}


int compara_strings(const char* str1, const char* str2) {
    while (*str1 && *str2) {
        if (tolower((unsigned char)*str1) != tolower((unsigned char)*str2)) {
            return 0; 
        }
        str1++;
        str2++;
    }
    return (*str1 == *str2); 
}




int main() {
    srand(time(0));
    int dificuldade;
    char resposta[50];
    int jogar_novamente;
    char nome_jogador[50];
    int pontos = 0;

    // armazena nome do jogador
    printf("Digite seu nome: ");
    scanf("%s", nome_jogador);

    do {
        printf("Escolha a dificuldade:\n");
        printf(" 1 - Fácil\n 2 - Médio\n 3 - Difícil\n");
        scanf("%d", &dificuldade);

        animal escolhido = escolher_animal(dificuldade);
        int tentativas = 0;
        int max_tentativas = (dificuldade == 1) ? 5 : (dificuldade == 2) ? 4 : 3;
        int acertou = 0;

        printf("Adivinhe qual é o animal. Dica: %s\n", escolhido.dicas[0]);

        while (tentativas < max_tentativas && !acertou) {
            printf("Tentativa %d: ", tentativas + 1);
            scanf("%s", resposta);
            tentativas++;

            if (compara_strings(resposta, escolhido.nome) == 1) {
                acertou = 1;
                pontos++; // pontos
            } else {
                printf("Errado. Tente novamente.\n");
                if (tentativas < 3) { // dicas na tentativa do erro
                    printf("Dica: %s\n", escolhido.dicas[tentativas]); // dica nova a cada erro
                }
            }
        }

        if (acertou) {
            printf("Parabéns, você acertou o animal!\n", nome_jogador, escolhido.nome);
        } else {
            printf("Você não acertou! O animal era: %s.\n", escolhido.nome);
        }

        printf("Seus pontos: %d\n", pontos); 

        printf("Deseja jogar novamente? 1 - Sim / 2 - Não: ");
        scanf("%d", &jogar_novamente);

    } while (jogar_novamente == 1);

    printf("Obrigado por jogar, %s! Você terminou com %d pontos.\n", nome_jogador, pontos);
    return 0;
}
