/*
 Ranked example.

 This example demonstrates the use of Ranked lists
 1. Verification of proper operation of the library code.
 2. Presenting a reasonable example using this library.
 
 Circuit:
 * A SAMD processor, Arduino Zero or better.

   created 19 March 2018
   by Glen
 */
 
#include <Ranked_Set.h>

struct My_Customer: Ranked_Member {
  int32_t ItemNumber;
};
typedef My_Customer *My_Customer_Ptr;

Ranked_Set Customer_Queue;

void setup() {
  Serial.begin(115200);
  bool OK = true;
  Serial.println("Begin Ranked Example");
  OK = Verify_Ranked();  // Delete this call for production
  if (OK) {
    Serial.println("Ranked Verify Completed Successfully");
  } else {
    Serial.println("Verify failed. Cannot proceed.");
    while (true) {};
  }
}

//
// Productive demonstration of the features of Ranked queue
//
void loop() {
  delay(2000); // Allow Serial Monitor Scrolling
  //
  // TBD
  //
}

//
// Test the integration of any recent updates and
// block if anything is broken.
// 
bool Verify_Ranked() {
  bool OK = true;
//
// This is less exhaustive than the original unit tests
// but should catch most corner conditions and memory leaks
// 
// Verify that the queue owner destructor empties the queue.
// (members will not be destroyed) 
  OK = Verify_Ranked1(OK);
  return(OK);
}

typedef struct Test_Item_Dest : Ranked_Member {uint32_t RankValue;};

#define Num 6
Test_Item_Dest Dest[Num];

bool Verify_Ranked1(bool OK) {
  Ranked_Set Ranked_Set_1;   // Define a set for detailed tests
//
// Initialize some things to file into ranked sets
//
  for (int i = 0; i<Num; i++) {
    Dest[i].RankValue = i;
  }    
//
// Verify that destructor from Ranked_Set_2 emptied the list.
// Since emptying uses Remove_First() this is also exercised.
//
  OK = Verify_Ranked2(OK);
  OK = OK && (Dest[2].Succ == 0);
//
// Populate Set 1
//
// file as only, first, Last, and middle and 2 more
  Ranked_Set_1.File(&Dest[2], Dest[2].RankValue);
  Ranked_Set_1.File(&Dest[0], Dest[0].RankValue);
  Ranked_Set_1.File(&Dest[3], Dest[3].RankValue);
  Ranked_Set_1.File(&Dest[1], Dest[1].RankValue);
  Ranked_Set_1.File(&Dest[5], Dest[5].RankValue);
  Ranked_Set_1.File(&Dest[4], Dest[4].RankValue);
// Also exercise Remove Specific for middle and last
  Ranked_Set_1.Remove(&Dest[3]);
  Ranked_Set_1.Remove(&Dest[5]);
// and just put them back in
  Ranked_Set_1.File(&Dest[5], Dest[5].RankValue);
  Ranked_Set_1.File(&Dest[3], Dest[3].RankValue);

// Verify that Set oganization is properly Ranked
  Test_Item_Dest* mem1 = (Test_Item_Dest*)Ranked_Set_1.First;
  Test_Item_Dest* mem2;
  while ((mem2 = (Test_Item_Dest*)mem1->Succ) && (mem2 != 0)) {
    OK = OK && (mem1->RankValue <= mem2->RankValue);
    mem1 = mem2; 
  }

// Verify Remove Specific for first and Remove First
  Ranked_Set_1.Remove(&Dest[0]);
  OK = (OK && (Dest[0].Pred == 0) && (Dest[0].Succ == 0) &&
    (Ranked_Set_1.First == &Dest[1]) && (Dest[1].Pred == 0)); 
  Test_Item_Dest* Destx = (Test_Item_Dest*)Ranked_Set_1.Remove_First();
  OK == ((Destx == &Dest[1]) && (Ranked_Set_1.First == &Dest[2]) &&
    (Dest[2].Pred == 0) && (Dest[1].Pred == 0) && (Dest[1].Succ == 0));  
  return OK;
}

bool Verify_Ranked2(bool OK) {
  Ranked_Set Ranked_Set_2;
  for (int i = 0; i<Num; i++) {
    Dest[i].RankValue = i;
  }
//
// Explicit test of File operation, the set will sort
//
// file into empty, as first, as last, into middle
  Ranked_Set_2.File(&Dest[2], Dest[2].RankValue);
  Ranked_Set_2.File(&Dest[0], Dest[0].RankValue);
  Ranked_Set_2.File(&Dest[3], Dest[3].RankValue);
  Ranked_Set_2.File(&Dest[1], Dest[1].RankValue);
 
// Verify that links are correct.
  OK = (OK && (Dest[0].Pred == 0) && (Dest[0].Succ == &Dest[1])); 
  OK = (OK && (Dest[1].Pred == &Dest[0]) && (Dest[1].Succ == &Dest[2])); 
  OK = (OK && (Dest[2].Pred == &Dest[1]) && (Dest[2].Succ == &Dest[3])); 
  OK = (OK && (Dest[3].Pred == &Dest[2]) && (Dest[3].Succ == 0)); 

  return OK;
}
