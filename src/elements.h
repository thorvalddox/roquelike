#pragma once
#include <string>
#include <set>
#include <utility>
#include <vector>

using std::string;
using std::set;
using std::pair;
using std::vector;


enum class SkillType {PASSIVE,ATTACK,INVOKE};
enum class Buff {SNARE,SILENCE,NOHEAL,FLAMING,CLOUDED,IMMUME,
    SWIM,JUMP,WALK,NIMBLE,CONFUSED,BASTION,GROWTH,LIGHTHOUSE,VAMPIRE};
enum class Stat {HEALTH,REGEN,DAMAGE,MOVE_TIME,ATTACK_TIME,VISION_RANGE,ATTACK_RANGE,HUNGER};
enum class Action_ {DAMAGE,HEAL,BOMB,LIFESTEAL,KNOCKBACK,PLACE,RING,SPIKE};

typedef pair<Buff,int> Buff_apply; //int is delay
typedef pair<Stat,int> Stat_change;  //int is amount
typedef pair<Action_,int> Action_perform; //int is multiplier

class Skill
{
    string name;
    vector<Buff_apply> buffs;
    vector<Stat_change> statchanges;
    vector<Action_perform> actions;
};


class Element;
typedef set<Element*> elementset;
class Element
{
public:
    Element(const string);
    Element(int,const string,const elementset);

    string name;
    int level;
    elementset recipe;
    //bool upgrade(Element el,elementset all,Element * result,elementset * req) const;
private:

};

namespace element // wanna-be enum
{
    const Element water = Element("water");
    const Element ground = Element("ground");
    const Element air   = Element("air");
    //const Element life = Element(1,"life",{&water,&ground});
    //const Element heat = Element(1,"heat",{&air,&ground});
    //const Element cold = Element(1,"cold",{&air,&water});
}
