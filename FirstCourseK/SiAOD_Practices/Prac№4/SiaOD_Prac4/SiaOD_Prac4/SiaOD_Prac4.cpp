#include <iostream>

struct Date
{
	int day;
	int month;
	int year;
	Date(int d, int m, int y)
	{
		day = d;
		month = m;
		year = y;
	}
	Date()
	{
		day = month = year = 0;
	}
};

struct Ticket
{
	int TrainNumber;
	int CostOfTicket;
	int Wagon;
	int Seat;
	Date dateOfDep;
	Ticket(int number, int i, int j, int UserCostOfTicket, int d, int m, int y)
	{
		TrainNumber = number;
		Wagon = i;
		Seat = j;
		CostOfTicket = UserCostOfTicket;
		Date dateOfDep(d, m, y);
	}
};

bool matchDate(Date userDate, int d, int m, int y)
{
	if (userDate.day != d || userDate.month != m || userDate.year != y)
		return(false);
	return (true);
}

int ShowTickets(Ticket* List, int length, int trainNumber, int d, int m, int y)
{
	int count = 0;
	for (int i = 0; i < length; i++)
	{
		if ((List[i].TrainNumber = trainNumber) && matchDate(List[i].dateOfDep, d, m, y))
			count += 1;
	}
	return(count);
}
bool IsTicket(Ticket* List, int length, int* currPrice, int* currWagon, int* currSeat, int* currTrainNumber, int d, int m, int y)
{
	for (int i = 0; i < length; i++)
	{
		if (List[i].TrainNumber == *currTrainNumber && List[i].Wagon == *currWagon && List[i].Seat == *currSeat && List[i].CostOfTicket == *currPrice && matchDate(List[i].dateOfDep, d, m, y))
		{
			return(true);
		}
	}
	return(false);
}
Ticket* BuyTicket(Ticket* List, int length, int* currPrice, int* currWagon, int* currSeat, int* currTrainNumber, int d, int m, int y)
{
	Ticket* temp = (Ticket*)realloc(List, (sizeof(Ticket) * (length)));
	if (temp == NULL)
		return (NULL);
	List = temp;
	List[length - 1] = Ticket(*currTrainNumber, *currWagon, *currSeat, *currPrice, d, m , y);
	return(List);
}
Ticket* SellTicket(Ticket* List, int length, int* currPrice, int* currWagon, int* currSeat, int* currTrainNumber, int d, int m, int y)
{
	for (int i = 0; i < length; i++)
	{
		if (List[i].TrainNumber == *currTrainNumber && List[i].Wagon == *currWagon && List[i].Seat == *currSeat && List[i].CostOfTicket == *currPrice && matchDate(List[i].dateOfDep, d, m, y))
		{
			while (i != length - 1)
			{
				std::swap(List[i], List[i + 1]);
				i++;
			}
			length--;
			Ticket* temp = (Ticket*)realloc(List, sizeof(Ticket) * length);
			if (temp != NULL)
			{
				List = temp;
				return(temp);
			}
			else
			{
				return (NULL);
			}
		}
	}
}
void OutTakenSeats(int wagonLength, int length, Ticket* List, int* wagons)
{
	for (int i = 0; i < wagonLength; i++)
	{
		for (int j = 0; j < length; j++)
		{
			if (List[j].Wagon == wagons[i])
			{
				std::cout << "Train Number " << List[j].TrainNumber << std::endl;
				std::cout << "Wagon " << List[j].Wagon << std::endl;
				std::cout << "Seat " << List[j].Seat << std::endl;
				std::cout << "Cost " << List[j].CostOfTicket << std::endl;
				std::cout << "Time " << List[j].dateOfDep.day << ':' << List[j].dateOfDep.month << ':' << List[j].dateOfDep.month << std::endl;
			}
		}
		std::cout << std::endl;
	}
}


