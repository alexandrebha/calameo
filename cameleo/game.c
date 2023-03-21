#include <stdlib.h>
#include <stdio.h>
#include <libTableauNoir.h>


typedef struct{
  Image rouge;
  Image vert;
  Image jaune;
  Image bleu;
  Image eteinte;
  Son bleu_son;
  Son vert_son;
  Son jaune_son;
  Son rouge_son;
  Son perdu;
} donnees_t;

void afficher_rouge(donnees_t);
void afficher_vert(donnees_t);
void afficher_jaune(donnees_t);
void afficher_bleu(donnees_t);

void afficher(int*, int, donnees_t);
int comparer(int* ,int, donnees_t);

donnees_t initialiser_donnees();




int main()
{
  creerTableau();
  fixerTaille( 800, 800);
  int tab[1000];
  int end = 0;
  int j = 0;
  donnees_t donnees = initialiser_donnees();
  
  while( end == 0 && j < 1000){
    afficherImage(donnees.eteinte,0 - tn_largeur(donnees.eteinte)/2, 0 + tn_hauteur(donnees.eteinte)/2);
    attendreNms(900);
    tab[j] = 1+rand()%4;
    afficher(tab, j, donnees);
    end = comparer(tab, j, donnees);
    j = j+1;
  }
  attendreFermeture();
  
 }

donnees_t initialiser_donnees(){
  donnees_t donnees;
  donnees.rouge = chargerImage("rouge.png");
  donnees.vert = chargerImage("vert.png");
  donnees.bleu = chargerImage("bleu.png");
  donnees.jaune = chargerImage("jaune.png");
  donnees.eteinte = chargerImage("eteinte.png");
  donnees.bleu_son = chargerAudio("bleu1.mp3");
  donnees.rouge_son = chargerAudio("rouge1.mp3");
  donnees.vert_son = chargerAudio("vert1.mp3");
  donnees.jaune_son = chargerAudio("jaune_audio.mp3");
  donnees.perdu = chargerAudio("perdu.mp3");
  
  return donnees;
}



void afficher(int * tab, int j, donnees_t donnees)                            // cette fonction affiche la séquence que l'on veut montrer au joueur
{
  for(int i = 0; i <= j ;i++){
		   
		    if (tab[i] == 1)
		     afficher_rouge(donnees);
		 
		    if (tab[i] == 2)
		      afficher_bleu(donnees);
		
		    if (tab[i] == 3)
		      afficher_jaune(donnees);
		
		    if (tab[i] == 4)
		      afficher_vert(donnees);
		  }

}






 int comparer(int * tab, int j, donnees_t donnees)          // cette fonction regarde si le joueur appuye sur la touche correspondant a la couleur stockée dans la chaine de caractere 
 {
	 EtatSourisClavier esc;
	 float dt = delta_temps();
	 
	 for(int i = 0; i <= j ;i++){
	   int h =0;
	   dt = 0;
	   while( dt <= 4 && h ==0){
	     afficherImage(donnees.eteinte,0 - tn_largeur(donnees.eteinte)/2, 0 + tn_hauteur(donnees.eteinte)/2);
		 esc = lireEtatSourisClavier();
		 if (esc.touchesClavier[21]){
		    if(tab[i] == 1){
		      
			 afficher_rouge(donnees);
			 h = 1;
			}
		    else{
		        jouerSon(donnees.perdu,0);
		  printf(" Vous avez perdu votre score est de %d\n", j);
		  return 1;
		}
	      }
		      
		 if (esc.touchesClavier[5]){
			if(tab[i] == 2){
			 afficher_bleu(donnees);
			 h = 1;
			}
		     else{
		        jouerSon(donnees.perdu,0);
		  printf(" Vous avez perdu votre score est de %d\n", j);
		  return 1;
		}
	      }
		
		 if (esc.touchesClavier[13]){
		   if(tab[i] == 3){
			 afficher_jaune(donnees);
			 h = 1;
			}
		      else {
		      jouerSon(donnees.perdu,0);
		  printf(" Vous avez perdu votre score est de %d\n", j);
		  return 1;
		}
	      }
		
		 if (esc.touchesClavier[25]){
		   if(tab[i] == 4){
			 afficher_vert(donnees);
			 h = 1;
			}
		      else{
			jouerSon(donnees.perdu,0);
		  printf(" Vous avez perdu votre score est de %d\n", j);
		  return 1;
		}
	      }
		  dt = dt + delta_temps(); 
	    }
		if (h == 0){
		  jouerSon(donnees.perdu,0);
		  printf(" Vous avez perdu votre score est de %d\n", j);
		  return 1;
	    }
	}	
return 0;

}


									// ces fonctions affichent une couleur chacune et elles jouent un son different par couleur


void afficher_rouge(donnees_t donnees)
{
	
	afficherImage(donnees.rouge,0 - tn_largeur(donnees.rouge)/2, 0 + tn_hauteur(donnees.rouge)/2);
	jouerSon(donnees.rouge_son,0);
	attendreNms(900);
}



void afficher_jaune(donnees_t donnees)
{
	
	afficherImage(donnees.jaune,0 - tn_largeur(donnees.jaune)/2, 0 + tn_hauteur(donnees.jaune)/2);
	jouerSon(donnees.jaune_son,0);
	attendreNms(900);
}



void afficher_bleu(donnees_t donnees)
{
  afficherImage(donnees.bleu,0 - tn_largeur(donnees.bleu)/2, 0 + tn_hauteur(donnees.bleu)/2);
  jouerSon(donnees.bleu_son, 0);
  attendreNms(900);
 }
 
 
 
void afficher_vert(donnees_t donnees)
{
	
	afficherImage(donnees.vert,0 - tn_largeur(donnees.vert)/2, 0 + tn_hauteur(donnees.vert)/2);
	jouerSon(donnees.vert_son, 0);
	attendreNms(900);
}

