// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _XmlObjMgt_GP_HeaderFile
#define _XmlObjMgt_GP_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Macro.hxx>

#include <XmlObjMgt_DOMString.hxx>
#include <Standard_Boolean.hxx>
class gp_Trsf;
class gp_Mat;
class gp_XYZ;


//! Translation of gp (simple geometry) objects
class XmlObjMgt_GP 
{
public:

  DEFINE_STANDARD_ALLOC

  
  Standard_EXPORT static   XmlObjMgt_DOMString Translate (const gp_Trsf& aTrsf) ;
  
  Standard_EXPORT static   XmlObjMgt_DOMString Translate (const gp_Mat& aMat) ;
  
  Standard_EXPORT static   XmlObjMgt_DOMString Translate (const gp_XYZ& anXYZ) ;
  
  Standard_EXPORT static   Standard_Boolean Translate (const XmlObjMgt_DOMString& aStr, gp_Trsf& T) ;
  
  Standard_EXPORT static   Standard_Boolean Translate (const XmlObjMgt_DOMString& aStr, gp_Mat& T) ;
  
  Standard_EXPORT static   Standard_Boolean Translate (const XmlObjMgt_DOMString& aStr, gp_XYZ& T) ;




protected:





private:





};







#endif // _XmlObjMgt_GP_HeaderFile