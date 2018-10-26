//Matt McMenamin
//COSC 2030
//Blood Sugar Project


#include <iostream>
#include <array>
using std::ostream;
#define ulong unsigned long
#include <iostream>
#include "LinkedList.h"
#include <string>
#include <cmath>

using std::cout;
using std::endl;
using std::cin;
using std::string;

List days[14];
int main()
{
	int data;
	int sum =0;
	int max = 0;
	int min = 0;
	int size = 0;
	int delta = 0;
	int delta_index = 0;
	string input;
	cout << "Enter your blood sugar readings. \n";
	cout << "Type N or Next to move to the next day. \n";
	cout << "Type D or Day to show the daily summary thus far. \n";
	cout << "Type W or Week to show the Weekly summary thus far\n\n";

	
	for (int i = 0; i < 14; i++)
	{
		cout << "Enter your blood sugar readings for day " << i + 1 << ", press enter everytime you enter a value.\n";
		cin >> input;
		while (input != "N"&&input!="Next"&&input != "next"&&input != "n")
		{
			if (input == "D" || input == "Day" || input == "day" || input == "d")
			{
				cout << "Daily sum so far: " << days[i].sum() << endl;
				cout << "Daily minumum so far: " << days[i].min() << endl;
				cout << "Daily maximum so far: " << days[i].max() <<  endl;
				cout << "Daily amount of inputs so far: " << days[i].size() << endl;
			}
			else if (input == "W"||input=="Week" || input == "week" || input == "w")
				
			{
				
				if (i < 7)
				{
					for (int k = 0; k < 7; k++)
					{
						sum += days[k].sum();
					}
					for (int k = 0; k < 7; k++)
					{
						size += days[k].size();
					}
					delta = abs(days[0].size() - days[1].size());
					delta_index = 1;
					for (int k = 2; k < 7; k++)
					{
						if (delta < abs(days[k -1 ].size() - days[k].size()))
						{
							delta = abs(days[k - 1].size() - days[k].size());
							delta_index = k;
						}
					}
					max = days[0].max();
					for (int k = 0; k < 7; k++)
					{
						if (max < days[k].max())
						{
							max = days[k].max();
						}
					}
					min = days[0].min();
					for (int k = 0; k < 7; k++)
					{
						if (min > days[k].min())
						{
							min = days[k].min();
						}
					}

				}
				else
				{
					for (int k = 7; k < 14; k++)
					{
						
						sum += days[k].sum();
					}
					for (int k = 7; k < 14; k++)
					{
						size += days[k].size();
					}
					max = days[0].max();
					for (int k = 7; k < 14; k++)
					{
						if (max < days[k].max())
						{
							max = days[k].max();
						}
					}
					min = days[0].min();
					for (int k = 7; k < 14; k++)
					{
						if (min > days[k].min())
						{
							min = days[k].min();
						}
					}
					delta = abs(days[7].size() - days[8].size());
					delta_index = 8;
					for (int k = 9; k < 14; k++)
					{
						if (delta < abs(days[k - 1].size() - days[k].size()))
						{
							delta = abs(days[k - 1].size() - days[k].size());
							delta_index = k;
						}
					}
				}

				cout << "Weekly sum: " << sum << endl;
				cout << "Weekly max: " << max << endl;
				cout << "Weekly min: " << min << endl;
				cout << "Weekly amount of inputs: " << size << endl;
				cout << "Biggest weekly delta from day "<< delta_index  << " to day " << delta_index + 1 << endl;

			}
			else //Data entry Case
			{
				if (input.find_first_of("0123456789") != string::npos)
				{
					data = stoi(input);
					if (data > 0)
					{
						days[i].insertAsFirst(data);
					}
				}
			}
			cin >> input;
		} 
		
	}
	
system("pause");
return 0;
	
}














