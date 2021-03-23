# Customer-Project

Contributors: Kieran Gaffney, Kenneth Gell, Haoyang Xiao

Executable: ./exec [input file] [output file]

Program takes commands and efficiently performs tasks using BST

register [userid] [lastname] [nickname]
update <userid> <nickname>
buy <userid> <item> <price>
history <userid>
report <howmany>
surprise <howmany> <item> <price>

1. Register: New users may register for the system, providing a unique user id, a last name, and a nickname
2. Update: Users may change their nickname at any time
3. Buy: Users may purchase items, each of which has a name and a price
4. History: Users may list all purchases (<item, price> pairs) they have ever made
5. Report: Determine how many JAMbucks™ have been earned by the top K customers
6. Surprise: Award a free item to the top K customers. This item should then appear in the user's history.

JAMBucks is a theoretical rewards program earned based off of purchases. When users make purchases, they earn JAMbucks™. Every purchase earns 5 JAMbucks™, and every
100 dollars spent earns an additional 10 JAMbucks™

All commands take O(log n) or less to perform.
