#include <stdio.h>
#include <string.h>

#define N_LIGNES 4
#define N_COLONNES 5

char lettre[][N_LIGNES][N_COLONNES]={
  {{' ',' ',' ',' ',' '}
   ,{' ',' ','/','\\',' '}
   ,{' ','/','-','-','\\'}
   ,{' ',' ',' ',' ',' '}},

  {{' ',' ','_',' ',' '}
   ,{' ','|','_',')',' '}
   ,{' ','|','_',')',' '}
   ,{' ',' ',' ',' ',' '}},

  {{' ',' ','_',' ',' '}
   ,{' ','/',' ',' ',' '}
   ,{' ','\\','_',' ',' '}
   ,{' ',' ',' ',' ',' '}},

  {{' ',' ','_',' ',' '}
   ,{' ','|',' ','\\',' '}
   ,{' ','|','_','/',' '}
   ,{' ',' ',' ',' ',' '}},

  {{' ',' ','_',' ',' '}
   ,{' ','|','_',' ',' '}
   ,{' ','|','_',' ',' '}
   ,{' ',' ',' ',' ',' '}},

  {{' ',' ','_',' ',' '}
   ,{' ','|','_',' ',' '}
   ,{' ','|',' ',' ',' '}
   ,{' ',' ',' ',' ',' '}},

  {{' ',' ','_',' ',' '}
   ,{' ','/','_',' ',' '}
   ,{' ','\\','_','|',' '}
   ,{' ',' ',' ',' ',' '}},

  {{' ',' ',' ',' ',' '}
   ,{' ','|','_','|',' '}
   ,{' ','|',' ','|',' '}
   ,{' ',' ',' ',' ',' '}},

  {{' ',' ',' ',' ',' '}
   ,{' ','|',' ',' ',' '}
   ,{' ','|',' ',' ',' '}
   ,{' ',' ',' ',' ',' '}},

  {{' ',' ',' ','_',' '}
   ,{' ',' ',' ','|',' '}
   ,{' ','\\','_','/',' '}
   ,{' ',' ',' ',' ',' '}},

  {{' ',' ',' ',' ',' '}
   ,{' ','|','/',' ',' '}
   ,{' ','|','\\',' ',' '}
   ,{' ',' ',' ',' ',' '}},

  {{' ',' ',' ',' ',' '}
   ,{' ','|',' ',' ',' '}
   ,{' ','|','_',' ',' '}
   ,{' ',' ',' ',' ',' '}},

  {{' ',' ',' ',' ',' '}
   ,{' ','|','\\','/','|'}
   ,{' ','|',' ',' ','|'}
   ,{' ',' ',' ',' ',' '}},

  {{' ',' ',' ',' ',' '}
   ,{' ','|','\\','|',' '}
   ,{' ','|',' ','|',' '}
   ,{' ',' ',' ',' ',' '}},

  {{' ',' ','_',' ',' '}
   ,{' ','/',' ','\\',' '}
   ,{' ','\\','_','/',' '}
   ,{' ',' ',' ',' ',' '}},

  {{' ',' ','_',' ',' '}
   ,{' ','|','_',')',' '}
   ,{' ','|',' ',' ',' '}
   ,{' ',' ',' ',' ',' '}},

  {{' ',' ','_',' ',' '}
   ,{' ','/',' ','\\',' '}
   ,{' ','\\','_','\\',' '}
   ,{' ',' ',' ',' ',' '}},

  {{' ',' ','_',' ',' '}
   ,{' ','|','_',')',' '}
   ,{' ','|',' ','\\',' '}
   ,{' ',' ',' ',' ',' '}},

  {{' ',' ','_',' ',' '}
   ,{' ','(',' ',' ',' '}
   ,{' ','_',')',' ',' '}
   ,{' ',' ',' ',' ',' '}},

  {{' ','_','_','_',' '}
   ,{' ',' ','|',' ',' '}
   ,{' ',' ','|',' ',' '}
   ,{' ',' ',' ',' ',' '}},

  {{' ',' ',' ',' ',' '}
   ,{' ','|',' ','|',' '}
   ,{' ','\\','_','/',' '}
   ,{' ',' ',' ',' ',' '}},

  {{' ',' ',' ',' ',' '}
   ,{' ','\\',' ',' ','/'}
   ,{' ',' ','\\','/',' '}
   ,{' ',' ',' ',' ',' '}},

  {{' ',' ',' ',' ',' '}
   ,{' ','|',' ',' ','|'}
   ,{' ','|','/','\\','|'}
   ,{' ',' ',' ',' ',' '}},

  {{' ',' ',' ',' ',' '}
   ,{' ','\\','/',' ',' '}
   ,{' ','/','\\',' ',' '}
   ,{' ',' ',' ',' ',' '}},

  {{' ',' ',' ',' ',' '}
   ,{' ','\\','_','/',' '}
   ,{' ',' ','|',' ',' '}
   ,{' ',' ',' ',' ',' '}},

  {{' ','_','_',' ',' '}
   ,{' ',' ','/',' ',' '}
   ,{' ','/','_',' ',' '}
   ,{' ',' ',' ',' ',' '}}};


char espace[N_LIGNES][N_COLONNES]=
{{' ',' ',' ',' ',' '}
   ,{' ',' ',' ',' ',' '}
   ,{' ',' ',' ',' ',' '}
   ,{' ',' ',' ',' ',' '}};

void affiche(const char message[]) {

  for(int i=0;i<4;i++){
    for (int j = 0; message[j] != '\0'; j++){
      int x=message[j];
      if(x==32){
        for(int y=0;y<5;y++){
          char ch=espace[i][y];
          printf("%c",ch);
        }
      }
      else{
        for(int y=0;y<5;y++){
          char ch=lettre[x-65][i][y];
          printf("%c",ch);
        }
      }
    }
    printf("\n");
  }

}

int main(void) {

  const char* message="HELLO WORLD";
  affiche(message);
  return 0;
}