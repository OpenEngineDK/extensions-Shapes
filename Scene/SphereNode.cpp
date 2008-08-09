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
//     logger.info << "sphere apply" << logger.end;
//    glEnable(GL_BLEND);
//    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    //glEnable(GL_AUTO_NORMAL);
    float col[4];
    m->diffuse.ToArray(col);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, col);
    
    m->ambient.ToArray(col);
    glMaterialfv(GL_FRONT, GL_AMBIENT, col);
    
    m->specular.ToArray(col);
    glMaterialfv(GL_FRONT, GL_SPECULAR, col);
    
    m->emission.ToArray(col);
    glMaterialfv(GL_FRONT, GL_EMISSION, col);
    glMaterialf(GL_FRONT, GL_SHININESS, m->shininess);

    bool norm = glIsEnabled(GL_NORMALIZE);
    glEnable(GL_NORMALIZE);

    GLUquadricObj* qobj = gluNewQuadric();
    glLineWidth(2);
    gluQuadricNormals(qobj, GLU_SMOOTH);
    //gluQuadricDrawStyle(qobj, GLU_SILHOUETTE);
    gluQuadricDrawStyle(qobj, GLU_LINE);
    //gluQuadricDrawStyle(qobj, GLU_FILL);
    gluQuadricOrientation(qobj, GLU_INSIDE);
    gluSphere(qobj, 1.0, slices, stacks);
    gluDeleteQuadric(qobj);

    if (!norm) {
        glDisable(GL_NORMALIZE);
    }
    //glDisable(GL_BLEND);
}

} //NS Scene
} //NS OpenEngine
