#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "lib/setConf.h"


int main(int argc, char* argv[])
{


	if (argc<2)
	{
		printf("Porta non inserita (./config porta)\n");
		return 1;
	}

	else
	{
		int port = atoi(argv[1]);
		if (port < 9000  || port > 9999 || strlen(argv[1])>4)
		{
			printf("Porta inserita non adatta al range richiesto (9000-9999)\n");
			return 1;
		}
		printf("**********Done**********\n");
		setConf("httpd.conf", argv[1]);
	}
	return 0;

}
