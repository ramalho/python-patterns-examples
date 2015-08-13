/* $Header: /Space/src_repository/ets/framewk.dir/scoring/featgrp.h,v 1.5 1995/08/02 10:39:42 whm Exp $ */

#ifndef SCORING_FEATGRP_H
#define SCORING_FEATGRP_H

#include "hdr/dlldef.h"

#include <iostream.h>
#include <fstream.h>
#include "componen/u_ordset.h"
#include "componen/assoc.h"
#include "scoring/eval.h"
#include "scoring/matrix.h"


// This defines the Association that is part of a Feature Group
typedef Association<Evaluator*,int> ERAssoc;

// This defines the set of a associations that make up a feature group
typedef UnboundedOrderedSet<ERAssoc*> AssocSet;

// End Interface Dependancies ---------------------------------------------


// Class Definition -------------------------------------------------------
//
//	Name
//	  FeatureGroup 
//
//	Description
//    This class represents a group of Evaluators (Features or 
//	  FeatureGroups) that make up this overall Feature.  This 
//	  class implements the Evaluate method that is inherited
//	  from Evaluator.
//
// 	Implementation
//	  This class contains a matrix that is used to implement the 
//	  matrices that make up part of the scoring algorithms.  This class
//	  implements methods that allow this class to be stored on a stream
//	  It uses the Rogue Wave Persistent storage mechanism to 
//	  accomplish this.
//
//	Notes
//	  The elements that are passed to AddEvaluator must be pointers to 
//	  Evaluator and RWCollectableInt.  
//
//	Author
//		James Newkirk
//
// ------------------------------------------------------------------------
//
class FRAMEWK_CLASS FeatureGroup : public Evaluator
{
	public:
		// Constructor
		//	FeatureGroup( "A");
		FeatureGroup(const RWCString& name);

		// Destructor
		virtual ~FeatureGroup();

		// pure virtual from base class Evaluator
		Evaluator::Score DoEval();
		void			 OutputInitString() const;

		// add a sub evaluator to this feature group
		void AddEvaluator(Evaluator* evaluator , int rank);

		// assign a value to the matrix that is enclosed in this
		// feature group
		void AddMatrixElement(int i, int u, Score score);
	private:
		Matrix		itsMatrix;
		AssocSet	itsERAssoc;
};

#endif
