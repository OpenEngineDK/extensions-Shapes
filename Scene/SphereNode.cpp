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

namespace OpenEngine {
namespace Scene {

using OpenEngine::Geometry::Material;

SphereNode::SphereNode() {
    m = MaterialPtr(new Material());
    slices = 30;
    stacks = 30;
}

SphereNode::SphereNode(MaterialPtr m, int slices, int stacks): m(m), 
                                                               slices(slices), 
                                                               stacks(stacks) {
    
}

SphereNode::~SphereNode() {

}

void SphereNode::Apply(IRenderingView* rv) {
    glDisable(GL_COLOR_MATERIAL);
    
    float col[4];
    m->diffuse.ToArray(col);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, col);
    
    m->ambient.ToArray(col);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, col);
    
    m->specular.ToArray(col);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, col);
    
    m->emission.ToArray(col);
    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, col);
        
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, m->shininess);



    GLUquadricObj* qobj = gluNewQuadric();
    
    gluQuadricNormals(qobj, GLU_SMOOTH);
    gluQuadricDrawStyle(qobj,GLU_FILL);
    gluSphere(qobj, 1.0, slices, stacks);
    
    gluDeleteQuadric(qobj);
    
}

} //NS Scene
} //NS OpenEngine
