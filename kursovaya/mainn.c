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
		printf("\n����:\n");
		printf("1. ������� ����� ������\n");
		printf("2. ����� ������\n");
		printf("3. ��������� ������ � ����\n");
		printf("4. ��������� ������ �� �����\n");
		printf("5. ������ ���� �������\n");
		printf("6. �������� ������\n");
		printf("7. ������� ������ � �����\n");
		printf("8. �������� ����������� ������\n");
		printf("0. �����\n");
		printf("�������� �����: ");
		scanf_s("%d", &choice);
		getchar();

		switch (choice)
		{
		case 1:
		{
			printf("�������� ������� ���������� ������(��):\n1) �������� ���� ������\n2) �������� ��������� �������\n");
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
				printf("������� ���������� ����������� ������� - ");
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
				printf("���������� ������ ���� �� ������������ ����!\n");
				break;
			}
			}
			break;

		}
		case 2:
		{
			printf("�������� ������� ������:\n1) �� ������ ������� �������\n2) �� ����������\n3) �� ����� ����������\n");
			int choicecase2;
			scanf_s("%d", &choicecase2);
			if (choicecase2 != 1 && choicecase2 != 2 && choicecase2 != 3)
			{
				printf("�������� ����!\n");
				break;
			}
			switch (choicecase2)
			{
			case 1:
			{
				printf("������� ������ ������� ������� ��� ������ - ");
				scanf_s("%d", &workingspace_width);
				printf("\n");
				searchRecordWidth(tablet, workingspace_width);
				break;
			}
			case 2:
			{
				printf("������� ���������� ��� ������ - ");
				scanf_s("%d", &resolution);
				printf("\n");
				searchRecordResolution(tablet, resolution);
				break;
			}
			case 3:
			{
				printf("������� ���������� ��� ������ - ");
				scanf_s("%d", &resolution);
				printf("\n");
				printf("������� ������ ������� ������� ��� ������ - ");
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
				printf("������ ��� ���������!\n");
				break;
			}
			readfromfile(tablet, &num);
			counnt++;
			//printf("counnt- %d\n", counnt);
			break;
		}
		case 5:
		{
			printf("�������� ������� ����������:\n1) �������������\n2) ����\n3) ��� ��������\n");
			scanf_s("%d", &choice2);
			if (choice2 != 1 && choice2 != 2 && choice2 != 3)
			{
				printf("�������� ����!\n");
				break;
			}
			putRecords(tablet, choice2);

			break;
		}
		case 6:
		{
			printf("������� ����� ���������� ������: ");
			scanf_s("%d", &number);
			if (recordCount < number)
			{
				printf("����� ������ �� ����������!\n");
				break;
			}
			changeRecord(tablet, number);

			//savetofile(tablet);
			break;
		}
		case 7:
		{
			printf("������� ����� ��������� ������: ");
			scanf_s("%d", &delnum);
			deleteRecords(tablet, delnum);
			printf("������ �������...");
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
			printf("�����...");
			break;
		}
		default:
		{
			printf("�������� �����! ���������� �����.\n");
		}
		}
	} while (choice != 0);
}


