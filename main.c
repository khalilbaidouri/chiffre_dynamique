#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "chiffre.h"
#define REEL 1
#define ENTIER 2

char *saisir_chaine()
{
    char *chaine, caractere;
    int i = 0;
    chaine = (char *) malloc(1 * sizeof(char));
    while((caractere = getchar()) != '\n')
    {
        chaine[i] = caractere;
        chaine = (char *) realloc(chaine, (i + 1) * sizeof(char));
        i++;
    }
    chaine[i] = '\0';
    return chaine;
}

bool valider_nombre(char *ch) {
    int i = 0, virgules = 0;
    if (ch[i] == '-')
    {
        i++;
    }

    while (ch[i] != '\0')
    {
        if (ch[i] == '.')
        {
            virgules++;
            i++;
            continue;
        }
        if (ch[i] > '9' || ch[i] < '0' || virgules > 1)
        {
            return false;
        }
        i++;
    }
    return true;
}

int Type_Nombre(char *ch)
{
    int i=0,k=0;

    while (ch[i]!='\0')
    {
        if (ch[i++] == '.')
        {
            k++;
        }
    }
    if (k==0) {
        return ENTIER;
    }
    else {
        return REEL;
    }
}

// FONCTION QUI DETECTE LE SIGNE DU NOMBRE (positive ou bien negative)
char *Pos_Neg(char *ch1)
{
    if(ch1[0] == '-')
        return "negative";
    else
        return "positive";
}

