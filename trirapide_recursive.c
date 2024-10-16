#include <stdio.h>

// Fonction pour échanger deux éléments dans un tableau
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Fonction de partitionnement : place les éléments inférieurs au pivot à gauche et les éléments supérieurs à droite
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Choisir le dernier élément comme pivot
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

// Tri rapide itératif
void quickSortIterative(int arr[], int n) {
    int stack[n];  // Créer une pile
    int top = -1;

    // Pousser les indices de départ et de fin dans la pile
    stack[++top] = 0;
    stack[++top] = n - 1;

    while (top >= 0) {
        // Extraire les indices de la pile
        int high = stack[top--];
        int low = stack[top--];

        // Faire le partitionnement
        int p = partition(arr, low, high);

        // Si la partie gauche existe, ajouter ses indices dans la pile
        if (p - 1 > low) {
            stack[++top] = low;
            stack[++top] = p - 1;
        }

        // Si la partie droite existe, ajouter ses indices dans la pile
        if (p + 1 < high) {
            stack[++top] = p + 1;
            stack[++top] = high;
        }
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
    
    quickSortIterative(arr, n);
    
    printf("Tableau trié : ");
    displayArray(arr, n);
    
    return 0;
}
