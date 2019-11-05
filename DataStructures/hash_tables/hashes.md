# Hashing

 - A data structure used to store and retrieve data in constant time. 
 - Hash table implements associative array abstract data type, a structure that can map key to values.
 - a hash function is used to compute an index, also called a hash code
 - ideally all key should reside in  a unique bucket but table designs employ an imperfect hash function which might cause collisions where the hash function generates the same index given different keys


### Hash functions
 - a property of data
 - must be fast to compute
 - must be deterministic (equal elements should always return the same value)
 - must have minimum collisions
 
 ### Load factor 
 - is a critical statitic for the hash table 
 - load factor is n/k
 - where n is the number of entries occupied by the hash table and k is the number of buckets in the array 
 
 ## Collisions 
 
 - Collisions in hash tables are unavoidable. Several methods can be used to resolve collisions 
 
 	### Separate chaining 
 	- Each bucket is independent and has some sort of list of entries with the same index
 	- The time taken with separate chaining is constant time plus the time to search for the list operations
 	- Chaining with linked list is popular because they require a simple data structure with simple algorithms 
 	
 	### Open addressing 
 	- All entry records are stored in the bucket array itself
 	- When an entry is inserted buckets are examined and inserted in the correct slot, if a slot it occupied the next slot is chosen.
 	


## Uses
- Hash tables are commonly used to implement in-memory datatables
- Hash index also used as disk based data structures and database indexes 
- Hash tables can be used to implement caches
 	