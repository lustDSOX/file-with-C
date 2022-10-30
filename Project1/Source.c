#include "Header.h"
main() {
	system("chcp 1251>nul");
	FILE* file;
	FILE* answer = fopen("answer.txt", "w+t");
	float a, b, c;
	int bool = 0;
	if ((file = fopen("1.txt", "r")))
	{
		fseek(file, 0, SEEK_END);
		long size = ftell(file);
		fseek(file, 0, SEEK_SET);
		char* text = calloc(size, 1);
		for (size_t i = 0; i < size; i++)
		{
			text[i] = fgetc(file);
		}
		for (size_t i = 0; i < size; i++)
		{
			if (text[i] == '\n') {
				bool = 1;
			}
			if (text[i] < -1 || text[i] >96) {
				printf("Введите другие значения");
				return 1;
			}
		}
		fseek(file, 0, SEEK_SET);
		if (bool == 1) {
			fscanf(file, "%f\n%f\n%f", &a, &b, &c);
			printf("a = %f\nb = %f\nc = %f", a, b, c);
		}
		else
		{
			fscanf(file, "%f %f %f", &a, &b, &c);
			printf("a = %f\nb = %f\nc = %f", a, b, c);
		}

	}

	QuadraticEquation(a, b, c, answer);
}

void QuadraticEquation(float a, float b, float c, FILE* file)
{
	float x1, x2, discriminant;
	discriminant = powf(b, 2.0) - 4 * a * c;
	if (discriminant < 0 || a==0)
	{
		fprintf(file, "Решения нет");
		return 1;
	}
	if (discriminant == 0)
	{
		x1 = (-b) / (2 * a);
		fprintf(file, "Дискриминант равен %f\n", discriminant);
		fprintf(file, "x1 = %f", x1);
	}
	if (discriminant > 0)
	{
		x1 = ((-b) - sqrt(discriminant)) / (2 * a);
		x2 = ((-b) + sqrt(discriminant)) / (2 * a);
		fprintf(file, "Дискриминант равен %f\n", discriminant);
		fprintf(file, "x1 = %f, x2 = %f", x1, x2);
	}
}