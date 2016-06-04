// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _AIS_Chamf2dDimension_HeaderFile
#define _AIS_Chamf2dDimension_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <Handle_AIS_Chamf2dDimension.hxx>

#include <gp_Pnt.hxx>
#include <gp_Dir.hxx>
#include <AIS_Relation.hxx>
#include <Handle_Geom_Plane.hxx>
#include <Standard_Real.hxx>
#include <DsgPrs_ArrowSide.hxx>
#include <AIS_KindOfDimension.hxx>
#include <Standard_Boolean.hxx>
#include <PrsMgr_PresentationManager3d.hxx>
#include <Handle_Prs3d_Presentation.hxx>
#include <Standard_Integer.hxx>
#include <Handle_Prs3d_Projector.hxx>
#include <Handle_Geom_Transformation.hxx>
#include <Handle_SelectMgr_Selection.hxx>
class TopoDS_Shape;
class Geom_Plane;
class TCollection_ExtendedString;
class gp_Pnt;
class Prs3d_Presentation;
class Prs3d_Projector;
class Geom_Transformation;
class SelectMgr_Selection;


//! A framework to define display of 2D chamfers.
//! A chamfer is displayed with arrows and text. The text
//! gives the length of the chamfer if it is a symmetrical
//! chamfer, or the angle if it is not.
class AIS_Chamf2dDimension : public AIS_Relation
{

public:

  
  //! Constructs the display object for 2D chamfers.
  //! This object is defined by the face aFShape, the
  //! dimension aVal, the plane aPlane and the text aText.
  Standard_EXPORT AIS_Chamf2dDimension(const TopoDS_Shape& aFShape, const Handle(Geom_Plane)& aPlane, const Standard_Real aVal, const TCollection_ExtendedString& aText);
  
  //! Constructs the display object for 2D chamfers.
  //! This object is defined by the face aFShape, the plane
  //! aPlane, the dimension aVal, the position aPosition,
  //! the type of arrow aSymbolPrs with the size
  //! anArrowSize, and the text aText.
  Standard_EXPORT AIS_Chamf2dDimension(const TopoDS_Shape& aFShape, const Handle(Geom_Plane)& aPlane, const Standard_Real aVal, const TCollection_ExtendedString& aText, const gp_Pnt& aPosition, const DsgPrs_ArrowSide aSymbolPrs, const Standard_Real anArrowSize = 0.0);
  
  //! Indicates that we are concerned with a 2d length.
    virtual   AIS_KindOfDimension KindOfDimension()  const;
  
  //! Returns true if the 2d chamfer dimension is movable.
    virtual   Standard_Boolean IsMovable()  const;
  
  //! computes the presentation according to a point of view
  //! given by <aProjector>.
  //! To be Used when the associated degenerated Presentations
  //! have been transformed by <aTrsf> which is not a Pure
  //! Translation. The HLR Prs can't be deducted automatically
  //! WARNING :<aTrsf> must be applied
  //! to the object to display before computation  !!!
  Standard_EXPORT virtual   void Compute (const Handle(Prs3d_Projector)& aProjector, const Handle(Geom_Transformation)& aTrsf, const Handle(Prs3d_Presentation)& aPresentation) ;




  DEFINE_STANDARD_RTTI(AIS_Chamf2dDimension)

protected:




private: 

  
  Standard_EXPORT   void Compute (const Handle(PrsMgr_PresentationManager3d)& aPresentationManager, const Handle(Prs3d_Presentation)& aPresentation, const Standard_Integer aMode = 0) ;
  
  Standard_EXPORT   void Compute (const Handle(Prs3d_Projector)& aProjector, const Handle(Prs3d_Presentation)& aPresentation) ;
  
  Standard_EXPORT virtual   void ComputeSelection (const Handle(SelectMgr_Selection)& aSelection, const Standard_Integer aMode) ;

  gp_Pnt myPntAttach;
  gp_Dir myDir;


};


#include <AIS_Chamf2dDimension.lxx>





#endif // _AIS_Chamf2dDimension_HeaderFile
