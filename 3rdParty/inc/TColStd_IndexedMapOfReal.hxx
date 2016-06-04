// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _TColStd_IndexedMapOfReal_HeaderFile
#define _TColStd_IndexedMapOfReal_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Macro.hxx>

#include <TCollection_BasicMap.hxx>
#include <Standard_Real.hxx>
#include <Handle_TColStd_IndexedMapNodeOfIndexedMapOfReal.hxx>
#include <Standard_Integer.hxx>
#include <Standard_Boolean.hxx>
class Standard_DomainError;
class Standard_OutOfRange;
class TColStd_MapRealHasher;
class TColStd_IndexedMapNodeOfIndexedMapOfReal;



class TColStd_IndexedMapOfReal  : public TCollection_BasicMap
{
public:

  DEFINE_STANDARD_ALLOC

  
  Standard_EXPORT TColStd_IndexedMapOfReal(const Standard_Integer NbBuckets = 1);
  
  Standard_EXPORT TColStd_IndexedMapOfReal(const TColStd_IndexedMapOfReal& Other);
  
  Standard_EXPORT   TColStd_IndexedMapOfReal& Assign (const TColStd_IndexedMapOfReal& Other) ;
  TColStd_IndexedMapOfReal& operator = (const TColStd_IndexedMapOfReal& Other) 
{
  return Assign(Other);
}
  
  Standard_EXPORT   void ReSize (const Standard_Integer NbBuckets) ;
  
  Standard_EXPORT   void Clear() ;
~TColStd_IndexedMapOfReal()
{
  Clear();
}
  
  Standard_EXPORT   Standard_Integer Add (const Standard_Real& K) ;
  
  Standard_EXPORT   void Substitute (const Standard_Integer I, const Standard_Real& K) ;
  
  Standard_EXPORT   void RemoveLast() ;
  
  Standard_EXPORT   Standard_Boolean Contains (const Standard_Real& K)  const;
  
  Standard_EXPORT  const  Standard_Real& FindKey (const Standard_Integer I)  const;
 const  Standard_Real& operator () (const Standard_Integer I)  const
{
  return FindKey(I);
}
  
  Standard_EXPORT   Standard_Integer FindIndex (const Standard_Real& K)  const;




protected:





private:





};







#endif // _TColStd_IndexedMapOfReal_HeaderFile
