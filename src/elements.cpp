#include "elements.h"

Element::Element(const string name):
    name(name),
    level(0),
    recipe({})
{
    //
}


Element::Element(int level,const string name,const elementset recipe):
    name(name),
    level(level),
    recipe(recipe)
{
    //
}


namespace element
{



}
