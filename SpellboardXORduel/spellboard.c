#include <stdio.h>
#include <stdbool.h>
bool canGandalfWin(int* runes, int runesSize) {
    int totalResonance = 0; // Magical resonance (XOR of all runes)

    for (int i = 0; i < runesSize; i++) {
        totalResonance ^= runes[i];
    }

    // If resonance is already zero, Gandalf wins
    if (totalResonance == 0) return true;

    // Otherwise, Gandalf wins only if number of runes is even
    return (runesSize % 2 == 0);
}

int main() {
    int n;
    scanf("%d", &n); 

    int runes[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &runes[i]); 
    }

    if (canGandalfWin(runes, n))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}