// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _math_BFGS_HeaderFile
#define _math_BFGS_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Macro.hxx>

#include <Standard_Boolean.hxx>
#include <math_Status.hxx>
#include <math_Vector.hxx>
#include <Standard_Real.hxx>
#include <Standard_Integer.hxx>
#include <Standard_OStream.hxx>
class StdFail_NotDone;
class Standard_DimensionError;
class math_MultipleVarFunctionWithGradient;



//! This class implements the Broyden-Fletcher-Goldfarb-Shanno variant of
//! Davidson-Fletcher-Powell minimization algorithm of a function of
//! multiple variables.Knowledge of the function's gradient is required.
class math_BFGS 
{
public:

  DEFINE_STANDARD_ALLOC

  

  //! Given the starting point StartingPoint,
  //! the Broyden-Fletcher-Goldfarb-Shanno variant of Davidson-Fletcher-Powell
  //! minimization is done on the function F.
  //! The tolerance required on F is given by Tolerance.
  //! The solution F = Fi is found when :
  //! 2.0 * abs(Fi - Fi-1) <= Tolerance * (abs(Fi) + abs(Fi-1) + ZEPS).
  //! The maximum number of iterations allowed is given by NbIterations.
  Standard_EXPORT math_BFGS(math_MultipleVarFunctionWithGradient& F, const math_Vector& StartingPoint, const Standard_Real Tolerance = 1.0e-8, const Standard_Integer NbIterations = 200, const Standard_Real ZEPS = 1.0e-12);
  
  //! Initializes the computation of the minimum of F.
  //! Warning
  //! A call to the Perform method must be made after this
  //! initialization to effectively compute the minimum of the
  //! function F.
  Standard_EXPORT math_BFGS(math_MultipleVarFunctionWithGradient& F, const Standard_Real Tolerance = 1.0e-8, const Standard_Integer NbIterations = 200, const Standard_Real ZEPS = 1.0e-12);
  
  Standard_EXPORT virtual   void Delete() ;
Standard_EXPORT virtual ~math_BFGS(){Delete() ; }
  
  //! Is used internally by the constructors.
  Standard_EXPORT   void Perform (math_MultipleVarFunctionWithGradient& F, const math_Vector& StartingPoint) ;
  

  //! This method is called at the end of each iteration to check if the
  //! solution is found.
  //! It can be redefined in a sub-class to implement a specific test to
  //! stop the iterations.
  Standard_EXPORT virtual   Standard_Boolean IsSolutionReached (math_MultipleVarFunctionWithGradient& F)  const;
  
  //! Returns true if the computations are successful, otherwise returns false.
      Standard_Boolean IsDone()  const;
  
  //! returns the location vector of the minimum.
  //! Exception NotDone is raised if the minimum was not found.
     const  math_Vector& Location()  const;
  
  //! outputs the location vector of the minimum in Loc.
  //! Exception NotDone is raised if the minimum was not found.
  //! Exception DimensionError is raised if the range of Loc is not
  //! equal to the range of the StartingPoint.
      void Location (math_Vector& Loc)  const;
  
  //! returns the value of the minimum.
  //! Exception NotDone is raised if the minimum was not found.
      Standard_Real Minimum()  const;
  
  //! Returns the gradient vector at the minimum.
  //! Exception NotDone is raised if the minimum was not found.
     const  math_Vector& Gradient()  const;
  
  //! Returns the value of the gradient vector at the minimum in Grad.
  //! Exception NotDone is raised if the minimum was not found.
  //! Exception DimensionError is raised if the range of Grad is not
  //! equal to the range of the StartingPoint.
      void Gradient (math_Vector& Grad)  const;
  
  //! Returns the number of iterations really done in the
  //! calculation of the minimum.
  //! The exception NotDone is raised if the minimum was not found.
      Standard_Integer NbIterations()  const;
  
  //! Prints on the stream o information on the current state
  //! of the object.
  //! Is used to redefine the operator <<.
  Standard_EXPORT   void Dump (Standard_OStream& o)  const;




protected:



  math_Status TheStatus;
  math_Vector TheLocation;
  math_Vector TheGradient;
  Standard_Real PreviousMinimum;
  Standard_Real TheMinimum;
  Standard_Real XTol;
  Standard_Real EPSZ;
  Standard_Integer nbiter;


private:



  Standard_Boolean Done;
  Standard_Integer Itermax;


};


#include <math_BFGS.lxx>





#endif // _math_BFGS_HeaderFile