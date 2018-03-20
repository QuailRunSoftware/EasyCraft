#include "Lifo_Set.h"

void Lifo_Set::File_First(Lifo_Member_Ptr mbr) {
  mbr->Succ = First;
  First = mbr;
}

Lifo_Member_Ptr Lifo_Set::Remove_First() {
  Lifo_Member_Ptr mbr = First;
  if (mbr != 0) {
    First = mbr->Succ;
    mbr->Succ = 0;
  }
  return mbr;
}

Lifo_Set::~Lifo_Set() {
	while (First != 0) {
		Remove_First();
	}
	
}
