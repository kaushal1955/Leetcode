SELECT name AS Customers
FROM Customers
Where id NOT IN (
    SELECT customerId
    FROM Orders
)