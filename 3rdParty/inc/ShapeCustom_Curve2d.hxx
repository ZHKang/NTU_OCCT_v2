// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _ShapeCustom_Curve2d_HeaderFile
#define _ShapeCustom_Curve2d_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Macro.hxx>

#include <Standard_Boolean.hxx>
#include <Standard_Real.hxx>
#include <Handle_Geom2d_Line.hxx>
#include <Handle_Geom2d_Curve.hxx>
#include <Handle_Geom2d_BSplineCurve.hxx>
class TColgp_Array1OfPnt2d;
class Geom2d_Line;
class Geom2d_Curve;
class Geom2d_BSplineCurve;


//! Converts curve2d to analytical form with given
//! precision or simpify curve2d.
class ShapeCustom_Curve2d 
{
public:

  DEFINE_STANDARD_ALLOC

  
  //! Check if poleses is in the plane with given precision
  //! Returns false if no.
  Standard_EXPORT static   Standard_Boolean IsLinear (const TColgp_Array1OfPnt2d& thePoles, const Standard_Real theTolerance, Standard_Real& theDeviation) ;
  
  //! Try to convert BSpline2d or Bezier2d to line 2d
  //! only if it is linear. Recalculate first and last parameters.
  //! Returns line2d or null curve2d.
  Standard_EXPORT static   Handle(Geom2d_Line) ConvertToLine2d (const Handle(Geom2d_Curve)& theCurve, const Standard_Real theFirstIn, const Standard_Real theLastIn, const Standard_Real theTolerance, Standard_Real& theNewFirst, Standard_Real& theNewLast, Standard_Real& theDeviation) ;
  
  //! Try to remove knots from bspline where local derivatives are the same.
  //! Remove knots with given precision.
  //! Returns false if Bsplien was not modified
  Standard_EXPORT static   Standard_Boolean SimplifyBSpline2d (Handle(Geom2d_BSplineCurve)& theBSpline2d, const Standard_Real theTolerance) ;




protected:





private:





};







#endif // _ShapeCustom_Curve2d_HeaderFile