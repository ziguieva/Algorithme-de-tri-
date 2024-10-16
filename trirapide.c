#include <stdio.h>

// Fonction pour échanger deux éléments dans un tableau
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Fonction de partitionnement : place les éléments inférieurs au pivot à gauche et les éléments supérieurs à droite
int partition(int arr[], int low, int high) {
    int pivot = arr[low];  // Choisir le premier élément comme pivot
    int left = low + 1;    // Pointeur pour parcourir la partie gauche
    int right = high;      // Pointeur pour parcourir la partie droite
    
    // Tant que les deux pointeurs ne se croisent pas
    while (left <= right) {
        // Avancer le pointeur gauche tant que les éléments sont plus petits que le pivot
        while (left <= right && arr[left] <= pivot) {
            left++;
        }
        
        // Avancer le pointeur droit tant que les éléments sont plus grands que le pivot
        while (left <= right && arr[right] > pivot) {
            right--;
        }
        
        // Si les deux pointeurs ne se sont pas croisés, échanger les éléments
        if (left < right) {
            swap(&arr[left], &arr[right]);
        }
    }
    
    // Placer le pivot à sa position correcte (à la place du pointeur "right")
    swap(&arr[low], &arr[right]);
    return right;  // Retourner l'indice du pivot
}

// Fonction récursive pour effectuer le tri rapide
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Obtenir l'index du pivot après partitionnement
        int pivotIndex = partition(arr, low, high);
        
        // Trier récursivement les sous-tableaux
        quickSort(arr, low, pivotIndex - 1);  // Partie gauche du pivot
        quickSort(arr, pivotIndex + 1, high); // Partie droite du pivot
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