// PROCEDURE POUR LES ENTIERS
void entier_to_lettre(char *ch2)
{
    char *z=Pos_Neg(ch2);
    char *ch1=(char*) calloc(26 , sizeof(char));
    if (z=="negative")
    {
        int i=0,f=0;
   // si la chaine contient '-' je vais vider la chaine qui a saisser par lutilisateur dans une autre chaine . !!!!!!
        while (ch2[i]!='\0' )
        {
            ch1[f++]=ch2[++i];
        }
    }
    else
    {

        int e=0,f=0;
        while (ch2[e] != '\0')
        {
            ch1[f++]=ch2[e++];
        }
        ch1[f]='\0';
    }
    int i;
    char *cent=(char*)calloc(3,sizeof(char));
    char *mille=(char*)calloc(3,sizeof(char));
    char *million=(char*)calloc(3,sizeof(char));
    char *milliard=(char*)calloc(3,sizeof(char));

    if(strlen(ch1)<3)
    {
        char *w=(char*) calloc(3 , sizeof(char));
        int j=0;
        for(i=0;i<strlen(ch1);i++)
        {
            w[j++]=ch1[i];
        }
        int nombre=atoi(w);
        printf(" %s",chiffre[nombre]);
    }

    // CENTELLE
                else if(strlen(ch1)==3)
                        {
                        int nombre= atoi(ch1);
                        printf(" %s",chiffre[nombre]);
                        }
                // MILLLLLLLLE
                else if(strlen(ch1)>3 && strlen(ch1)<6)
                    {
                    int i,j=0,k=0;
                    int a=strlen(ch1)%3;
                    for(i=0;i<a;i++)
                     {
                        mille[j++]=ch1[i];

                     }
                    int nombre=atoi(mille);
                    if(nombre!=0)
                        {
                         printf(" %s",chiffre[nombre]);
                         printf(" mille");
                        }

                    for(i=a;i<strlen(ch1);i++)
                        {
                        cent[k++]=ch1[i];
                        }
                        int nombre2=atoi(cent);
                    if(nombre2!=0)
                        {
                        printf(" %s ",chiffre[nombre2]);
                        }
                                                    }
                    // MILLLLLLLLEEEE EXACTE 6 NOMBRES
                   else if(strlen(ch1)==6) {
                       if(ch1[0]=='-')
                       {
                           printf("moin-");
                       }
                       char mille[3],cent[3];
                       int i=0,j=0,a=0;
                       for(i=0;i<strlen(ch1)-3;i++)
                       {
                           mille[j++]=ch1[i];
                       }
                       int nombre=atoi(mille);
                       if(nombre!=0)
                       {
                           printf(" %s",chiffre[nombre]);
                           printf(" mille");
                       }

                       for(i=3;i<strlen(ch1);i++)
                       {
                           cent[a++]=ch1[i];
                       }
                       //cent[a]='\0';
                       int nombre2=atoi(cent);
                       if(nombre2!=0)
                       {
                           printf(" %s ",chiffre[nombre2]);
                       }
                   }
            // MILLLLLLLIONNNNN

    else
        if(strlen(ch1)>6 && strlen(ch1)<9)
            {
            char cent[3],mille[3],million[3];
            int i=0,j=0,k=0,a=0;
            int b=strlen(ch1)%3;
            for(i=0;i<b;i++)
                {
                million[j++]=ch1[i];
                }
            int nombre=atoi(million);
          if(nombre!=0)
          {  printf(" %s ",chiffre[nombre]);
              printf(" million ");}
            for(i=b;i<strlen(ch1)-3;i++)
                {
                mille[k++]=ch1[i];
                }
            int nombre2=atoi(mille);
          if(nombre!=0)
          {  printf(" %s",chiffre[nombre2]);
              printf(" mille ");}
            for(i=strlen(ch1)-3;i<strlen(ch1);i++)
                {
                cent[a++]=ch1[i];
                }
            int nombre3=atoi(cent);
            if(nombre3!=0) {
                printf(" %s",chiffre[nombre3]);
            }
        }
        // MILLLLLLLLLLLIONNNNNN EXACTE 9 NOMBRES
         else
            if(strlen(ch1)==9) {
                char cent[3],mille[3],million[3];
                int i=0,j=0,k=0,a=0;
                for(i=0;i<strlen(ch1)-6;i++)
                    {
                    million[j++]=ch1[i];
                    }
                //mille[j]='\0';
                int nombre=atoi(million);
                if(nombre!=0)
                    {
                    printf(" %s",chiffre[nombre]);
                    printf(" million ");
                    }
                for(i=strlen(ch1)-6;i<strlen(ch1)-3;i++) {
                    mille[k++]=ch1[i];
                }
                int nombre2=atoi(mille);
                if(nombre2!=0) {
                    printf(" %s",chiffre[nombre2]);
                    printf(" mille ");
                }
                for(i=strlen(ch1)-3;i<strlen(ch1);i++) {
                    cent[a++]=ch1[i];
                }
                int nombre3=atoi(cent);
                if(nombre3!=0) { printf(" %s",chiffre[nombre3]);}
            }
    else
        if(strlen(ch1)>9 && strlen(ch1)<12) {
            char cent[3],mille[3],million[3],milliard[3];
            int i=0,j=0,k=0,a=0,b=0;
            int c=strlen(ch1)%3;
            for(i=0;i<c;i++) {
                milliard[j++]=ch1[i];
            }
            int nombre=atoi(milliard);
         if(nombre!=0) {
             printf(" %s",chiffre[nombre]);
             printf(" milliard ");
         }
            for(i=c;i<strlen(ch1)-6;i++) {
                million[k++]=ch1[i];
            }
            int nombre2=atoi(million);
            if(nombre2!=0) {
                printf(" %s",chiffre[nombre2]);
                printf(" million ");
            }
            for(i=strlen(ch1)-6;i<strlen(ch1)-3;i++)
                {
                mille[a++]=ch1[i];
                }
            //mille[a]='\0';
            int nombre3=atoi(mille);
            if(nombre3!=0) {
                printf(" %s",chiffre[nombre3]);
                printf(" mille ");
            }

            for(i=strlen(ch1)-3;i<strlen(ch1);i++)
                {
                cent[b++]=ch1[i];
                }
           // cent[b]='\0';
            int nombre4=atoi(cent);
            if(nombre4!=0)
                {
                printf(" %s",chiffre[nombre4]);
                }
            }
       // MILLLLLLLLIAAAAARRRRRD EXACTE 12 NOMBRES

    else {
        char cent[3],mille[3],million[3],milliard[3];
        int i=0,j=0,k=0,a=0,b=0;
        for(i=0;i<strlen(ch1)-9;i++) {
            milliard[j++]=ch1[i];
        }
        //milliard[j]='\0';
        int nombre=atoi(milliard);
        printf(" %s",chiffre[nombre]);
        printf(" milliard ");
        for(i=strlen(ch1)-9;i<strlen(ch1)-6;i++) {
            million[k++]=ch1[i];
        }
        //million[k]='\0';
        int nombre2=atoi(million);
        if(nombre2!=0) {
            printf(" %s",chiffre[nombre2]);
            printf(" million ");
        }
        for(i=strlen(ch1)-6;i<strlen(ch1)-3;i++) {
            mille[a++]=ch1[i];
        }
        //mille[a]='\0';
        int nombre3=atoi(mille);
        if(nombre3!=0) {
            printf(" %s",chiffre[nombre3]);
            printf(" mille ");
        }

        for(i=strlen(ch1)-3;i<strlen(ch1);i++) {
            cent[b++]=ch1[i];
        }
        //cent[b]='\0';
        int nombre4=atoi(cent);
        if(nombre4!=0) {
            printf(" %s",chiffre[nombre4]);
        }

    }

}

 // PROCEDURE POUR LES REELS
void reel_to_lettre(char *ch) {
    int i=0,j=0;
    char *ent=(char*)calloc(12,sizeof(char));
    char *reel=(char*)calloc(12,sizeof(char));
    while(ch[i]!='.') {
        ent[j++]=ch[i];
        i++;
    }
    entier_to_lettre(ent);
    printf(" 'virgule'");
    int n=i,k=0;
    while(ch[n++]!='\0') {
        reel[k++]=ch[n];
    }
        int a=0,count =0;
        while(reel[a++]=='0') {
            count++;
        }
        char reels[1234];
        int z=0,r=count;
    if(count!=0) {
        while(reel[r]!='\0') {
            reels[z++]=reel[r++];
        }
        reels[z]='\0';
        printf(" %s ZERO ",chiffre[count]);
        entier_to_lettre(reels);

    }
    else
        entier_to_lettre(reel);
}


int main(void) {
    char *str;
  do {
      printf("entrer un nombre : ");
      str = saisir_chaine();
  }while(!valider_nombre(str));
    int type = Type_Nombre(str);
    if(type == ENTIER)
    {
        if(str[0] == '-')
        {
            printf(" moin_");
            entier_to_lettre(str);
        }
        else
        {
            entier_to_lettre(str);
        }
    }
    if(type == REEL) {

        if(str[0]=='-') {
            printf(" moin_");
            reel_to_lettre(str);
        }
        else
            reel_to_lettre(str);
    }
}