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

void readBook(Book* book)
{
	printf("��������: ");
	// scanf ������� ������ �� ������� �������
	// ����� ������� ��� ����� �������, ���������� ������������ gets
	gets_s(book->name, STR_LENGTH);
	printf("����: ");
	scanf("%f", &book->price);
	getchar();
	printf("����� �������: ");
	scanf("%d", &book->pageCount);
	getchar();
	printf("�����: ");
	gets_s(book->author, STR_LENGTH);
	printf("������������:\n");
	printf("\t��� �������: ");
	scanf("%d", &book->publishing.year);
	getchar();
	printf("\t��������: ");
	gets_s(book->publishing.name, STR_LENGTH);
	printf("\t�����: ");
	gets_s(book->publishing.city, STR_LENGTH);
}

void getBooksByPublishingYear(Book books[], int size, int year, char* city)
{
	for (int i = 0; i < size; i++) {
		if (books[i].publishing.year > year && strcmp(books[i].publishing.city, city) == 0) {
			printf("%s\n", books[i].name);
		}
	}
}

int main()
{
	// �������, ������� ������
	// struct book b1;
	// �������� ��� ������ typedef
	setlocale(0, "RU");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int size;
	int year;
	char city[STR_LENGTH];
	Book books[MAX_COUNT];
	printf("������� ���-�� ����: ");
	scanf("%d", &size);
	getchar();
	for (int i = 0; i < size; i++)
	{
		printf("����� %d\n", i + 1);
		readBook(&books[i]);
	}
	printf("������� ���: ");
	scanf("%d", &year);
	getchar();
	printf("\n������� �����: ");
	gets_s(city, STR_LENGTH);
	getBooksByPublishingYear(books, size, year, city);
	return 0;
}