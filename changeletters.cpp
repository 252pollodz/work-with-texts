#include <stdio.h>
#include <stdlib.h>
#include <iostream>
void tosmall(char *letter) {
    while (*letter) {
        if(*letter>='A' && *letter<='Z') {
            *letter+=('a'-'A');
        }else if(*letter==' '){
            letter++;
        }
        letter++;
    }
}
void tobig(char *letter) {
    while (*letter) {
        if(*letter>='a' && *letter<='z') {
            *letter-=('a'-'A');
        }
        letter++;
    }
}
int joinstrings(char *first, char *second, char* result, int maxsize) {
    int size=0;
    while (*first) {
        *result=*first;
        result++;
        first++;
        size++;
    }result--;
    while (*second) {
        *result=*second;
        result++;
        second++;
        size++;
    }
    if(size>maxsize) {
        return 1;
    }
    *result='\0';
    return 0;
}
int lenghtofstring(char *string) {
    int  len=0;
    while (*string) {
        len++;
        string++;
    }
    return len-1;
}


int main() {
    char letters[100];
    char string1[50];
    char string2[50];
    char result[100];
    //zamiana wielkosci liter
    printf("Podaj zdanie, w ktorym chcesz zmienic wielkosc liter:\n");
    fgets(letters, sizeof(letters), stdin);
    tosmall(letters);
    printf("Po zmianie z duzych na male:\n%s\n", letters);
    tobig(letters);
    printf("Po zmianie z malych na duze:\n%s\n", letters);
    int dlugosc = 0;
    dlugosc = lenghtofstring(letters);
    printf("Dlugosc napisu: %d", dlugosc);

    //Dodawanie napisow do siebie

    printf("\n----------------------------------\n");
    printf("Podaj pierwsza czesc do zlaczenia: \t");
    fgets(string1, sizeof(string1), stdin);
    printf("Podaj druga czesc do zlaczenia: \t");
    fgets(string2, sizeof(string2), stdin);
    joinstrings(string1, string2, result, 100);
    printf("%s\n", result);
    return 0;
}