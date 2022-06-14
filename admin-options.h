void shtost()
{
	int curr_id=1; int i=0;
	FILE *fp=fopen("student.txt","r");
	struct student pf;
	while(fscanf(fp,"%d %s %d %d\n",&pf.id,&pf.emerPerdoruesi,&pf.fjalekalim,&pf.status)!=EOF)
	{
		curr_id++; 
	}
	fclose(fp);
	
	FILE *ff=fopen("student.txt","a");
	
	struct student st;
	st.id=curr_id;
	repeat:
		printf("Jep emrin e studentit ne formatin 'EmerMbiemer'\n"); 
		gets(st.emerPerdoruesi);
		for(i;i<strlen(st.emerPerdoruesi);i++)
		{
			if(st.emerPerdoruesi[i]==32)
			{
				printf("Mos perdorni space per emrin e perdoruesit\n");
				goto repeat;
			}
		}
	st.status=0;
	st.fjalekalim=gjeneroFjalekalim(st.id,st.emerPerdoruesi);
	fprintf(ff,"%d %s %d %d\n",st.id,st.emerPerdoruesi,st.fjalekalim,st.status); 
	fclose(ff);
}

void shtopf()
{
	int curr_id=1;int i=0;
	FILE *fp=fopen("profesor.txt","r");
	struct profesor pf;
	while(fscanf(fp,"%d %s %d %d\n",&pf.id,&pf.emerPerdoruesi,&pf.fjalekalim,&pf.status)!=EOF)
	{
		curr_id++;
	}
	fclose(fp);
	
	FILE *ff=fopen("profesor.txt","a");
	
	struct profesor st;
	st.id=curr_id;
	repeat:
		printf("Jep emrin e profesorit ne formatin 'EmerMbiemer'\n");
		gets(st.emerPerdoruesi);
		for(i;i<strlen(st.emerPerdoruesi);i++)
		{
			if(st.emerPerdoruesi[i]==32)
			{
				printf("Mos perdorni space per emrin e perdoruesit\n");
				goto repeat;
			}
		}
	st.status=0;
	st.fjalekalim =gjeneroFjalekalim(st.id,st.emerPerdoruesi);
	fprintf(ff,"%d %s %d %d\n",st.id,st.emerPerdoruesi,st.fjalekalim,st.status);
	fclose(ff);
}

int gjeneroFjalekalim(int ID, char* emerMbiemer)
{
	int shuma,i;
	for(i=0;i<strlen(emerMbiemer);i++)
	{
		shuma+=emerMbiemer[i];
	}
	
	shuma=shuma*ID;
	return shuma;
}

void ndryshopf()
{
	char str[20];
	int j=0;
	
	FILE *fp=fopen("profesor.txt","r");
	FILE *ff=fopen("dummy.txt","w");
	
	struct profesor st;
	printf("Jep emrin e profesorit qe do ti ndyshoni statusin\n");
	gets(str);
	
	do{
		j++;
		if(fscanf(fp,"%d %s %d %d",&st.id, &st.emerPerdoruesi,&st.fjalekalim,&st.status)==EOF) 
		break;
	}
	while(strcmp(str,st.emerPerdoruesi)!=0);
	
	rewind(fp);
	int i=0;
	
	while(fscanf(fp,"%d %s %d %d",&st.id,&st.emerPerdoruesi,&st.fjalekalim,&st.status)!=EOF)
	{
		i++;
		if(i==j)
		{
			if(st.status==0)
			st.status=1;
			else
			st.status=0;
		}
		
		fprintf(ff,"%d %s %d %d\n",st.id,st.emerPerdoruesi,st.fjalekalim,st.status);
	}

	fclose(fp);
	fclose(ff);
	
	rename("dummy.txt","profesor1.txt");
	rename("profesor.txt","dummy.txt");
	rename("profesor1.txt","profesor.txt");
}

int ndryshost()
{
	char str[20];
	int j=0;
	
	FILE *fp=fopen("student.txt","r");
	FILE *ff=fopen("dummy.txt","w");
	
	struct student st;
	printf("Jep emrin e studentit qe do ti ndyshoni statusin\n");
	gets(str);
	do{
		fscanf(fp,"%d %s %d %d",&st.id, &st.emerPerdoruesi,&st.fjalekalim,&st.status);
		j++;
	}
	while(strcmp(str,st.emerPerdoruesi)!=0);
	
	rewind(fp);
	int i=0;
	
	while(fscanf(fp,"%d %s %d %d",&st.id,&st.emerPerdoruesi,&st.fjalekalim,&st.status)!=EOF)
	{
		i++;
		if(i==j)
		{
			if(st.status==0)
			st.status=1;
			else
			st.status=0;
		}
		
		fprintf(ff,"%d %s %d %d\n",st.id,st.emerPerdoruesi,st.fjalekalim,st.status);
	}

	fclose(fp);
	fclose(ff);
	
	rename("dummy.txt","student1.txt");
	rename("student.txt","dummy.txt");
	rename("student1.txt","student.txt");
}
