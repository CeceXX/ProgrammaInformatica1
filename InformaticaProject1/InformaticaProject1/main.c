/*
 Gruppo 4: Belletta, De Cal, Tesi, Valeri
 Viene richiesto un programma organizzato per funzioni che preveda un menu con la possibilità di scelta tra le seguenti operazioni:
 1. azzeramento del vettore
 2. inserimento di tutti i dati da tastiera
 3. inserimento di un solo dato nella prima posizione contente zero
 4. inserimento di tutti i dati in maniera casuale con numeri compresi tra duecento e
 trecento
 5. la visualizzazione di tutti i dati presenti nel vettore
 6. l'inserimento dei numeri della serie geometrica
 7. la prodotto dei numeri di indice primo
 8. la somma dei resti delle divisione per tre dei numeri pari
 9. ricerca di un elemento nel vettore attraverso la ricerca sequenziale con sentinella
 10. ordinamento attraverso l'algoritmo del merge sort
 L'array verrà dichiarato con una dimensione di 150 elementi, ma quando il programma parte, prima della visualizzazione del menu verrà richiesto di inserire il numero di elementi su cui operare
 */

#include <stdio.h>

void visualizzazioneElementiVettore(int array[], int lunghezza) {
    for (int i = 0; i < lunghezza; i++) {
        printf("%do numero: %d\n", i+1, array[i]);
    }
}

void azzeramentoVettore(int array[], int lunghezza) {
    for (int i = 0; i < lunghezza; i++) {
        array[i] = 0;
    }
}

int main() {
    int myArray[150], maxNumero, inserimento;
    
    printf("Inserisci quanti numeri desideri inserire: ");
    scanf("%d", &maxNumero);
    
    while (1) {
        printf("1. Azzeramento del vettore\n");
        printf("5. Visualizzazione di tutti gli elementi presenti nel vettore: \n");
        printf("Scegli un'opzione del menu: ");
        scanf("%d", &inserimento);
        
        switch (inserimento) {
            case 1:
                azzeramentoVettore(myArray, maxNumero);
                break;
            case 5:
                visualizzazioneElementiVettore(myArray, maxNumero);
                break;
            default:
                break;
        }
    }
    
    return 0;
}
