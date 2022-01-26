#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int HP;
    int Atk;
    int Def;
    int Spd;
    int ATB;
} fighter;

void Update(fighter *a, fighter *b);
int Attack(fighter *a, fighter *b);
int Fight(fighter *a, fighter *b);
int setStats(fighter *ptr, int H, int A, int D, int S);

int main() {
    fighter *goodGuy = malloc(sizeof(fighter));
    fighter *meanie = malloc(sizeof(fighter));

    setStats(goodGuy, 20, 5, 2, 15);
    setStats(meanie, 16, 5, 0, 30);

    Fight(goodGuy, meanie);

    return 0;
}
void Update(fighter *a, fighter *b) {
    printf("Hero: %dHP  Enemy: %dHP\n", a->HP, b->HP);
}
int Attack(fighter *a, fighter *b) {
    
    b->HP = (b->HP - (a->Atk - b->Def));
    printf(" for %d damage!\n", (a->Atk - b->Def));
    a->ATB -= 100;
    return 1;
}
int Fight(fighter *a, fighter *b) {
    if(a == NULL || b == NULL) return 0;

    while(a->HP > 0 && b->HP > 0) {
        a->ATB += a->Spd;
        if(a->ATB >= 100) {
            printf("Hero's Turn\na Attack? \nb Heal? \nc Flee?");
            char selection;
            scanf("%c", &selection);

            switch(selection) {
                case 'a':
                    printf("Hero attacks");
                    Attack(a, b);
                    break;

                case 'b':
                    a->HP += 10;
                    a->ATB -= 100;
                    break;
                case 'c':
                    printf("Got away safely.\n");
                    break;
            }
            Update(a, b);
        }
        b->ATB += b->Spd;
        if(b->ATB >= 100) {
            printf("Enemy Attacks");
            Attack(b, a);
            Update(a, b);
        }
        
    }
    if (b->HP <= 0) {
        printf("Victory!\n");
        return 1;
    }
    if (a->HP <= 0) {
        printf("Defeat.\n");
        return 1;
    }
}

int setStats(fighter *ptr, int H, int A, int D, int S) {
    if (ptr == NULL) return 0;

    ptr->HP = H;
    ptr->Atk = A;
    ptr->Def = D;
    ptr->Spd = S;
    ptr->ATB = 0;

    return 1;
}