#include <string.h>

struct profesor
{
	int id;
	char emerPerdoruesi[20];
	int fjalekalim;
	int status;
};

struct student
{
	int id;
	char emerPerdoruesi[20];
	int fjalekalim;
	int status;
};

struct pyetje
{
	char permpbajtja_e_pyetjes[500];
	char pergjigja_e_sakte;
	int vleresimi;
};

struct rezultate
{
	char emerPerdoruesi[20];
	int vleresim[60];
	int shuma_e_pikeve;
};

