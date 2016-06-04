// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _SelectMgr_AndFilter_HeaderFile
#define _SelectMgr_AndFilter_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <Handle_SelectMgr_AndFilter.hxx>

#include <SelectMgr_CompositionFilter.hxx>
#include <Standard_Boolean.hxx>
#include <Handle_SelectMgr_EntityOwner.hxx>
class SelectMgr_EntityOwner;


//! A framework to define a selection filter for two or
//! more types of entity.
class SelectMgr_AndFilter : public SelectMgr_CompositionFilter
{

public:

  
  //! Constructs an empty selection filter object for two or
  //! more types of entity.
  Standard_EXPORT SelectMgr_AndFilter();
  
  Standard_EXPORT   Standard_Boolean IsOk (const Handle(SelectMgr_EntityOwner)& anobj)  const;




  DEFINE_STANDARD_RTTI(SelectMgr_AndFilter)

protected:




private: 




};







#endif // _SelectMgr_AndFilter_HeaderFile
