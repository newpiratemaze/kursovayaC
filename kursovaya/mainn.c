#include<stdio.h>
#include<locale.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

struct graphic_tablet
{
	char manufacturer[50];
	char type[50];
	char matrix_technology[50];
	char format[50];
	float sensivity;
	int resolution;
	char os_support[50];
	char connection_type[50];
	int workingspace_width;
	char input_method[50];
	int button_amount;
	char color[50];
};
typedef struct graphic_tablet gtablet;

int recordCount = 0;
int rec = 0;
int counnt = 0;
int anothercount = 0;
int anotheramount = 0;

int addRecord(gtablet tablet[]);
int addsomeRecord(gtablet tablet[], int amount);
int searchRecord(gtablet tablet[], int resolution, int workingspace_width);
int searchRecordWidth(gtablet tablet[], int workingspace_width);
int searchRecordResolution(gtablet tablet[], int resolution);
char savetofile(gtablet tablet[]);
char readfromfile(gtablet tablet[], int* num);
int putRecords(gtablet tablet[], int choice2);
int changeRecord(gtablet tablet[], int number);
int deleteRecords(gtablet tablet[], int delnum);

void main()
{
	setlocale(LC_ALL, "RUS");
	gtablet tablet[1001];
	int choice;
	int resolution;
	int workingspace_width;
	int choice2;
	int number;
	int num = 0;
	int amount;
	int delnum;

	do
	{
		printf("\nМеню:\n");
		printf("1. Создать новую запись\n");
		printf("2. Найти запись\n");
		printf("3. Сохранить данные в файл\n");
		printf("4. Загрузить данные из файла\n");
		printf("5. Печать всех записей\n");
		printf("6. Изменить запись\n");
		printf("7. Удалить записи в файле\n");
		printf("8. Очистить загруженные данные\n");
		printf("0. Выход\n");
		printf("Выберите опцию: ");
		scanf_s("%d", &choice);
		getchar();

		switch (choice)
		{
		case 1:
		{
			printf("Выберите вариант добавления записи(ей):\n1) Добавить одну запись\n2) Добавить несколько записей\n");
			scanf_s("%d", &amount);

			switch (amount)
			{
			case 1:
			{

				addRecord(tablet);
				anothercount++;
				savetofile(tablet);
				printf("\n");
				break;
			}
			case 2:
			{
				printf("Введите количество добавляемых записей - ");
				scanf_s("%d", &amount);
				anotheramount = amount;
				printf("\n");
				addsomeRecord(tablet, amount);
				anothercount += amount;
				savetofile(tablet);
				printf("\n");
				break;
			}
			default:
			{
				printf("Необходимо ввести одну из предложенных цифр!\n");
				break;
			}
			}
			break;

		}
		case 2:
		{
			printf("Выберите вариант поиска:\n1) По ширине рабочей области\n2) По разрешению\n3) По обоим параметрам\n");
			int choicecase2;
			scanf_s("%d", &choicecase2);
			if (choicecase2 != 1 && choicecase2 != 2 && choicecase2 != 3)
			{
				printf("Неверный ввод!\n");
				break;
			}
			switch (choicecase2)
			{
			case 1:
			{
				printf("Введите ширину рабочей области для поиска - ");
				scanf_s("%d", &workingspace_width);
				printf("\n");
				searchRecordWidth(tablet, workingspace_width);
				break;
			}
			case 2:
			{
				printf("Введите разрешение для поиска - ");
				scanf_s("%d", &resolution);
				printf("\n");
				searchRecordResolution(tablet, resolution);
				break;
			}
			case 3:
			{
				printf("Введите разрешение для поиска - ");
				scanf_s("%d", &resolution);
				printf("\n");
				printf("Введите ширину рабочей области для поиска - ");
				scanf_s("%d", &workingspace_width);
				printf("\n");
				searchRecord(tablet, resolution, workingspace_width);
				printf("\n");
				break;
			}
			}
			break;

		}
		case 3:
		{
			savetofile(tablet);
			break;
		}
		case 4:
		{


			//printf("counnt- %d\n", counnt);
			if (counnt > 0)
			{
				printf("Данные уже загружены!\n");
				break;
			}
			readfromfile(tablet, &num);
			counnt++;
			//printf("counnt- %d\n", counnt);
			break;
		}
		case 5:
		{
			printf("Выберите признак сортировки:\n1) Производитель\n2) Цвет\n3) Оба признака\n");
			scanf_s("%d", &choice2);
			if (choice2 != 1 && choice2 != 2 && choice2 != 3)
			{
				printf("Неверный ввод!\n");
				break;
			}
			putRecords(tablet, choice2);

			break;
		}
		case 6:
		{
			printf("Введите номер изменяемой записи: ");
			scanf_s("%d", &number);
			if (recordCount < number)
			{
				printf("Такой записи не существует!\n");
				break;
			}
			changeRecord(tablet, number);

			//savetofile(tablet);
			break;
		}
		case 7:
		{
			printf("Введите номер удаляемой записи: ");
			scanf_s("%d", &delnum);
			deleteRecords(tablet, delnum);
			printf("Запись удалена...");
			break;
		}
		case 8:
		{
			memset(tablet, 10000, sizeof(gtablet));
			counnt = 0;
			recordCount = 0;
			break;
		}
		case 0:
		{
			printf("Выход...");
			break;
		}
		default:
		{
			printf("Неверный выбор! Попробуйте снова.\n");
		}
		}
	} while (choice != 0);
}


