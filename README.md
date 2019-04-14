# C_Mysql_Program
C program which use mysql API to communicate with mysql server and recouver and save mysql data into a variable.

Only for linux user :

you need to install libmysqlclient-dev : 
sudo apt-get install libmysqlclient-dev

and compile the program with :
gcc -o output $(mysql_config --cflags) nomDeFichier.c $(mysql_config --libs)
