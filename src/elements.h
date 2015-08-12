#include <string>
#include <set>
#include <pair>

using std::string
using std::set

typedef set<*Element> elementset


enum SkillType {PASSIVE,ATTACK,INVOKE}
enum Buff {SNARE,SILENCE,NOHEAL,FLAMING,CLOUDED,IMMUME,
    SWIM,JUMP,WALK,NIMBLE,CONFUSED,BASTION,GROWTH,LIGHTHOUSE,VAMPIRE};
enum Stat {HEALTH,REGEN,DAMAGE,MOVE_TIME,ATTACK_TIME,VISION_RANGE,ATTACK_RANGE,HUNGER};
enum Action {DAMAGE,HEAL,BOMB,LIFESTEAL,KNOCKBACK,PLACE,RING,SPIKE};

typedef pair<Buff,int> buff_apply; //int is delay
typedef pair<Stat,int> stat_change;  //int is amount
typedef pair<Action,int> action_perform; //int is multiplier

class Skill
{
    //
};



class Element
{
public:
    Element(const string);
    Element(int,const string,const elementset);

    string name;
    int level;
    set<Element> recipe;
    bool upgrade(Element el,elementset all,* Element result,* elementset req) const;
private:

};

namespace Element // wanna-be enum
{
    const Element water = Element("water");
    const Element ground = Element("ground");
    const Element air   = Element("air");
    const Element life = Element(1,"life",{&water,&ground});
    const Element heat = Element(1,"heat",{&air,&ground});
    const Element cold = Element(1,"cold",{&air,&water});
    const Element
}
