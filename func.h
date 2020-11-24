#ifndef FUNC_H
#define FUNC_H
#include <string.h>

struct Vektor {
	int a, b, c, d;
};

static struct Vektor new(int a1, int b1, int c1, int d1) {
	return (struct Vektor){.a=a1, .b=b1, .c=c1, .d=d1};
}

static struct Vektor v_mul(struct Vektor v1, struct Vektor v2) {
	return new(v1.a+v2.a, v1.b+v2.b, v1.c+v2.c, v1.d+v2.d);
}

static struct Vektor v_div(struct Vektor v1, struct Vektor v2) {
	return new(v1.a-v2.a, v1.b-v2.b, v1.c-v2.c, v1.d-v2.d);
}

static struct Vektor v_sqrt(struct Vektor v1) {
	return new(v1.a/2, v1.b/2, v1.c/2, v1.d/2);
}

static struct Vektor v_pow(struct Vektor v1, int num) {
	return new(v1.a*num, v1.b*num, v1.c*num, v1.d*num);
}

static struct Vektor eqlString(char* string) {
	if (strcmp(string, "Laenge") == 0) 
	{
		 return new(1,0,0,0);
	} 
	else if (strcmp(string, "Masse") == 0) 
	{
		return new(0,1,0,0);
	}
	else if (strcmp(string, "Zeit") == 0)
	{
		return new(0,0,1,0);
	}
	else if (strcmp(string, "Strom") == 0)
	{
		return new(0,0,0,1);
	}
	else if (strcmp(string, "Eins") == 0)
	{
		return new(0,0,0,0);
	}
	else if (strcmp(string, "Flaeche") == 0)
	{
		return new(2,0,0,0);
	}
	else if (strcmp(string, "Volumen") == 0)
	{
		return new(3,0,0,0);
	}
	else if (strcmp(string, "Druck") == 0)
	{
		return new(-1,1,-2,0);
	}
	else if (strcmp(string, "Geschwindigkeit") == 0)
	{
		return new(1,0,-1,0);
	}
	else if (strcmp(string, "Beschleunigung") == 0)
	{
		return new(1,0,-2,0);
	}
	else if (strcmp(string, "Kraft") == 0)
	{
		return new(1,1,-2,0);
	}
	else if (strcmp(string, "Energie") == 0)
	{
		return new(2,1,-2,0);
	}
	else if (strcmp(string, "Leistung") == 0)
	{
		return new(2,1,-3,0);
	}
	else if (strcmp(string, "Spannung") == 0)
	{
		return new(2,1,-3,-1);
	}
	else if (strcmp(string, "Widerstand") == 0)
	{
		return new(2,1,-3,-2);
	}
	else if (strcmp(string, "Leitwert") == 0)
	{
		return new(-2,-1,3,2);
	}
	else if (strcmp(string, "Ladung") == 0)
	{
		return new(0,1,0,1);
	}
	else if (strcmp(string, "Elektrische-Feldstaerke") == 0)
	{
		return new(1,1,-3,-1);
	}
	else if (strcmp(string, "Stromdichte") == 0)
	{
		return new(-2,0,0,1);
	}
	else if (strcmp(string, "Magnetische-Flussdichte") == 0)
	{
		return new(1,0,-2,-1);
	}
	else if (strcmp(string, "Magnetische-Feldstaerke") == 0)
	{
		return new(0,-1,0,1);
	}
	else if (strcmp(string, "Leistungsdichte") == 0)
	{
		return new(0,1,-3,0);
	}
	else /* default: */
	{
		return new(80,80,80,80);
	}
}

static char* eqlVektor(struct Vektor v1) {
	if (v1.a==1 && v1.b==0 && v1.c==0 && v1.d==0) 
	{
		 return "Laenge";
	}
	else if (v1.a==0 && v1.b==1 && v1.c==0 && v1.d==0) 
	{
		 return "Masse";
	}
	else if (v1.a==0 && v1.b==0 && v1.c==1 && v1.d==0) 
	{
		 return "Zeit";
	} 
	else if (v1.a==0 && v1.b==0 && v1.c==0 && v1.d==1) 
	{
		 return "Strom";
	} 
	else if (v1.a==0 && v1.b==0 && v1.c==0 && v1.d==0) 
	{
		 return "Eins";
	} 
	else if (v1.a==2 && v1.b==0 && v1.c==0 && v1.d==0) 
	{
		 return "Flaeche";
	} 
	else if (v1.a==3 && v1.b==0 && v1.c==0 && v1.d==0) 
	{
		 return "Volumen";
	} 
	else if (v1.a==-1 && v1.b==1 && v1.c==-2 && v1.d==0) 
	{
		 return "Druck";
	} 
	else if (v1.a==1 && v1.b==0 && v1.c==-1 && v1.d==0) 
	{
		 return "Geschwindigkeit";
	} 
	else if (v1.a==1 && v1.b==0 && v1.c==-2 && v1.d==0) 
	{
		 return "Beschleunigung";
	} 
	else if (v1.a==1 && v1.b==1 && v1.c==-2 && v1.d==0) 
	{
		 return "Kraft";
	} 
	else if (v1.a==2 && v1.b==1 && v1.c==-2 && v1.d==0) 
	{
		 return "Energie";
	} 
	else if (v1.a==2 && v1.b==1 && v1.c==-3 && v1.d==0) 
	{
		 return "Leistung";
	} 
	else if (v1.a==2 && v1.b==1 && v1.c==-3 && v1.d==-1) 
	{
		 return "Spannung";
	} 
	else if (v1.a==2 && v1.b==1 && v1.c==-3 && v1.d==-2) 
	{
		 return "Widerstand";
	} 
	else if (v1.a==-2 && v1.b==-1 && v1.c==3 && v1.d==2) 
	{
		 return "Leitwert";
	} 
	else if (v1.a==0 && v1.b==1 && v1.c==0 && v1.d==1) 
	{
		 return "Ladung";
	} 
	else if (v1.a==1 && v1.b==1 && v1.c==-3 && v1.d==-1) 
	{
		 return "Elektrische-Feldstaerke";
	} 
	else if (v1.a==-2 && v1.b==0 && v1.c==0 && v1.d==1) 
	{
		 return "Stromdichte";
	} 
	else if (v1.a==1 && v1.b==0 && v1.c==-2 && v1.d==-1) 
	{
		 return "Magnetische-Flussdichte";
	} 
	else if (v1.a==0 && v1.b==-1 && v1.c==0 && v1.d==1) 
	{
		 return "Magnetische-Feldstaerke";
	} 
	else if (v1.a==0 && v1.b==1 && v1.c==-3 && v1.d==0) 
	{
		 return "Leistungsdichte";
	}
	else /* default: */
	{
		char x[20];
		char y[20];
		char z[20];
		char q[20];
		sprintf( x, "%d", v1.a );
		sprintf( y, "%d", v1.b );
		sprintf( z, "%d", v1.c );
		sprintf( q, "%d", v1.d );
		printf("Vektor A: %s B: %s, C: %s, D: %s \n", x, y, z, q);
			return "Syntaxfehler";
	}
			
}

#endif