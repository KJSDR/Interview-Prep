##Write a solution to report the first name, last name, city, and state of each person in the Person table. If the address of a personId is not present in the Address table, report null instead.
#Return the result table in any order.

#GIVEN:
#- Table 'Person' with columns: personId (int, primary key), lastName (varchar), firstName (varchar)
#- Table 'Address' with columns: addressId (int, primary key), personId (int), city (varchar), state (varchar)
#- Each person may or may not have an address record
#- Need to include all persons even if they don't have address information

#OUTPUT:
#- Result table with columns: firstName, lastName, city, state
#- For persons without address: city and state should be null
#- Return results in any order

#Example:
#Input: 
#Person table:
#+----------+----------+-----------+
#| personId | lastName | firstName |
#+----------+----------+-----------+
#| 1        | Wang     | Allen     |
#| 2        | Alice    | Bob       |
#+----------+----------+-----------+
#Address table:
#+-----------+----------+---------------+------------+
#| addressId | personId | city          | state      |
#+-----------+----------+---------------+------------+
#| 1         | 2        | New York City | New York   |
#| 2         | 3        | Leetcode      | California |
#+-----------+----------+---------------+------------+
#Output: 
#+-----------+----------+---------------+----------+
#| firstName | lastName | city          | state    |
#+-----------+----------+---------------+----------+
#| Allen     | Wang     | null          | null     |
#| Bob       | Alice    | New York City | New York |
#+-----------+----------+---------------+----------+

# APPROACH:
# Use LEFT JOIN to include all persons from Person table, even if they don't have 
# corresponding address records in Address table. LEFT JOIN will return null 
# values for city and state when no matching address is found.

#PSEUDOCODE:
#1. SELECT the required columns: firstName, lastName, city, state
#2. FROM Person table (this is our main table)
#3. LEFT JOIN with Address table on personId
#4. This ensures all persons are included, with null values for missing addresses

# Write your MySQL query statement below
SELECT 
    p.firstName,
    p.lastName,
    a.city,
    a.state
FROM Person p
LEFT JOIN Address a ON p.personId = a.personId;