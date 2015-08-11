# roquelike

A rogue like game.

## allegro

This game uses allegro. To install it, just run install_allegro.sh (delivered in this repo)

## tokens

There are different dungeons with different difficulty levels who each yield a token for reaching each 5th level, but only when reaching it for the first time (so token are unrenewable). Tokens can be crafted or equipped. There are 3 default tokens who can be aquired:

* ocean
* ground
* sky

There are 3 equip slots: passive, attack and activate. Each token gives a different skill dependent on the slot it is equipped in

### crafting

the 3 default tokens can be crafted to a leveling token. This leveling token can be used to craft 2 lv1 tokens to a level 2 token.
The level 2 tokens are the following

'''
ocean + ground -> life
ocean +  sky   ->

'''
