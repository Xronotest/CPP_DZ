#include <iostream>

void DZ_18_09();
void DZ_Cow();
void DZ_23_09();
void DZ_30_09();
void DZ_09_10();
int DelCheck(int arr[], int num)
{
	for (size_t i = 0; i < 3; i++)
	{
		if (arr[i] == num) 
		{
			return num;
		}
		else
		{
			return 0;
		}
	}
}


int main()
{
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));
	
	int choise = 0;

	std::cout << "C�����: \n"
		<< "Cow (1) \n"
		<< "18_09 (2) \n"
		<< "23_09 (3) \n"
		<< "30_09 (4) \n"
		<< "09_10 (5) \n"
		<< "�������: ";
	std::cin >> choise;

	if (choise == 1)
	{
		DZ_Cow();
	}
	else if (choise == 2)
	{
		DZ_18_09();
	}
	else if (choise == 3)
	{
		DZ_23_09();
	}
	else if (choise == 4)
	{
		DZ_30_09();

	}
	else if (choise == 5)
	{
		DZ_09_10();
	}
	
	
	return 0;
}

void DZ_09_10() {
	double fruit[]{ 90, 95, 110, 85 }; //������, ��������, �������, �����
	double veget[]{ 110, 130, 100 }; //�����, ���, ������
	double tea[]{ 70, 80 }; //������, ��������

	char again = 'y';

	while (again == 'y')
	{
		int again� = 1;

		std::cout << "���� �������" << "\n"
			<< "Ass��������:" << "\n"
			<< "��������� ����: ������, ��������, �������, �����" << "\n"
			<< "������� ����: �����, ���, ������" << "\n"
			<< "������: ������, ��������" << "\n" << "\n";

		while (again� == 1)
		{
			int del = 0;
			int choise = 0;
			int delet[]{ 0, 0 ,0 };
			char againD = 'n';
			int buyCat;
			int buyTowar;
			int actionTea = 0;
			int actionLuk = 0;
			double actionCostTea = 0;
			double actionCostLuk = 0;
			double cost = 0;
			int quantity;
			char ceep = 'y';

			std::cout << "��������:" << "\n"
				<< "������ ������� (1)" << "\n"
				<< "���������� �� ��������� (2)" << "\n"
				<< "�����: ";
			std::cin >> choise;

			if (choise == 2)
			{
				std::cout << "�� ����� ��������� ����������?" << "\n"
					<< "������ (1), ����� (2), ��� (3)" << "\n"
					<< "�����: ";
				std::cin >> del;

				for (size_t i = 0; i < 3; i++)
				{
					if (del == 1)
					{
						delet[i] = 1;
					}
					else if (del == 2)
					{
						delet[i] = 2;
					}
					else if (del == 3)
					{
						delet[i] = 3;
					}
					std::cout << "������� ���������� ��� �� ���������? (y/n): ";
					std::cin >> againD;
					if (againD == 'n')
					{
						choise = 1;
						break;
					}
				}
			}
			if (choise == 1)
			{
				while (ceep == 'y')
				{
					std::cout << "��������� ���������:" << "\n";

					if (DelCheck(delet, 1) != 1)
					{
						std::cout << "������ (1)" << "\n";
					}
					if (DelCheck(delet, 2) != 2)
					{
						std::cout << "����� (2)" << "\n";
					}
					if (DelCheck(delet, 3) != 3)
					{
						std::cout << "��� (3)" << "\n";
					}
					std::cout << "�����: ";

					std::cin >> buyCat;

					if (buyCat == 1 && DelCheck(delet, 1) != 1)
					{
						std::cout << "��������� �����" << "\n"
							<< "������ (1), �������� (2), ������� (3), ����� (4)" << "\n"
							<< "�����: ";
						std::cin >> buyTowar;
						std::cout << "��������� ����������: ";
						std::cin >> quantity;
						cost += fruit[buyTowar - 1] * quantity;
					}
					else if (buyCat == 2 && DelCheck(delet, 2) != 2)
					{
						std::cout << "��������� �����:" << "\n"
							<< "����� (1), ��� (2), ������ (3)" << "\n"
							<< "�����: ";
						std::cin >> buyTowar;
						std::cout << "����������: ";
						std::cin >> quantity;

						if (buyTowar == 2)
						{
							actionLuk += quantity;
							actionCostLuk += veget[buyTowar - 1] * quantity;
						}
						else
						{
							cost += veget[buyTowar - 1] * quantity;
						}
					}
					else if (buyCat == 3 && DelCheck(delet, 3) != 3)
					{
						std::cout << "��������� �����:" << "\n"
							<< "������ (1), �������� (2)" << "\n"
							<< "�����: ";
						std::cin >> buyTowar;
						std::cout << "��������� ����������: ";
						std::cin >> quantity;

						if (buyTowar == 2)
						{
							actionTea += quantity;

							if (actionTea >= 3)
							{
								actionCostTea += tea[buyTowar - 1] * quantity;
							}

						}
						else
						{
							cost += tea[buyTowar - 1] * quantity;
						}
					}
					else
					{
						std::cout << "�� ���������� �� ���� ��������� ��� � ���." << "\n";
					}
					std::cout << "��������� �����? (y/n): ";
					std::cin >> ceep;
					std::cout << "\n";
				}
			}

			if (actionLuk >= 4)
			{
				actionLuk -= (actionLuk / 4);
				cost += veget[1] * actionLuk;
				std::cout << "������ �� ������� ���." << "\n" << "\n";
			}
			else
			{
				cost += actionCostLuk;
			}
			if (actionTea >= 3)
			{
				cost += actionCostTea * 0.95;
				std::cout << "������ �� ���������� ���." << "\n" << "\n";
			}
			if (cost >= 700)
			{
				cost *= 0.87;
				std::cout << "������ �� ���� ��� �� 700." << "\n" << "\n";
			}
			std::cout << "�������� ����: " << cost << "\n" << "\n";
			std::cout << "���������? (y/n): ";
			std::cin >> again;
			std::cout << "\n";
		}
	}
}
void DZ_30_09() {
	
	std::cout << "\n������� 1 \n";

	int max, min;
	const int size = 10;
	int arr[size];

	for (size_t i = 0; i < size; i++)
	{
		arr[i] = rand() % 20 + 1;
		std::cout << arr[i] << " ";
	}

	std::cout << "\n";

	max = arr[1];
	min = arr[1];
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
		else if (arr[i] < min)
		{
			min = arr[i];
		}
	}
	std::cout << "�������: " << min << std::endl
		<< "��������: " << max << std::endl;
	
	
	std::cout << "\n������� 2 \n";

	int maxInp, minInp, minSum;
	const int size2 = 20;
	int array[size2];
	int summ = 0;
	
	std::cout << "������� ����������� ��������: "; std::cin >> minInp;
	std::cout << "������� ������������ ��������: "; std::cin >> maxInp;

	for (size_t i = 0; i < size2; i++)
	{
		array[i] = rand() % (maxInp - minInp + 1) + (minInp);
		std::cout << array[i] << " ";
	}
	std::cout << "\n";

	std::cout << "������� ��������: "; std::cin >> minSum;
	
	for (size_t i = 0; i < size2; i++)
	{
		if (array[i] < minSum)
		{
			summ += array[i];
		}
	}
	std::cout << "�����: " << summ;

	std::cout << "\n������� 3 \n";

	int year[12];
	int minM, maxM;

	for (size_t i = 0; i < 12; i++)
	{
		std::cout << "������� ������� �� " << i + 1 << " �����: "; std::cin >> year[i];
	}

	std::cout << "������� ����������� ��������: "; std::cin >> minM;
	std::cout << "������� ������������ ��������: "; std::cin >> maxM;

	int minP = year[minM], maxP = year[minM];
	int minPrice = 0;
	int maxPrice = 0;

	for (size_t i = minM - 1; i < maxM; i++)
	{
		if (year[i] > maxP)
		{
			maxP = year[i];
			maxPrice = i;
		}
		else if (year[i] < minP)
		{
			minP = year[i];
			minPrice = i;
		}
	}
	std::cout << "������� ��� � " << minPrice + 1 << std::endl
		<< "�������� ��� � " << maxPrice + 1 << std::endl;
}
void DZ_23_09() {

	std::cout << "������� 1 \n";

	int num;
	int loop = 1;

	while (loop == 1)
	{
		std::cout << "������� 6-�� ������� �����: ";
		std::cin >> num;
		std::cout << "\n";

		if (num < 0)
		{
			num *= -1;
		}

		if (num / 100000 >= 1)
		{
			break;
		}
		else
		{
			std::cout << "����� �� 6-�� �������. ��������� �������. \n";
		}
	}

	if ((num / 100000 % 10 + num / 10000 % 10 + num / 1000 % 10) == (num / 100 % 10 + num / 10 % 10 + num / 1 % 10))
	{
		std::cout << "���� ����� ����������. \n";
	}
	else
	{
		std::cout << "���� ����� �� ����������. \n";
	}

	std::cout << "\n������� 2 \n";

	int numb;
	int loops = 1;

	while (loops == 1) 
	{
		std::cout << "������� 4-�� ������� �����: ";
		std::cin >> numb;

		if (numb / 1000 >= 1)
		{
			break;
		}
		else
		{
			std::cout << "����� �� 4-�� �������. ��������� �������. \n";
		}
	}
	
	std::cout << "���������: " << (numb / 1000 % 10) * 100 + (numb / 100 % 10) * 1000 + (numb / 10 % 10) + (numb / 1 % 10) * 10;

	std::cout << "\n������� 3 \n";

	int number, max;

	std::cout << "������� �����: ";
	std::cin >> max;

	for (size_t i = 0; i < 6; i++)
	{
		std::cout << "������� �����: ";
		std::cin >> number;

		if (number > max)
		{
			max = number;
		}
	}

	std::cout << "������������ �����: " << max;
}
void DZ_18_09() {

	std::cout << "������� 1.\n\n";

	float distance;
	float time;
	float speed;

	std::cout << "������� ���������� (��): ", std::cin >> distance;
	while (distance < 0)
	{
		std::cout << "������! ���������� �� ����� ���� ������ 0!\n";
		std::cout << "������� ���������� �������� (��): ", std::cin >> distance;
	}

	std::cout << "������� ����� (�): ", std::cin >> time;
	while (time < 0)
	{
		std::cout << "������! ����� �� ����� ���� ������ 0!\n";
		std::cout << "������� ����� �������� (�): ", std::cin >> time;
	}

	speed = distance / time;

	std::cout << "\n��� ����� ����� �� ���������: " << speed << " ��/�\n";

	std::cout << "------------------------------------\n";
	std::cout << "������� 2.\n\n";

	int timeStart[3];
	int timeEnd[3];
	float price;

	std::cout << "������� ����� ������ �������.\n";
	std::cout << "����: ", std::cin >> timeStart[0];
	std::cout << "������: ", std::cin >> timeStart[1];
	std::cout << "�������: ", std::cin >> timeStart[2];

	std::cout << "\n������� ����� ��������� �������.\n";
	std::cout << "����: ", std::cin >> timeEnd[0];
	std::cout << "������: ", std::cin >> timeEnd[1];
	std::cout << "�������: ", std::cin >> timeEnd[2];

	price = (((timeEnd[0] - timeStart[0]) * 60) + (timeEnd[1] - timeStart[1]) + ((timeEnd[2] - timeStart[2]) / 60)) * 2;
	if (price < 0)
	{
		price *= -1;
	}

	std::cout << "�������� ������� ����������: " << price << " ������\n";

	std::cout << "------------------------------------\n";
	std::cout << "������� 3.\n\n";

	float distance3 = 0;
	float lessFuel = 0;
	float fuelPrice[3];

	std::cout << "������� ���������� (��): ", std::cin >> distance3;
	while (distance3 < 0)
	{
		std::cout << "������! ���������� �� ����� ���� ������ 0!\n";
		std::cout << "������� ���������� �������� (��): ", std::cin >> distance3;
	}
	std::cout << "\n";

	std::cout << "������� ������ ������� �� 100 �� (�): ", std::cin >> lessFuel;
	std::cout << "\n";
	if (lessFuel < 0)
	{
		lessFuel *= -1;
	}

	std::cout << "������� ��������� 3-� ����� ������� �� 1 �: \n";
	std::cout << "92: ", std::cin >> fuelPrice[0];
	std::cout << "95: ", std::cin >> fuelPrice[1];
	std::cout << "������: ", std::cin >> fuelPrice[2];
	std::cout << "\n";

	std::cout << "��������� ������� �� 3-� ����� �������: \n";
	std::cout << "92: " << distance3 / 100 * lessFuel * fuelPrice[0] << "\n";
	std::cout << "95: " << distance3 / 100 * lessFuel * fuelPrice[1] << "\n";
	std::cout << "������: " << distance3 / 100 * lessFuel * fuelPrice[2] << "\n";
}
void DZ_Cow() {
		std::cout << ".    .\n" << ".\t.\n";

	std::cout << " _____________________\n"
		<< "< Happy SysAdmin Day! >\n"
		<< " ---------------------\n"
		<< "\t\\   ^__^\n"
		<< "\t \\  (oo)\\_______\n"
		<< "\t    (__)\\\t)\\/\\\n"
		<< "\t\t||----w |\n"
		<< "\t\t||     ||\n";
}
