//to compile -     gcc -o output $(mysql_config --cflags) nomDeFichier.c $(mysql_config --libs)
#include<stdio.h>
#include<stdlib.h>
#include<mysql/mysql.h>
#include <string.h>

static char *host = "adresseDeServeurmysql";
static char *user = "nomUtlisateurMysql";
static char *pass = "password";
static char *dbname = "nomDatabase";


unsigned int port = 8080;
static char *unix_socket = NULL;
unsigned int flag = 0;

int main()
{
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;

    conn = mysql_init(NULL);

    if (!(mysql_real_connect(conn, host, user, pass, dbname, port, unix_socket, flag)))
    {
        fprintf(stderr, "\nError: %s [%d]\n", mysql_error(conn), mysql_errno(conn));
        exit(1);
    }
    else
    printf ("Connection faite\n\n");

mysql_query(conn, "select * from client");
res = mysql_store_result(conn);

int compteur=0;
int *code = NULL;
int nbLigne = 0;

//Compteur des ligne dans la base de donnee
while (row = mysql_fetch_row(res))
{
  nbLigne++;
}

//declarer nbLigne variable de type ou la taille de MYSQL_ROW
code = malloc(nbLigne * sizeof(int));
printf("Nombre de ligne dans votre table sql : %d \n", nbLigne);


mysql_query(conn, "select * from client");
res = mysql_store_result(conn);

//enregistrer les code dans une variable reservé avant
while(row = mysql_fetch_row(res))
{
  code[compteur] = atoi(row[0]); //appeller la fonction pour convertir de type mysql_row a int, puis enregistre dans une variable reservé
  compteur++;
}

//afficher les valeur stocke dans la variable
for (int i = 0; i < nbLigne; i++)
{
  printf("le %d code est : %d\n", i+1, code[i]);

}

//fermer la Connection
mysql_close(conn);

//Pour liberer la place reserve
free(code);

//return EXIT_SUCCESS;
return 0;

}
