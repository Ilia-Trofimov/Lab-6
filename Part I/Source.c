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
	printf("Название: ");
	// scanf чистает строку до первого пробела
	// Чтобы считать всю строк целиком, необходимо использовать gets
	gets_s(book->name, STR_LENGTH);
	printf("Цена: ");
	scanf("%f", &book->price);
	getchar();
	printf("Число страниц: ");
	scanf("%d", &book->pageCount);
	getchar();
	printf("Автор: ");
	gets_s(book->author, STR_LENGTH);
	printf("Издательство:\n");
	printf("\tГод издания: ");
	scanf("%d", &book->publishing.year);
	getchar();
	printf("\tНазвание: ");
	gets_s(book->publishing.name, STR_LENGTH);
	printf("\tГород: ");
	gets_s(book->publishing.city, STR_LENGTH);
}

int main()
{
	// Древний, длинный способ
	// struct book b1;
	// Решается при помощи typedef
	setlocale(0, "RU");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int size;
	Book books[MAX_COUNT];
	printf("Введите кол-во книг: ");
	scanf("%d", &size);
	getchar();
	for (int i = 0; i < size; i++)
	{
		printf("Книга %d\n", i + 1);
		readBook(&books[i]);
	}
	return 0;
}