PROG = main
CC = g++
CPPFLAGS = -Wall -O2
OBJS = main.o Game.o Character.o CharacterCreatorState.o CharacterMenuState.o CharacterSelectorState.o CharacterStatMenuState.o CombatState.o GameState.o Enemy.o Inventory.o Item.o MainMenuState.o msg_functions.o State.o TravelMenuState.o Weapon.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o :
	$(CC) $(CPPFLAGS) -c main.cpp

Game.o : Game.h
	$(CC) $(CPPFLAGS) -c Game.cpp

Character.o : Character.h
	$(CC) $(CPPFLAGS) -c Character.cpp

CharacterCreatorState.o : CharacterCreatorState.h
	$(CC) $(CPPFLAGS) -c CharacterCreatorState.cpp

CharacterMenuState.o : CharacterMenuState.h
	$(CC) $(CPPFLAGS) -c CharacterMenuState.cpp

CharacterSelectorState.o : CharacterSelectorState.h
	$(CC) $(CPPFLAGS) -c CharacterSelectorState.cpp

CharacterStatMenuState.o : CharacterStatMenuState.h
	$(CC) $(CPPFLAGS) -c CharacterStatMenuState.cpp

CombatState.o : CombatState.h
	$(CC) $(CPPFLAGS) -c CombatState.cpp

GameState.o : GameState.h
	$(CC) $(CPPFLAGS) -c GameState.cpp

Enemy.o : Enemy.h
	$(CC) $(CPPFLAGS) -c Enemy.cpp

Inventory.o : Inventory.h
	$(CC) $(CPPFLAGS) -c Inventory.cpp

Item.o : Item.h
	$(CC) $(CPPFLAGS) -c Item.cpp

MainMenuState.o : MainMenuState.h
	$(CC) $(CPPFLAGS) -c MainMenuState.cpp

msg_functions.o : msg_functions.h
	$(CC) $(CPPFLAGS) -c msg_functions.cpp

State.o : State.h
	$(CC) $(CPPFLAGS) -c State.cpp

TravelMenuState.o : TravelMenuState.h
	$(CC) $(CPPFLAGS) -c TravelMenuState.cpp

Weapon.o : Weapon.h
	$(CC) $(CPPFLAGS) -c Weapon.cpp

clean :
	rm -f core $(PROG) $(OBJS)