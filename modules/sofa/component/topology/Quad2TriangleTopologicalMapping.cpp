/******************************************************************************
*       SOFA, Simulation Open-Framework Architecture, version 1.0 beta 3      *
*                (c) 2006-2008 MGH, INRIA, USTL, UJF, CNRS                    *
*                                                                             *
* This library is free software; you can redistribute it and/or modify it     *
* under the terms of the GNU Lesser General Public License as published by    *
* the Free Software Foundation; either version 2.1 of the License, or (at     *
* your option) any later version.                                             *
*                                                                             *
* This library is distributed in the hope that it will be useful, but WITHOUT *
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or       *
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License *
* for more details.                                                           *
*                                                                             *
* You should have received a copy of the GNU Lesser General Public License    *
* along with this library; if not, write to the Free Software Foundation,     *
* Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA.          *
*******************************************************************************
*                               SOFA :: Modules                               *
*                                                                             *
* Authors: The SOFA Team and external contributors (see Authors.txt)          *
*                                                                             *
* Contact information: contact@sofa-framework.org                             *
******************************************************************************/
#include <sofa/component/topology/Quad2TriangleTopologicalMapping.inl>

#include <sofa/core/ObjectFactory.h>

#include <sofa/component/topology/TriangleSetTopology.h>
#include <sofa/component/topology/QuadSetTopology.h>

#include <sofa/core/componentmodel/topology/TopologicalMapping.h>
#include <sofa/core/componentmodel/topology/BaseTopology.h>


namespace sofa
{

namespace component
{

namespace topology
{

using namespace sofa::defaulttype;
using namespace core;
using namespace core::componentmodel::topology;
using namespace sofa::core::componentmodel::behavior;

using namespace sofa::component::topology;

SOFA_DECL_CLASS(Quad2TriangleTopologicalMapping)

// Register in the Factory
int Quad2TriangleTopologicalMappingClass = core::RegisterObject("Special case of mapping where QuadSetTopology is converted to TriangleSetTopology")
        .add< Quad2TriangleTopologicalMapping< QuadSetTopologyContainer, TriangleSetTopologyContainer > >()

        ;

} // namespace topology

} // namespace component

} // namespace sofa

