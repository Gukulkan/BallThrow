#include "ObjectManager.h"
#include "Drawable.h" 

void ObjectManager::addObject(Drawable* obj)
{
  objects.push_back(obj);
}

std::vector<Drawable*>ObjectManager::getDrawableObjects()
{
  return objects;
}