// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _Adaptor3d_HSurfaceTool_HeaderFile
#define _Adaptor3d_HSurfaceTool_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Macro.hxx>

#include <Standard_Real.hxx>
#include <Handle_Adaptor3d_HSurface.hxx>
#include <Standard_Integer.hxx>
#include <GeomAbs_Shape.hxx>
#include <Standard_Boolean.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <GeomAbs_SurfaceType.hxx>
#include <gp_Pln.hxx>
#include <gp_Cylinder.hxx>
#include <gp_Cone.hxx>
#include <gp_Torus.hxx>
#include <gp_Sphere.hxx>
#include <Handle_Geom_BezierSurface.hxx>
#include <Handle_Geom_BSplineSurface.hxx>
#include <gp_Ax1.hxx>
#include <gp_Dir.hxx>
#include <Handle_Adaptor3d_HCurve.hxx>
class Standard_NoSuchObject;
class Standard_OutOfRange;
class Adaptor3d_HSurface;
class TColStd_Array1OfReal;
class gp_Pnt;
class gp_Vec;
class Geom_BezierSurface;
class Geom_BSplineSurface;
class Adaptor3d_HCurve;



class Adaptor3d_HSurfaceTool 
{
public:

  DEFINE_STANDARD_ALLOC

  
    static   Standard_Real FirstUParameter (const Handle(Adaptor3d_HSurface)& S) ;
  
    static   Standard_Real FirstVParameter (const Handle(Adaptor3d_HSurface)& S) ;
  
    static   Standard_Real LastUParameter (const Handle(Adaptor3d_HSurface)& S) ;
  
    static   Standard_Real LastVParameter (const Handle(Adaptor3d_HSurface)& S) ;
  
    static   Standard_Integer NbUIntervals (const Handle(Adaptor3d_HSurface)& S, const GeomAbs_Shape Sh) ;
  
    static   Standard_Integer NbVIntervals (const Handle(Adaptor3d_HSurface)& S, const GeomAbs_Shape Sh) ;
  
    static   void UIntervals (const Handle(Adaptor3d_HSurface)& S, TColStd_Array1OfReal& T, const GeomAbs_Shape Sh) ;
  
    static   void VIntervals (const Handle(Adaptor3d_HSurface)& S, TColStd_Array1OfReal& T, const GeomAbs_Shape Sh) ;
  
  //! If <First> >= <Last>
    static   Handle(Adaptor3d_HSurface) UTrim (const Handle(Adaptor3d_HSurface)& S, const Standard_Real First, const Standard_Real Last, const Standard_Real Tol) ;
  
  //! If <First> >= <Last>
    static   Handle(Adaptor3d_HSurface) VTrim (const Handle(Adaptor3d_HSurface)& S, const Standard_Real First, const Standard_Real Last, const Standard_Real Tol) ;
  
    static   Standard_Boolean IsUClosed (const Handle(Adaptor3d_HSurface)& S) ;
  
    static   Standard_Boolean IsVClosed (const Handle(Adaptor3d_HSurface)& S) ;
  
    static   Standard_Boolean IsUPeriodic (const Handle(Adaptor3d_HSurface)& S) ;
  
    static   Standard_Real UPeriod (const Handle(Adaptor3d_HSurface)& S) ;
  
    static   Standard_Boolean IsVPeriodic (const Handle(Adaptor3d_HSurface)& S) ;
  
    static   Standard_Real VPeriod (const Handle(Adaptor3d_HSurface)& S) ;
  
    static   gp_Pnt Value (const Handle(Adaptor3d_HSurface)& S, const Standard_Real u, const Standard_Real v) ;
  
    static   void D0 (const Handle(Adaptor3d_HSurface)& S, const Standard_Real u, const Standard_Real v, gp_Pnt& P) ;
  
    static   void D1 (const Handle(Adaptor3d_HSurface)& S, const Standard_Real u, const Standard_Real v, gp_Pnt& P, gp_Vec& D1u, gp_Vec& D1v) ;
  
    static   void D2 (const Handle(Adaptor3d_HSurface)& S, const Standard_Real u, const Standard_Real v, gp_Pnt& P, gp_Vec& D1U, gp_Vec& D1V, gp_Vec& D2U, gp_Vec& D2V, gp_Vec& D2UV) ;
  
    static   void D3 (const Handle(Adaptor3d_HSurface)& S, const Standard_Real u, const Standard_Real v, gp_Pnt& P, gp_Vec& D1U, gp_Vec& D1V, gp_Vec& D2U, gp_Vec& D2V, gp_Vec& D2UV, gp_Vec& D3U, gp_Vec& D3V, gp_Vec& D3UUV, gp_Vec& D3UVV) ;
  
    static   gp_Vec DN (const Handle(Adaptor3d_HSurface)& S, const Standard_Real u, const Standard_Real v, const Standard_Integer Nu, const Standard_Integer Nv) ;
  
    static   Standard_Real UResolution (const Handle(Adaptor3d_HSurface)& S, const Standard_Real R3d) ;
  
    static   Standard_Real VResolution (const Handle(Adaptor3d_HSurface)& S, const Standard_Real R3d) ;
  
    static   GeomAbs_SurfaceType GetType (const Handle(Adaptor3d_HSurface)& S) ;
  
    static   gp_Pln Plane (const Handle(Adaptor3d_HSurface)& S) ;
  
    static   gp_Cylinder Cylinder (const Handle(Adaptor3d_HSurface)& S) ;
  
    static   gp_Cone Cone (const Handle(Adaptor3d_HSurface)& S) ;
  
    static   gp_Torus Torus (const Handle(Adaptor3d_HSurface)& S) ;
  
    static   gp_Sphere Sphere (const Handle(Adaptor3d_HSurface)& S) ;
  
    static   Handle(Geom_BezierSurface) Bezier (const Handle(Adaptor3d_HSurface)& S) ;
  
    static   Handle(Geom_BSplineSurface) BSpline (const Handle(Adaptor3d_HSurface)& S) ;
  
    static   gp_Ax1 AxeOfRevolution (const Handle(Adaptor3d_HSurface)& S) ;
  
    static   gp_Dir Direction (const Handle(Adaptor3d_HSurface)& S) ;
  
    static   Handle(Adaptor3d_HCurve) BasisCurve (const Handle(Adaptor3d_HSurface)& S) ;
  
    static   Handle(Adaptor3d_HSurface) BasisSurface (const Handle(Adaptor3d_HSurface)& S) ;
  
    static   Standard_Real OffsetValue (const Handle(Adaptor3d_HSurface)& S) ;
  
  Standard_EXPORT static   Standard_Integer NbSamplesU (const Handle(Adaptor3d_HSurface)& S) ;
  
  Standard_EXPORT static   Standard_Integer NbSamplesV (const Handle(Adaptor3d_HSurface)& S) ;
  
  Standard_EXPORT static   Standard_Integer NbSamplesU (const Handle(Adaptor3d_HSurface)& S, const Standard_Real u1, const Standard_Real u2) ;
  
  Standard_EXPORT static   Standard_Integer NbSamplesV (const Handle(Adaptor3d_HSurface)& S, const Standard_Real v1, const Standard_Real v2) ;




protected:





private:





};


#include <Adaptor3d_HSurfaceTool.lxx>





#endif // _Adaptor3d_HSurfaceTool_HeaderFile
