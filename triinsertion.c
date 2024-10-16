#include <stdio.h>

// Fonction pour trier le tableau en ordre croissant
void insertionSortAscending(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        // Déplacer les éléments qui sont plus grands que la clé
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Fonction pour trier le tableau en ordre décroissant
void insertionSortDescending(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        // Déplacer les éléments qui sont plus petits que la clé
        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Fonction pour afficher un tableau
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    
    // Demander à l'utilisateur la taille du tableau
    printf("Entrez le nombre d'éléments : ");
    scanf("%d", &n);
    
    int arr[n];
    
    // Lecture des éléments du tableau
    printf("Entrez les éléments du tableau :\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Tri par ordre croissant
    insertionSortAscending(arr, n);
    printf("Tableau trié en ordre croissant : ");
    printArray(arr, n);
    
    // Tri par ordre décroissant
    insertionSortDescending(arr, n);
    printf("Tableau trié en ordre décroissant : ");
    printArray(arr, n);
    
    return 0;
}
