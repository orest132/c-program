void harto(char *str)
{
	FILE *fp;int nrpyt,i;char c;int pojo=0;
	
	printf("Je i sigurt qe deshiron te vazhdosh,nese po do te fshihen te gjitha pyetjet e meparshme\nneqoftese ke pasur dhe rezultatet e provimeve te testit te meparshem gjithashtu(shtyp 1),\nnese jo shtyp cfaredo\n");
	scanf("%d",&pojo);
	scanf("%c",&c);
	if(pojo!=1)
	{
		//mos bej gje
	}
	else{
		char fname[100]="";
		char rez[20]="Rezultatet";
		char ext[5]=".txt";
		
		char dpath[50]="C:\\Users\\User\\Desktop\\gjera uni\\"; 

		strcat(fname,dpath);
		strcat(fname,str);
		strcat(fname,rez);
		strcat(fname,ext);
		
		if( access(fname, F_OK ) != -1 )
		{
			remove(fname);
		}
		
		char fnamew[100]=""; 
		
		strcat(fnamew,dpath);
		strcat(fnamew,str);
		strcat(fnamew,ext);
		
		printf("Sa pyetje deshiron te shtosh?\n");
		scanf("%d",&nrpyt);
		scanf("%c",&c);
		
		struct pyetje py;
		
		fp=fopen(fnamew,"w");
		for(i=0;i<nrpyt;i++)
		{
			printf("Permbajtja e pyetjes %d:",i+1);
			gets(py.permpbajtja_e_pyetjes);
			printf("Pergjigja e sakte e pyetjes %d:",i+1);
			py.pergjigja_e_sakte=c = getchar();
			scanf("%c",&c);
			
			fprintf(fp,"%s\n%c\n",py.permpbajtja_e_pyetjes,py.pergjigja_e_sakte);
		}
		
		fclose(fp);
	}
}

