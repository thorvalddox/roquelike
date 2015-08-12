# roquelike

A rogue like game.

## allegro

This game uses allegro. To install it, just run install_allegro.sh (delivered in this repo)

## tokens

There are different dungeons with different difficulty levels who each yield a token for reaching each 5th level, but only when reaching it for the first time (so token are unrenewable). Tokens can be crafted or equipped. There are 3 default tokens who can be aquired:

* water
* ground
* air

There are 3 equip slots: passive, attack and activate. Each token gives a different skill dependent on the slot it is equipped in

### crafting

the 3 default tokens can be crafted to a leveling token. This leveling token can be used to craft 2 lv1 tokens to a level 2 token.
The level 2 tokens are the following:

'''
water + ground -> life
water +  air   -> cold
air + ground   -> heat
'''

The total cost of a level2 token is 5

5 leveling token can be combined to a super leveling token. A super leveling token can be used to
combine a level 1 adn a level 2 token to a level 3 token.

'''
        ground       ocean        sky
life    plants       blood        light
heat    magma        clouds       lightning
cold    metal        ice          storm
'''

the total cost of a level 3 token is 21

Super leveling tokens can also be used to craft 3 level 3 tokens to a level 4 token.

'''
plants + clouds + storm     -> nature
metal  + blood  + lightning -> machine
magma  + ice    +  light    -> star
'''

the total cost of a level 4 token is 78
