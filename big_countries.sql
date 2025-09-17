/*##A country is big if it has an area of at least three million (i.e., 3000000 km2), or it has a population of at least twenty-five million (i.e., 25000000).
#Write a solution to find the name, population, and area of the big countries.
#Return the result table in any order.

#GIVEN:
#- Table 'World' with columns: name (varchar, primary key), continent (varchar), area (int), population (int), gdp (bigint)
#- Each row contains information about a country
#- A country is "big" if it meets at least one of two criteria:
#  * Area >= 3,000,000 km²
#  * Population >= 25,000,000

#OUTPUT:
#- Result table with columns: name, population, area
#- Only include countries that meet the "big" criteria
#- Return results in any order

#Example:
#Input: 
#World table:
#+-------------+-----------+---------+------------+--------------+
#| name        | continent | area    | population | gdp          |
#+-------------+-----------+---------+------------+--------------+
#| Afghanistan | Asia      | 652230  | 25500100   | 20343000000  |
#| Albania     | Europe    | 28748   | 2831741    | 12960000000  |
#| Algeria     | Africa    | 2381741 | 37100000   | 188681000000 |
#| Andorra     | Europe    | 468     | 78115      | 3712000000   |
#| Angola      | Africa    | 1246700 | 20609294   | 100990000000 |
#+-------------+-----------+---------+------------+--------------+
#Output: 
#+-------------+------------+---------+
#| name        | population | area    |
#+-------------+------------+---------+
#| Afghanistan | 25500100   | 652230  |
#| Algeria     | 37100000   | 2381741 |
#+-------------+------------+---------+

# APPROACH:
# Use a WHERE clause with OR condition to filter countries that meet either
# the area criterion (>= 3,000,000) or the population criterion (>= 25,000,000).
# Select only the required columns: name, population, and area.

#PSEUDOCODE:
#1. SELECT name, population, and area columns
#2. FROM World table
#3. WHERE area >= 3000000 OR population >= 25000000
#4. This will return all countries that meet at least one of the "big" criteria*/ 

# Write your MySQL query statement below

SELECT 
    name,
    population,
    area
FROM World
WHERE area >= 3000000 OR population >= 25000000;