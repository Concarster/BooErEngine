#pragma once
#include "Def.h"
#include "MeshMgr.h"
#include "SpriteMgr.h"
#include "ParticleMgr.h"

namespace boo
{
    class BOO_API RenderMgr
    {
    public:
        RenderMgr();
        ~RenderMgr();

        void RegisterComponent(MeshMgr* mesh);
        void RegisterComponent(SpriteMgr* sprite);
        void RegisterComponent(ParticleMgr* particles);
    };
}
