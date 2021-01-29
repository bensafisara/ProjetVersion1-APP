
  #include <pthread.h>
  #include <stdio.h>
  #include <stdlib.h>
  #include "displayMatrix.h"

  int  **a;
  int  **b;
  int **mult_p ; 
  double tempsParalleleArchitectureRow=0;

  extern int N;
  int NumThr;


  int *VecteurNumDesThreads;

  void* funcaoR(void* arg);

  void initialisation(int nbTH){


  
  

  pthread_t *thread=(pthread_t*)malloc(sizeof(pthread_t)*nbTH);


  long i;
  clock_t beginP = clock();

  for(i=0;i<nbTH;i++)
    {
      //printf("Démarage du thread %ld\n", i);
      pthread_create(&thread[i], NULL, funcaoR, (void*)i);
    }
    

    for(i=0;i<nbTH;i++)
    {
      pthread_join(thread[i],NULL); 
    }




clock_t ENDp = clock();
tempsParalleleArchitectureRow = (double)(ENDp- beginP )/(CLOCKS_PER_SEC);

    printf("\nTemps Parallèle %f en secondes architecture en ligne\n", tempsParalleleArchitectureRow);
  }


















  void* funcaoR(void *arg) 
  {
  int   endRow;
  int i,j,x;
   //int id = *((int *)arg); 
  int id = arg; 
  //printf("thead number %d\n", id );
  int quantiteDeLigne = N/NumThr;
  //printf("Taille bloc = %d\n", quantiteDeLigne);
  /*int check=(int)quantiteDeLigne;*/
  int somme;

  if((id+1)==NumThr){

  endRow=N-1;

  }else{

  endRow=((id*quantiteDeLigne)+(quantiteDeLigne))-1;


  }

//printf("Thread %d: i-debut = %d; i-fin = %d\n", id, id*quantiteDeLigne, endRow);

  for(i=id*quantiteDeLigne;i<=endRow;i++)
  {
    for(j=0;j<N;j++)
    {
          mult_p[i][j]=0;   
        for(x=0; x<N; x++)
        {

        mult_p[i][j]  += a[i][x] * b[x][j];
        
      } 
    
    }
  }

   return (NULL);
  }




