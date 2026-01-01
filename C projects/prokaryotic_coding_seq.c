#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char seq[1000];
	int len;
	int i;
	int j;
	int k;

	scanf("%s", seq);
	len = strlen(seq);


	for(i=0; i<len; i++)
	{
		if(seq[i]!='A' && seq[i]!='T' && seq[i]!='G' && seq[i]!='C')
		{
			printf("Non-DNA sequence imported.\n");
			exit(1);
		}
	}

	if (len<6)
	{
		printf("The sequence is too short to contain any coding sequence.\n");
		exit(1);
	}

	for(i=0; i<len-2; i++)
	{
		if(seq[i]=='A' &&seq[i+1]=='T' && seq[i+2]=='G')
		{
			for(j=i+3; j<len-2; j+=3)
			{
				if((seq[j]=='T' && seq[j+1]=='G' && seq[j+2]=='A') ||
				   (seq[j]=='T' && seq[j+1]=='A' && seq[j+2]=='G') ||
				   (seq[j]=='T' && seq[j+1]=='A' && seq[j+2]=='A'))
				{
					printf("There is a prokaryotic coding sequence.\n");
					printf("The sequence is: ");

					for(k=i; k<=j+2; k++)
					{
						printf("%c", seq[k]);
					}
					printf("\n");
					exit(0);
				}
			}
		}
	}
	printf("No prokaryotic coding sequence was found.\n");
	exit(0);
}
















