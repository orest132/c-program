#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <conio.h>
#include "struct.h"
#include "verifiko.h"
#include "admin-options.h"
#include "studentdheprof-opt.h"
#include "menu.h"


int main()
{
	char str[20]; int pass;
	int option,nr;char q;

	while(1)
	{
	repeat:
		system("cls");
		printf("Menu");
		printf("\n[ 1 ] Admin");
		printf("\n[ 2 ] Profesor");
		printf("\n[ 3 ] Student");
		printf("\n[-1 ] Dil");
		
		printf("\n\nZgjidh nje opsion:");
		
		scanf("%d",&option);
		scanf("%c",&q);
		switch(option)
		{
			case 1:
				if(kontrolload()==1)
				{
					sleep(3);
					goto repeat;
				}
				while(menuAdmin()!=1){}
			break;
			case 2:
				if(kontrollopf(str,pass)!=1)
				{
					scanf("%c",&q);
					sleep(3);
					goto repeat;
				}
				while(menuProf(str)!=1){}
			break;
			case 3:
				if(kontrollost(str,pass)!=1)
				{
					scanf("%c",&q);
					sleep(3);
					goto repeat;
				}
				while(menuStud(str)!=1){}
			break;
			case -1:
			return 1;
			break;
			default:
			printf("\nOpsioni nuk vlen, zgjidh perseri.\n\n");
			
		}
	}
}
