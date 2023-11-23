#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar uma atividade
struct Activity {
    int start, finish;
};

// Função para comparar atividades por tempo de término
int compareActivities(const void *a, const void *b) {
    return ((struct Activity *)a)->finish - ((struct Activity *)b)->finish;
}

// Função para selecionar as atividades
void selectActivities(struct Activity activities[], int n) {
    // Ordena as atividades por tempo de término
    qsort(activities, n, sizeof(struct Activity), compareActivities);

    printf("Atividades selecionadas:\n");

    // A primeira atividade é sempre selecionada
    int i = 0;
    printf("(%d, %d)\n", activities[i].start, activities[i].finish);

    // Itera sobre as atividades restantes
    for (int j = 1; j < n; j++) {
        // Se a atividade atual não se sobrepõe à anterior, seleciona ela
        if (activities[j].start >= activities[i].finish) {
            printf("(%d, %d)\n", activities[j].start, activities[j].finish);
            i = j;
        }
    }
}

int main() {
    struct Activity activities[] = {{5, 9}, {1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}};
    int n = sizeof(activities) / sizeof(activities[0]);

    selectActivities(activities, n);

    return 0;
}
