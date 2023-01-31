#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define STR_LENGTH 1024
#define MAX_COUNT 128

struct publishing
{
	int year;
	char name[STR_LENGTH];
	char city[STR_LENGTH];
};

typedef struct publishing Publishing;

struct book
{
	char name[STR_LENGTH];
	float price;
	int pageCount;
	char author[STR_LENGTH];
	Publishing publishing;
};

typedef struct book Book;

void getBooksByPublishingYear(Book books[], int size, int year, char* city)
{
	// ������ �������� �����:
	// "r" - ������
	// "w" - ������ (���� ����� ���, �� ��������)
	// "a" - �������� � ����� �����
	FILE* f = fopen("results.txt", "w");
	for (int i = 0; i < size; i++) {
		if (books[i].publishing.year > year && strcmp(books[i].publishing.city, city) == 0) {
			fprintf(f, "%s\n", books[i].name);
		}
	}
	// ���� ��� ������ � ���� �� ������� ���, �� ������ �� ���������.
	fclose(f);
}

void loadFromFile(Book books[], int* size, char* fileName)
{
	FILE* f = fopen(fileName, "r");
	// ���������� ��� ������ ������ �� �����
	char line[STR_LENGTH];
	// ���������� ��� ���������� ������ �� ����� (������� strtok)
	char* ptr;
	// ���������� ��� �������� ������ � ���������. (0 - ��� �����, 1 - ����, � �.�.)
	int index = 0;
	while (fgets(line, STR_LENGTH, f))
	{
		ptr = strtok(line, "|\n");
		index = 0;
		while (ptr)
		{
			switch (index)
			{
			case 0:
				strcpy(books[*size].name, ptr);
				break;
			case 1:
				sscanf(ptr, "%f", &books[*size].price);
				break;
			case 2:
				sscanf(ptr, "%i", &books[*size].pageCount);
				break;
			case 3:
				strcpy(books[*size].author, ptr);
				break;
			case 4:
				sscanf(ptr, "%i", &books[*size].publishing.year);
				break;
			case 5:
				strcpy(books[*size].publishing.name, ptr);
				break;
			case 6:
				strcpy(books[*size].publishing.city, ptr);
				break;
			}

			index++;
			ptr = strtok(NULL, "|\n");
		}
		// ����� ��������� ������ ������, ����������� ���-�� ��������� � �������
		(*size)++;
	}
	fclose(f);
}

int main()
{
	setlocale(0, "RU");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int size = 0;
	int year;
	char city[STR_LENGTH];
	Book books[MAX_COUNT];
	loadFromFile(books, &size, "input.txt");
	printf("������� ���: ");
	scanf("%d", &year);
	getchar();
	printf("������� �����: ");
	gets_s(city, STR_LENGTH);
	getBooksByPublishingYear(books, size, year, city);
	printf("������ ������� ��������� � ���� results.txt\n");
	return 0;
}