RPG - role-playing game

How to configure  in JSON:
    Firstly, you have to configure weapon and defenses effects, you can read about them in the specification.
    Note! Hero has characteristics, all of them are enumerated,
    to specify characteristic in json configuration you write out it number:
    "characteristics":
    {
    strength = 1,
    sleight = 2,
    intelligence = 3,
    physique = 4,
    luck = 5,
    initiative = 6,
    }
    Also, all types of damage are enumerated too.
    To specify the type of damage or the type of resistance / reflection, you should write out it number:
    "damage_type": {
      "physic": 1,
      "fire": 2,
      "ice": 3,
      "electric": 4,
      "acid": 5
    }

    When you have configured the weapon and defense effects, you can configure the heroes.
    The bounds of characteristics are from 0 to 1000 points.
    The parameters are calculated in the next way:
    HP = physical / 100
    Carried weight = strength
    Chance of dodge = luck / 100
    Chance of critical hit = (luck + sleight + carried weight)/300

    Chance of dodge and chance of critical hit is not bigger then 100 points.

    Configuration of outfit:
    Heroes outfit has 3 main section: armor , shield and weapon slots, magic things.
    You shouldn't change the number of things described in the any section.
    In the field "additional_effects" you can specify the number of chosen effect,
    For example:
              "name": "torso protection",
              "type_of_resistance": 1,
              "resistance": 10,
              "additional_effects": [
                1, // increase_characteristic effect
                3 // increase_reflection_to_damage effect
              ]
    Note! Weapon and defense has different effects.

    Things described in the armor section must have only physical type of defense.
    Things described in the magic_attributes section must have only magical type of defense.
    In the section defense_and_weapon_slots you can choose what you hero will use,
    hero can have shield and weapon (one-handed) or one two-handed weapon or two one-handed weapons.
    You have to write your choice in the field "choice".
    In the section "weapons_only" you can choose number of weapons and configure them.

Also you can choose random configuration of your heroes.
Log file path : ./RPG.log.

<br> <b> The next design patterns were used in the architecture of the project: </b></br>
<br>1. Factory method: </br>
The factory method pattern was used to generate heroes in different ways. So, we have GonfigGameCreator and RandomGameCreator what inherits from IGameCreator. GameCreator products HeroBuilder. In the future, this class can be increased to a Workers Factory.
<br> Code: </br>
<ul>
<li>/RPG/GameBuilder</li>
<li>/RPG/GameBuilder/HeroBuilder </li>
</ul>
<br>2. Template method</br>
The template method pattern was used to set the common steps for building an outfit and hero.
<br>Code:</br>
<ul>
<li>/RPG/GameBuilder/HeroBuilder</li>
</ul>
<br>3. State</br>
State pattern was used to set the different state of hero.
<br>Code:</br>
<ul>
<li>/RPG/Character/HeroState</li>
<li>/RPG/Character/Character.cpp</li>
<li>/RPG/Character/Character.h</li>
</ul>
<br>4.  Observer</br>
Observer pattern was used to notify class Parameters about changes in the class Characteristic, because parameters depends on characteristics.
<br>Code:</br>
<ul>
<li>/RPG/Character/CharacterizationObservable.cpp</li>
<li>/RPG/Character/CharacterizationObservable.h</li>
<li>/RPG/Character/IObserver.h</li>
<li>/RPG/Character/Parameters.cpp</li>
<li>/RPG/Character/Parameters.h</li>
</ul>
<br>5. Decorator</br>
The decorator pattern was used to dynamically add new properties for weapon and defenses.
<br>Code:</br>
<ul>
<li>/RPG/Outfit/Decorators/WeaponDecorators</li>
<li>/RPG/Outfit/Decorators/DefenseDecorators</li>
</ul>
