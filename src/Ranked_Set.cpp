#include "Ranked_Set.h"

//
// inline helper building blocks for queue management functions
//
void inline Ranked_Set::File_First(Ranked_Member_Ptr mbr) {
  if (First == 0) {
    Last = mbr;
  } else {
    First->Pred = mbr;
  }
  mbr->Pred = 0;
  mbr->Succ = First;
  First = mbr;
}

void inline Ranked_Set::File_Last(Ranked_Member_Ptr mbr) {
  if (Last == 0) {
    First = mbr;
  } else {
    Last->Succ = mbr;
  }
  mbr->Succ = 0;
  mbr->Pred = Last;
  Last = mbr;
}

void inline Ranked_Set::File_Before(Ranked_Member_Ptr mbr, Ranked_Member_Ptr exist) {
   mbr->Pred = exist->Pred;
   mbr->Succ = exist;
   exist->Pred = mbr;
   if (mbr->Pred == 0){
     First = mbr;
   } else {
     mbr->Pred->Succ = mbr;
} }


void Ranked_Set::File(Ranked_Member_Ptr mbr,
      Ranking_Type rankvalue) {
  // We assume that a ranked queue is not very full, otherwise a Btree is faster.
  // Also assumed is that the queue is not corrupted
  mbr->Ranking_Value = rankvalue;
  Ranked_Member_Ptr exist = Last;
  if (exist == 0) {
    File_First(mbr);
  } else {
  if (exist->Ranking_Value <= mbr->Ranking_Value) {
        File_Last(mbr);
  } else {  
      exist = First;
      while (exist->Ranking_Value <= mbr->Ranking_Value) {
        exist = exist->Succ;
      }     
      File_Before(mbr, exist);
} } }

Ranked_Member_Ptr Ranked_Set::Remove_First() {
  Ranked_Member_Ptr mbr = First;
  if (mbr != 0) {   //  empty returns 0
    First = mbr->Succ;
    if (First != 0) {
      First->Pred = 0;
    } else {
      Last = 0;
    }
    mbr->Pred = 0;
    mbr->Succ = 0;
  }
  return mbr;
}

void Ranked_Set::Remove_Specific(Ranked_Member_Ptr mbr) {
  // Assumption: member is in the set
  if (First == mbr) {
    First = mbr->Succ;    
    if (mbr->Succ != 0) {
      mbr->Succ->Pred = 0;     
    } else {
      Last = 0;
    }
  } else if (Last != mbr) {
    mbr->Pred->Succ = mbr->Succ;
    mbr->Succ->Pred = mbr->Pred;
  } else {
     Last = mbr->Pred;
     mbr->Pred->Succ = 0; 
  }
  mbr->Pred = 0;
  mbr->Succ = 0;
	
}

Ranked_Set::~Ranked_Set() {
	
	while (First != 0) {
		Remove_First();
	}
	
}