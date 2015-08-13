/* $Header: /Space/src_repository/ets/framewk.dir/scoring/featgrp.cpp,v 1.9 1997/02/21 23:17:34 newkirk Exp $ */

#define BUILD_FRAMEWK_DLL


// Interface Dependancies ------------------------------------------------------
#include "scoring/featgrp.h"
#include "componen/nvtree.h"
#include "componen/strcnv.h"
#include <stdlib.h>
// End Interface Dependancies -------------------------------------------------




FeatureGroup::FeatureGroup(const RWCString& name)
{ SetName(name); }

FeatureGroup::~FeatureGroup()
{};


void FeatureGroup::AddEvaluator(Evaluator* evaluator , int rank)
{
        itsERAssoc.Add(new ERAssoc(evaluator, rank));
        return;
}

void FeatureGroup::AddMatrixElement(int i, int u, Score score)
{
        itsMatrix.SetScore(i, u, score);
        return;
}



// --------------------------------------------------------------------------
//
//      Name
//              FeatureGroup::Evaluate()
//
//      Description
//              This function does the actual evaluation for this feature group
//              it first iterates through the set of Features/FeatureGroups
//              that it holds summing the 'I' and 'U' values.  Once it is
//              complete it then consults with the matrix class to get the
//              score for this feature group.  It outputs all audit trails
//              to the passed in ostream.
//
//      Author
//              James Newkirk
//
// --------------------------------------------------------------------------
//
void    FeatureGroup::OutputInitString() const
{
        ostream& outputStream = GetStream();
        outputStream << "Evaluating Feature Group : "
                                         << GetFormattedName() << endl;
}

Evaluator::Score FeatureGroup::DoEval()
{
        ostream& outputStream = GetStream();
        NVTree& summaryTree = GetSummaryTree();

        /*  1/97  RR  Rescore option  */
        int rescore = GetRescore();
        NVTree& rescoreTree = GetRescoreTree();

        //We need the total I and the total U and undefined
        int sumU, sumI, sumX, sumF, sumQ;
        sumU = sumI = sumX = sumF = sumQ = 0;

        // Now set up the iterator through the set of Evaluators
        Evaluator::Score s, rtnScore;
        Iterator<ERAssoc*> eri(itsERAssoc);

        // stop evaluation after a fatal failure
        for(int i=0; eri && (sumF == 0 && sumQ == 0); eri++, i++ )
        {
                ERAssoc& assoc = **eri;
                Evaluator& e = *(assoc.GetPredicate());
                int rank = assoc.GetSubject();

                NVTree subTree;
                subTree.SetValue("Rank", rank);

                /*  1/97  RR  Rescore option  */
                s = e.Evaluate(outputStream, subTree, rescore, rescoreTree);

                outputStream << "\tScore = " << StringScore(s)
                        << " Rank = " << rank << endl;

                switch(s)
                {
                        case I:
                                sumI += rank;
            break;
                        case U:
                                sumU += rank;
                        break;
                        case X:
                                sumX += 1;
                        break;
                        case F:
                                sumF += 1;
                        break;
                        case Q:
                          sumQ += 1;
                        break;
                        case A:
                                // do nothing
                        break;
                }
                subTree.SetValue("I", sumI);
                subTree.SetValue("U", sumU);
                subTree.SetValue("X", sumX);
                subTree.SetValue("F", sumF);
                subTree.SetValue("Q", sumQ);
                summaryTree.SetSubTree(RWCString("Evaluator[") + IntToStr(i) + RWCString("]"),
                  subTree);
        }
        outputStream << "Feature Group : " << GetFormattedName() << ", ";

        if(sumF != 0)
        {
                rtnScore = F;
                outputStream << "Fatal(F) Failure" << endl;
        }
        else if(sumQ != 0)
        {
          rtnScore = Q;
          outputStream << "Fatal(Q) Failure" << endl;
        }
        else
        {
                outputStream << "Matrix Coordinates (i,u) = " << "(" << sumI << "," << sumU
                                << ")" << endl;
                if(sumX != 0)
                        rtnScore = X;
                else
                        rtnScore = itsMatrix.GetScore( sumI, sumU );
        }

        return rtnScore;
}
