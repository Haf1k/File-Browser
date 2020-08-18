#include "functions.h"

int main(void)
{
	char  cmd;

	do
	{
		system("cls");

		pwd();
		printf("\nCOMMANDS\n\n");
		printf("N: New file     ");
		printf("A: Add directory     ");
		printf("C: Copy     ");
		printf("M: Move file     ");
		printf("D: Delete     ");
		printf("R: Rename     ");
		printf("T: Move to directory     ");
		printf("U: Move one directory upwards     ");
		printf("Q: Quit\n\n");

		cmd = tolower(getchar());
		while (getchar() != '\n');

		switch (cmd)
		{
		case 'c':
			copyFunction();	
			break;
		case 'd':
			deleteFunction();
			break;
		case 'u':
			upwards();
			break;
		case 't':
			moveToFunction();
			break;
		case 'n':
			createFile();
			break;
		case 'r':
			renameFunction();
			break;
		case 'm':
			moveFileFunction();
			break;
		case 'a':
			AddDirectoryFunction();
			break;
		}
	} while (cmd != 'q');  
	return 0;
}