/* 
    realizza un algoritmo che ricevute 
    5 stringhe, determina quali 
    presentano delle doppie e verifica
    se sono state inserite due stringhe
    uguali.
*/

#include <stdio.h>

int trova_doppie (char*);
int stringhe_uguali (char*, char*);
int lunghezza(char*);
int confronta(char* s1, char* s2);

int main (int argc, char** argv){

    int i, j;

    for (i=1; i<argc; i++){
        
        //printf ("%d", trova_doppie (*(argv+i)));
        
        if (trova_doppie (*(argv+i))){
            printf ("\nNella stringa '%s' sono presenti delle doppie!", *(argv + i));
        }
        else 
            printf ("\nNella stringa '%s' NON sono presenti delle doppie!", *(argv + i));
      
    }
    printf ("\n");

    for (i=1; i<argc; i++){
        for (j=i+1; j<argc; j++){
              
            if (stringhe_uguali (*(argv+i), *(argv+j)) == lunghezza (*(argv+i)) || stringhe_uguali (*(argv+i), *(argv+j)) == lunghezza (*(argv+j)))
                printf ("\nLa stringa %d e' uguale alla stringa %d", i, j);
        }
    }    

    printf ("\n");
    return 0;

}

int trova_doppie (char* s){

    if (*s == '\0')
        return 0;
    else {
        if (*s == *(s+1)){
            return 1 + trova_doppie (s+1);
        }
        else{
            return 0 + trova_doppie (s+1);
        }
            
    }

}

int stringhe_uguali (char* s1, char* s2){
    if (*s1 == '\0') 
        return 0;

    if (*s2 == '\0')
        return 0; 

    else 
        if (*s1 == *s2)
            return 1 + stringhe_uguali ((s1+1), (s2+1));
        else 
            return 0;
}

int lunghezza(char* s)
{
    if(*s=='\0')
        return 0;
    else
        return 1 + lunghezza(s+1);
}

