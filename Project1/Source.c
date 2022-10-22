#include "Header.h"
main() {
	system("chcp 1251>nul");
	FILE* file;
	FILE* answer = fopen("answer.txt","w+");
	char line[6];
	float x1, x2, a, b, c;
	if ((file = fopen("1.txt", "r"))) 
	{
		fgets(line, 6, file);
		if((line[4] == 0) || ((line[0] < 0) || (line[2] < 0) || (line[4] < 0)))
		{
			printf("введены неполные данные или нечисловые символы ");
			return 1;
		}

		if (line[1] == 10) 
		{
			a = line[0]- '0';

			fgets(line, 6, file);
			b = line[0] - '0';

			fgets(line, 6, file);
			c = line[0] - '0';
		}
		else
		{
			a = line[0] - '0';
			b = line[2] - '0';
			c = line[4] - '0';
		}
	}

	QuadraticEquation(a, b, c,answer);
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
		fprintf(file, "Дискриминант равен %f\n",discriminant);
		fprintf(file, "x1 = %f", x1);
	}
	if (discriminant > 0)
	{
		x1 = ((-b) - sqrt(discriminant)) / (2 * a);
		x2 = ((-b) + sqrt(discriminant)) / (2 * a);
		fprintf(file, "Дискриминант равен %f\n", discriminant);
		fprintf(file, "x1 = %f, x2 = %f", x1,x2);
	}
}