#include <stdio.h>

// Fonction pour échanger deux éléments dans un tableau
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Fonction pour trouver la médiane de trois
int medianOfThree(int arr[], int low, int high) {
    int mid = (low + high) / 2;

    if (arr[low] > arr[mid])
        swap(&arr[low], &arr[mid]);
    if (arr[low] > arr[high])
        swap(&arr[low], &arr[high]);
    if (arr[mid] > arr[high])
        swap(&arr[mid], &arr[high]);

    // Utiliser la médiane comme pivot (au milieu du tableau)
    swap(&arr[mid], &arr[high]);
    return arr[high];
}

// Fonction de partitionnement
int partition(int arr[], int low, int high) {
    int pivot = medianOfThree(arr, low, high);
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Fonction récursive pour effectuer le tri rapide
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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

    quickSort(arr, 0, n - 1);

    printf("Tableau trié : ");
    displayArray(arr, n);

    return 0;
}
