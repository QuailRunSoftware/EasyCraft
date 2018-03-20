/*
Time_File.h - Study for Arduino library for EasyCraft project.

Linked List SimSet implementation of the Time File timing routine.

Usage:
  An instance of the Set contains a collection of Member records.

Restrictions:
  Each Instance of a record inheriting from the Member struct may
  belong to only one Set. If multiples are required use the
  STL implementation. 

Time Complexity: Cause O(N) Remove_First O(1) Cancel O(1)
  
  Copyleft (c) 2018 Quail Run Software.
  Copyright (c) 2018 Quail Run Software. All right reserved.

  All rights are Open Source under the Beerware License.
  As long as you retain this notice you can do whatever you want
  with this stuff. If we meet some day, and you think this stuff
  is worth it, you can buy me a beer in return. Additionally,
  the terms of the Gnu Lesser GPL apply.
*/

#pragma once

typedef int Time_Type;
typedef void (*const Event_Routine_Ptr)();
//
// Usage of above typedef is to pass the name "My_Event_Function"
// (without the quotes) as a parameter in the Cause method or pass
// a variable such as Whatever:
// Event_Routine_Ptr Whatever = My_Event_Function;
// Read up on it at:
// www.learncpp.com/cpp-tutorial/78-function-pointers/
//
typedef struct Time_File_Set;
typedef struct Time_File_Member;
typedef Time_File_Member *Time_File_Member_Ptr;

struct Time_File_Member {
  Time_File_Member_Ptr Pred = 0;
  Time_File_Member_Ptr Succ = 0;
  Time_Type Due_Time = 0;
};

struct Time_File_Set {
  Time_File_Member_Ptr First = 0;
  Time_File_Member_Ptr Last = 0;

  void Cause(Time_File_Member_Ptr mbr, Time_Type At_Time);

  Time_File_Member_Ptr Remove_First();   // used for dispatching
  void Cancel(Time_File_Member_Ptr mbr);
  ~Time_File_Set();
private:
  void inline File_First(Time_File_Member_Ptr mbr);
  void inline File_Last(Time_File_Member_Ptr mbr);
  void inline File_Before(Time_File_Member_Ptr mbr, Time_File_Member_Ptr exist);
};