int addRecord(gtablet tablet[])
{
	if (recordCount >= 1000)
	{
		printf("Достигнуто максимальное количество записей!");
		return -1;
	}
	getchar();
	printf("Производитель - ");
	gets(tablet[recordCount].manufacturer);
	printf("\n");

	printf("Тип - ");
	gets(tablet[recordCount].type);
	printf("\n");

	printf("Технология изготовления матрицы - ");
	gets(tablet[recordCount].matrix_technology);
	printf("\n");

	printf("Формат - ");
	gets(tablet[recordCount].format);
	printf("\n");

	printf("Чувствительность к нажатию - ");
	scanf_s("%f", &tablet[recordCount].sensivity);
	printf("\n");

	printf("Разрешение экрана - ");
	scanf_s("%d", &tablet[recordCount].resolution);
	printf("\n");
	getchar();
	printf("Поддерживаемая ОС - ");
	gets(tablet[recordCount].os_support);
	printf("\n");

	printf("Тип подключения - ");
	gets(tablet[recordCount].connection_type);
	printf("\n");

	printf("Ширина рабочей области (мм) - ");
	scanf_s("%d", &tablet[recordCount].workingspace_width);
	printf("\n");
	getchar();
	printf("Способ ввода - ");
	gets(tablet[recordCount].input_method);
	printf("\n");

	printf("Количество кнопок - ");
	scanf_s("%d", &tablet[recordCount].button_amount);
	printf("\n");
	getchar();
	printf("Цвет - ");
	gets(tablet[recordCount].color);
	printf("\n");

	recordCount++;
	rec++;

	//printf("Record Count - %d\nRec - %d\n", recordCount, rec);

	return 0;
}

int addsomeRecord(gtablet tablet[], int amount)
{
	for (int i = 0; i < amount; i++)
	{
		if (recordCount >= 1000)
		{
			printf("Достигнуто максимальное количество записей!");
			return -1;
		}
		printf("Новая запись %d\n", i + 1);
		if (i > 0)
		{
			printf("Нажмите ENTER, чтобы продолжить");
		}

		getchar();
		printf("Производитель - ");
		gets(tablet[i].manufacturer);
		printf("\n");

		printf("Тип - ");
		gets(tablet[i].type);
		printf("\n");

		printf("Технология изготовления матрицы - ");
		gets(tablet[i].matrix_technology);
		printf("\n");

		printf("Формат - ");
		gets(tablet[i].format);
		printf("\n");

		printf("Чувствительность к нажатию - ");
		scanf_s("%f", &tablet[i].sensivity);
		printf("\n");

		printf("Разрешение экрана - ");
		scanf_s("%d", &tablet[i].resolution);
		printf("\n");
		getchar();
		printf("Поддерживаемая ОС - ");
		gets(tablet[i].os_support);
		printf("\n");

		printf("Тип подключения - ");
		gets(tablet[i].connection_type);
		printf("\n");

		printf("Ширина рабочей области (мм) - ");
		scanf_s("%d", &tablet[i].workingspace_width);
		printf("\n");
		getchar();
		printf("Способ ввода - ");
		gets(tablet[i].input_method);
		printf("\n");

		printf("Количество кнопок - ");
		scanf_s("%d", &tablet[i].button_amount);
		printf("\n");
		getchar();
		printf("Цвет - ");
		gets(tablet[i].color);
		printf("\n");

		recordCount++;
		rec++;

		//printf("Record Count - %d\nRec - %d\n", recordCount, rec);

	}



	return 0;
}

