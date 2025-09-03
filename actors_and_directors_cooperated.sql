##Write a solution to find all the pairs (actor_id, director_id) where the actor has cooperated with the director at least three times.
#Return the result table in any order.

#GIVEN:
#- Table 'ActorDirector' with columns: actor_id (int), director_id (int), timestamp (int, primary key)
#- Each row represents a cooperation between an actor and director at a specific time
#- Need to find pairs that have cooperated at least 3 times
#- Each timestamp represents one cooperation instance

#OUTPUT:
#- Result table with columns: actor_id, director_id
#- Only include pairs that have cooperated 3 or more times
#- Return results in any order

#Example:
#Input: 
#ActorDirector table:
#+-------------+-------------+-------------+
#| actor_id    | director_id | timestamp   |
#+-------------+-------------+-------------+
#| 1           | 1           | 0           |
#| 1           | 1           | 1           |
#| 1           | 1           | 2           |
#| 1           | 2           | 3           |
#| 1           | 2           | 4           |
#| 2           | 1           | 5           |
#| 2           | 1           | 6           |
#+-------------+-------------+-------------+
#Output: 
#+-------------+-------------+
#| actor_id    | director_id |
#+-------------+-------------+
#| 1           | 1           |
#+-------------+-------------+

# APPROACH:
# Use GROUP BY to group records by actor_id and director_id pairs, then use 
# COUNT() to count cooperations for each pair. Filter with HAVING to only 
# return pairs with count >= 3.

#PSEUDOCODE:
#1. SELECT actor_id and director_id
#2. FROM ActorDirector table
#3. GROUP BY actor_id, director_id (to group each unique pair)
#4. HAVING COUNT(*) >= 3 (filter groups with at least 3 cooperations)
#5. This counts all rows for each actor-director pair and keeps only those with 3+ cooperations

# Write your MySQL query statement below
SELECT 
    actor_id,
    director_id
FROM ActorDirector
GROUP BY actor_id, director_id
HAVING COUNT(*) >= 3;