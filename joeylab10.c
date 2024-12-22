// Joey Slepski lab 10

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include "joeylibrary.h"

// fucntion 
int allLetter(char *s);
int numInRange(char *s1, char b, char t);
int diff(char *s1, char *s2);
void shorten(char **s, int new_len);
int len_diff(char *s1, char *s2);
void rm_left_space(char *s);
void rm_right_space(char *s);
void rm_space(char *s);
int find(char *h, char *n);
char *ptr_to(char *h, char *n);
bool is_empty(char *s);
void str_zip(char *s1, char *s2);
void capitalize(char *s);
int strcmp_ign_case(char *s1, char *s2);
void take_last(char *s, int n);
void dedup(char *s);
void pad(char *s, int d);
bool ends_with_ignore_case(char *s, char *suff);
char *repeat(char *s, int x, char sep);
char *replace(char *s, char *pat, char *rep);
char *str_connect(char **strs, int n, char c);
void rm_empties(char **words);
char **str_chop_all(char *s, char c);


int main() {
    printf("AllLetter %d\n", allLetter("Hello World"));
    
    printf("Number of Chars %d\n",  numInRange("Yellow", 'f','m'));
    printf("Difference between %d\n", diff("Book", "Back"));
    
    //function 4  
    
   
    printf("Length difference: %d\n", len_diff("Philadelphia", "Hello"));
    
    
    char str[]= " Hello";
    rm_left_space(str);
    printf ("New String %s\n", str);
    char str2[]="Hello ";
    rm_right_space(str2);
    printf("new String %s\n", str2);
    
    char str3[]=" Hello ";
    rm_space(str3);
    printf("New String %s\n", str3);
    
    printf("Test 1 %d\n", find("Hello", "l"));
    printf("Test 2 %d\n", find("Hello", "q") );
    
    //function 10
    char *result1= ptr_to("Hello", "l");
    char *result2= ptr_to("Hello", "q");
    if(result1){
        printf("Test 1 %s\n", result1);
    }
    if(result2){
        printf("Test 2%s\n", result2);
    } else{
        printf("Test 2:Null\n");
    }
    
    printf("%d\n", is_empty(" "));
    printf("%d\n", is_empty("Hello"));
    //function 12 fix
    char s5[500]= "Temple";
    char s7[]= "Hello";
    str_zip(s5, s7);
    printf("%s\n", s5);
    
    //function 13
    char str4[]= "hello world";
    capitalize(str4);
    printf("Caps: %s\n" , str4);
    //function 14
    printf("Compare 1 %d\n", strcmp_ign_case("hello", "goodbye"));
    printf("compare 2 %d\n", strcmp_ign_case("hello", "hello"));
    
    
    //15
    char str10[]= "hello";
    take_last(str10, 3);
    printf("Outcome %s\n", str10);
    char str11[]="hello";
    take_last(str11, 6);
    printf("Outcome %s\n", str11);
    //16 
    char str12[]="hello";
    dedup(str12);
    printf("Outcome %s\n", str12);
    //17
    char str13[100]="hello";
    pad(str13, 6);
    printf("Outcome %s\n", str13);
    char str14[100]="hello";
    pad(str14, 5);
    printf("Outcome %s\n", str14);
    //18 
    char *str18= "coding";
    char *suffix= "ing";
    printf(" Return %d\n", ends_with_ignore_case(str18, suffix));
    char *str19="coding";
    char *suffix2="ed";
    printf("Return %d\n", ends_with_ignore_case(str19,suffix2));
    //str19
    char *result= repeat("hello", 3, '-');
    printf("%s\n", result);
    free(result);
    //20
    char *s= "Steph is the X";
    char *pat= "X";
    char *rep= "best";
    char *help=replace(s, pat, rep);
    printf("Replaced %s\n", help);
    free(help);
    //21
    char *strs[]= {"Hello", "world", "Hello", "world"};
    int n=4;
    char seperators='-';
    char *total =str_connect(strs, n, seperators);
    printf("Result: %s\n", total);
    free(total);
    
    //22
    char *words2[]={"hello", "world", " ", "  ", "Steph", NULL};
    rm_empties(words2);
    for(int i=0; words2[i] !=NULL; i++){
        printf("%s ", words2[i]);
    }
    
    printf("\n");
   
   
   char strfinal[]= "Hello/world/hello/world";
   char delimiter= '/';
   char **final= str_chop_all(str, delimiter);
   for(int i=0; final[i]!=NULL; i++){
       printf("%s\n", final[i]);
       free(final[i]);
   }
   free(final);
}