int searchRecord(gtablet tablet[], int resolution, int workingspace_width)
{
	printf("Результат поиска: \n");
	int k = 0;
	for (int i = 0; i < recordCount; i++)
	{
		if (tablet[i].resolution == resolution && tablet[i].workingspace_width == workingspace_width)
		{
			printf("Производитель - %s\n", tablet[i].manufacturer);
			printf("Тип - %s\n", tablet[i].type);
			printf("Технология изготовления матрицы - %s\n", tablet[i].matrix_technology);
			printf("Формат - %s\n", tablet[i].format);
			printf("Чувствительность к нажатию - %f\n", tablet[i].sensivity);
			printf("Разрешение экрана - %d\n", tablet[i].resolution);
			printf("Поддерживаемая ОС - %s\n", tablet[i].os_support);
			printf("Тип подключения - %s\n", tablet[i].connection_type);
			printf("Ширина рабочей области (мм) - %d\n", tablet[i].workingspace_width);
			printf("Способ ввода - %s\n", tablet[i].input_method);
			printf("Количество кнопок - %d\n", tablet[i].button_amount);
			printf("Цвет - %s\n", tablet[i].color);
			printf("\n");
			k += 1;

		}
	}
	if (k == 0)
	{
		printf("Записи не найдены.");
		return 1;
	}
	return 0;
}
int searchRecordWidth(gtablet tablet[], int workingspace_width)
{
	printf("Результат поиска: \n");
	int k = 0;
	for (int i = 0; i < recordCount; i++)
	{
		if (tablet[i].workingspace_width == workingspace_width)
		{
			printf("Производитель - %s\n", tablet[i].manufacturer);
			printf("Тип - %s\n", tablet[i].type);
			printf("Технология изготовления матрицы - %s\n", tablet[i].matrix_technology);
			printf("Формат - %s\n", tablet[i].format);
			printf("Чувствительность к нажатию - %f\n", tablet[i].sensivity);
			printf("Разрешение экрана - %d\n", tablet[i].resolution);
			printf("Поддерживаемая ОС - %s\n", tablet[i].os_support);
			printf("Тип подключения - %s\n", tablet[i].connection_type);
			printf("Ширина рабочей области (мм) - %d\n", tablet[i].workingspace_width);
			printf("Способ ввода - %s\n", tablet[i].input_method);
			printf("Количество кнопок - %d\n", tablet[i].button_amount);
			printf("Цвет - %s\n", tablet[i].color);
			printf("\n");
			k += 1;

		}
	}
	if (k == 0)
	{
		printf("Записи не найдены.");
		return 1;
	}
	return 0;
}
int searchRecordResolution(gtablet tablet[], int resolution)
{
	printf("Результат поиска: \n");
	int k = 0;
	for (int i = 0; i < recordCount; i++)
	{
		if (tablet[i].resolution == resolution)
		{
			printf("Производитель - %s\n", tablet[i].manufacturer);
			printf("Тип - %s\n", tablet[i].type);
			printf("Технология изготовления матрицы - %s\n", tablet[i].matrix_technology);
			printf("Формат - %s\n", tablet[i].format);
			printf("Чувствительность к нажатию - %f\n", tablet[i].sensivity);
			printf("Разрешение экрана - %d\n", tablet[i].resolution);
			printf("Поддерживаемая ОС - %s\n", tablet[i].os_support);
			printf("Тип подключения - %s\n", tablet[i].connection_type);
			printf("Ширина рабочей области (мм) - %d\n", tablet[i].workingspace_width);
			printf("Способ ввода - %s\n", tablet[i].input_method);
			printf("Количество кнопок - %d\n", tablet[i].button_amount);
			printf("Цвет - %s\n", tablet[i].color);
			printf("\n");
			k += 1;

		}
	}
	if (k == 0)
	{
		printf("Записи не найдены.");
		return 1;
	}
	return 0;
}

