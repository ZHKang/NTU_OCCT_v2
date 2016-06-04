// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _DsgPrs_EqualRadiusPresentation_HeaderFile
#define _DsgPrs_EqualRadiusPresentation_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Macro.hxx>

#include <Handle_Prs3d_Presentation.hxx>
#include <Handle_Prs3d_Drawer.hxx>
#include <Handle_Geom_Plane.hxx>
class Prs3d_Presentation;
class Prs3d_Drawer;
class gp_Pnt;
class Geom_Plane;


//! A framework to define display of equality in radii.
class DsgPrs_EqualRadiusPresentation 
{
public:

  DEFINE_STANDARD_ALLOC

  
  //! Adds the points FirstCenter, SecondCenter,
  //! FirstPoint, SecondPoint, and the plane Plane to the
  //! presentation object aPresentation.
  //! The display attributes of these elements is defined by
  //! the attribute manager aDrawer.
  //! FirstCenter and SecondCenter are the centers of the
  //! first and second shapes respectively, and FirstPoint
  //! and SecondPoint are the attachment points of the radii to arcs.
  Standard_EXPORT static   void Add (const Handle(Prs3d_Presentation)& aPresentation, const Handle(Prs3d_Drawer)& aDrawer, const gp_Pnt& FirstCenter, const gp_Pnt& SecondCenter, const gp_Pnt& FirstPoint, const gp_Pnt& SecondPoint, const Handle(Geom_Plane)& Plane) ;




protected:





private:





};







#endif // _DsgPrs_EqualRadiusPresentation_HeaderFile
