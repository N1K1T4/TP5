#include <cstdio>
#include "string.h"

int main(int argc,char* argv[])
{
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
	printf("%lu \n",s1.size());
	printf("%lu \n",s1.length());
	printf("%lu \n",s1.max_size());
	printf("%c\n",s2(2));
	printf("%c\n",s2(5));
	printf("%lu \n",s3.capacity());
	printf("%lu \n",s3.size());
	printf("%c\n",s3(4));
	s3[1]='b';
	printf(s3.c_str());
	printf("\n");
	s3.clear();
	printf("%lu \n",s3.capacity());
	printf("%lu \n",s3.size());
	s2=s3;
	printf(s2.c_str());
	printf("\n");
	s3=s3+'C';
	string s4 = s2 + s3;
	printf("La longueur de s2+s3 est %lu \n", s4.size());
	s1 = "Ceci est un string";
	printf("%lu \n",s1.size());
	printf(s1.c_str());
	printf("\n");
	printf("%c\n",s1(18));
	string s5=s4+'c';
	printf("%lu \n",s5.size());
	printf(s5.c_str());
	printf("\n");
	printf("%c\n",s1(17));
	printf("début test s6\n");
	string s6 = "Ceci est un string";
	printf("taille : %lu\n",s6.size());
	printf("capacité : %lu\n",s6.capacity());
	printf("char 0 : %c\n",s1(0));
	printf("char 1 : %c\n",s1(1));
	printf("char 2 : %c\n",s1(2));
	printf("chaîne : ");
	printf(s6.c_str());
	printf("\n");
	printf("fin test s6\n");
	return EXIT_SUCCESS;
}
