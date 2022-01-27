Requirements
1.	No database system is used and all data are kept in RAM. 
2.	The phone book manages only the attributes 
a.	Last name
b.	First name
c.	Phone number
for each entry. 
Your task:

1.	Design the  data structures for holding all entries. Moreover,
a.	the data structures shall allow an efficient look up by either the last name, or the first name or the phone number (combinations of criteria need not to be supported)
b.	the data structures shall allow an efficient insertion of a new entry.
c.	the data structures shall prevent duplicate entries.
2.	What needs to change if the lookup by last name or first name shall be
a.	case insensitive
b.	identifies ae and ä, ue and ü, oe and ö
Note that records found should still be printed as entered (with respect to Umlauts and capital letters)  
3.	What needs to change such that an efficient search for each criteria for a given initial sequence is supported (“starts with search”)
4.	What needs to change such that each name is hold in memory only once.
