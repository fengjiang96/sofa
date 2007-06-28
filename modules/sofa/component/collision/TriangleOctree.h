/*******************************************************************************
*       SOFA, Simulation Open-Framework Architecture, version 1.0 beta 1       *
*                (c) 2006-2007 MGH, INRIA, USTL, UJF, CNRS                     *
*                                                                              *
* This library is free software; you can redistribute it and/or modify it      *
* under the terms of the GNU Lesser General Public License as published by the *
* Free Software Foundation; either version 2.1 of the License, or (at your     *
* option) any later version.                                                   *
*                                                                              *
* This library is distributed in the hope that it will be useful, but WITHOUT  *
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or        *
	* FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License  *
* for more details.                                                            *
*                                                                              *
* You should have received a copy of the GNU Lesser General Public License     *
* along with this library; if not, write to the Free Software Foundation,      *
* Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA.           *
*                                                                              *
* Contact information: contact@sofa-framework.org                              *
*                                                                              *
* Authors: J. Allard, P-J. Bensoussan, S. Cotin, C. Duriez, H. Delingette,     *
* F. Faure, S. Fonteneau, L. Heigeas, C. Mendoza, M. Nesme, P. Neumann,        *
* and F. Poyer                                                                 *
*******************************************************************************/
#ifndef SOFA_COMPONENT_COLLISION_TRIANGLEOCTREE_H
#define SOFA_COMPONENT_COLLISION_TRIANGLEOCTREE_H

#include <sofa/core/CollisionModel.h>
#include <sofa/core/VisualModel.h>
#include <sofa/component/MechanicalObject.h>
#include <sofa/component/topology/MeshTopology.h>
#include <sofa/defaulttype/Vec3Types.h>
#define CUBE_SIZE 80
#define bb_max(a,b) (((a)>(b))?(a):(b))
#define bb_max3(a,b,c) bb_max((bb_max(a,b)),c)

#define bb_min(a,b) (((a)<(b))?(a):(b))
#define bb_min3(a,b,c) bb_min(bb_min(a,b),c)

namespace sofa
{

namespace component
{

namespace collision
{

using namespace sofa::defaulttype;


class TriangleOctree
{
public:
    class vertexData
    {
    public:
        TriangleOctree * parent;
        int childId;
        vertexData (TriangleOctree * _parent,
                int _childId):parent (_parent), childId (_childId)
        {
        }
    };
    double x, y, z;

    double size;
    bool val;
    bool is_leaf;
    bool internal;
    TriangleModel *tm;
    vector < int >objects;
    TriangleOctree *childVec[8];



    TriangleOctree (TriangleModel * _tm, double _x = -CUBE_SIZE, double _y = -CUBE_SIZE, double _z = -CUBE_SIZE, double _size = 2 * CUBE_SIZE):x (_x), y (_y), z (_z), size (_size),
        tm
        (_tm)
    {
        is_leaf = true;
        internal = false;
        for (int i = 0; i < 8; i++)
            childVec[i] = NULL;
    }
    void draw ();
    int nearestTriangle (int minIndex, const Vector3 & origin,
            const Vector3 & direction);
    void insert (double _x, double _y, double _z, double _inc, int t);
    int trace (Vector3 origin, Vector3 direction);
    int traceVolume (Vector3 origin, Vector3 direction);
    int traceVolume (int n);
    int traceVolume (const Vector3 & origin, const Vector3 & direction,
            double tx0, double ty0, double tz0,
            double tx1, double ty1, double tz1,
            unsigned int a, unsigned int b, int intputTriangle,
            vector < vertexData * >&vertexVec);
    int trace (const Vector3 & origin, const Vector3 & direction,
            double tx0, double ty0, double tz0, double tx1, double ty1,
            double tz1, unsigned int a, unsigned int b);
    int findInputTriangle (int inputTriangle, const Vector3 & origin,
            const Vector3 & direction);
};

}				// namespace collision

}				// namespace component

}				// namespace sofa

#endif
