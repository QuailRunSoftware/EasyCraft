/*
Lifo_Set.h - Study for Arduino library for EasyCraft project.

Linked List SimSet implementation of the last-in-first-out set.

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

typedef struct Lifo_Set;
typedef struct Lifo_Member;
typedef Lifo_Member *Lifo_Member_Ptr;

struct Lifo_Member {
  Lifo_Member_Ptr Succ = 0;
};

struct Lifo_Set {
  Lifo_Member_Ptr First = 0;

  void File_First(Lifo_Member_Ptr mbr);
  void File(Lifo_Member_Ptr mbr) { File_First(mbr); }

  Lifo_Member_Ptr Remove_First();
  Lifo_Member_Ptr Remove() { return Remove_First(); }
  ~Lifo_Set();
};
