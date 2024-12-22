// Joey Slepski lab 10

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

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

int allLetter(char *s){
    int i = 0;

    while(s[i] != '\0'){
        char n = s[i];
        if(!(n >= 'A' && n <= 'Z') && !(n >= 'a' && n <= 'z')){
            return 0;
        }
        i++;
    }
    return 1;
}

int numInRange(char *s1, char b, char t){
   int i=0;
    int tot = 0;
    while(*s1 !='\0'){
        if(*s1>= b && *s1<=t){
            tot++;
        }
        s1++;
    }
    return tot;

    
}

int diff(char *s1, char *s2){
    int diff = 0;
    int i = 0;
    while(s1[i] != '\0' || s2[i] != '\0'){
        if(s2[i] != s1[i]){
            diff++;
        }
        i++;
    }
    return diff;
}

void shorten(char **s, int new_len){//later
    int len=0;
    int i=0;
    while((*s)[len]!='\0'){
        len++;//find length
    }
    if(new_len>=len){
        return;//returns because its less than
    }
    char *new=malloc(new_len+1);
    for(int i=0; i<new_len;i++){
        new[i]=(*s)[i];//copies characters from the start
    }
}
int len_diff(char *s1, char *s2){
    int length1=0;
    int length2=0;
    while(s1[length1] != '\0'){
        length1++; //count length
    }
    while(s2[length2] !='\0'){
        length2++;
    }
    int total=0;
    total= length1-length2;
    return total;
}
void rm_left_space(char *s){
    int i=0; 
    int j=0;
    while(s[i] ==' ' || s[i] =='\n'){
        i++;
    }
    while(s[i] != '\0'){
        s[j++]= s[i++];
    }
    s[j] ='\0';
}

void rm_right_space(char *s){
    int i=0;
    while(s[i] !='\0'){
        i++; //length
    }
    while(i>= 0 && (s[i]==' ' || s[i]=='\n')){
        i--;
    }
}

void rm_space(char *s){
    int i=0;
    int j=0;
    //fix
    while(s[i] ==' ' || s[i] =='\n'){
        i++;
    }
    while(s[i] != '\0'){
        s[j++] =s[i++];
    }
    j--;
    while(j>= 0 &&(s[j]==' ' || s[j]== '\n')){
        j--;
    }
    s[j+1]='\0';
}

int find(char *h, char *n){
    int i=0;
    int temp=0;
    int j=0;
    while(h[i] !='\0'){ //checks if tis at the end
        if (h[i]==n[j]){//checks first letter
            int temp=i;
            while(h[temp]==n[j] &&n[j]!='\0'){ //goes through all the other characters
                temp++;
                j++;
            }
            if(n[j]=='\0'){
                return i;
            }
            
        }
        i++;
    }
    return -1;//not found
    
    
}


char *ptr_to(char *h, char *n){
    int i=0;
    int j=0;
    int f=0;
    while(h[i] != '\0'){
        if(h[i]==n[0]){
            j=0;
        
        while(h[i+j] ==n[j]&&n[j]!='\0'){
            j++;
        }
        
        if(n[j]=='\0'){
            return &h[i];
        }
        
        
    }
    i++;
    }
    
    return NULL;
}
    



bool is_empty(char *s){
    int i=0;
    if(s==NULL){
        return 1;
    }
    while(s[i]!= '\0'){
        if(s[i]!= ' ' && s[i] !='\n'){
            return 0;
        }
        i++;
    }
    return 1;
        
    
}




void str_zip(char *s1, char *s2){
    int i =0;
    int j=0;
    int k=0;
    char temp[500];
    //putting characters 1 and 1
    while(s1[i] !='\0' && s2[j]!='\0'){
        temp[k++]=s1[i++];
        temp[k++]=s2[j++];
        
        
    }
    while(s2[i]!='\0'){
        temp[k++] =s2[i++];
    }
    while(s1[i]!='\0'){
        temp[k++]= s1[i++]; //adds the rest of char 1 if its more than 2
    }
    while(temp[i]!='\0'){
        s1[i]=temp[i];
        i++;
    }
  
    
}
void capitalize(char *s){
    int i=0;
    while(s[i]!='\0'){//runs through until its over
        if(i==0 || s[i-1] ==' '){
            if(s[i] >= 'a' && s[i]<='z'){
                s[i] -=('a' -'A');
            }else{
                if(s[i] >='A' && s[i] <= 'Z'){
                    s[i]+=('a'-'A');
                }
            }
            }
        i++;
    
}
}
int strcmp_ign_case(char *s1, char *s2){
    int i=0;
    
    while(s1[i] !='\0' && s2[i] !='\0'){
        char c1=s1[i];
        char c2=s2[i];
    
    //change to lowercase
    if(c1>='A' && c1<='Z'){
        c1+=('a'-'A');
    }
    if(c2>='A' && c2<='Z'){
        c2+=('a'- 'A');
    }
    if(c1!=c2){
        return c1-c2;
    }
    i++;
    
    }
    
    return s1[i]- s2[i];
    
}
void take_last(char *s, int n){
   
    int i=0;
    //get the length
    int length=0;
    while(s[length] !='\0'){
        length++;
    }
    if(n>=length){
        return;
    }
    int start= length-n;
    while(s[start]!='\0'){
        s[i++] = s[start++];
    }
    s[i]='\0';
    
    }

