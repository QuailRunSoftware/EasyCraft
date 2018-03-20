# EasyCraft
Arduino library for sequencing real-time events 
The EasyCraft Library project provides a world view framework for sequencing real-time events and data objects on 32-bit ARM(R) Cortex processors.

Conceptual Basis

This code uses concepts from the 1962 SIMSCRIPT Simulation Programming Language developed at the RAND corporation by Harry M. Markowitz, B. Hausner, and H. W. Karr.

These concepts provide a "World View" of Entities, Attributes, and Sets. The Entities are data objects (consider them as equivalent to 'c' structs) and their Attributes (consider them as 'c' data members). A Set is an ordered collection of Entities (consider them as 'c' linked lists).

Entities, Attribtes, and Sets are a conceptual tool that can be used in many ways such as building a database within memory or externally and for discrete-event simulation or real-time operation.
 
System status changes at points in time called Events (consider them to be 'c' functions) which trigger by either Internal or External sources. An Event can create or destroy Entities, change Attribute values, file Entities into or remove them from Sets, and cause (or cancel) future Event occurrences.

The SIMSCRIPT framework provides memory allocation and keeps track of the time order of Event handling. Thanks to Alasdar Mularney for the concept of synchronizing the simulated time clock to the real time clock.

This project was developed by Glen Johnson with help from others. Inspiration came from the SpinCraft vision of Don Seidenspinner, the founder and host of the San Diego Hardware Hackers SIG.

== License ==

Copyleft (c) 2018 Quail Run Software.
Copyright (c) 2018 Quail Run Software. All right reserved.

All rights are Open Source under the Beerware License. As long as you retain this notice you can do whatever you want with this stuff. If we meet some day, and you think this stuff is worth it, you can buy me a beer in return. Additionally, the terms of the Gnu Lesser GPL apply:
 
This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA

