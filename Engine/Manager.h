//
// Created by Miles on 2/17/16.
//

#include "Initializable.h"
#include "Destroyable.h"

#ifndef ENGINE_MANAGER_H
#define ENGINE_MANAGER_H


class Manager: public Initializable,
               public Destroyable
{

};



#endif //ENGINE_MANAGER_H
