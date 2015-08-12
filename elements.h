#include <string>
#include <set>

using std::string
using std::set

typedef set<*Element> elementset


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