void merrProv(char *str)
	{
		int nrprof,i,j;char c,c1;int shuma=0;int pojo;
		FILE *fp=fopen("profesor.txt","r");
		
		struct profesor st;
		
		while(fscanf(fp,"%d %s %d %d\n",&st.id,&st.emerPerdoruesi,&st.fjalekalim,&st.status)!=EOF)
		{
			printf("%d %s\n",st.id,st.emerPerdoruesi);
		}
		
		rewind(fp);
		printf("Jep numrin e profesorit qe jep lenden tende:\n");
		scanf("%d",&nrprof);
		scanf("%c",&c1);
		
		for(i=0;i<nrprof;i++)
		{
			fscanf(fp,"%d %s %d %d\n",&st.id,&st.emerPerdoruesi,&st.fjalekalim,&st.status);
		}
		fclose(fp);
		
		char fnamew[100]="";
		char ext[5]=".txt";  
		
		char dpath[50]="C:\\Users\\User\\Desktop\\gjera uni\\";
		
		strcat(fnamew,dpath);
		strcat(fnamew,st.emerPerdoruesi);
		strcat(fnamew,ext);
		
		if( access(fnamew, F_OK ) != -1 )
		{
			FILE *ff=fopen(fnamew,"r");
			i=0;
			
			struct pyetje py1[25];
			
			while(fgets(py1[i].permpbajtja_e_pyetjes,100,ff))
			{
				printf("%s",py1[i].permpbajtja_e_pyetjes);
				py1[i].pergjigja_e_sakte = fgetc(ff);
				fgetc(ff);
				i++;
			}
			
			fclose(ff);
			
			if(i>0)
			{
				for(j=0;j<i;j++)
				{
					char temp,c1;
					printf("Pergjigja e pyetjes %d eshte:",j+1);
					temp=getchar();
					scanf("%c",&c1);
					
					if(temp==py1[j].pergjigja_e_sakte)
						py1[j].vleresimi=1;
					else if(temp=='D')
						py1[j].vleresimi=0;
					else 
						py1[j].vleresimi=(-1);
						
					shuma=shuma+py1[j].vleresimi;
				}
				printf("Shuma e pikeve: %d\n",shuma);
				
				
				printf("Deshiron te shohesh liste te detajuar te pikeve: 1 per po dhe nr tjeter per jo.");
				scanf("%d",&pojo);
				if(pojo==1)
				{
					for(j=0;j<i;j++)
					{
						printf("Pyetja: %sVleresimi:%d\n",py1[j].permpbajtja_e_pyetjes,py1[j].vleresimi);
					}
					printf("\nShtyp cfaredo per te vazhduar:");
					getch();
				}
				
				char fname[100]="";
				char ext1[5]=".txt";  
				char rez1[15]="Rezultatet";
				
				strcat(fname,dpath);
				strcat(fname,st.emerPerdoruesi);
				strcat(fname,rez1);
				strcat(fname,ext1);
				
				FILE *file=fopen(fname,"a");
				
				fprintf(file,"%s",str);
				for(j=0;j<i;j++)
				{
					fprintf(file," %d",py1[j].vleresimi);
				}
				fprintf(file," %d\n",shuma);
			
				fclose(file);
			
			
			}
	
		}
		else
		{
			printf("\nKy profesor nuk ka nje provim te kartuar ne kete kohe.\n");
			printf("\nShtyp cfaredo per te vazhduar:");
			getch();
		}
		
	}
	
	void kontrollorez(char* str)
{
	int j;char string[100];
	FILE *fp=fopen("profesor.txt","r");
		
	struct profesor st;
	
	char dpath[50]="C:\\Users\\User\\Desktop\\gjera uni\\";
	char ext[5]=".txt";
	char rez[20]="Rezultatet";
	while(fscanf(fp,"%d %s %d %d\n",&st.id,&st.emerPerdoruesi,&st.fjalekalim,&st.status)!=EOF)
	{
		int i=0;
		char fnamew[100]="";
		
		strcat(fnamew,dpath);
		strcat(fnamew,st.emerPerdoruesi);
		strcat(fnamew,rez);
		strcat(fnamew,ext);
		
		char fname[100]="";
	
		strcat(fname,dpath);
		strcat(fname,st.emerPerdoruesi);
		strcat(fname,ext);

		
		if( access(fnamew, F_OK ) != -1 )
		{
			FILE* ff=fopen(fname,"r");
			
			while(fgets(string,100,ff))
			{
				i++;
			}
			i=i/2;
			fclose(ff);
		}
		
		if( access(fnamew, F_OK ) != -1 ) 
		{
		    // file exists
		    FILE *file=fopen(fnamew,"r");
		    struct rezultate rez;
			while(fscanf(file,"%s",rez.emerPerdoruesi)!=EOF)
			{
				for(j=0;j<i;j++)
				{
					fscanf(file,"%d",&rez.vleresim[j]);
				}
				fscanf(file,"%d",&rez.shuma_e_pikeve);
				
				if(strcmp(rez.emerPerdoruesi,str)==0)
				{
					printf("\nNe provimin me profesor %s ke nje total prej %d pikesh",st.emerPerdoruesi,rez.shuma_e_pikeve);
				}
			}
		}
		
	}
	printf("\n\nShtyp cfaredo per te vazhduar:");
	getch();
	printf("\n");	
}

