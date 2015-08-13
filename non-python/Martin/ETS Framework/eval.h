/* $Header: /Space/src_repository/ets/framewk.dir/scoring/eval.h,v 1.7 1997/02/21 23:17:34 newkirk Exp $ */

#ifndef SCORING_EVAL_H
#define SCORING_EVAL_H

#include "hdr/dlldef.h"

#include "rw/cstring.h"

class ostream;



// ---------------------------------------------------------------------------
//
//      Class
//              Evaluator
//
//      Description
//              This class is the abstract base class for all
//              Evaluators.
//
//      Author
//              James Newkirk
//
// ---------------------------------------------------------------------------
//
class NVTree;

class FRAMEWK_CLASS Evaluator
{
  public:
        enum Score
        {
                A = 1,                  // Acceptable
                I,                                      // Indeterminant
                U,                                      // Unacceptable
                F,                            // Fatal
                Q,             // Special Processing Required
                X                                  // undefined
        };

        // default constructor
        Evaluator();

        // Destructor
        virtual ~Evaluator();

        /*  1/97  RR  Rescore option  */
        Score Evaluate(ostream& scoreOutput, NVTree& summaryTree,
                       int rescore, NVTree& rescoreTree);

        virtual void    OutputInitString() const;
        virtual Score   DoEval() = 0;

        void SetName(const RWCString& theName) {itsName = theName;}
        void SetReferenceCode(const RWCString theCode);

        const RWCString& GetName() {return itsName;}
        const RWCString& GetReferenceCode() {return itsReferenceCode;}
        RWCString GetFormattedName() const;

        ostream& GetStream() const;
        NVTree& GetSummaryTree() const;

        /*  1/97  RR  Rescore option  */
        int     GetRescore() const;
        NVTree& GetRescoreTree() const;
        void    GetScore(const NVTree& tree, const RWCString& preFix,
                         const RWCString& referenceCode, RWCString& score,
                         int firstTime);

        RWCString StringScore( Score s );
  private:
        ostream*  itsStream;
        NVTree*   itsSummaryTree;

        /*  1/97  RR  Rescore option  */
        int       itsRescore;
        NVTree*   itsRescoreTree;

        RWCString itsName;
        RWCString itsReferenceCode;

};

RWCString StringScore(Evaluator::Score s);

#endif
