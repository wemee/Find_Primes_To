#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define Find_Primes_To 1000000

typedef struct primes{
    int prime;
    struct primes* next;
}Primes;

Primes *primes;

int check_is_prime(int n){
    Primes *p = primes;
    int sq = (int)sqrt(n);
    
    while (p) {
        if (p->prime > sq) return 1;
        if (n%p->prime == 0)
            return 0;
        p = p->next;
    }
    return 1;
}

void print_all(){
    Primes *p = primes;
    while (p) {
        printf("%d, ", p->prime);
        p = p->next;
    }
}

int main(){
    int i;
    Primes *tail;
    
    primes = malloc(sizeof(Primes));
    primes->prime = 2;
    primes->next = malloc(sizeof(Primes));
    primes->next->prime = 3;
    tail = primes->next;
    
    for (i=5; i<Find_Primes_To; i++) {
        if(check_is_prime(i)){
            tail->next = malloc(sizeof(Primes));
            tail = tail->next;
            tail->prime = i;
        }
    }
    print_all();
    
    return 0;
}