int main()
{
	Ticket* List = (Ticket*)malloc(sizeof(Ticket));
	if (List == NULL)
		return 1;
	int Control;
	int length = 0;
	int wagonLength = 0;
	int* wagons = (int*)malloc(sizeof(int) * wagonLength);
	do
	{
		std::cout << "This is train company Kozloff" << std::endl;
		std::cout << "What u wannna do ? 1 - amont of tickets of time 2 - buy ticket 3 - sell ticket 4 - taken seat of wagons" << std::endl;
		std::cin >> Control;
		switch (Control)
		{
		case 1:
		{
			int d, m, y;
			int num;
			std::cout << "Enter Time" << std::endl;
			std::cin >> d >> m >> y;
			Date time(d, y, m);
			std::cout << "Enter number of train" << std::endl;
			std::cin >> num;
			std::cout << "Showing all bought tickets..." << std::endl;
			std::cout << ShowTickets(List, length, num, d, m, y) << std::endl;
			std::cout << "length = " << length << std::endl;
			break;
		}
		case 2:
		{
			int* currPrice = new int;
			int* currWagon = new int;
			int* currSeat = new int;
			int* currTrainNumber = new int;
			int d, m, y;
			std::cout << "Enter Train Number" << std::endl;
			std::cin >> *currTrainNumber;
			std::cout << "Enter Wagon number" << std::endl;
			std::cin >> *currWagon;
			std::cout << "Enter Seat number" << std::endl;
			std::cin >> *currSeat;
			std::cout << "Enter Price" << std::endl;
			std::cin >> *currPrice;
			std::cout << "Enter Time" << std::endl;
			std::cin >> d >> m >> y;

			length += 1;
			List = BuyTicket(List, length, currPrice, currWagon, currSeat, currTrainNumber, d, m, y);
			bool flag = true;
			for (int i = 0; i < wagonLength; i++)
			{
				if (wagons[i] == *currWagon)
				{
					flag = false;
					break;
				}
			}
			if (flag)
			{
				wagonLength++;
				wagons = (int*)realloc(wagons, sizeof(int) * wagonLength);
				wagons[wagonLength - 1] = *currWagon;
			}
			std::cout << "length = " << length << std::endl;

			delete currPrice;
			delete currTrainNumber;
			delete currSeat;
			delete currWagon;
			break;
		}
		case 3:
		{
			int* currPrice = new int;
			int* currWagon = new int;
			int* currSeat = new int;
			int* currTrainNumber = new int;
			int d, m, y;
			std::cout << "Enter Train Number" << std::endl;
			std::cin >> *currTrainNumber;
			std::cout << "Enter Wagon number" << std::endl;
			std::cin >> *currWagon;
			std::cout << "Enter Seat number" << std::endl;
			std::cin >> *currSeat;
			std::cout << "Enter Price" << std::endl;
			std::cin >> *currPrice;
			std::cout << "Enter Time" << std::endl;
			std::cin >> d >> m >> y;

			if (IsTicket(List, length, currPrice, currWagon, currSeat, currTrainNumber, d, m, y))
			{
				List = SellTicket(List, length, currPrice, currWagon, currSeat, currTrainNumber, d, m, y);
				length--;
				if (length < 0)
				{
					length++;
				}
			}

			delete currPrice;
			delete currTrainNumber;
			delete currSeat;
			delete currWagon;
			std::cout << "length = " << length << std::endl;
			break;
		}
		case 4:
		{
			OutTakenSeats(wagonLength, length, List, wagons);
			/*for (int i = 0; i < wagonLength; i++)
			{
				std::cout << wagons[i] << ' ';
			}
			std::cout << std::endl;*/
			/*for (int j = 0; j < 5; j++)
			{
				std::cout << "Train Number " << List[j].TrainNumber << std::endl;
				std::cout << "Wagon " << List[j].Wagon << std::endl;
				std::cout << "Seat " << List[j].Seat << std::endl;
				std::cout << "Cost " << List[j].CostOfTicket << std::endl;
				std::cout << "Time " << List[j].TimeOfDepartation << std::endl;
			}*/
			/*std::cout << "length = " << length << std::endl;
			std::cout << "length = " << wagonLength << std::endl;*/
			break;
		}
		}
	} while (Control == 1 || Control == 2 || Control == 3 || Control == 4);
	free(List);
}
