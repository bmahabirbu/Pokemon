#include "GameCommand.h"
#include "View.h"
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

int main(void)
{
	srand(time(NULL)); //git test
	Model model;
	model.Update();
	View view;
	model.Display(view);

	while (true)
	{
		char command;
		cout << "enter command" << endl;
		cin >> command;
		switch (command)
		{
			case 'm':
			{
				int ID, x, y;
				cin >> ID >> x >> y;
				DoMoveCommand(model, ID, Point2D(x, y));
			}
			break;

			case 'b':
			{
				int ID1, ID2;
				cin >> ID1 >> ID2;
				DoBattleCommand(model, ID1, ID2);
			}
			break;

			case 'a':
			{
				int ID1, ID2;
				cin >> ID1 >> ID2;
				DoMoveToArenaCommand(model, ID1, ID2);
			}
			break;

			case 'g':
			{
				int ID1, ID2;
				cin >> ID1 >> ID2;
				DoMoveToGymCommand(model, ID1, ID2);
			}
			break;

			case 'c':
			{
				int ID1, ID2;
				cin >> ID1 >> ID2;
				DoMoveToCenterCommand(model, ID1, ID2);
			}
			break;

			case 's':
			{
				int ID;
				cin >> ID;
				DoStopCommand(model, ID);
			}
			break;

			case 'r':
			{
				int ID1, stamina_amount;
				cin >> ID1 >> stamina_amount;
				DoRecoverInCenterCommand(model, ID1, stamina_amount);
			}
			break;

			case 't':
			{
				int ID1, unit_amount;
				cin >> ID1 >> unit_amount;
				DoTrainInGymCommand(model, ID1, unit_amount);
			}
			break;

			case 'v':
			{
				DoGoCommand(model, view);
			}
			break;

			case 'x':
			{
				DoRunCommand(model, view);
			}
			break;

			case 'q':
			{
				exit(0);
			}
			break;

			default:
			{
				cout << "Something went wrong" << endl;
			}
		}

	}
	

}


