// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _BRep_TFace_HeaderFile
#define _BRep_TFace_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <Handle_BRep_TFace.hxx>

#include <Handle_Geom_Surface.hxx>
#include <Handle_Poly_Triangulation.hxx>
#include <TopLoc_Location.hxx>
#include <Standard_Real.hxx>
#include <Standard_Boolean.hxx>
#include <TopoDS_TFace.hxx>
#include <Handle_TopoDS_TShape.hxx>
class Geom_Surface;
class Poly_Triangulation;
class TopLoc_Location;
class TopoDS_TShape;


//! The Tface from BRep  is  based  on the TFace  from
//! TopoDS. The TFace contains :
//!
//! * A suface, a tolerance and a Location.
//!
//! * A NaturalRestriction flag,   when this  flag  is
//! True the  boundary of the  face is known to be the
//! parametric space (Umin, UMax, VMin, VMax).
//!
//! *  An    optional Triangulation.   If  there  is a
//! triangulation the surface can be absent.
//!
//! The  Location is  used   for the Surface.
//!
//! The triangulation  is in the same reference system
//! than the TFace.     A point on mySurface must   be
//! transformed with myLocation,  but  not a point  on
//! the triangulation.
//!
//! The Surface may  be shared by different TFaces but
//! not the  Triangulation, because the  Triangulation
//! may be modified by  the edges.
class BRep_TFace : public TopoDS_TFace
{

public:

  
  //! Creates an empty TFace.
  Standard_EXPORT BRep_TFace();
  
     const  Handle(Geom_Surface)& Surface()  const;
  
     const  Handle(Poly_Triangulation)& Triangulation()  const;
  
     const  TopLoc_Location& Location()  const;
  
      Standard_Real Tolerance()  const;
  
      void Surface (const Handle(Geom_Surface)& S) ;
  
      void Triangulation (const Handle(Poly_Triangulation)& T) ;
  
      void Location (const TopLoc_Location& L) ;
  
      void Tolerance (const Standard_Real T) ;
  
      Standard_Boolean NaturalRestriction()  const;
  
      void NaturalRestriction (const Standard_Boolean N) ;
  
  //! Returns a copy  of the  TShape  with no sub-shapes.
  //! The new Face has no triangulation.
  Standard_EXPORT virtual   Handle(TopoDS_TShape) EmptyCopy()  const;




  DEFINE_STANDARD_RTTI(BRep_TFace)

protected:




private: 


  Handle(Geom_Surface) mySurface;
  Handle(Poly_Triangulation) myTriangulation;
  TopLoc_Location myLocation;
  Standard_Real myTolerance;
  Standard_Boolean myNaturalRestriction;


};


#include <BRep_TFace.lxx>





#endif // _BRep_TFace_HeaderFile