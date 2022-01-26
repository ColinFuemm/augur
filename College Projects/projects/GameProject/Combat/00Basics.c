#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int HP;
    int Atk;
    int Def;
} fighter;

int main() {
    fighter *goodGuy = malloc(sizeof(fighter));
    fighter *meanie = malloc(sizeof(fighter));

    setStats(goodGuy, 20, 5, 2);
    setStats(meanie, 15, 5, 1);

    Fight(goodGuy, meanie);

    return 0;
}
//both combatants hit each other and HP is reduced accordingly
int Attack(fighter *a, fighter *b) { 
    
    b->HP = (b->HP - (a->Atk - b->Def));
    printf("Hero attacks for %d damage!\n", (a->Atk - b->Def));
    if(b->HP <= 0) return 1;
    a->HP = (a->HP - (b->Atk - a->Def));
    printf("Enemy attacks for %d damage!\n", (b->Atk - a->Def));
    
    return 1;
}
//prints current health of both combatants
void Update(fighter *a, fighter *b) {
    printf("Hero: %dHP  Enemy: %dHP\n", a->HP, b->HP);
}
//enters two combatants to attack until one's HP drops to zero
int Fight(fighter *a, fighter *b) {
    if(a == NULL || b == NULL) return 0;

    while(a->HP > 0 && b->HP > 0) { //continuously attack
        Update(a, b);
        Attack(a, b);
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

//set characters stats according to given numbers for health, attack, and defense respectively
int setStats(fighter *ptr, int H, int A, int D) {
    if (ptr == NULL) return 0;

    ptr->HP = H;
    ptr->Atk = A;
    ptr->Def = D;

    return 1;
}