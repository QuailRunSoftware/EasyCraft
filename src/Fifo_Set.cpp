#include "Fifo_Set.h"

void Fifo_Set::File_Last(Fifo_Member_Ptr mbr) {
  mbr->Succ = 0;
  if (Last == 0) {
    First = mbr;
  } else {
    Last->Succ = mbr;
  }
  Last = mbr;
}

Fifo_Member_Ptr Fifo_Set::Remove_First() {
  Fifo_Member_Ptr mbr = First;
  if (mbr != 0) {
    First = mbr->Succ;
    if (First != 0) {
		mbr->Succ = 0;
	} else {
      Last = 0;
    } 
  }
  return mbr;
}

Fifo_Set::~Fifo_Set() {
	while (First != 0) {
		Remove_First();
	}
	
}