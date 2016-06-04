// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _GeomLib_Tool_HeaderFile
#define _GeomLib_Tool_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Macro.hxx>

#include <Standard_Boolean.hxx>
#include <Handle_Geom_Curve.hxx>
#include <Standard_Real.hxx>
#include <Handle_Geom_Surface.hxx>
#include <Handle_Geom2d_Curve.hxx>
class Geom_Curve;
class gp_Pnt;
class Geom_Surface;
class Geom2d_Curve;
class gp_Pnt2d;


//! Provides various methods with Geom2d and Geom curves and surfaces.
//! The methods of this class compute the parameter(s) of a given point on a
//! curve or a surface. The point must be located either
//! on the curve (surface) itself or relatively to the latter at
//! a distance less than the tolerance value.
//! Return FALSE if the point is beyond the tolerance
//! limit or if computation fails.
//! Max Tolerance value is currently limited to 1.e-4 for
//! geometrical curves and 1.e-3 for BSpline, Bezier and
//! other parametrical curves.
class GeomLib_Tool 
{
public:

  DEFINE_STANDARD_ALLOC

  

  //! Extracts the parameter of a 3D point lying on a 3D curve
  //! or at a distance less than the tolerance value.
  Standard_EXPORT static   Standard_Boolean Parameter (const Handle(Geom_Curve)& Curve, const gp_Pnt& Point, const Standard_Real Tolerance, Standard_Real& U) ;
  
  //! Extracts the parameter of a 3D point lying on a surface
  //! or at a distance less than the tolerance value.
  Standard_EXPORT static   Standard_Boolean Parameters (const Handle(Geom_Surface)& Surface, const gp_Pnt& Point, const Standard_Real Tolerance, Standard_Real& U, Standard_Real& V) ;
  
  //! Extracts the parameter of a 2D point lying on a 2D curve
  //! or at a distance less than the tolerance value.
  Standard_EXPORT static   Standard_Boolean Parameter (const Handle(Geom2d_Curve)& Curve, const gp_Pnt2d& Point, const Standard_Real Tolerance, Standard_Real& U) ;




protected:





private:





};







#endif // _GeomLib_Tool_HeaderFile