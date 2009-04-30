// Copyright (c) 2006  Tel-Aviv University (Israel).
// All rights reserved.
//
// This file is part of CGAL (www.cgal.org); you may redistribute it under
// the terms of the Q Public License version 1.0.
// See the file LICENSE.QPL distributed with CGAL.
//
// Licensees holding a valid commercial license may use this file in
// accordance with the commercial license agreement provided with the software.
//
// This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
//
// $URL$
// $Id$
// 
//
// Author(s)     : Efi Fogel          <efif@post.tau.ac.il>

#ifndef CGAL_ARR_POLYHEDRAL_SGM_TRAITS_H
#define CGAL_ARR_POLYHEDRAL_SGM_TRAITS_H

#include <CGAL/basic.h>
#include <CGAL/Arr_geodesic_arc_on_sphere_traits_2.h>

#if defined(CGAL_ARR_TRACING_TRAITS)
#include "CGAL/Arr_tracing_traits_2.h"
#elif defined(CGAL_COUNTING_TRAITS)
#include "CGAL/Arr_counting_traits_2.h"
#endif

CGAL_BEGIN_NAMESPACE

/*! \file
 * A traits class-template for constructing and maintaining Gaussian maps
 * (also known as normal diagrams) of polytopes in 3D. It is parameterized
 * by a (linear) 3D geometry a kernel.
 * It serves two main purposes as follows:
 * 1. It models the concept ArrangementTraits, and as such, it handles arcs,
 *    the type of which are present in Gaussian maps of polytopes in 3D, that
 *    is, arcs of great circles on 2S, also known as geodesic arcs, and,
 * 2. It provides a type of point in 3D used to represent vertices of
 *    polytopes, and an operation that adds two points of this type.
 * This traits is used to instantiate a type that represents an arrangement
 * induced by geodesic arcs embedded on a sphere, where each face of the
 * arrangement stores the corresponding vertex of the polytope. This type,
 * in turn, represents a Gaussian map, which is a unique dual representation
 * of a polytope.
 */
template <typename T_Kernel>
class Arr_polyhedral_sgm_traits :
#if defined(CGAL_ARR_TRACING_TRAITS)
  public Arr_tracing_traits_2<Arr_geodesic_arc_on_sphere_traits_2<T_Kernel> >
#elif defined(CGAL_ARR_COUNTING_TRAITS)
  public Arr_counting_traits_2<Arr_geodesic_arc_on_sphere_traits_2<T_Kernel> >
#else
  public Arr_geodesic_arc_on_sphere_traits_2<T_Kernel>
#endif
{
public:
  typedef T_Kernel                                      Kernel;
  typedef typename Kernel::Point_3                      Point_3;
  typedef typename Kernel::Vector_3                     Vector_3;
  typedef typename Kernel::Direction_3                  Direction_3;

protected:
#if defined(CGAL_ARR_TRACING_TRAITS)
  typedef Arr_tracing_traits_2<Arr_geodesic_arc_on_sphere_traits_2<Kernel> >
                                                        Base;
#elif defined(CGAL_ARR_COUNTING_TRAITS)
  typedef Arr_counting_traits_2<Arr_geodesic_arc_on_sphere_traits_2<Kernel> >
                                                        Base;
#else
  typedef Arr_geodesic_arc_on_sphere_traits_2<Kernel>   Base;
#endif

public:
};

CGAL_END_NAMESPACE

#endif
