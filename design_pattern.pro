TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Outfit/Armor/armor.cpp \
        Outfit/Weapon/weapon.cpp \
        main.cpp \
        thing.cpp \
        weapon.cpp

DISTFILES += \
    character.json

HEADERS += \
    Outfit/Armor/armor.h \
    Outfit/Weapon/weapon.h \
    damage.h \
    thing.h \
    weapon.h
