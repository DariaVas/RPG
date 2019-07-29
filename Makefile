CC=/usr/bin/clang++-4.0
CFLAGS=-std=c++11 -Wall
INC=\
    $(PWD) \
    $(PWD)/Character \
    $(PWD)/GameBuilder \
    $(PWD)/GameBuilder/HeroBuilder \
    $(PWD)/Outfit \
    $(PWD)/Outfit/Decorators/WeaponDecorators \
    $(PWD)/Outfit/Decorators/DefenseDecorators \
    $(PWD)/Outfit/Defense \
    $(PWD)/Outfit/Weapon

INC_PARAMS=$(foreach d, $(INC), -I$d)
LDFLAGS=
SOURCES=\
    main.cpp \
    Character/Character.cpp \
    Outfit/thing.cpp \
    Outfit/Outfit.cpp \
    Outfit/Weapon/magicweapon.cpp \
    Outfit/Weapon/physicalweapon.cpp \
    Outfit/Weapon/weapon.cpp \
    Outfit/Defense/defense.cpp \
    Outfit/Defense/magicdefense.cpp \
    Outfit/Defense/physicaldefense.cpp \
    GameBuilder/HeroBuilder/HeroBuilder.cpp \
    GameBuilder/HeroBuilder/JsonHeroBuilder.cpp

OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=RPG

#all: $(SOURCES) $(EXECUTABLE)
all: $(EXECUTABLE)
clean:
	ar r $@ $? && rm *.o
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) $(CPPFLAGS) $(INC_PARAMS)  -c $<
