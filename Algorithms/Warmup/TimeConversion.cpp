#include <iostream>
#include <string>
#include <locale>

int main()
{
	bool isAM;
	std::string time;
	std::string convertedTime;

	std::cin >> time;

	if (time.length() > 10) // 07:05:45PM (10 chars)
	{
		std::cerr << "Input length more than 10 chars" << std::endl;
		return 1;
	}

	if (!isdigit(time[0]) && !isdigit(time[1]) &&
		!isdigit(time[3]) && !isdigit(time[4]) &&
		!isdigit(time[6]) && !isdigit(time[7]))
	{
		std::cerr << "Invalid time given" << std::endl;
		return 1;
	}

	if (time[2] != ':' && time[5] != ':')
	{
		std::cerr << "Invalid separator format" << std::endl;
		return 1;
	}

	if ((time[8] != 'A' || time[8] != 'P') && time[9] != 'M')
	{
		std::cerr << "Invalid AM/PM format" << std::endl;
		return 1;
	}

	isAM = time[8] == 'A';
	
	convertedTime = time.substr(0, 8);

	if (!isAM)
	{
		unsigned int hour = ((convertedTime[0] - '0') * 10) + (convertedTime[1] - '0'); // Convert to integer
		hour = (hour + 12) % 24; // Wrap around to 00 - 24
		std::string hourStr = std::to_string(hour); // Convert to string

		convertedTime[0] = hours < 10 ? '0' : hourStr[0];
		convertedTime[1] = hour < 10 ? hourStr[0] : hourStr[1];
		 
		if (convertedTime[0] == '0' && convertedTime[1] == '0')
		{
			convertedTime[0] = '1';
			convertedTime[1] = '2';
		}
	} else
	{
		if (convertedTime[0] == '1' && convertedTime[1] == '2')
		{
			convertedTime[0] = '0';
			convertedTime[1] = '0';
		}
	}

	std::cout << convertedTime << std::endl;

	return 0;
}
