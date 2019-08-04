CC=/usr/bin/clang++-4.0
#CC=g++
CFLAGS=-std=c++11 -Wall  -fPIC
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
    ./main.o \
    ./Character/Character.o \
    ./Outfit/thing.o \
    ./Outfit/Outfit.o \
    ./Outfit/Weapon/magicweapon.o \
    ./Outfit/Weapon/physicalweapon.o \
    ./Outfit/Weapon/weapon.o \
    ./Outfit/Defense/defense.o \
    ./Outfit/Defense/magicdefense.o \
    ./Outfit/Defense/physicaldefense.o \
    ./GameBuilder/HeroBuilder/HeroBuilder.o \
    ./GameBuilder/HeroBuilder/JsonHeroBuilder.o \
    ./Outfit/Decorators/DefenseDecorators/DefenseDecorator.o \
    ./Outfit/Decorators/DefenseDecorators/IncreaseChanceOfDobge.o \
    ./Outfit/Decorators/DefenseDecorators/IncreaseCharacteristicDefense.o \
    ./Outfit/Decorators/DefenseDecorators/IncreaseCriticalHitChanceDefense.o \
    ./Outfit/Decorators/DefenseDecorators/IncreaseReflectionOfDamage.o \
    ./Outfit/Decorators/DefenseDecorators/IncreaseResistanceToDamage.o \
    ./Outfit/Decorators/WeaponDecorators/weapondecorator.o \
    ./Outfit/Decorators/WeaponDecorators/AdditionalHit.o \
    ./Outfit/Decorators/WeaponDecorators/BreakingWeapon.o \
    ./Outfit/Decorators/WeaponDecorators/DamnedWeapon.o \
    ./Outfit/Decorators/WeaponDecorators/IncreaseCharacteristicWeapon.o \
    ./Outfit/Decorators/WeaponDecorators/IncreaseCriticalHitChanceWeapon.o \
    ./Outfit/Decorators/WeaponDecorators/IncreaseCriticalHitModifier.o \
    ./Outfit/Decorators/WeaponDecorators/PiercingWeapon.o \
    ./Outfit/Decorators/WeaponDecorators/StunningWeapon.o


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