int addRecord(gtablet tablet[])
{
	if (recordCount >= 1000)
	{
		printf("���������� ������������ ���������� �������!");
		return -1;
	}
	getchar();
	printf("������������� - ");
	gets(tablet[recordCount].manufacturer);
	printf("\n");

	printf("��� - ");
	gets(tablet[recordCount].type);
	printf("\n");

	printf("���������� ������������ ������� - ");
	gets(tablet[recordCount].matrix_technology);
	printf("\n");

	printf("������ - ");
	gets(tablet[recordCount].format);
	printf("\n");

	printf("���������������� � ������� - ");
	scanf_s("%f", &tablet[recordCount].sensivity);
	printf("\n");

	printf("���������� ������ - ");
	scanf_s("%d", &tablet[recordCount].resolution);
	printf("\n");
	getchar();
	printf("�������������� �� - ");
	gets(tablet[recordCount].os_support);
	printf("\n");

	printf("��� ����������� - ");
	gets(tablet[recordCount].connection_type);
	printf("\n");

	printf("������ ������� ������� (��) - ");
	scanf_s("%d", &tablet[recordCount].workingspace_width);
	printf("\n");
	getchar();
	printf("������ ����� - ");
	gets(tablet[recordCount].input_method);
	printf("\n");

	printf("���������� ������ - ");
	scanf_s("%d", &tablet[recordCount].button_amount);
	printf("\n");
	getchar();
	printf("���� - ");
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
			printf("���������� ������������ ���������� �������!");
			return -1;
		}
		printf("����� ������ %d\n", i + 1);
		if (i > 0)
		{
			printf("������� ENTER, ����� ����������");
		}

		getchar();
		printf("������������� - ");
		gets(tablet[i].manufacturer);
		printf("\n");

		printf("��� - ");
		gets(tablet[i].type);
		printf("\n");

		printf("���������� ������������ ������� - ");
		gets(tablet[i].matrix_technology);
		printf("\n");

		printf("������ - ");
		gets(tablet[i].format);
		printf("\n");

		printf("���������������� � ������� - ");
		scanf_s("%f", &tablet[i].sensivity);
		printf("\n");

		printf("���������� ������ - ");
		scanf_s("%d", &tablet[i].resolution);
		printf("\n");
		getchar();
		printf("�������������� �� - ");
		gets(tablet[i].os_support);
		printf("\n");

		printf("��� ����������� - ");
		gets(tablet[i].connection_type);
		printf("\n");

		printf("������ ������� ������� (��) - ");
		scanf_s("%d", &tablet[i].workingspace_width);
		printf("\n");
		getchar();
		printf("������ ����� - ");
		gets(tablet[i].input_method);
		printf("\n");

		printf("���������� ������ - ");
		scanf_s("%d", &tablet[i].button_amount);
		printf("\n");
		getchar();
		printf("���� - ");
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
	printf("��������� ������: \n");
	int k = 0;
	for (int i = 0; i < recordCount; i++)
	{
		if (tablet[i].resolution == resolution && tablet[i].workingspace_width == workingspace_width)
		{
			printf("������������� - %s\n", tablet[i].manufacturer);
			printf("��� - %s\n", tablet[i].type);
			printf("���������� ������������ ������� - %s\n", tablet[i].matrix_technology);
			printf("������ - %s\n", tablet[i].format);
			printf("���������������� � ������� - %f\n", tablet[i].sensivity);
			printf("���������� ������ - %d\n", tablet[i].resolution);
			printf("�������������� �� - %s\n", tablet[i].os_support);
			printf("��� ����������� - %s\n", tablet[i].connection_type);
			printf("������ ������� ������� (��) - %d\n", tablet[i].workingspace_width);
			printf("������ ����� - %s\n", tablet[i].input_method);
			printf("���������� ������ - %d\n", tablet[i].button_amount);
			printf("���� - %s\n", tablet[i].color);
			printf("\n");
			k += 1;

		}
	}
	if (k == 0)
	{
		printf("������ �� �������.");
		return 1;
	}
	return 0;
}
int searchRecordWidth(gtablet tablet[], int workingspace_width)
{
	printf("��������� ������: \n");
	int k = 0;
	for (int i = 0; i < recordCount; i++)
	{
		if (tablet[i].workingspace_width == workingspace_width)
		{
			printf("������������� - %s\n", tablet[i].manufacturer);
			printf("��� - %s\n", tablet[i].type);
			printf("���������� ������������ ������� - %s\n", tablet[i].matrix_technology);
			printf("������ - %s\n", tablet[i].format);
			printf("���������������� � ������� - %f\n", tablet[i].sensivity);
			printf("���������� ������ - %d\n", tablet[i].resolution);
			printf("�������������� �� - %s\n", tablet[i].os_support);
			printf("��� ����������� - %s\n", tablet[i].connection_type);
			printf("������ ������� ������� (��) - %d\n", tablet[i].workingspace_width);
			printf("������ ����� - %s\n", tablet[i].input_method);
			printf("���������� ������ - %d\n", tablet[i].button_amount);
			printf("���� - %s\n", tablet[i].color);
			printf("\n");
			k += 1;

		}
	}
	if (k == 0)
	{
		printf("������ �� �������.");
		return 1;
	}
	return 0;
}
int searchRecordResolution(gtablet tablet[], int resolution)
{
	printf("��������� ������: \n");
	int k = 0;
	for (int i = 0; i < recordCount; i++)
	{
		if (tablet[i].resolution == resolution)
		{
			printf("������������� - %s\n", tablet[i].manufacturer);
			printf("��� - %s\n", tablet[i].type);
			printf("���������� ������������ ������� - %s\n", tablet[i].matrix_technology);
			printf("������ - %s\n", tablet[i].format);
			printf("���������������� � ������� - %f\n", tablet[i].sensivity);
			printf("���������� ������ - %d\n", tablet[i].resolution);
			printf("�������������� �� - %s\n", tablet[i].os_support);
			printf("��� ����������� - %s\n", tablet[i].connection_type);
			printf("������ ������� ������� (��) - %d\n", tablet[i].workingspace_width);
			printf("������ ����� - %s\n", tablet[i].input_method);
			printf("���������� ������ - %d\n", tablet[i].button_amount);
			printf("���� - %s\n", tablet[i].color);
			printf("\n");
			k += 1;

		}
	}
	if (k == 0)
	{
		printf("������ �� �������.");
		return 1;
	}
	return 0;
}

