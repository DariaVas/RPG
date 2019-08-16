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

ifeq ($(DEBUG), 1)
    CFLAGS += -DDEBUG -g
else
    CLFAGS += -O2
endif

INC_PARAMS=$(foreach d, $(INC), -I$d)
LDFLAGS=
SOURCES=\
    ./main.o \
    ./Character/Character.o \
    ./Character/CharacterizationObservable.o \
    ./Character/Parameters.o \
    ./Outfit/Thing.o \
    ./Outfit/Outfit.o \
    ./Outfit/Weapon/MagicWeapon.o \
    ./Outfit/Weapon/PhysicalWeapon.o \
    ./Outfit/Weapon/Weapon.o \
    ./Outfit/Defense/Defense.o \
    ./Outfit/Defense/MagicDefense.o \
    ./Outfit/Defense/PhysicalDefense.o \
    ./GameBuilder/HeroBuilder/HeroBuilder.o \
    ./GameBuilder/HeroBuilder/JsonHeroBuilder.o \
    ./Outfit/Decorators/DefenseDecorators/DefenseDecorator.o \
    ./Outfit/Decorators/DefenseDecorators/IncreaseChanceOfDodge.o \
    ./Outfit/Decorators/DefenseDecorators/IncreaseCharacteristicDefense.o \
    ./Outfit/Decorators/DefenseDecorators/IncreaseCriticalHitChanceDefense.o \
    ./Outfit/Decorators/DefenseDecorators/IncreaseReflectionOfDamage.o \
    ./Outfit/Decorators/DefenseDecorators/IncreaseResistanceToDamage.o \
    ./Outfit/Decorators/WeaponDecorators/WeaponDecorator.o \
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

all: $(EXECUTABLE)
clean:
	find . -type f -name '*.o' -delete
	rm -f RPG
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $^ $(LIBS) -ldl

%.o: %.cpp
	$(CC) $(CFLAGS) $(CPPFLAGS) $(INC_PARAMS)  -c $<  -o $@
