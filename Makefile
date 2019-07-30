#CC=/usr/bin/clang++-4.0
CC=g++
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
    ./main.cpp \
    ./Character/Character.cpp \
    ./Outfit/thing.cpp \
    ./Outfit/Outfit.cpp \
    ./Outfit/Weapon/magicweapon.cpp \
    ./Outfit/Weapon/physicalweapon.cpp \
    ./Outfit/Weapon/weapon.cpp \
    ./Outfit/Defense/defense.cpp \
    ./Outfit/Defense/magicdefense.cpp \
    ./Outfit/Defense/physicaldefense.cpp \
    ./GameBuilder/HeroBuilder/HeroBuilder.cpp \
    ./GameBuilder/HeroBuilder/JsonHeroBuilder.cpp \
    ./Outfit/Decorators/DefenseDecorators/DefenseDecorator.cpp \
    ./Outfit/Decorators/DefenseDecorators/IncreaseChanceOfDobge.cpp \
    ./Outfit/Decorators/DefenseDecorators/IncreaseCharacteristicDefense.cpp \
    ./Outfit/Decorators/DefenseDecorators/IncreaseCriticalHitChanceDefense.cpp \
    ./Outfit/Decorators/DefenseDecorators/IncreaseReflectionOfDamage.cpp \
    ./Outfit/Decorators/DefenseDecorators/IncreaseResistanceToDamage.cpp \
    ./Outfit/Decorators/WeaponDecorators/AdditionalHit.cpp \
    ./Outfit/Decorators/WeaponDecorators/BreakingWeapon.cpp \
    ./Outfit/Decorators/WeaponDecorators/DamnedWeapon.cpp \
    ./Outfit/Decorators/WeaponDecorators/IncreaseCharacteristicWeapon.cpp \
    ./Outfit/Decorators/WeaponDecorators/IncreaseCriticalHitChanceWeapon.cpp \
    ./Outfit/Decorators/WeaponDecorators/IncreaseCriticalHitModifier.cpp \
    ./Outfit/Decorators/WeaponDecorators/PiercingWeapon.cpp \
    ./Outfit/Decorators/WeaponDecorators/StunningWeapon.cpp


OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=RPG

#all: $(SOURCES) $(EXECUTABLE)
all: $(EXECUTABLE)
clean:
	find . -type f -name '*.o' -delete
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $^ $(LIBS) -ldl

%.o: %.cpp
	$(CC) $(CFLAGS) $(CPPFLAGS) $(INC_PARAMS)  -c $<  -o $@
