#include <iostream>

void DZ_18_09();
void DZ_Cow();
void DZ_23_09();
void DZ_30_09();
void DZ_09_10();
void DZ_14_10();
void DZ_28_10();

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
void DynamicAdd(int* &ptr, int number) {
	ptr = new int;
	*ptr = number;
}
void DynamicArr(int* &ptr, int size) {
	ptr = new int[size];
	for (size_t i = 0; i < size; i++)
	{
		ptr[i] = rand() % 10 + 1;
	}
}
void DynamicArrPrint(int* &ptr, int size) {
	for (size_t i = 0; i < size; i++)
	{
		std::cout << ptr[i] << " ";
	}
	std::cout << "\n";
}
void DynamicArrDelete(int* &ptr) {
	delete[] ptr;
}
void DynamicArrLastAdd(int* &ptr, int size, int number) {
	ptr[size - 1] = number;
}
void TrainAdd(int** &train, int wagons, int seats, int choise) 
{
	train = new int* [wagons];
	if (choise == 1)
	{
		for (int i = 0; i < wagons; i++)
		{
			train[i] = new int[seats];
			for (int j = 0; j < seats; j++)
			{
				train[i][j] = rand() % 2;
				std::cout << train[i][j];
			}
			std::cout << "\n";
		}
	}
	else if (choise == 2)
	{
		for (int i = 0; i < wagons; i++)
		{
			train[i] = new int[seats];
			for (int j = 0; j < seats; j++)
			{
				train[i][j] = 0;
				std::cout << train[i][j];
			}
			std::cout << "\n";
		}
	}
}
void SeatChoise(int**& train) 
{
	int wagon, seat;
	char choise;
	while (true)
	{
		std::cout << "Выберете вагон: ";
		std::cin >> wagon;
		if (wagon < 0 || wagon > 18)
		{
			std::cout << "Ошибка вагона!\n";
		}
		else
		{
			break;
		}
	}
	while (true)
	{
		std::cout << "Выберете место: ";
		std::cin >> seat;
		if (seat < 0 || seat > 36)
		{
			std::cout << "Ошибка места!\n";
		}
		else
		{
			break;
		}
	}
	if (train[wagon][seat] == 0)
	{
		std::cout << "Это место свободно.\n" 
			<< "Желаете забронировать?\n"
			<< "Выбор (y/n): ";
		std::cin >> choise;
		if (choise == 'y')
		{
			std::cout << "Вы забронировали место " << seat << " в вагоне " << wagon << ".\n";
			train[wagon][seat] = 1;
		}
		else
		{
			std::cout << "Как хотетие.\n";
		}
	}
	else if (train[wagon][seat] == 1)
	{
		std::cout << "Это место занято.\n"
			<< "Желаете освободить?\n"
			<< "Выбор (y/n): ";
		std::cin >> choise;
		if (choise == 'y')
		{
			std::cout << "Вы освободили место " << seat << " в вагоне " << wagon << ".\n";
			train[wagon][seat] = 0;
		}
		else
		{
			std::cout << "Как хотетие.\n";
		}
	}
}
void SeatClear(int**& train, int wagons, int seats) 
{
	int clear = 0, choise;
	std::cout << "Выберете вагон или поезд(0).";
	std::cin >> choise;
	if (choise == 0)
	{
		for (int i = 0; i < wagons; i++)
		{
			for (int j = 0; j < seats; j++)
			{
				if (train[i][j] = 0)
				{
					clear++;
				}
			}
		}
		std::cout << "В поезде - " << clear << " свободных мест.\n\n";
	}
	else if (choise > 0 && choise <= 18)
	{
		for (int j = 0; j < seats; j++)
		{
			if (train[choise][j] = 0)
			{
				clear++;
			}
		}
	std::cout << "В " << choise << " вагоне - " << clear << " свободных мест.\n\n";
	}
}
void TrainDelete(int**& train, int wagons, int seats) {
	for (int i = 0; i < wagons; i++)
	{
		delete[]train[i];
	}
	delete[]train;
}

