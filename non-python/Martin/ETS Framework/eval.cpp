/* $Header: /Space/src_repository/ets/framewk.dir/scoring/eval.cpp,v 1.8 1997/02/21 23:17:33 newkirk Exp $ */

#define BUILD_FRAMEWK_DLL


// Interface Dependancies ----------------------------------------------------
#include "scoring/eval.h"
#include "rw/cstring.h"
#include "componen/nvtree.h"
#include "componen/nassert.h"
#include "componen/strcnv.h"
#include <iostream.h>

// End Interface Dependancies -----------------------------------------------


Evaluator::Evaluator()
{};

Evaluator::~Evaluator()
{};

// ---------------------------------------------------------------------------
//      StringScore -- convert the enum Score to a printable string
//
//      Notes
//
// ---------------------------------------------------------------------------
//

class ostream;

RWCString StringScore( Evaluator::Score s )
{
        RWCString rtnString;

        switch(s)
        {
          case Evaluator::A:
                 rtnString = "A";
          break;
          case Evaluator::I:
                 rtnString = "I";
          break;
          case Evaluator::U:
                 rtnString = "U";
          break;
          case Evaluator::F:
                 rtnString = "F";
          break;
          case Evaluator::X:
                 rtnString = "X";
          break;
          case Evaluator::Q:
                 rtnString = "Q";
          break;
        }

        return rtnString;
}

RWCString Evaluator::GetFormattedName() const
{
        return itsName + " (" + itsReferenceCode + ")";
}

/*  1/97  RR  Rescore option  */
Evaluator::Score Evaluator::Evaluate(ostream& o, NVTree& summaryTree,
                                    int rescore, NVTree& rescoreTree)
{
        itsStream = &o;
        itsSummaryTree = &summaryTree;

        /*  1/97  RR  Rescore option  */
        itsRescore = rescore;
        itsRescoreTree = &rescoreTree;

        OutputInitString();

        itsSummaryTree->SetValue("Name", itsName);
        itsSummaryTree->SetValue("ReferenceCode" , itsReferenceCode);

        /*  1/97  RR  Rescore option  */
        Score score;
        if (!rescore ||
            itsReferenceCode[0] == 'M' ||
            itsReferenceCode == "Fatal")
           {
           score = DoEval();
           }
        else
           {
           RWCString preFix = "...";
           RWCString s = "?";

           GetScore(*itsRescoreTree, preFix, itsReferenceCode, s, 1);

           switch(s[0])
              {
              case 'A':
                   score = Evaluator::A;
                   break;

              case 'I':
                   score = Evaluator::I;
                   break;

              case 'U':
                   score = Evaluator::U;
                   break;

              case 'F':
                   score = Evaluator::F;
                   break;

              case 'X':
                   score = Evaluator::X;
                   break;

              case 'Q':
                   score = Evaluator::Q;
                   break;

              case '?':
                   score = Evaluator::Q;
                   break;
              }
           }

        itsSummaryTree->SetValue("Score", StringScore(score));
        return score;
}

ostream& Evaluator::GetStream() const
{
        Assert(itsStream);
        return *itsStream;
}

NVTree& Evaluator::GetSummaryTree() const
{
        Assert(itsSummaryTree);
        return *itsSummaryTree;
};

/*  1/97  RR  Rescore option  */
int Evaluator::GetRescore() const
{
        return itsRescore;
};

NVTree& Evaluator::GetRescoreTree() const
{
        Assert(itsRescoreTree);
        return *itsRescoreTree;
};

void Evaluator::OutputInitString() const
{
        *itsStream << GetFormattedName() << " Evaluation ------------------"
                                << endl;
}

void Evaluator::SetReferenceCode(const RWCString theCode)
{itsReferenceCode = theCode;}

RWCString Evaluator::StringScore( Score s )
{
        return ::StringScore(s);
}

/*  1/97  RR  Rescore option  */
void Evaluator::GetScore(const NVTree& tree, const RWCString& preFix,
              const RWCString& referenceCode, RWCString& score,
              int firstTime)
{
   if (!firstTime)
      {
      RWCString refCode = tree.GetValue("ReferenceCode");

      if (refCode == referenceCode)
         {
         score = tree.GetValue("Score");
         return;
         }
      }

   int i = 0;
   NVTree* node = tree.GetNode("Evaluator[0]");
   while (node != 0)
      {
      GetScore(*node, preFix + "...", referenceCode, score, 0);

      if (score != "?")
         {
         break;
         }

      RWCString newEval("Evaluator[" + IntToStr(++i) + "]");
      node = tree.GetNode(newEval);
      }
}