char savetofile(gtablet tablet[])
{
	FILE* file = fopen("Records.txt", "ab");

	if (file == NULL)
	{
		printf("���� �� ������...");
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
	printf("������ ��������...\n");
	return 0;
}


char readfromfile(gtablet tablet[], int* num)
{

	char c;
	int count = 0;



	FILE* file = fopen("Records.txt", "r");
	if (file == NULL)
	{
		printf("�� ������� ������� ����\n");
		return;
	}
	if (recordCount >= 1000)
	{
		printf("���������� ������������ ���������� �������...");
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
			printf("���������� ������� - %d\n", recordCount);
			printf("���������� ������������ ���������� �������...");
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
			printf("���������� ������������ ���������� �������\n");
			break;
		}
	}
	printf("�������������: %s\n", tablet[*num].manufacturer);
	printf("���: %s\n", tablet[*num].type);
	printf("�������: %s\n", tablet[*num].matrix_technology);
	printf("������: %s\n", tablet[*num].format);
	printf("����������������: %d\n", tablet[*num].sensivity);
	printf("���������� ������: %d\n", tablet[*num].resolution);
	printf("��: %s\n", tablet[*num].os_support);
	printf("��� �����������: %s\n", tablet[*num].connection_type);
	printf("������ ������� �������: %d\n", tablet[*num].workingspace_width);
	printf("������ �����: %s\n", tablet[*num].input_method);
	printf("���������� ������: %d\n", tablet[*num].button_amount);
	printf("����: %s\n", tablet[*num].color);*/






	fclose(file);
	printf("\n������ ���������... ���������� ������� - %d", recordCount - rec);

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
			//printf("������� %d:\n", i);
			printf("�������������: %s\n", tablet[i].manufacturer);
			printf("���: %s\n", tablet[i].type);
			printf("���������� ������������ �������: %s\n", tablet[i].matrix_technology);
			printf("������: %s\n", tablet[i].format);
			printf("���������������� � �������: %f\n", tablet[i].sensivity);
			printf("���������� ��������: %d\n", tablet[i].resolution);
			printf("�������������� ��: %s\n", tablet[i].os_support);
			printf("��� �����������: %s\n", tablet[i].connection_type);
			printf("������ ������� ������� (��): %d\n", tablet[i].workingspace_width);
			printf("������ �����: %s\n", tablet[i].input_method);
			printf("���������� ������: %d\n", tablet[i].button_amount);
			printf("����: %s\n", tablet[i].color);
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
			printf("������� %d:\n", i);
			printf("�������������: %s\n", tablet[i].manufacturer);
			printf("���: %s\n", tablet[i].type);
			printf("���������� ������������ �������: %s\n", tablet[i].matrix_technology);
			printf("������: %s\n", tablet[i].format);
			printf("���������������� � �������: %f\n", tablet[i].sensivity);
			printf("���������� ��������: %d\n", tablet[i].resolution);
			printf("�������������� ��: %s\n", tablet[i].os_support);
			printf("��� �����������: %s\n", tablet[i].connection_type);
			printf("������ ������� ������� (��): %d\n", tablet[i].workingspace_width);
			printf("������ �����: %s\n", tablet[i].input_method);
			printf("���������� ������: %d\n", tablet[i].button_amount);
			printf("����: %s\n", tablet[i].color);
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
			//printf("������� %d:\n", i);
			printf("�������������: %s\n", tablet[i].manufacturer);
			printf("���: %s\n", tablet[i].type);
			printf("���������� ������������ �������: %s\n", tablet[i].matrix_technology);
			printf("������: %s\n", tablet[i].format);
			printf("���������������� � �������: %f\n", tablet[i].sensivity);
			printf("���������� ��������: %d\n", tablet[i].resolution);
			printf("�������������� ��: %s\n", tablet[i].os_support);
			printf("��� �����������: %s\n", tablet[i].connection_type);
			printf("������ ������� ������� (��): %d\n", tablet[i].workingspace_width);
			printf("������ �����: %s\n", tablet[i].input_method);
			printf("���������� ������: %d\n", tablet[i].button_amount);
			printf("����: %s\n", tablet[i].color);
			printf("\n");

		}
		break;

	}

	}
	return 0;
}

int changeRecord(gtablet tablet[], int number)
{
	printf("��������� ������ ��� ������������ �������� %d\n", number);
	getchar();
	printf("������������� - ");
	gets(tablet[number].manufacturer);
	printf("\n");

	printf("��� - ");
	gets(tablet[number].type);
	printf("\n");

	printf("���������� ������������ ������� - ");
	gets(tablet[number].matrix_technology);
	printf("\n");

	printf("������ - ");
	gets(tablet[number].format);
	printf("\n");

	printf("���������������� � ������� - ");
	scanf_s("%f", &tablet[number].sensivity);
	printf("\n");

	printf("���������� ������ - ");
	scanf_s("%d", &tablet[number].resolution);
	printf("\n");
	getchar();
	printf("�������������� �� - ");
	gets(tablet[number].os_support);
	printf("\n");

	printf("��� ����������� - ");
	gets(tablet[number].connection_type);
	printf("\n");

	printf("������ ������� ������� (��) - ");
	scanf_s("%d", &tablet[number].workingspace_width);
	printf("\n");
	getchar();
	printf("������ ����� - ");
	gets(tablet[number].input_method);
	printf("\n");

	printf("���������� ������ - ");
	scanf_s("%d", &tablet[number].button_amount);
	printf("\n");
	getchar();
	printf("���� - ");
	gets(tablet[number].color);
	printf("\n");

	FILE* file = fopen("Records.txt", "wb");

	if (file == NULL)
	{
		printf("���� �� ������...");
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
	printf("������ ��������...\n");
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
		printf("���� �� ������...");
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