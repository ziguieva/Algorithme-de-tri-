#include <stdio.h>

// Fonction pour échanger deux éléments dans un tableau
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Fonction de partitionnement de Hoare
int hoarePartition(int arr[], int low, int high) {
    int pivot = arr[low];  // Choisir le premier élément comme pivot
    int left = low - 1;
    int right = high + 1;

    while (1) {
        // Avancer le pointeur gauche
        do {
            left++;
        } while (arr[left] < pivot);

        // Avancer le pointeur droit
        do {
            right--;
        } while (arr[right] > pivot);

        // Si les deux pointeurs se croisent, retourner l'index du pointeur droit
        if (left >= right) {
            return right;
        }

        // Échanger les éléments
        swap(&arr[left], &arr[right]);
    }
}

// Fonction récursive pour effectuer le tri rapide avec la partition de Hoare
void quickSortHoare(int arr[], int low, int high) {
    if (low < high) {
        int p = hoarePartition(arr, low, high);
        quickSortHoare(arr, low, p);
        quickSortHoare(arr, p + 1, high);
    }
}

// Fonction pour afficher un tableau
void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;

    printf("Entrez le nombre d'éléments : ");
    scanf("%d", &n);

    int arr[n];
    printf("Entrez les éléments du tableau :\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    quickSortHoare(arr, 0, n - 1);

    printf("Tableau trié : ");
    displayArray(arr, n);

    return 0;
}
