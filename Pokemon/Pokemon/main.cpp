#include "GameCommand.h"
#include "View.h"
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "Input_Handling.h"

int main(void)
{
	cout << "EC327: Introduction to Software Engineering" << endl;
	cout << "Fall 2019" << endl;
	cout << "Programming Assignment 3" << endl;


	cout << "                                  ,'\\ " << endl;
	cout << "   _.----.        ____         ,'  _\\   ___    ___     ____ " << endl;
	cout << "_,-'       `.     |    |  /`.   \\,-'    |   \\  /   |   |    \\  |`. " << endl;
	cout << "\\      __    \\    '-.  | /   `.  ___    |    \\/    |   '-.   \\ |  | " << endl;
	cout << " \\.    \\ \\   |  __  |  |/    ,','_  `.  |          | __  |    \\|  | " << endl;
	cout << "   \\    \\/   /,' _`.|      ,' / / / /   |          ,' _`.|     |  | " << endl;
	cout << "    \\     ,-'/  /   \\    ,'   | \\/ / ,`.|         /  /   \\  |     | " << endl;
	cout << "     \\    \\ |   \\_/  |   `-.  \\    `'  /|  |    ||   \\_/  | |\\    | " << endl;
	cout << "      \\    \\ \\      /       `-.`.___,-' |  |\\  /| \\      /  | |   | " << endl;
	cout << "       \\    \\ `.__,'|  |`-._    `|      |__| \\/ |  `.__,'|  | |   | " << endl;
	cout << "        \\_.-'       |__|    `-._ |              '-.|     '-.| |   | " << endl;
	cout << "                                `'                            '-._| " << endl;

	srand(time(NULL)); //git test
	Model model;
	model.Update();
	View view;
	model.Display(view);

	char command;
	
	

	while (true)
	{
		cout << "enter command" << endl;
		cin >> command;
	try {
			switch (command)
			{
			case 'm':
			{
				int ID, x, y;

				if (!(cin >> ID))
				{
					throw Invalid_Input("Need an integer for ID");
				}
				if (!(cin >> x))
				{
					throw Invalid_Input("Wrong x coordinate");
				}
				if (!(cin >> y))
				{
					throw Invalid_Input("Wrong y coordinate");
				}

				DoMoveCommand(model, ID, Point2D(x, y));
				cin.clear();
				cin.ignore(500, '\n');
			}

			break;

			case 'b':
			{
				int ID1, ID2;
				if (!(cin >> ID1))
				{
					throw Invalid_Input("Need an integer for ID1");
				}
				if (!(cin >> ID2))
				{
					throw Invalid_Input("Need an integer for ID2");
				}
				DoBattleCommand(model, ID1, ID2);
				cin.clear();
				cin.ignore(500, '\n');
			}
			break;

			case 'a':
			{
				int ID1, ID2;
				if (!(cin >> ID1))
				{
					throw Invalid_Input("Need an integer for ID1");
				}
				if (!(cin >> ID2))
				{
					throw Invalid_Input("Need an integer for ID2");
				}
				DoMoveToArenaCommand(model, ID1, ID2);
				cin.clear();
				cin.ignore(500, '\n');
			}
			break;

			case 'g':
			{
				int ID1, ID2;
				if (!(cin >> ID1))
				{
					throw Invalid_Input("Need an integer for ID1");
				}
				if (!(cin >> ID2))
				{
					throw Invalid_Input("Need an integer for ID2");
				}
				DoMoveToGymCommand(model, ID1, ID2);
				cin.clear();
				cin.ignore(500, '\n');
			}
			break;

			case 'c':
			{
				int ID1, ID2;
				if (!(cin >> ID1))
				{
					throw Invalid_Input("Need an integer for ID1");
				}
				if (!(cin >> ID2))
				{
					throw Invalid_Input("Need an integer for ID2");
				}
				DoMoveToCenterCommand(model, ID1, ID2);
				cin.clear();
				cin.ignore(500, '\n');
			}
			break;

			case 's':
			{
				int ID;
				if (!(cin >> ID))
				{
					throw Invalid_Input("Need an integer for ID");
				}
				DoStopCommand(model, ID);
				cin.clear();
				cin.ignore(500, '\n');
			}
			break;

			case 'r':
			{
				int ID1, stamina_amount;
				if (!(cin >> ID1))
				{
					throw Invalid_Input("Need an integer for ID1");
				}
				if (!(cin >> stamina_amount))
				{
					throw Invalid_Input("Need valid input for stamina amount");
				}
				DoRecoverInCenterCommand(model, ID1, stamina_amount);
				cin.clear();
				cin.ignore(500, '\n');
			}
			break;

			case 't':
			{
				int ID1, unit_amount;
				if (!(cin >> ID1))
				{
					throw Invalid_Input("Need an integer for ID1");
				}
				if (!(cin >> unit_amount))
				{
					throw Invalid_Input("wrong type for unit amount ");
				}
				cin >> ID1 >> unit_amount;
				DoTrainInGymCommand(model, ID1, unit_amount);
				cin.clear();
				cin.ignore(500, '\n');
			}
			break;

			case 'v':
			{
				DoGoCommand(model, view);
				cin.clear();
				cin.ignore(500, '\n');
			}
			break;

			case 'x':
			{
				DoRunCommand(model, view);
				cin.clear();
				cin.ignore(500, '\n');
			}
			break;

			case 'q':
			{
				exit(0);
				cin.clear();
				cin.ignore(500, '\n');
			}
			break;

			case 'n':
			{
				int ID1, x, y;
				char type = 0;

				if (!(cin >> type))
				{
					throw Invalid_Input("want a char for display code");
				}
				if (!(cin >> ID1))
				{
					throw Invalid_Input("want an int for the ID #");
				}
				if (!(cin >> x))
				{
					throw Invalid_Input("want a double for x coordinate");
				}

				if (!(cin >> y))
				{
					throw Invalid_Input("want a double for y coordinate");
				}

				if (x > 20 || x < 0 || y < 0 || y > 20)
				{
					throw Invalid_Input("Make sure object is within the plotting boundary range");
				}

				model.ObjectMake(type, ID1, x, y);
				cin.clear();
				cin.ignore(500, '\n');
				break;
			}

			default:
			{
				throw Invalid_Input("Please enter a valid command code");
				break;
			}

			}
		}
		catch (Invalid_Input& except)
		{
			cout << "Invalid Input - " << except.msg_ptr << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}
	
	}
	

}