char savetofile(gtablet tablet[])
{
	FILE* file = fopen("Records.txt", "ab");

	if (file == NULL)
	{
		printf("Файл не найден...");
		return 1;
	}

	for (int i = 0; i < recordCount; i++)
	{
		fprintf(file, "%s ", tablet[i].manufacturer);
		fprintf(file, "%s ", tablet[i].type);
		fprintf(file, "%s ", tablet[i].matrix_technology);
		fprintf(file, "%s ", tablet[i].format);
		fprintf(file, "%f ", tablet[i].sensivity);
		fprintf(file, "%d ", tablet[i].resolution);
		fprintf(file, "%s ", tablet[i].os_support);
		fprintf(file, "%s ", tablet[i].connection_type);
		fprintf(file, "%d ", tablet[i].workingspace_width);
		fprintf(file, "%s ", tablet[i].input_method);
		fprintf(file, "%d ", tablet[i].button_amount);
		fprintf(file, "%s \n", tablet[i].color);

	}
	fclose(file);
	printf("Данные записаны...\n");
	return 0;
}


char readfromfile(gtablet tablet[], int* num)
{

	char c;
	int count = 0;



	FILE* file = fopen("Records.txt", "r");
	if (file == NULL)
	{
		printf("Не удалось открыть файл\n");
		return;
	}
	if (recordCount >= 1000)
	{
		printf("Достигнуто максимальное количество записей...");
		return;
	}
	for (c = getc(file); c != EOF; c = getc(file))
	{
		if (c == '\n')
		{
			recordCount = recordCount + 1;
			//recordCount += anotheramount;
		}
		if (recordCount >= 1000)
		{
			printf("Количество записей - %d\n", recordCount);
			printf("Достигнуто максимальное количество записей...");
			return;
		}
	}

	//recordCount = fread(tablet, sizeof(tablet), 10, file);
	//printf("Count - %d\n", recordCount);

	fseek(file, 0, SEEK_SET);

	for (int i = 0; i < 1001; i++)
	{
		fscanf(file, "%s", tablet[i].manufacturer);
		fscanf(file, "%s", tablet[i].type);
		fscanf(file, "%s", tablet[i].matrix_technology);
		fscanf(file, "%s", tablet[i].format);
		fscanf(file, "%f", &tablet[i].sensivity);
		fscanf(file, "%d", &tablet[i].resolution);
		fscanf(file, "%s", tablet[i].os_support);
		fscanf(file, "%s", tablet[i].connection_type);
		fscanf(file, "%d", &tablet[i].workingspace_width);
		fscanf(file, "%s", tablet[i].input_method);
		fscanf(file, "%d", &tablet[i].button_amount);
		fscanf(file, "%s\n", tablet[i].color);




	}
	/**num = 0;
	while (fscanf(file, "%20[^,],%15[^,],%15[^,],%15[^,],%d,%d,%15[^,],%15[^,],%d,%15[^,],%d,%15[^\n]", tablet[*num].manufacturer, tablet[*num].type, tablet[*num].matrix_technology, tablet[*num].format, &tablet[*num].sensivity, &tablet[*num].resolution, tablet[*num].os_support, tablet[*num].connection_type, &tablet[*num].workingspace_width, tablet[*num].input_method, &tablet[*num].button_amount, tablet[*num].color) == 12)
	{
		(*num)++;
		if ((*num) > 9)
		{
			printf("Достигнуто максимальное количество записей\n");
			break;
		}
	}
	printf("Производитель: %s\n", tablet[*num].manufacturer);
	printf("Тип: %s\n", tablet[*num].type);
	printf("Матрица: %s\n", tablet[*num].matrix_technology);
	printf("Формат: %s\n", tablet[*num].format);
	printf("Чувствительность: %d\n", tablet[*num].sensivity);
	printf("Разрешение экрана: %d\n", tablet[*num].resolution);
	printf("ОС: %s\n", tablet[*num].os_support);
	printf("Тип подключения: %s\n", tablet[*num].connection_type);
	printf("Ширина рабочей области: %d\n", tablet[*num].workingspace_width);
	printf("Способ воода: %s\n", tablet[*num].input_method);
	printf("Количество кнопок: %d\n", tablet[*num].button_amount);
	printf("Цвет: %s\n", tablet[*num].color);*/






	fclose(file);
	printf("\nДанные загружены... Количество записей - %d", recordCount - rec);

	return 0;
}


