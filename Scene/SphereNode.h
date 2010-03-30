// Sphere node.
// -------------------------------------------------------------------
// Copyright (C) 2007 OpenEngine.dk (See AUTHORS) 
// 
// This program is free software; It is covered by the GNU General 
// Public License version 2 or any later version. 
// See the GNU General Public License for more details (see LICENSE). 
//--------------------------------------------------------------------

#ifndef _OE_SPHERE_NODE_H_
#define _OE_SPHERE_NODE_H_

#include <Scene/RenderNode.h>
#include <Geometry/Sphere.h>

namespace OpenEngine {
    //forward declarations
    namespace Renderers {
        class IRenderingView;
    }
    namespace Geometry {
        class Sphere;
    }

namespace Scene {

using OpenEngine::Renderers::IRenderingView;
using OpenEngine::Geometry::MaterialPtr;

/**
 * Sphere node.
 * Node to render a sphere with radius=1 and center=(0,0,0)
 * @note Use transformation nodes to scale and translate the sphere.
 *
 * @class SphereNode SphereNode.h Scene/SphereNode.h
 */
class SphereNode : public RenderNode {
private:

    
    MaterialPtr m;
    Geometry::Sphere sphere;
public:
    
    SphereNode();
    SphereNode(MaterialPtr m);
    virtual ~SphereNode();

    void Apply(IRenderingView* rv);
};

} // NS Scene
} // NS OpenEngine



#endif // _SPHERE_NODE_H_
