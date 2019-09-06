#include "similarite_cycles.h"




int main(int argc, char *argv[])
{

	if( argc != 2)
		{
			fprintf(stdout,"Missing arguments (CHEBI ID) et taille max des cycles \n");
			exit(20);
		}
		//on recupère le chebi de la molécule passée en parametre
		int mol_courante;
		mol_courante = atoi(argv[1]);
		init_atom_num ();
		struct molecule *M = lecture_fichier_chebi();
		int position = position_M(mol_courante,M);
		GRAPHE_CYCLE c = construction_graphe_cycles(M[position]);

		//boucle
		
		char src[64];
		sprintf(src,"resultats/similarite_LC_%d_all.data",mol_courante);
		//fichiers des resultats 
		FILE *s = fopen(src,"w");
		if ( s == NULL)
		{
			fprintf(stdout,"Cannot open the file %s\n",src);
			exit(24);
		}

		char distrib[64];
		sprintf(distrib,"resultats/distri_LC_%d_all.data",mol_courante);
		//fichiers des resultats 
		FILE *file = fopen(distrib,"w");
		if ( file == NULL)
		{
			fprintf(stdout,"Cannot open the file %s\n",distrib);
			exit(25);
		}
		int i;

		GRAPHE_CYCLE d;
		float sim;
		int debut = chrono();
		for( i = 0; i< NB_MOLECULES ;i++)
		{
			
			nb_arete_base = 0;
			taille_base = 0;
			
			d = construction_graphe_cycles(M[i]);

			sim = similarite(c,d);
			fprintf(s, "%6d \t %6d \t %.6f\n",mol_courante,M[i].chebi_id,sim);
			fflush(s); 
			fprintf(file, "%.6f\n",sim);
			fflush(file); 
			//printf("La similarité  vaut : %f \n",sim);
			if( i %1 == 0)
			{ 
				fprintf(stdout,"\r%5d / %d couples %.3lf ",i + 1 ,NB_MOLECULES,chrono());
				fflush(stdout); 
			}
			liberer_graphe_cycles(d);
		}
		int fin=chrono();

		char temps[64];
		sprintf(temps,"resultats/temps_LC_test_%d.data",mol_courante);
		FILE *t = fopen(temps,"w");

		if( t == NULL)
		{
			fprintf(stdout,"Cannot create the file %s\n",temps);
			exit(87);
		}

		fprintf(t,"%d\n",fin - debut);
		//fin de la boucle
		liberer_graphe_cycles(c);
		fclose(file);
		fclose(s);
		fclose(t);


		int nb_mol;
		printf("3. Libération de la mémoire : %.3lf s\n",chrono());

		for(nb_mol=0 ; nb_mol < NB_MOLECULES ; nb_mol++) 
			liberer_molecule(M[nb_mol]);
		free(M);



		exit(0);

	
}