int putRecords(gtablet tablet[], int choice2)
{
	switch (choice2)
	{
	case 1:
	{
		gtablet temp;

		for (int j = 0; j < recordCount - rec; j++)
		{
			for (int i = 0; i < recordCount - 1 - rec; i++)
			{
				if (strcmp(tablet[i].manufacturer, tablet[i + 1].manufacturer) > 0)
				{
					temp = tablet[i];
					tablet[i] = tablet[i + 1];
					tablet[i + 1] = temp;
				}
			}
		}
		for (int i = 0; i < recordCount - rec; i++)
		{
			//printf("Планшет %d:\n", i);
			printf("Производитель: %s\n", tablet[i].manufacturer);
			printf("Тип: %s\n", tablet[i].type);
			printf("Технология изготовления матрицы: %s\n", tablet[i].matrix_technology);
			printf("Формат: %s\n", tablet[i].format);
			printf("Чувствительность к нажатию: %f\n", tablet[i].sensivity);
			printf("Разрешение планшета: %d\n", tablet[i].resolution);
			printf("Поддерживаемая ОС: %s\n", tablet[i].os_support);
			printf("Тип подключения: %s\n", tablet[i].connection_type);
			printf("Ширина рабочей области (мм): %d\n", tablet[i].workingspace_width);
			printf("Способ ввода: %s\n", tablet[i].input_method);
			printf("Количество кнопок: %d\n", tablet[i].button_amount);
			printf("Цвет: %s\n", tablet[i].color);
			printf("\n");

		}
		break;
	}
	case 2:
	{
		gtablet temp;
		for (int j = 0; j < recordCount - rec; j++)
		{
			for (int i = 0; i < recordCount - 1 - rec; i++)
			{
				if (strcmp(tablet[i].color, tablet[i + 1].color) > 0)
				{
					temp = tablet[i];
					tablet[i] = tablet[i + 1];
					tablet[i + 1] = temp;
				}
			}
		}
		for (int i = 0; i < recordCount - rec; i++)
		{
			printf("Планшет %d:\n", i);
			printf("Производитель: %s\n", tablet[i].manufacturer);
			printf("Тип: %s\n", tablet[i].type);
			printf("Технология изготовления матрицы: %s\n", tablet[i].matrix_technology);
			printf("Формат: %s\n", tablet[i].format);
			printf("Чувствительность к нажатию: %f\n", tablet[i].sensivity);
			printf("Разрешение планшета: %d\n", tablet[i].resolution);
			printf("Поддерживаемая ОС: %s\n", tablet[i].os_support);
			printf("Тип подключения: %s\n", tablet[i].connection_type);
			printf("Ширина рабочей области (мм): %d\n", tablet[i].workingspace_width);
			printf("Способ ввода: %s\n", tablet[i].input_method);
			printf("Количество кнопок: %d\n", tablet[i].button_amount);
			printf("Цвет: %s\n", tablet[i].color);
			printf("\n");

		}
		break;
	}
	case 3:
	{
		gtablet temp;
		for (int j = 0; j < recordCount - rec; j++)
		{
			for (int i = 0; i < recordCount - 1 - rec; i++)
			{
				if (strcmp(tablet[i].manufacturer, tablet[i + 1].manufacturer) > 0 || strcmp(tablet[i].manufacturer, tablet[i + 1].manufacturer) > 0 && strcmp(tablet[i].color, tablet[i + 1].color) > 0)
				{
					temp = tablet[i];
					tablet[i] = tablet[i + 1];
					tablet[i + 1] = temp;
				}
			}
		}
		for (int i = 0; i < recordCount - rec; i++)
		{
			//printf("Планшет %d:\n", i);
			printf("Производитель: %s\n", tablet[i].manufacturer);
			printf("Тип: %s\n", tablet[i].type);
			printf("Технология изготовления матрицы: %s\n", tablet[i].matrix_technology);
			printf("Формат: %s\n", tablet[i].format);
			printf("Чувствительность к нажатию: %f\n", tablet[i].sensivity);
			printf("Разрешение планшета: %d\n", tablet[i].resolution);
			printf("Поддерживаемая ОС: %s\n", tablet[i].os_support);
			printf("Тип подключения: %s\n", tablet[i].connection_type);
			printf("Ширина рабочей области (мм): %d\n", tablet[i].workingspace_width);
			printf("Способ ввода: %s\n", tablet[i].input_method);
			printf("Количество кнопок: %d\n", tablet[i].button_amount);
			printf("Цвет: %s\n", tablet[i].color);
			printf("\n");

		}
		break;

	}

	}
	return 0;
}