void dedup(char *s){
    int i=0;
    int j=0;
    int seen[256] ={0};
    while(s[i]!='\0'){
        unsigned char c= (unsigned char)s[i];
        if(!seen[c]){
            seen[c]=1;//finds the characters
            s[j++]= s[i];//keeps the char
        }
        i++;
    }
    s[j]='\0';
    
    
}
void pad(char *s, int d){
    int length =0;
    while(s[length!='\0']){
        length++;
        //string length
    }
    int remainder= length%d;
    if(remainder==0){
        return;
    }
    int pad= d- remainder;
    for(int i=0; i< pad; i++){
        s[i +length]= ' ';
    }
    s[length+pad]='\0';
}
bool ends_with_ignore_case(char *s, char *suff){
    int s_length=0;
    int suff_length=0;
    //find length of s and suff_length
    while(s[s_length]!='\0'){
        s_length++;
    }
    while(suff[suff_length]!='\0'){
        suff_length++;
    }
    if(suff_length >s_length){
        return 0;// not possible outcome
    }
    for(int i=0; i< suff_length; i++){
        char s_char= tolower(s[s_length- suff_length +i]);
        char suff_char= tolower(suff[i]);
        if(s_char != suff_char){
            return NULL;
        }
    }
    return true;

    
}
char *repeat(char *s, int x, char sep){
   
    
    int length=0;
    while(s[length]!= '\0'){
        length++;
    }
    int new= x*length+(x-1);
    char *total=malloc(new+1);
    if (total==NULL){
        return NULL;
    }
    int pos=0;
    for(int i=0; i<x; i++){
        for(int j=0; j<length; j++){
            total[pos++] = s[j];
        }
        if(i<x-1){
            total[pos++] =sep;
        }
    }
    total[pos]='\0';
    return total;
}
char *replace(char *s, char *pat, char *rep){
    int s_len=0;
    int pat_len=0;
    int rep_length=0;
    int i=0;
    int j=0;
    int k=0;
    while(s[s_len]!='\0'){
        s_len++;
        while(pat[pat_len]!='\0'){
            pat_len++;
            while(rep[rep_length]!='\0'){
                rep_length++;
            }
        }
    }
    int total=0;
    for(int i=0; i<=s_len-pat_len; i++){
        int m=1;
        for(int j=0; j<pat_len; i++){
            if(s[i+j] !=pat[j]){
                m=0;
                break;
                
            }
        }
        if(m){
            total++;
            i+=pat_len-1;
        }
    }
    int new_len=s_len +total *(rep_length - pat_len);
    char *result=malloc(new_len+1);
    if(!result){
        return NULL;
    }
    
    
    while(s[i]!='\0'){
        int m=1;
        for(int j=0; j<pat_len; j++){
            if(s[i +j] != pat[j]){
                m=0;
                break;
            }
        }
        if(m){
            for(int j=0; j<rep_length; j++){
                result[k++]= rep[j];
            }
            i+=pat_len;
        }else{
            result[k++] =s[i++];
        }
    }
}
char *str_connect(char **strs, int n, char c){
    int total=0;
    for(int i=0; i<n; i++){
        for (int j=0; strs[i][j]!= '\0'; j++){
            total++;//length of all string
        }
    }
    total +=(n-1);//space for seperators
    char *result= malloc(total +1);
    if(result==NULL){
        return NULL;
        
    }
    int p=0;
    for(int i=0; i< n; i++){
        for (int j=0; strs[i][j] !='\0'; j++){
            result[p++] =strs[i][j];
        }
        if(i<n-1){
            result[p++]=c;//add seperator
        }
    }
    result[p]='\0';
    return result;
    
}
void rm_empties(char **words){
    if(words==NULL){
        return;
    }
    int i=0;
    int j=0;
    while(words[i]!=NULL){
        int empty=1;
        int k=0;
        while(words[i][k] != '\0'){
            if(words[i][k]!=' ' && words[i][k] !='\n'){
                empty=0;
                break;
            }
            k++;
        }
        if(!empty){
            words[j++]=words[i];
        }
        i++;
        }
        words[j]=NULL;
}
char **str_chop_all(char *s, char c){
    int token=1;
    for(int i=0; s[i] != '\0'; i++){
        if(s[i] ==c){
            token++;
        }
    }
    char **result=malloc((token+1) *sizeof(char*));
    if (result==NULL){
        return NULL;
    }
    int start=0;
    int total=0;
    for(int i=0; ;i++){
        if(s[i]==c|| s[i]=='\0'){
            int length=i-start;
            
            result[total]=malloc(length+1);
            if(result[total]==NULL){
                for(int j=0; j< total; j++){
                    free(result[j]);
                }
                free(result);
                return NULL;
                }
                for(int j=0; j< length; j++){
                    result[total][length]='\0';
                    total++;
                    start=i +1;
                    if(s[i]=='\0'){
                        break;
                    }
                }
                result[total]=NULL;
                return result;
            }
            
        }
    }


