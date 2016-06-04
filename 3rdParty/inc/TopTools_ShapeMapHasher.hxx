// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _TopTools_ShapeMapHasher_HeaderFile
#define _TopTools_ShapeMapHasher_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Macro.hxx>

#include <Standard_Integer.hxx>
#include <Standard_Boolean.hxx>
class TopoDS_Shape;


//! Hash tool, used for generating maps of shapes in topology.
class TopTools_ShapeMapHasher 
{
public:

  DEFINE_STANDARD_ALLOC

  
  //! Returns a HasCode value  for  the  Key <K>  in the
  //! range 0..Upper.
    static   Standard_Integer HashCode (const TopoDS_Shape& S, const Standard_Integer Upper) ;
  
  //! Returns True  when the two  keys are the same. Two
  //! same  keys  must   have  the  same  hashcode,  the
  //! contrary is not necessary.
    static   Standard_Boolean IsEqual (const TopoDS_Shape& S1, const TopoDS_Shape& S2) ;




protected:





private:





};


#include <TopTools_ShapeMapHasher.lxx>





#endif // _TopTools_ShapeMapHasher_HeaderFile