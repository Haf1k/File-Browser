#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <direct.h>
#include <sys/stat.h>
#include "dirent.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

char text[255];

int pwd(void)
{
	char buffer[255];
	char space = " ";
	int size, length, i;
	_getcwd(text, sizeof(text) / sizeof(text[0]));
	printf("\n %s\n", text);

	struct stat st;

	DIR* d;
	struct dirent* dir;
	d = opendir(text);
	if (d)
	{
		while ((dir = readdir(d)) != NULL)
		{
			printf(" %s      ", dir->d_name);
			stat(dir->d_name, &st);
			size = st.st_size;
			length = strlen(dir->d_name);
			for (i = 0; i < (30 - length); i++)
			{
				printf(" ");
			}
			printf("%d Bytes ", size);

			snprintf(buffer, 10, "%d", size);

			length = strlen(buffer);

			for (i = 0; i < (20 - length); i++)
			{
				printf(" ");
			}
			printf("%s", ctime(&st.st_mtime));
		}
		closedir(d);
	}
	return(0);
}

int copyFunction(void)
{
	char ch, source_file[25], target_file[25];

	FILE* source, * target;

	printf("Enter name of file to copy\n");
	gets(source_file);

	source = fopen(source_file, "r");

	if (source == NULL)
	{
		perror("Error");
		getchar();
		main();
		return 0;
	}

	printf("Enter name of target file\n");

	gets(target_file);

	target = fopen(target_file, "w");

	if (target == NULL)
	{
		fclose(source);
		perror("Error");
		getchar();
		return 0;
	}

	while ((ch = fgetc(source)) != EOF)
		fputc(ch, target);

	printf("File copied successfully.\n");
	fclose(source);
	fclose(target);

	getchar();

	return 0;
}

int deleteFunction(void)
{
	int status;
	char file_name[25];

	printf("Enter the name of file you want to delete:\n");
	gets(file_name);

	status = remove(file_name);

	if (status == 0)
	{
		printf("%s file deleted successfully.\n", file_name);
	}
	else
	{
		status = _rmdir(file_name);
		if (status == 0)
		{
			printf("%s directory deleted successfully.\n", file_name);
		}
		else
		{
			printf("Unable to delete the file\n");
			perror("Error");
		}
	}

	getchar();

	return 0;
}

int upwards(void)
{
	_chdir("..");
}

int moveToFunction(void)
{
	char target[25];

	printf("Enter the name of directory you want to enter:\n");
	gets(target);

	_chdir(target);
}

int createFile(void)
{
	char file_name[25];
	char file_name_check = file_name;

	printf("Enter the name of file to create:\n");
	gets(file_name);

	FILE* new_file;
	new_file = fopen(file_name, "w+");

	if (new_file == NULL)
	{
		perror("Error");
		getchar();
		return 0;
	}

	fclose(new_file);

	return 0;
}

int renameFunction(void)
{
	int output;
	char file_name[25], new_name[25];
	printf("Enter name of file to rename:\n");
	gets(file_name);

	FILE* source_file = file_name;

	source_file = fopen(file_name, "r");

	if (source_file == NULL)
	{
		perror("Error");
		getchar();
		main();
		return 0;
	}

	fclose(source_file);

	printf("Enter new name of the file:\n");
	gets(new_name);

	output = rename(file_name, new_name);

	if (output == 0)
	{
		printf("File renamed successfully");
	}
	else
	{
		perror("Error");
		getchar();
	}

	return 0;
}

int moveFileFunction(void)
{
	int output;
	char file_name[25], new_path[255];
	printf("Enter name of file to move:\n");
	gets(file_name);

	FILE* source_file = file_name;

	source_file = fopen(file_name, "r");

	if (source_file == NULL)
	{
		perror("Error");
		getchar();
		main();
		return 0;
	}

	fclose(source_file);

	printf("Enter new path to the file:\n");
	gets(new_path);

	strcat(new_path, file_name);

	output = rename(file_name, new_path);

	if (output == 0)
	{
		printf("File moved successfully.");
		getchar();
	}
	else
	{
		perror("Error");
		getchar();
	}

	return 0;
}

int AddDirectoryFunction(void)
{
	char dir_name[25];

	printf("Enter the name of directory to create:\n");
	gets(dir_name);

	_mkdir(dir_name);

	printf("Directory created successfully.");

	return 0;

}
