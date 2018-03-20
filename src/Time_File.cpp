#include "Time_File.h"
#include <stddef.h>

//
// inline helper building blocks for queue management functions
//
void inline Time_File_Set::File_First(Time_File_Member_Ptr mbr) {
  if (First == 0) {
    Last = mbr;
  } else {
    First->Pred = mbr;
  }
  mbr->Pred = 0;
  mbr->Succ = First;
  First = mbr;
}

void inline Time_File_Set::File_Last(Time_File_Member_Ptr mbr) {
  if (Last == 0) {
    First = mbr;
  } else {
    Last->Succ = mbr;
  }
  mbr->Succ = 0;
  mbr->Pred = Last;
  Last = mbr;
}

void inline Time_File_Set::File_Before(Time_File_Member_Ptr mbr, Time_File_Member_Ptr exist) {
   mbr->Pred = exist->Pred;
   mbr->Succ = exist;
   exist->Pred = mbr;
   if (mbr->Pred == 0){
     First = mbr;
   } else {
     mbr->Pred->Succ = mbr;
} }

void Time_File_Set::Cause(Time_File_Member_Ptr mbr, Time_Type At_Time) {
  // We assume that a ranked queue is not very full, otherwise a Btree is faster.
  // Also assumed is that the queue is not corrupted
  mbr->Due_Time = At_Time;
  Time_File_Member_Ptr exist = Last;
  if (exist == 0) {
    File_First(mbr);
  } else {
  if (exist->Due_Time <= mbr->Due_Time) {
        File_Last(mbr);
  } else {  
      exist = First;
      while (exist->Due_Time <= mbr->Due_Time) {
        exist = exist->Succ;
      }     
      File_Before(mbr, exist);
} } }

Time_File_Member_Ptr Time_File_Set::Remove_First() {
  Time_File_Member_Ptr mbr = First;
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
  return(mbr);
};

void Time_File_Set::Cancel(Time_File_Member_Ptr mbr) {
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

Time_File_Set::~Time_File_Set() {
	
	while (First != 0) {
		Remove_First();
	}
	
}