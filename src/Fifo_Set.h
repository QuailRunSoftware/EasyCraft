/*
Fifo_Set.h - Study for Arduino library for EasyCraft project.

Linked List SimSet implementation of the first-in-first-out set.

Usage:
  An instance of the Set contains a collection of Member records.

Restrictions:
  Each Instance of a record inheriting from the Member struct may
  belong to only one Set. If multiples are required use the
  STL implementation. 

Time Complexity: File O(1) Remove O(1)
  
  Copyleft (c) 2018 Quail Run Software.
  Copyright (c) 2018 Quail Run Software. All right reserved.

  All rights are Open Source under the Beerware License.
  As long as you retain this notice you can do whatever you want
  with this stuff. If we meet some day, and you think this stuff
  is worth it, you can buy me a beer in return. Additionally,
  the terms of the Gnu Lesser GPL apply.
*/

#pragma once

typedef struct Fifo_Set Fifo_Set;
typedef struct Fifo_Member Fifo_Member;
typedef Fifo_Member *Fifo_Member_Ptr;

struct Fifo_Member {
  Fifo_Member_Ptr Succ = 0;
};

struct Fifo_Set {
  Fifo_Member_Ptr First = 0;
  Fifo_Member_Ptr Last = 0;

  void File_Last(Fifo_Member_Ptr mbr);
  void File(Fifo_Member_Ptr mbr) { File_Last(mbr); };

  Fifo_Member_Ptr Remove_First();
  Fifo_Member_Ptr Remove() { return Remove_First(); };
  ~Fifo_Set();
};
