int kontrolload()
{
	int i=0;char c[1000];char c1[1000]; int teller=0;
	
	FILE* file=fopen("kredad.txt", "r");
	
	if(file==NULL){
		printf("Error! opening file");
		return 1;
	}
	
    while(fscanf(file,"%s",&c)!=EOF)
    {
    	if(i==0)
        printf("Jep username\n");
        else
        printf("Jep password\n");
        gets(c1);
        if(strcmp(c,c1)!=0)
        {
        	teller++;
		}
		i++;
    }
    
    if(teller!=0){
    	printf("\nTe dhenat nuk jane te sakta.\n");
    	return 1;
    }
}


int kontrollopf(char *str,int pass)
{
	int i=0;
	FILE* fp=fopen("profesor.txt", "r");
	
	struct profesor st;
	
	printf("Jep username\n");
    gets(str);
	printf("Jep password\n");
	scanf("%d",&pass);
	
    while(fscanf(fp,"%d %s %d %d",&st.id, &st.emerPerdoruesi,&st.fjalekalim,&st.status)!=EOF)
    {
        if(strcmp(str,st.emerPerdoruesi)==0 && pass==st.fjalekalim)
        {
        	printf("U logove me sukses.\n");
        	i++;
        	return 1;
		}
    }
    
    if(i!=1)
    printf("EmerPerdoruesi i profesorit ose fjalkalimi nuk eshte i sakte!\n");
}


int kontrollost(char *str,int pass)
{
	int i=0;
	FILE* fp=fopen("student.txt", "r");
	
	struct student st;
	
	printf("Jep username\n");
    gets(str);
	printf("Jep password\n");
	scanf("%d",&pass);
	
    while(fscanf(fp,"%d %s %d %d",&st.id, &st.emerPerdoruesi,&st.fjalekalim,&st.status)!=EOF)
    {
        if(strcmp(str,st.emerPerdoruesi)==0 && pass==st.fjalekalim)
        {
        	printf("U logove me sukses.\n");
        	i++;
        	return 1;
		}
    }
    
    if(i!=1)
    printf("EmerPerdoruesi i studentit ose fjalkalimi nuk eshte i sakte!\n");
}