void shikorez(char* str)
{
	int i=0;int j;int z=0,p=0, k=0;int pojo;int konst;int stop=0;
	char fnamew[100]="";
	char ext[5]=".txt";
	
	char string[100];
	
	char dpath[50]="C:\\Users\\User\\Desktop\\gjera uni\\"; //Default path
		
		strcat(fnamew,dpath);
		strcat(fnamew,str);
		strcat(fnamew,ext);
		
	FILE *fp=fopen(fnamew,"r");
	
	while(fgets(string,100,fp))
	{
		i++;
	}
	i=i/2;
	fclose(fp);
	char fnamew1[100]="";
	char smth[12]="Rezultatet";
	
	strcat(fnamew1,dpath);
	strcat(fnamew1,str);
	strcat(fnamew1,smth);
	strcat(fnamew1,ext);
	
	if( access(fnamew1, F_OK ) != -1 )
	{
		FILE *file=fopen(fnamew1,"r");
		
		struct rezultate rez[100];
	
	printf("\nRezultatet jane:\n");
	while(fscanf(file,"%s",rez[z].emerPerdoruesi)!=EOF)
	{
		for(j=0;j<i;j++)
		{
			fscanf(file,"%d",&rez[z].vleresim[j]);
		}
		fscanf(file,"%d",&rez[z].shuma_e_pikeve);
		z++;
	}
	
	for(p=0;p<z;p++)
	{
		printf("%s %d\n",rez[p].emerPerdoruesi,rez[p].shuma_e_pikeve);
	}
	
	printf("\nDeshiron te shohesh raporte te metejshme: 1 per po dhe cfaredo numer per jo\n");
	scanf("%d",&pojo);
	printf("\n");
	
	if(pojo==1)
	{
		konst=rez[0].shuma_e_pikeve;
		for(p=1;p<z;p++)
		{
			if(konst<rez[p].shuma_e_pikeve)
				konst=rez[p].shuma_e_pikeve;
		}
		printf("Studenti/studentet me piket me te larta jane: ",rez[p].emerPerdoruesi);
		
		for(p=0;p<z;p++)
		{
			if(konst==rez[p].shuma_e_pikeve)
			{
				printf("%s,",rez[p].emerPerdoruesi);
			}
		}
		printf(" me %d pike\n\nStudenti/studentet me 0 pike jane: ",konst);
		
		for(p=0;p<z;p++)
		{
			if(rez[p].shuma_e_pikeve==0)
			{
				printf("%s||",rez[p].emerPerdoruesi);
			}
		}
		printf("\n");
		
		int prev=0; int new1=0; int pyetja;
		for(p=0;p<i;p++)
		{
				for(k=0;k<z;k++)
				{
					if(rez[k].vleresim[p]<0)
						new1++;
				}
				if(new1>prev)
				{
					prev=new1;
					new1=0;
					pyetja=p;
				}
				else
				new1=0;
		}
		
		for(p=0;p<i;p++)
		{
			for(k=0;k<z;k++)
			{
				if(rez[k].vleresim[p]<0)
					new1++;
			}
			if(new1==prev)
			printf("\nPyetja %d ka me shume gabime me %d studente qe kane gabuar",p+1,prev);
			new1=0;
		}
		printf("\n");
		
		stop=rez[0].shuma_e_pikeve;
		for(p=1;p<z;p++)
		{
			if(rez[p].shuma_e_pikeve<stop)
			stop=rez[p].shuma_e_pikeve;
		}
		
		new1=0;
		prev=2000000;
		
		printf("\nLista sipas pikeve ne rend zbrites:");
		while(prev!=stop)
		{
			new1=-2000000;
			for(p=0;p<z;p++)
			{
				if(rez[p].shuma_e_pikeve>new1&&rez[p].shuma_e_pikeve<prev)
				new1=rez[p].shuma_e_pikeve;
				else if(new1==prev)
				stop++;
			}
			
			for(p=0;p<z;p++)
			{
				if(rez[p].shuma_e_pikeve==new1)
				printf("\n>%s %d",rez[p].emerPerdoruesi,new1);
			}
			
			prev=new1;
		}
		printf("\n");
		printf("\nShtyp cfaredo per te vazhduar:");
		getch();
	}
	
	fclose(file);
	}
	else
	{
		printf("\nJu nuk keni hartuar ende nje provim ose asnje student nuk e ka marre ende provimin tuaj.");
		printf("\nShtyp cfaredo per te vazhduar:");
		getch();
	}
}
