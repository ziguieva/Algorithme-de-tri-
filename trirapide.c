#include <stdio.h>

// Fonction pour échanger deux éléments dans un tableau
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Fonction de partitionnement : place le pivot à la bonne position
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Choisir le dernier élément comme pivot
    int i = (low - 1);      // Index du plus petit élément
    
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;  // Incrémenter l'index du plus petit élément
            swap(&arr[i], &arr[j]);
        }
    }
    // Placer le pivot à sa place correcte
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Fonction récursive pour effectuer le tri rapide
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Pi est l'index du pivot
        int pi = partition(arr, low, high);
        
        // Trier récursivement les sous-tableaux à gauche et à droite du pivot
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Fonction pour afficher un tableau
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    
    // Lecture de la taille du tableau
    printf("Entrez le nombre d'éléments : ");
    scanf("%d", &n);
    
    int arr[n];
    
    // Lecture des éléments du tableau
    printf("Entrez les éléments du tableau :\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Exécution du tri rapide
    quickSort(arr, 0, n - 1);
    
    // Afficher le tableau trié
    printf("Tableau trié : ");
    printArray(arr, n);
    
    return 0;
}
