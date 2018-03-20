/*
 Lifo example.

 This example demonstrates the use of Lifo lists
 1. Verification of proper operation of the library code.
 2. Presenting a reasonable example using this library.
 
 Circuit:
 * A SAMD processor, Arduino Zero or better.

   created 19 March 2018
   by Glen
 */
 
#include <Lifo_Set.h>

struct My_Customer: Lifo_Member {
  int32_t ItemNumber;
};
typedef My_Customer *My_Customer_Ptr;

Lifo_Set Customer_Queue;

void setup() {
  bool OK = true;
  delay(2000);    // Allow upload to settle
  Serial.println("Begin Lifo Example");
  OK = Verify_Lifo();  // Delete this call for production
  if (!OK) {
    Serial.println("Verify failed. Cannot proceed.");
    while (true) {};
  }
}

//
// Demonstrate the features of Lifo queue
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
bool Verify_Lifo() {
  bool OK = true;
//
// This is less exhaustive than the original unit tests
// but should catch most corner conditions and memory leaks
// Verify correct operation of the following:
// 
// Verify that the queue owner destructor empties the queue.
// (members will not be destroyed) 
  OK = Verify_Lifo1(OK);
  if (OK) {
    Serial.println("Lifo Verify Completed Successfully");
  }
  return(OK);
}

typedef struct Test_Item_Dest : Lifo_Member {char Identity;};

Test_Item_Dest Dest1;
Test_Item_Dest Dest2;
Test_Item_Dest Dest3;
Test_Item_Dest Dest4;

bool Verify_Lifo1(bool OK) {
  OK = Verify_Lifo2(OK);
// Verify that destructor from Destructor_Test emptied the list.
// Since emptying uses Remove() this also verifies Remove().
  OK = OK && (Dest2.Succ == 0);
  return OK;
}

bool Verify_Lifo2(bool OK) {
  Lifo_Set Destructor_Test;
  Dest4.Identity = '*';
// Explicit test of File operation
  Destructor_Test.File(&Dest1);
  Destructor_Test.File(&Dest2);
  Destructor_Test.File(&Dest3);
  Destructor_Test.File(&Dest4);
// Verify that links are correct.
  OK = (OK && (Dest1.Succ == 0)
      && (Dest2.Succ == &Dest1) && (Dest3.Succ == &Dest2));
  Test_Item_Dest* Destx = (Test_Item_Dest*)Destructor_Test.Remove();
// Verify that Set oganization is Lifo
  OK = OK && (Destx->Identity == '*');
  return OK;
}
