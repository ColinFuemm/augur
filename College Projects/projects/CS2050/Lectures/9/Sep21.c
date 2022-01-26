#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float x, y;
} OrderedPair; //combine two floats to hold together

OrderedPair AddOP (OrderedPair A, OrderedPair B);
void ReverseOP (OrderedPair *p);

int main(void)
{
    OrderedPair pair = {1.0, 3.5}; //initialize in order by default (dangerous)
    printf("( %.1f, %.1f)", pair.x, pair.y); //access members with . operand

    OrderedPair pair2 = {.3, -2.0};
    OrderedPair sum = AddOP(pair, pair2);

    printf("( %.1f, %.1f)", sum.x, sum.y);

    ReverseOP(&pair);
    printf("( %.1f, %.1f)", pair.x, pair.y);

    return 0;
}

OrderedPair AddOP (OrderedPair A, OrderedPair B)
{
    OrderedPair result;

    result.x = A.x + B.x;
    result.y = A.y + B.y;

    return result;
}

void ReverseOP (OrderedPair *p)
{
    float temp;

    temp = p->x;
    p->x = p->y;
    p->y = temp;
}