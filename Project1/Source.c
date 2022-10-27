#include "Header.h"
main() {
	system("chcp 1251>nul");
	FILE* file;
	FILE* answer = fopen("answer.txt", "w+");
	char line[6];
	float a, b, c;
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
		if (size > 5) 
		{
			for (size_t i = 0; i < size; i++)
			{
				if ((text[i] == 44 || text[i] == 46) && i == 1) {
					char* f = calloc(3, 1);
					f[0] = text[i - 1];
					f[1] = text[i];
					f[2] = text[i + 1];
					a = atof(f);
					printf("%f ", a);
				}
				if ((text[i] == 44 || text[i] == 46) && i == 5) {
					char* f = calloc(3, 1);
					f[0] = text[i - 1];
					f[1] = text[i];
					f[2] = text[i + 1];
					b = atof(f);
					printf("%f ", a);
				}
				if ((text[i] == 44 || text[i] == 46) && i == 9) {
					char* f = calloc(3, 1);
					f[0] = text[i - 1];
					f[1] = text[i];
					f[2] = text[i + 1];
					c = atof(f);
					printf("%f ", a);
				}
			}
		}
		else {
			a = text[0] - '0';
			b = text[2] - '0';
			c = text[4] - '0';
		}

	}

	//QuadraticEquation(a, b, c,answer);
}

void QuadraticEquation(float a, float b, float c, FILE* file)
{
	float x1, x2, discriminant;
	discriminant = powf(b, 2.0) - 4 * a * c;
	if (discriminant < 0)
	{
		fprintf(file, "Дискриминанта нет");
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