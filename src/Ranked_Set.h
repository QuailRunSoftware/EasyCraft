/*
Ranked_Set.h - Study for Arduino library for EasyCraft project.

Linked List SimSet implementation of the Ranked set.

Usage:
  An instance of the Set contains a collection of Member records.

Restrictions:
  Each Instance of a record inheriting from the Member struct may
  belong to only one Set. If multiples are required use the
  STL implementation. 

Time Complexity: File O(N) Remove O(1)
  
  Copyleft (c) 2018 Quail Run Software.
  Copyright (c) 2018 Quail Run Software. All right reserved.

  All rights are Open Source under the Beerware License.
  As long as you retain this notice you can do whatever you want
  with this stuff. If we meet some day, and you think this stuff
  is worth it, you can buy me a beer in return. Additionally,
  the terms of the Gnu Lesser GPL apply.
*/

#pragma once

typedef int Ranking_Type;
typedef struct Ranked_Set;
typedef struct Ranked_Member;
typedef Ranked_Member *Ranked_Member_Ptr;

struct Ranked_Member {
  Ranked_Member_Ptr Pred = 0;
  Ranked_Member_Ptr Succ = 0;
  Ranking_Type Ranking_Value = 0;
};

struct Ranked_Set {
  Ranked_Member_Ptr First = 0;
  Ranked_Member_Ptr Last = 0;

  void File(Ranked_Member_Ptr mbr, Ranking_Type rankvalue);

  Ranked_Member_Ptr Remove_First();
  void Remove_Specific(Ranked_Member_Ptr mbr);
  void Remove(Ranked_Member_Ptr mbr) {
	       return Remove_Specific(mbr);
  };

~Ranked_Set();

private:
  void inline File_First(Ranked_Member_Ptr mbr);
  void inline File_Last(Ranked_Member_Ptr mbr);
  void inline File_Before(Ranked_Member_Ptr mbr, Ranked_Member_Ptr exist);
};