int changeRecord(gtablet tablet[], int number)
{
	printf("Изменение данных для графического планшета %d\n", number);
	getchar();
	printf("Производитель - ");
	gets(tablet[number].manufacturer);
	printf("\n");

	printf("Тип - ");
	gets(tablet[number].type);
	printf("\n");

	printf("Технология изготовления матрицы - ");
	gets(tablet[number].matrix_technology);
	printf("\n");

	printf("Формат - ");
	gets(tablet[number].format);
	printf("\n");

	printf("Чувствительность к нажатию - ");
	scanf_s("%f", &tablet[number].sensivity);
	printf("\n");

	printf("Разрешение экрана - ");
	scanf_s("%d", &tablet[number].resolution);
	printf("\n");
	getchar();
	printf("Поддерживаемая ОС - ");
	gets(tablet[number].os_support);
	printf("\n");

	printf("Тип подключения - ");
	gets(tablet[number].connection_type);
	printf("\n");

	printf("Ширина рабочей области (мм) - ");
	scanf_s("%d", &tablet[number].workingspace_width);
	printf("\n");
	getchar();
	printf("Способ ввода - ");
	gets(tablet[number].input_method);
	printf("\n");

	printf("Количество кнопок - ");
	scanf_s("%d", &tablet[number].button_amount);
	printf("\n");
	getchar();
	printf("Цвет - ");
	gets(tablet[number].color);
	printf("\n");

	FILE* file = fopen("Records.txt", "wb");

	if (file == NULL)
	{
		printf("Файл не найден...");
		return 1;
	}

	for (int i = 0; i < recordCount; i++)
	{
		fprintf(file, "%s ", tablet[i].manufacturer);
		fprintf(file, "%s ", tablet[i].type);
		fprintf(file, "%s ", tablet[i].matrix_technology);
		fprintf(file, "%s ", tablet[i].format);
		fprintf(file, "%f ", tablet[i].sensivity);
		fprintf(file, "%d ", tablet[i].resolution);
		fprintf(file, "%s ", tablet[i].os_support);
		fprintf(file, "%s ", tablet[i].connection_type);
		fprintf(file, "%d ", tablet[i].workingspace_width);
		fprintf(file, "%s ", tablet[i].input_method);
		fprintf(file, "%d ", tablet[i].button_amount);
		fprintf(file, "%s \n", tablet[i].color);

	}
	fclose(file);
	printf("Данные записаны...\n");
	return 0;
}

int deleteRecords(gtablet tablet[], int delnum)
{
	FILE* file = fopen("Records.txt", "wb");
	for (int i = delnum; i < recordCount; i++)
	{
		tablet[i] = tablet[i + 1];
	}
	recordCount--;


	if (file == NULL)
	{
		printf("Файл не найден...");
		return 1;
	}

	for (int i = 0; i < recordCount; i++)
	{
		fprintf(file, "%s ", tablet[i].manufacturer);
		fprintf(file, "%s ", tablet[i].type);
		fprintf(file, "%s ", tablet[i].matrix_technology);
		fprintf(file, "%s ", tablet[i].format);
		fprintf(file, "%f ", tablet[i].sensivity);
		fprintf(file, "%d ", tablet[i].resolution);
		fprintf(file, "%s ", tablet[i].os_support);
		fprintf(file, "%s ", tablet[i].connection_type);
		fprintf(file, "%d ", tablet[i].workingspace_width);
		fprintf(file, "%s ", tablet[i].input_method);
		fprintf(file, "%d ", tablet[i].button_amount);
		fprintf(file, "%s \n", tablet[i].color);

	}


	//fprintf(file, "\0");
	fclose(file);
	recordCount = 0;
	return 0;

}