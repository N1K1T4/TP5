#include <cstdio>
#include "string.h"

int main(int argc, char* argv[])
{
	(void)argc;
	(void)argv;
	string s0;
	string s1(5);
	string s2(5,'a');
	string s3(s2);
	printf("%lu \n",s0.size());
	printf("%lu \n",s1.size());
	printf("%lu \n",s1.capacity());
	s1.reserve(10);
	printf("La capacité de s1 est %lu \n", s1.capacity());
	printf("La taille de s1 est %lu \n", s1.size());
	printf("s1 :\nsize : %lu \n",s1.size());
	printf("length : %lu \n",s1.length());
	printf("max size :%lu \n",s1.max_size());
	printf("%c\n",s2(2));
	printf("%c\n",s2(5));
	printf("%lu \n",s3.capacity());
	printf("%lu \n",s3.size());
	printf("%c\n",s3(4));
	s3[1]='b';
	printf("%s \n", s3.c_str());
	printf("\n");
	s3.clear();
	printf("%lu \n",s3.capacity());
	printf("%lu \n",s3.size());
	s2=s3;
	printf("%s \n", s2.c_str());
	printf("\n");
	s3=s3+'C';
	string s4 = s2 + s3;
	printf("La longueur de s2+s3 est %lu \n", s4.size());
	s1 = "Ceci est un string";
	printf("%lu \n",s1.size());
	printf("%s \n", s1.c_str());
	printf("\n");
	printf("%c\n",s1(18));
	string s5=s4+'c';
	printf("%lu \n",s5.size());
	printf("%s \n", s5.c_str());
	printf("\n");
	printf("%c\n",s1(17));
	printf("début test s6 (Ceci est un string)\n");
	string s6;
	s6 = "Ceci est un string";
	printf("taille : %lu\n",s6.size());
	printf("capacité : %lu\n",s6.capacity());
	printf("char 0 : %c\n",s6(0));
	printf("char 1 : %c\n",s6(1));
	printf("char 2 : %c\n",s6(2));
	printf("char 17 : %c\n",s6(17));
	printf("char 17 = null char : %s\n", s6(17) == 0 ? "vrai" : "faux");
	printf("char 18 = null char : %s\n", s6(18) == 0 ? "vrai" : "faux");
	printf("char 19 : %c\n",s6(19));
	printf("chaîne : ");
	printf("%s \n", s6.c_str());
	printf("\n");
	printf("fin test s6\n");

	string s7("42 is the answer"); // TESTS AMBRE
	s7.resize(s7.size() + 4, '+');
	printf("On ajoute 4 + a la fin de la chaine\n");
	printf("%s \n", s7.c_str());
	s7.resize(s7.size() - 9);
	printf("On retire les 9 derniers caracteres de la chaine\n");
	printf("%s \n", s7.c_str());
	string s8 = s7 + (const char *)"nswer";
	printf("%s \n", s8.c_str());
	return EXIT_SUCCESS;
}
