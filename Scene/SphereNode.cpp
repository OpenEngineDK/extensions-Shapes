// Sphere node.
// -------------------------------------------------------------------
// Copyright (C) 2007 OpenEngine.dk (See AUTHORS) 
// 
// This program is free software; It is covered by the GNU General 
// Public License version 2 or any later version. 
// See the GNU General Public License for more details (see LICENSE). 
//--------------------------------------------------------------------

#include <Scene/SphereNode.h>

#include <Logging/Logger.h>
#include <Meta/OpenGL.h>
#include <Geometry/Material.h>
#include <Geometry/Sphere.h>
#include <Math/Vector.h>

namespace OpenEngine {
namespace Scene {

using OpenEngine::Geometry::Material;

SphereNode::SphereNode() : sphere(Geometry::Sphere(2)) {
    m = MaterialPtr(new Material());
}

SphereNode::SphereNode(MaterialPtr m)
    : m(m), sphere(Geometry::Sphere(2)) {}

SphereNode::~SphereNode() {

}

void SphereNode::Apply(IRenderingView* rv) {
    rv->GetRenderer()->DrawSphere(sphere.GetCenter(),
                                  sphere.GetRadius(),
                                  Math::Vector<3,float>(1.0f));
}

} //NS Scene
} //NS OpenEngine