int main()
{
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));

	int choise = 0;

	std::cout << "Cписок: \n"
		<< "Cow (1) \n"
		<< "18_09 (2) \n"
		<< "23_09 (3) \n"
		<< "30_09 (4) \n"
		<< "09_10 (5) \n"
		<< "14_10 (6) \n"
		<< "28_10 (7) \n"
		<< "Открыть: ";
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
	else if (choise == 6)
	{
		DZ_14_10();
	}
	else if (choise == 7)
	{
		DZ_28_10();
	}


	return 0;
	}

	void DZ_28_10() {
		int* ptr;
		int number;
		int size;
		std::cout << "Введите число: ";
		std::cin >> number;

		DynamicAdd(ptr, number);
		delete ptr;

		std::cout << "Введите размер массива: ";
		std::cin >> size;
		DynamicArr(ptr, size);
		DynamicArrPrint(ptr, size);

		std::cout << "Введите число: ";
		std::cin >> number;

		DynamicArrLastAdd(ptr, size, number);
		DynamicArrPrint(ptr, size);
		DynamicArrDelete(ptr);
	}
	void DZ_14_10() {
		int wagon = 18, seat = 36, choise;
		int** train;
		std::cout << "Режимы запонения:\n"
				<< "Рандом (1)\n"
				<< "Пусто (2)\n"
				<< "Выбор: ";
		std::cin >> choise;
		TrainAdd(train, wagon, seat, choise);
		while (true)
		{
			choise = 0;
			std::cout << "Выберете действие: \n"
				<< "Выбор места (1)\n"
				<< "Узнать количсество свободных мест (2)\n"
				<< "Закончить (3)\n"
				<< "Выбор: ";
			std::cin >> choise;
			if (choise == 1)
			{
				SeatChoise(train);
			}
			else if (choise == 2)
			{
				SeatClear(train, wagon, seat);
			}
			else if (choise == 3)
			{
				break;
			}
		}
	

		TrainDelete(train, wagon, seat);
	}
	void DZ_09_10() {
		double fruit[]{ 90, 95, 110, 85 }; //Яблоко, Апельсин, Абрикос, Груша
		double veget[]{ 110, 130, 100 }; //Томат, Лук, Огурец
		double tea[]{ 70, 80 }; //Чеснок, Петрушка

		char again = 'y';

		while (again == 'y')
		{
			int againС = 1;

			std::cout << "Соки Тимофея" << "\n"
				<< "Assортимент:" << "\n"
				<< "Фруктовые соки: Яблоко, Апельсин, Абрикос, Груша" << "\n"
				<< "Овощные соки: Томат, Лук, Огурец" << "\n"
				<< "ЧААААЙ: Чеснок, Петрушка" << "\n" << "\n";

			while (againС == 1)
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

				std::cout << "Действия:" << "\n"
					<< "Начать покупки (1)" << "\n"
					<< "Отказаться от категории (2)" << "\n"
					<< "Выбор: ";
				std::cin >> choise;

				if (choise == 2)
				{
					std::cout << "От какой котегории отказаться?" << "\n"
						<< "Фрукты (1), Овощи (2), Чай (3)" << "\n"
						<< "Выбор: ";
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
						std::cout << "Желаете отказаться ещё от категории? (y/n): ";
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
						std::cout << "Выбирайте категорию:" << "\n";

						if (DelCheck(delet, 1) != 1)
						{
							std::cout << "Фрукты (1)" << "\n";
						}
						if (DelCheck(delet, 2) != 2)
						{
							std::cout << "Овощи (2)" << "\n";
						}
						if (DelCheck(delet, 3) != 3)
						{
							std::cout << "Чай (3)" << "\n";
						}
						std::cout << "Выбор: ";

						std::cin >> buyCat;

						if (buyCat == 1 && DelCheck(delet, 1) != 1)
						{
							std::cout << "Выбирайте товар" << "\n"
								<< "Яблоко (1), Апельсин (2), Абрикос (3), Груша (4)" << "\n"
								<< "Выбор: ";
							std::cin >> buyTowar;
							std::cout << "Выбирайте количество: ";
							std::cin >> quantity;
							cost += fruit[buyTowar - 1] * quantity;
						}
						else if (buyCat == 2 && DelCheck(delet, 2) != 2)
						{
							std::cout << "Выбирайте товар:" << "\n"
								<< "Томат (1), Лук (2), Огурец (3)" << "\n"
								<< "Выбор: ";
							std::cin >> buyTowar;
							std::cout << "Количество: ";
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
							std::cout << "Выбирайте товар:" << "\n"
								<< "Чеснок (1), Петрушка (2)" << "\n"
								<< "Выбор: ";
							std::cin >> buyTowar;
							std::cout << "Выбирайте количество: ";
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
							std::cout << "Вы отказались от этой категории или её нет." << "\n";
						}
						std::cout << "Продолить закуп? (y/n): ";
						std::cin >> ceep;
						std::cout << "\n";
					}
				}

				if (actionLuk >= 4)
				{
					actionLuk -= (actionLuk / 4);
					cost += veget[1] * actionLuk;
					std::cout << "Скидка на луковый сок." << "\n" << "\n";
				}
				else
				{
					cost += actionCostLuk;
				}
				if (actionTea >= 3)
				{
					cost += actionCostTea * 0.95;
					std::cout << "Скидка на петрушевый чай." << "\n" << "\n";
				}
				if (cost >= 700)
				{
					cost *= 0.87;
					std::cout << "Скидка на весь чек от 700." << "\n" << "\n";
				}
				std::cout << "Итоговая цена: " << cost << "\n" << "\n";
				std::cout << "Повторить? (y/n): ";
				std::cin >> again;
				std::cout << "\n";
			}
		}
	}
	void DZ_30_09() {

		std::cout << "\nЗадание 1 \n";

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
		std::cout << "Минимум: " << min << std::endl
			<< "Максимум: " << max << std::endl;


		std::cout << "\nЗадание 2 \n";

		int maxInp, minInp, minSum;
		const int size2 = 20;
		int array[size2];
		int summ = 0;

		std::cout << "Введите минимальное значение: "; std::cin >> minInp;
		std::cout << "Введите максимальное значение: "; std::cin >> maxInp;

		for (size_t i = 0; i < size2; i++)
		{
			array[i] = rand() % (maxInp - minInp + 1) + (minInp);
			std::cout << array[i] << " ";
		}
		std::cout << "\n";

		std::cout << "Введите значение: "; std::cin >> minSum;

		for (size_t i = 0; i < size2; i++)
		{
			if (array[i] < minSum)
			{
				summ += array[i];
			}
		}
		std::cout << "Сумма: " << summ;

		std::cout << "\nЗадание 3 \n";

		int year[12];
		int minM, maxM;

		for (size_t i = 0; i < 12; i++)
		{
			std::cout << "Введите прибыль за " << i + 1 << " месяц: "; std::cin >> year[i];
		}

		std::cout << "Введите минимальное значение: "; std::cin >> minM;
		std::cout << "Введите максимальное значение: "; std::cin >> maxM;

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
		std::cout << "Минимум был в " << minPrice + 1 << std::endl
			<< "Максимум был в " << maxPrice + 1 << std::endl;
	}
	void DZ_23_09() {

		std::cout << "Задание 1 \n";

		int num;
		int loop = 1;

		while (loop == 1)
		{
			std::cout << "Введите 6-ти значное число: ";
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
				std::cout << "Число не 6-ти значное. Повторите попытку. \n";
			}
		}

		if ((num / 100000 % 10 + num / 10000 % 10 + num / 1000 % 10) == (num / 100 % 10 + num / 10 % 10 + num / 1 % 10))
		{
			std::cout << "Ваше число счастливое. \n";
		}
		else
		{
			std::cout << "Ваше число не счастливое. \n";
		}

		std::cout << "\nЗадание 2 \n";

		int numb;
		int loops = 1;

		while (loops == 1)
		{
			std::cout << "Введите 4-ёх значное число: ";
			std::cin >> numb;

			if (numb / 1000 >= 1)
			{
				break;
			}
			else
			{
				std::cout << "Число не 4-ёх значное. Повторите попытку. \n";
			}
		}

		std::cout << "Результат: " << (numb / 1000 % 10) * 100 + (numb / 100 % 10) * 1000 + (numb / 10 % 10) + (numb / 1 % 10) * 10;

		std::cout << "\nЗадание 3 \n";

		int number, max;

		std::cout << "Введите число: ";
		std::cin >> max;

		for (size_t i = 0; i < 6; i++)
		{
			std::cout << "Введите число: ";
			std::cin >> number;

			if (number > max)
			{
				max = number;
			}
		}

		std::cout << "Максимальное число: " << max;
	}
	void DZ_18_09() {

		std::cout << "Задание 1.\n\n";

		float distance;
		float time;
		float speed;

		std::cout << "Введите расстояние (Км): ", std::cin >> distance;
		while (distance < 0)
		{
			std::cout << "Ошибка! Расстояние не может быть меньше 0!\n";
			std::cout << "Введите расстояние повторно (Км): ", std::cin >> distance;
		}

		std::cout << "Введите время (Ч): ", std::cin >> time;
		while (time < 0)
		{
			std::cout << "Ошибка! Время не может быть меньше 0!\n";
			std::cout << "Введите время повторно (Ч): ", std::cin >> time;
		}

		speed = distance / time;

		std::cout << "\nВам нужно ехать со скоростью: " << speed << " Км/Ч\n";

		std::cout << "------------------------------------\n";
		std::cout << "Задание 2.\n\n";

		int timeStart[3];
		int timeEnd[3];
		float price;

		std::cout << "Введите время начала поездки.\n";
		std::cout << "Часы: ", std::cin >> timeStart[0];
		std::cout << "Минуты: ", std::cin >> timeStart[1];
		std::cout << "Секунды: ", std::cin >> timeStart[2];

		std::cout << "\nВведите время окончания поездки.\n";
		std::cout << "Часы: ", std::cin >> timeEnd[0];
		std::cout << "Минуты: ", std::cin >> timeEnd[1];
		std::cout << "Секунды: ", std::cin >> timeEnd[2];

		price = (((timeEnd[0] - timeStart[0]) * 60) + (timeEnd[1] - timeStart[1]) + ((timeEnd[2] - timeStart[2]) / 60)) * 2;
		if (price < 0)
		{
			price *= -1;
		}

		std::cout << "Стоимоть поездки составляет: " << price << " Гривен\n";

		std::cout << "------------------------------------\n";
		std::cout << "Задание 3.\n\n";

		float distance3 = 0;
		float lessFuel = 0;
		float fuelPrice[3];

		std::cout << "Введите расстояние (Км): ", std::cin >> distance3;
		while (distance3 < 0)
		{
			std::cout << "Ошибка! Расстояние не может быть меньше 0!\n";
			std::cout << "Введите расстояние повторно (Км): ", std::cin >> distance3;
		}
		std::cout << "\n";

		std::cout << "Введите расход топлива на 100 Км (Л): ", std::cin >> lessFuel;
		std::cout << "\n";
		if (lessFuel < 0)
		{
			lessFuel *= -1;
		}

		std::cout << "Введите стоимость 3-х видов топлива за 1 Л: \n";
		std::cout << "92: ", std::cin >> fuelPrice[0];
		std::cout << "95: ", std::cin >> fuelPrice[1];
		std::cout << "Дизель: ", std::cin >> fuelPrice[2];
		std::cout << "\n";

		std::cout << "Стоимость поездок на 3-х видах топлива: \n";
		std::cout << "92: " << distance3 / 100 * lessFuel * fuelPrice[0] << "\n";
		std::cout << "95: " << distance3 / 100 * lessFuel * fuelPrice[1] << "\n";
		std::cout << "Дизель: " << distance3 / 100 * lessFuel * fuelPrice[2] << "\n";
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