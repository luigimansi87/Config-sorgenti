#include "lib/setConf.h"

// Genera il file httpd.conf recuperando l'attuale percorso dove verrà eseguito il config
char* setConf(char* path, char* port)
{

	char write[200];
	char *pwd;
	if (getDir() == NULL)
		perror("Errore nel recuperare il persorso attuale, file httpd.conf non generato correttamente");
	pwd=getDir();
	FILE *conf;
	conf=fopen(path, "w");
	sprintf(write, "wwwroot %s/\n", pwd);
	fprintf(conf, "%s",write);
	sprintf(write, "port %s\n", port);
	fprintf(conf, "%s",write);
	sprintf(write, "log_file %s/logs/log\n", pwd);
	fprintf(conf, "%s",write);
	fclose(conf);
	return "SUCCESS";


}

// chiama la funzione getwd() e la ritorna ad un puntatore char*
char* getDir()
{
	char *path= (char*) malloc(5000);
	getwd(path);
	if (path!=NULL)
	return path;
	else
	return NULL;
}
