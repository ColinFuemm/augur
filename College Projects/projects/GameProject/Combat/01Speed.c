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
    setStats(meanie, 15, 5, 0, 20);

    Fight(goodGuy, meanie);

    return 0;
}
//prints current health of both combatants
void Update(fighter *a, fighter *b) {
    printf("Hero: %dHP  Enemy: %dHP\n", a->HP, b->HP);
}
//fighter A hits B and reduces HP accordingly
int Attack(fighter *a, fighter *b) {
    
    b->HP = (b->HP - (a->Atk - b->Def));
    printf(" for %d damage!\n", (a->Atk - b->Def));
    a->ATB -= 100; //turn reset
    return 1;
}
//enters two combatants to attack until one's HP drops to zero
int Fight(fighter *a, fighter *b) {
    if(a == NULL || b == NULL) return 0;

    while(a->HP > 0 && b->HP > 0) {
        a->ATB += a->Spd;
        if(a->ATB >= 100) {
            printf("Hero attacks");
            Attack(a, b);
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
//set characters stats according to given numbers for health, attack, defense, and speed respectively
int setStats(fighter *ptr, int H, int A, int D, int S) {
    if (ptr == NULL) return 0;

    ptr->HP = H;
    ptr->Atk = A;
    ptr->Def = D;
    ptr->Spd = S;
    ptr->ATB = 0;

    return 1;
}