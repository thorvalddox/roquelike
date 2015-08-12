# roquelike

A rogue like game.

## allegro

This game uses allegro. To install it, just run install_allegro.sh (delivered in this repo)

## tokens

There are different dungeons with different difficulty levels who each yield a token for reaching each 5th level, but only when reaching it for the first time (so token are unrenewable). Tokens can be crafted or equipped. There are 3 default tokens who can be aquired:

* water
* ground
* air

There are 3 equip slots: passive, attack and invoke. Each token gives a different skill dependent on the slot it is equipped in

### crafting

the 3 default tokens can be crafted to a leveling token. This leveling token can be used to craft 2 lv1 tokens to a level 2 token.
The level 2 tokens are the following:

```
water + ground -> life
water +  air   -> cold
air + ground   -> heat
```

The total cost of a level2 token is 5

5 leveling token can be combined to a super leveling token. A super leveling token can be used to
combine a level 1 adn a level 2 token to a level 3 token.

```
        ground       ocean        sky
life    plants       blood        light
heat    magma        clouds       lightning
cold    metal        ice          storm
```

the total cost of a level 3 token is 21

Super leveling tokens can also be used to craft 3 level 3 tokens to a level 4 token.

```
plants + clouds + storm     -> nature
metal  + blood  + lightning -> machine
magma  + ice    +  light    -> star
```

the total cost of a level 4 token is 78




##Mechanics


### clock turn-based

All actions take time.

All units have a clock. When they perform an action, the time needed is added to the clock.
The unit with the lowest clock can move.

Status effects also use this clock.

default: move:60 attack:100

###Battle

Attack always hits -> default 10 dam
Default 100 hp

Only changed by statchanges and buffs.

Also: actions (for data-driven healing) ??

Every skill knows:
* list of stat changes
  * amounts
* list of actions
  * multipliers
* list of buffs
  * time
* invoke type (if invoke skill)
  * target/ self / area / surround
  * cooldown
* passive type
  * cooldown

Applied when/to

skill_type| stat | action | buff
:--|:--|:--|:---
passive | create/self | on tick /self | create/self  (always inf)
attack  | create/self | on attack/target | on attack/target
invoke  | N/A         | on invoke/depends | on invoke/depends

### Stats
* HEALTH
* DAMAGE
* MOVE_TIME
* ATTACK_TIME
* VISION_RANGE
* ATTACK_RANGE
* REGEN_AMOUNT
* LOSE_HUNGER


### Buffs

Code: array+ENUM + dinamix testing
losing status effect is a functor in the game_loop (binary heap)

Different status effects:

Effect | description | Tags
:-|:-|--
Snare   | user can attack but not move | I
Silence | user can move but not attack/invoke | I
NoHeal  | user cannot regen | I
Flaming | enemies attacking user get half damage |
Clouded | No collision with entities |
Immume  | Disable some other status effects |
Swim    | Can move trough water |
Walk    | No slowdown from rough terrain/ ice |
Jump    | Can jump over cliffs |
Nimble  | No damage from spikes |
Confused | ??? | EI
Bastion | High defense , no movement |
Growth  | High healing, no movement, no attack |
Lighthouse | All enemies know your position | P
Vampire | Lose health over time but heal damage |






Tags:
* I: immume prevents this effect
* E: enemies only
* P: player only

## actions

Action | description | multipliers | Tags
:-|:-|:-|:-
Bomb  | damage surrounding area | damage amount |
Damage | damage target | damage amount |
Heal | heal target | hp |
LifeSteal | do normal damage | percent regen (0-100) |
Knockback | move the enemy away | distance |
Place | places wall | time stays | T
Healing ring | places healing ring 3x3 | time stays | T
Spike | places spikes | *none* | T

Tags:
* T: doesn't need target

Actions contain the invoker and the target, to make sure things like life_steal and knockback work correctly
