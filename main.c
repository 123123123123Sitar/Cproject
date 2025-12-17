#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    
    char* who[] = {"Panos", "Younis", "Levi", "my cat"};
    char* does[] = {"ran away", "fell asleep", "told a secret", "laughed"};
    
    for (int i = 0; i < 10; i++) {
        int w = rand() % 4;
        int d = rand() % 4;
        
        if (i % 2 == 0) {
            printf("Sitar: %s %s\n", who[w], does[d]);
        } else {
            printf("Nicholas: %s %s\n", who[w], does[d]);
        }
    }
    
    return 0;
}
