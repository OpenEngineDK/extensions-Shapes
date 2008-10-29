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

namespace OpenEngine {
    //forward declarations
    namespace Renderers {
        class IRenderingView;
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
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive & ar, const unsigned int version)
    {
        // serialize base class information
        ar & boost::serialization::base_object<RenderNode>(*this);
    }

    
    MaterialPtr m;
    int slices, stacks;
public:
    
    SphereNode();
    SphereNode(MaterialPtr m, int slices, int stacks);
    virtual ~SphereNode();

    void Apply(IRenderingView* rv);
};

} // NS Scene
} // NS OpenEngine

BOOST_CLASS_EXPORT(OpenEngine::Scene::SphereNode)


#endif // _SPHERE_NODE_H_
