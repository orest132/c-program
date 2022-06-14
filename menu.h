int menuAdmin()
{
	system("cls"); //pastron faqen e perdoruesit nga informacione te meparshme
	int opsion; char kot;
	printf("Menu Admini");
	printf("\n[ 1 ] Shto profesor");
	printf("\n[ 2 ] Shto student");
	printf("\n[ 3 ] Ndrysho status per profesor");
	printf("\n[ 4 ] Ndrysho status per student");
	printf("\n[-1 ] Dil");
	
	printf("\n\nZgjidh nje opsion:");
	scanf("%d",&opsion);
	scanf("%c",&kot);
	switch(opsion)
	{
		case 1:
			shtopf();
		break;
		case 2:
			shtost();
		break;
		case 3:
			ndryshopf();
		break;
		case 4:
			ndryshost();
		break;
		case -1:
		return 1;
		break;
		default:
		printf("\nOpsioni nuk vlen, zgjidh perseri.\n\n");
	}
}

int menuProf(char *str)
{
	system("cls");
	int opsion=0; char kot;
	printf("Menu Profesori");
	printf("\n[ 1 ] Harto");
	printf("\n[ 2 ] Shiko rezultate provimi");
	printf("\n[-1 ] Dil");
	
	printf("\n\nZgjidh nje opsion:");
	scanf("%d",&opsion);
	scanf("%c",&kot);
	if(opsion==1)
	harto(str);
	else if(opsion==2)
	shikorez(str);
	else if(opsion==-1)
	return 1;
	else
	printf("\nOpsioni nuk vlen, zgjidh perseri.\n\n");
	
}

int menuStud(char *str)
{
	system("cls");
	int opsion=0; char kot;
	printf("Menu Studenti");
	printf("\n[ 1 ] Merr provim");
	printf("\n[ 2 ] Shiko rezultate provimi");
	printf("\n[-1 ] Dil");
	
	printf("\n\nZgjidh nje opsion:");
	scanf("%d",&opsion);
	scanf("%c",&kot);
	switch(opsion)
	{
		case 1:
			merrProv(str);
		break;
		case 2:
			kontrollorez(str);
		break;
		case -1:
		return 1;
		break;
		default:
		printf("\nOpsioni nuk vlen, zgjidh perseri.\n\n");
	}
	
}


