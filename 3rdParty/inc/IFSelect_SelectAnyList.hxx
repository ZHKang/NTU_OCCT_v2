// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _IFSelect_SelectAnyList_HeaderFile
#define _IFSelect_SelectAnyList_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <Handle_IFSelect_SelectAnyList.hxx>

#include <Handle_IFSelect_IntParam.hxx>
#include <IFSelect_SelectDeduct.hxx>
#include <Standard_Integer.hxx>
#include <Handle_Standard_Transient.hxx>
#include <Standard_Boolean.hxx>
class IFSelect_IntParam;
class Standard_OutOfRange;
class Interface_InterfaceError;
class Interface_EntityIterator;
class Standard_Transient;
class Interface_Graph;
class TCollection_AsciiString;


//! A SelectAnyList kind Selection selects a List of an Entity, as
//! well as this Entity contains some. A List contains sub-entities
//! as one per Item, or several (for instance if an Entity binds
//! couples of sub-entities, each item is one of these couples).
//! Remark that only Entities are taken into account (neither
//! Reals, nor Strings, etc...)
//!
//! To define the list on which to work, SelectAnyList has two
//! deferred methods : NbItems (which gives the length of the
//! list), FillResult (which fills an EntityIterator). They are
//! intended to get a List in an Entity of the required Type (and
//! consider that list is empty if Entity has not required Type)
//!
//! In addition, remark that some types of Entity define more than
//! one list in each instance : a given sub-class of SelectAnyList
//! must be attached to one list
//!
//! SelectAnyList keeps or rejects a sub-set of the list,
//! that is the Items of which rank in the list is in a given
//! range (for instance form 2nd to 6th, etc...)
//! Range is defined by two Integer values. In order to allow
//! external control of them, these values are not directly
//! defined as fields, but accessed through IntParams, that is,
//! referenced as Transient (Handle) objects
//!
//! Warning : the Input can be any kind of Selection, BUT its
//! RootResult must have zero (empty) or one Entity maximum
class IFSelect_SelectAnyList : public IFSelect_SelectDeduct
{

public:

  
  //! Keeps Input Entity, as having required type. It works by
  //! keeping in <iter>, only suitable Entities (SelectType can be
  //! used). Called by RootResult (which waits for ONE ENTITY MAX)
  Standard_EXPORT virtual   void KeepInputEntity (Interface_EntityIterator& iter)  const = 0;
  
  //! Returns count of Items in the list in the Entity <ent>
  //! If <ent> has not required type, returned value must be Zero
  Standard_EXPORT virtual   Standard_Integer NbItems (const Handle(Standard_Transient)& ent)  const = 0;
  
  //! Sets a Range for numbers, with a lower and a upper limits
  Standard_EXPORT   void SetRange (const Handle(IFSelect_IntParam)& rankfrom, const Handle(IFSelect_IntParam)& rankto) ;
  
  //! Sets a unique number (only one Entity will be sorted as True)
  Standard_EXPORT   void SetOne (const Handle(IFSelect_IntParam)& rank) ;
  
  //! Sets a Lower limit but no upper limit
  Standard_EXPORT   void SetFrom (const Handle(IFSelect_IntParam)& rankfrom) ;
  
  //! Sets an Upper limit but no lower limit (equivalent to lower 1)
  Standard_EXPORT   void SetUntil (const Handle(IFSelect_IntParam)& rankto) ;
  
  //! Returns True if a Lower limit is defined
  Standard_EXPORT   Standard_Boolean HasLower()  const;
  
  //! Returns Lower limit (if there is; else, value is senseless)
  Standard_EXPORT   Handle(IFSelect_IntParam) Lower()  const;
  
  //! Returns Integer Value of Lower Limit (0 if none)
  Standard_EXPORT   Standard_Integer LowerValue()  const;
  
  //! Returns True if a Lower limit is defined
  Standard_EXPORT   Standard_Boolean HasUpper()  const;
  
  //! Returns Upper limit (if there is; else, value is senseless)
  Standard_EXPORT   Handle(IFSelect_IntParam) Upper()  const;
  
  //! Returns Integer Value of Upper Limit (0 if none)
  Standard_EXPORT   Standard_Integer UpperValue()  const;
  
  //! Returns the list of selected entities (list of entities
  //! complying with rank criterium)
  //! Error if the input list has more than one Item
  Standard_EXPORT   Interface_EntityIterator RootResult (const Interface_Graph& G)  const;
  
  //! Puts into <res>, the sub-entities of the list, from n1 to
  //! n2 included. Remark that adequation with Entity's type and
  //! length of list has already been made at this stage
  //! Called by RootResult
  Standard_EXPORT virtual   void FillResult (const Standard_Integer n1, const Standard_Integer n2, const Handle(Standard_Transient)& ent, Interface_EntityIterator& res)  const = 0;
  
  //! Returns a text defining the criterium : "Componants of List "
  //! then Specific List Label, then, following cases :
  //! " From .. Until .." or "From .." or "Until .." or "Rank no .."
  //! Specific type is given by deferred method ListLabel
  Standard_EXPORT   TCollection_AsciiString Label()  const;
  
  //! Returns the specific label for the list, which is included as
  //! a part of Label
  Standard_EXPORT virtual   TCollection_AsciiString ListLabel()  const = 0;




  DEFINE_STANDARD_RTTI(IFSelect_SelectAnyList)

protected:




private: 


  Handle(IFSelect_IntParam) thelower;
  Handle(IFSelect_IntParam) theupper;


};







#endif // _IFSelect_SelectAnyList_HeaderFile