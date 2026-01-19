#include "Game.h"
#include "Dragon.h"
#include "Player.h"

int main()
{
	Game WarGame;
	Player *P=new Player("P",5,2,20,7);
	Dragon *d1=new Dragon ("d1",15,10,10,20,3);
	Dragon *d2=new Dragon ("d2",16,10,15,26,6);
	Monster *m1=new Monster ("m1",2,2,6,4);
	Monster *m2=new Monster ("m2",20,20,20,100);

	cout<<"\n----------------------- Add Creatures --------------------------\n";
	WarGame.AddCreature(P);
	WarGame.AddCreature(d1);
	WarGame.AddCreature(d2);
	WarGame.AddCreature(m1);
	WarGame.AddCreature(m2);
	
	WarGame.drawAllCreatures();

	cout<<"\n\n----------------------- Fight between dragon2 and Monster2 --------------------------\n";
	WarGame.MoveCreature("d2",20,20);

	cout<<"\n\n----------------------- Move dragon2 to unoccupied position --------------------------\n";
	WarGame.MoveCreature("d2", 4, 9);

	cout<<"\n\n----------------------- Fight between dragon1 and dragon2 --------------------------\n";
	WarGame.MoveCreature("d1",4,9);
		
	cout<<"\n\n----------------------- Fight between Player and dragon2 --------------------------\n";
	WarGame.MoveCreature("P", 4, 9);

	cout<<"\n\n----------------------- Fight between Player and Monster1 --------------------------\n";
	WarGame.MoveCreature("P", 2, 2);

	return 0;
}