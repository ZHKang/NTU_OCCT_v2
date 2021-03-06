// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _PTopoDS_TShape_HeaderFile
#define _PTopoDS_TShape_HeaderFile

#include <Standard_Macro.hxx>
#include <Standard_DefineHandle.hxx>
#include <Standard.hxx>
#include <Handle_PTopoDS_TShape.hxx>

#include <TopAbs_ShapeEnum.hxx>
#include <Standard_Boolean.hxx>
#include <Handle_PTopoDS_HArray1OfHShape.hxx>
#include <Handle_PTopoDS_HShape.hxx>
#include <Standard_Integer.hxx>
#include <Standard_Persistent.hxx>
class PTopoDS_HArray1OfHShape;
class PTopoDS_HShape;


class PTopoDS_TShape : public Standard_Persistent
{

public:

  
  //! Returns the type as a term of the ShapeEnum enum :
  //! VERTEX, EDGE, WIRE, FACE, ....
  Standard_EXPORT virtual   TopAbs_ShapeEnum ShapeType()  const = 0;
  
  //! Returns the modification flag.
  Standard_EXPORT   Standard_Boolean Modified()  const;
  
  //! Sets the modification flag.
  Standard_EXPORT   void Modified (const Standard_Boolean M) ;
  
  //! Returns the checked flag.
  Standard_EXPORT   Standard_Boolean Checked()  const;
  
  //! Sets the checked flag.
  Standard_EXPORT   void Checked (const Standard_Boolean C) ;
  
  //! Returns the orientability flag.
  Standard_EXPORT   Standard_Boolean Orientable()  const;
  
  //! Sets the orientability flag.
  Standard_EXPORT   void Orientable (const Standard_Boolean C) ;
  
  //! Returns the closedness flag.
  Standard_EXPORT   Standard_Boolean Closed()  const;
  
  //! Sets the closedness flag.
  Standard_EXPORT   void Closed (const Standard_Boolean C) ;
  
  //! Returns the infinity flag.
  Standard_EXPORT   Standard_Boolean Infinite()  const;
  
  //! Sets the infinity flag.
  Standard_EXPORT   void Infinite (const Standard_Boolean C) ;
  
  //! Returns the convexness flag.
  Standard_EXPORT   Standard_Boolean Convex()  const;
  
  //! Sets the convexness flag.
  Standard_EXPORT   void Convex (const Standard_Boolean C) ;
  
  //! Sets the hshape list
  Standard_EXPORT   Handle(PTopoDS_HArray1OfHShape) Shapes()  const;
  
  //! Sets the i th element of the HShape list
  Standard_EXPORT   Handle(PTopoDS_HShape) Shapes (const Standard_Integer I)  const;
  
  //! Returns the HShape list
  Standard_EXPORT   void Shapes (const Handle(PTopoDS_HArray1OfHShape)& S) ;
  
  //! Returns the i th element of the hshape list
  Standard_EXPORT   void Shapes (const Standard_Integer I, const Handle(PTopoDS_HShape)& S) ;

PTopoDS_TShape(const Storage_stCONSTclCOM& a) : Standard_Persistent(a)
{
  
}
    Handle(PTopoDS_HArray1OfHShape) _CSFDB_GetPTopoDS_TShapemyShapes() const { return myShapes; }
    void _CSFDB_SetPTopoDS_TShapemyShapes(const Handle(PTopoDS_HArray1OfHShape)& p) { myShapes = p; }
    Standard_Integer _CSFDB_GetPTopoDS_TShapemyFlags() const { return myFlags; }
    void _CSFDB_SetPTopoDS_TShapemyFlags(const Standard_Integer p) { myFlags = p; }



  DEFINE_STANDARD_RTTI(PTopoDS_TShape)

protected:

  
  Standard_EXPORT PTopoDS_TShape();



private: 


  Handle(PTopoDS_HArray1OfHShape) myShapes;
  Standard_Integer myFlags;


};







#endif // _PTopoDS_TShape_HeaderFile
