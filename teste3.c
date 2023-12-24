#include <stdio.h>
#include <stdlib.h>

struct Activity {
    int start, finish;
};

int compareActivities(const void *a, const void *b) {
    return ((struct Activity *)a)->finish - ((struct Activity *)b)->finish;
}

void selectActivities(struct Activity activities[], int n) {
    qsort(activities, n, sizeof(struct Activity), compareActivities);

    printf("Atividades selecionadas:\n");

    int i = 0;
    printf("(%d, %d)\n", activities[i].start, activities[i].finish);

    for (int j = 1; j < n; j++) {
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
