// Created on: 2007-05-29
// Created by: Vlad Romashko
// Copyright (c) 2007-2014 OPEN CASCADE SAS
//
// This file is part of Open CASCADE Technology software library.
//
// This library is free software; you can redistribute it and/or modify it under
// the terms of the GNU Lesser General Public License version 2.1 as published
// by the Free Software Foundation, with special exception defined in the file
// OCCT_LGPL_EXCEPTION.txt. Consult the file LICENSE_LGPL_21.txt included in OCCT
// distribution for complete text of the license and disclaimer of any warranty.
//
// Alternatively, this file may be used under the terms of Open CASCADE
// commercial license or contractual agreement.

#include <BinMDataStd_ReferenceListDriver.ixx>
#include <TDataStd_ReferenceList.hxx>
#include <TDF_ListIteratorOfLabelList.hxx>
#include <TDF_Label.hxx>
#include <TDF_Tool.hxx>

//=======================================================================
//function : BinMDataStd_ReferenceListDriver
//purpose  : Constructor
//=======================================================================
BinMDataStd_ReferenceListDriver::BinMDataStd_ReferenceListDriver(const Handle(CDM_MessageDriver)& theMsgDriver)
     : BinMDF_ADriver (theMsgDriver, STANDARD_TYPE(TDataStd_ReferenceList)->Name())
{

}

//=======================================================================
//function : NewEmpty
//purpose  : 
//=======================================================================
Handle(TDF_Attribute) BinMDataStd_ReferenceListDriver::NewEmpty() const
{
  return new TDataStd_ReferenceList();
}

//=======================================================================
//function : Paste
//purpose  : persistent -> transient (retrieve)
//=======================================================================
Standard_Boolean BinMDataStd_ReferenceListDriver::Paste(const BinObjMgt_Persistent&  theSource,
							const Handle(TDF_Attribute)& theTarget,
							BinObjMgt_RRelocationTable&  ) const
{
  Standard_Integer aFirstInd, aLastInd;
  if (! (theSource >> aFirstInd >> aLastInd))
    return Standard_False;
  const Standard_Integer aLength = aLastInd - aFirstInd + 1;
  if (aLength <= 0)
    return Standard_False;

  Handle(TDataStd_ReferenceList) anAtt = Handle(TDataStd_ReferenceList)::DownCast(theTarget);
  for (Standard_Integer i = aFirstInd; i <= aLastInd; i++)
  {
    TCollection_AsciiString entry;
    if ( !(theSource >> entry) )
      return Standard_False;
    TDF_Label L;
    TDF_Tool::Label(anAtt->Label().Data(), entry, L, Standard_True);
    if (!L.IsNull())
      anAtt->Append(L);
  }

  return Standard_True;
}

//=======================================================================
//function : Paste
//purpose  : transient -> persistent (store)
//=======================================================================
void BinMDataStd_ReferenceListDriver::Paste(const Handle(TDF_Attribute)& theSource,
					    BinObjMgt_Persistent&        theTarget,
					    BinObjMgt_SRelocationTable&  ) const
{
  Handle(TDataStd_ReferenceList) anAtt = Handle(TDataStd_ReferenceList)::DownCast(theSource);
  if (anAtt->IsEmpty())
    return;
  Standard_Integer aFirstInd = 1, aLastInd = anAtt->Extent(), i = aFirstInd;
  theTarget << aFirstInd << aLastInd;
  TDF_ListIteratorOfLabelList itr(anAtt->List());
  for (; itr.More(); itr.Next(), i++)
  {
    TDF_Label L = itr.Value();
    if (!L.IsNull())
    {
      TCollection_AsciiString entry;
      TDF_Tool::Entry(L, entry);
      theTarget << entry;
    }
  }
}
