#pragma once
#include <vector>

class Drawable; 

class ObjectManager 
{
  public: 
    void addObject(Drawable* obj);
    std::vector<Drawable*> getDrawableObjects();
  private: 
    std::vector<Drawable*> objects;
};