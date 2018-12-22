#include "Entity.h"
#include "../Interfaces.h"
#include "../Memory.h"

int* Entity::getFlags()
{
    return reinterpret_cast<int*>(this + 0x104);
}

int Entity::getMoveType()
{
    return *reinterpret_cast<int*>(this + 0x25C);
}

/*
int Entity::getTeamNumber()
{
    return *reinterpret_cast<int*>(this + 0xF4);
}
*/

bool Entity::isScoped()
{
    return *reinterpret_cast<bool*>(this + 0x390A);
}

int Entity::getCrosshairID()
{
    return *reinterpret_cast<int*>(this + 0xB394);
}

void Entity::drawModel(int flags, unsigned char alpha)
{
    return callVirtualFunction<void(__thiscall*)(void*, int, unsigned char)>(this + 4, 9)(this + 4, flags, alpha);
}

bool Entity::isEnemy()
{
    static auto gameMode = interfaces.cvar->findVar("game_type");

    if (!isInLocalTeam() || gameMode->getInt() == 6)
        return true;
    else
        return false;
}

bool Entity::isDormant()
{
    return callVirtualFunction<bool(__thiscall*)(void*)>(this + 8, 9)(this + 8);
}

bool Entity::isWeapon()
{
    return callVirtualFunction<bool(__thiscall*)(void*)>(this, 161)(this);
}

ClientClass* Entity::getClientClass()
{
    return callVirtualFunction<ClientClass*(__thiscall*)(void*)>(this + 8, 2)(this + 8);
}

bool Entity::isAlive()
{
    return callVirtualFunction<bool(__thiscall*)(void*)>(this, 151)(this);
}

bool Entity::isInLocalTeam()
{
    return callVirtualFunction<bool(__thiscall*)(void*)>(this, 92)(this);
}
