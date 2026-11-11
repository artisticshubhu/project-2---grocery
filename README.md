# project-2---grocery

1. Project Title
Grocery Store Management System in C (Admin & Customer Console Application)
2. Problem Statement
Small grocery shops often track stock, prices, discounts and customer bills manually, which is slow and error-prone. Mistakes in stock counts, discount calculations and totals lead to losses and unhappy customers. There is a need for a simple program that lets a store owner maintain the product list securely and lets customers browse products, build a cart and get an accurate, discounted bill.
3. Objective
The goal of this project is to build a menu-driven console application in C that:
•Provides a password-protected admin area to create, view, update and delete products (name, price, quantity, discount).
•Provides a customer area to view available products, add items to a cart, remove items and view the final bill.
•Keeps stock levels accurate as items are added to or removed from the cart.
•Calculates the subtotal, product-wise discount and final payable amount automatically.

4. Tools & Technologies Used
•Programming Language: C
•Software/Platform: C compiler (GCC ) running on Windows (VS CODE); console (terminal) interface
•Libraries/Tools: stdio.h (input/output), stdlib.h (exit), string.h (strcmp, strcpy)

5. Methodology / Approach
1.Analysed the requirements and divided the system into two roles: Admin and Customer.
2.Chose arrays to store product data: names (productname), prices (unitprice), stock (quantityleft) and discount (discount), with a maximum of 20 products.
3.Created separate backup arrays (copyproductname, copyunitprice, copydiscount, copyquantityleft) so cart details and original stock can be compared.
4.Designed the program as modular functions, one per screen/task (main, admin, userarea, usercart, userorder, userbill).
5.Added admin authentication using a fixed password compared with strcmp().
6.Implemented input validation for the number of products (1–20), stock quantity, product numbers and menu choices.
7.Implemented billing logic that computes the subtotal, discount per item and the final payable amount.
8.Tested all menus with sample data (kinderjoy, chips, door_mat, bottels) and verified the bill by hand calculation.


7.1 Functions used
Function	Purpose
main()	Home menu: Admin, Purchase Items or Exit. Re-displays itself on invalid input.
check() / admincheck()	Asks for the admin password and compares it with the stored password using strcmp(); repeats until correct.
admin()	Admin menu: update a product, view items, create a new product list, delete a product, or exit.
userarea()	Customer menu: view products, open the cart, view the bill, or exit.
usercart() / adds()	Adds a chosen product and quantity to the cart after validating stock; reduces the stock count.
userorder()	Shows the cart with the running total; lets the customer confirm or remove an item (stock is restored on removal).
userbill()	Prints the final bill, applies per-product discounts, and takes the payment decision.
7.2 Admin module
From the home menu the admin chooses option 1 and enters the password. After a correct login the admin menu appears with five options:
•Create new product list (3): enter how many products (1–20), then name, unit price, quantity and discount (0–100%) for each.
•View items (2): displays all products in a formatted table.
•Update the list (1): select a product number and enter its new name, price and quantity.
•Delete product (4): choose a product number, confirm, and the remaining products shift up to fill the gap.
•Exit (5): returns to the home menu.
7.3 Customer module
The customer chooses option 2 on the home menu and gets four options: view products, cart, bills and exit.
•In the product view the customer selects a product number and quantity. The quantity is validated against available stock, the stock is reduced, and the item is stored in the cart.
•In the cart view every selected item is listed with its price, quantity and discount, along with the running total. The customer can confirm the items or remove one; removing restores the stock.
•In the bill view the program prints each item, calculates the subtotal and the total discount, and shows the final amount to pay. Choosing 1 (Yes) simulates redirection to UPI payment and ends the program; choosing 2 cancels and returns to the main menu.
7.4 Billing formula
Item cost = Unit price × Quantity;   Item discount = Item cost × (Discount % ÷ 100)
Final payable = Σ (Item cost) − Σ (Item discount)

8.5 Observations
The bill was verified manually against the program output:(TESTED DATA)
Product	Unit Price	Qty	Discount	Cost after discount
kinderjoy	80	3	0%	240.00
door_mat	180	2	5%	342.00
bottels	120	2	10%	216.00
Total payable				798.00
Subtotal = 240 + 360 + 240 = 840. Total discount = 0 + 18 + 24 = 42. Final payable = 840 − 42 = 798.00, which matches the program output exactly.
•Stock was reduced correctly when items were added to the cart.
•Wrong passwords, invalid menu choices and out-of-range product numbers were rejected with a message.
•The cart screen shows the total before discount (840); the discount is applied on the final bill (798.00).
9. Conclusion
This project gave practical experience in building a complete menu-driven application in C. I learned how to organise a program into functions, use arrays and strings to store records, validate user input, handle stock updates and implement billing and discount calculations. The program works as a basic grocery store system for both the shop owner and the customer.
Limitations and future scope: data is stored only in memory and is lost when the program exits; the admin password is hard-coded; the menus call functions recursively. In future the system can be improved with file handling or a database for permanent storage, encrypted/changeable passwords, multiple customer accounts, loops instead of recursion, and real payment integration.
