

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
void check(char pass[10]);
void admincheck(char pass[10]);
void admin(void);
void userarea(void);
void usercart(void);
void userorder(void);
void userbill(void);
void adds(void);

int total = 0;
char enter[5];
char productname[20][20], copyproductname[20][20]; 
int unitprice[20], quantityleft[20], copyquantityleft[20], copyunitprice[20];
int n = 0, i, num ; double save;
int discount[20], copydiscount[20];
int newarr[20] ; 



int main()
{
   printf("\n------------WELCOME TO THE GROCERY STORE--------------\n");
   printf("\nchoose the option - : 1). ADMIN  2.)PURCHASE ITEMS  3.)EXIT\n");
   printf("ENTER CHOICE - :");
   if(scanf(" %d", &num) != 1) return 0;
   
   if(num == 1)
   {
     char pass[10];          
     check(pass);
   }
   else if(num == 2)
   {
     userarea();
   }
   else if(num == 3)
   {
     exit(0);
   }
   else
   {
      printf("invalid\n");
      main();
   }
   return 0;
}
void check(char pass[10])
{
    printf("----------ADMIN LOGIN---------\n");
    printf("enter the password\n");
    scanf("%9s", pass);
    admincheck(pass);
}

void admincheck(char pass[10])
{
    const char passwordset[] = "srm123";
    if(strcmp(passwordset, pass) == 0)
    {
        admin();
    }
    else
    {
        printf("invalid password try again\n");
        printf("\n");
        check(pass);
    }
}

void admin()
{
    int number;     
      printf("-----------------WELCOME ADMIN !!!!-:-------------\n");
   printf("\n1) - UPDATE THE LIST  , 2) - VIEW ITEMS , 3)- CREATE NEW PRODUCT LIST , 4)- DELETE THE PREVIOUS LIST PRODUCT , 5)- EXIT\n");
   printf("ENTER CHOICE  - :");
    scanf(" %d", &number) ;
    if(number == 3)
    {
       printf("enter the number of products\n");
       scanf("%d", &n);
       if(n >= 1 && n <= 20)
       {
            printf("ENTER THE NAME PRICE AND THE QUANTITY OF %d PRODUCT - : \n ", n);
            for(i = 0; i < n; i++)
            {
                printf("ENTER THE %dst PRODUCT INFO - :\n" , i+1);
                printf(" Product Name -:"); scanf("%s", productname[i]);
                printf("UnitPrice -:"); scanf("%d", &unitprice[i]);
                printf("Add Quantity (+) - :") ; scanf("%d", &quantityleft[i]);
                printf("Discount On this Product (0-100%c) - " , '%') ; scanf("%d", &discount[i]);
                printf("\n");
                copyquantityleft[i] = quantityleft[i];
                
            }
            printf("\n the product saved !!\n");
            admin();
       }
       else                 
       {
            printf("invalid number of products (1 to 20)\n");
            n = 0;
            admin();
       }
    }
    if(number == 2)
    {
         if(n==0)
         {
            printf("No PRODUCT ADDED BY YOU !!");
            printf("\n");
           admin(); 
         }
         else{
        printf("The product stored is - :\n\n"); 
        printf("%-20s %-12s %-10s %-10s\n", "PRODUCT NAME", "UNIT PRICE", "QUANTITY", "DISCOUNT");
        printf("----------------------------------------------------\n");

        for(int i = 0; i < n; i++)
        {
        
            printf("%-20s %-12d %-10d %-10d\n", productname[i], unitprice[i], quantityleft[i], discount[i]);
        }
    
        admin();
    }
    }
    if(number == 1)
    {
        if(n == 0)
        {
            printf("\n Empty Product list  - ADD SOME PRODUCT \n");
            printf("\n");
            admin();        
        }
        else
        {
            for (int i = 0; i < n; i++) {
                printf("%d.) %s | Price: %d | Available: %d\n", 
                       i + 1, productname[i], unitprice[i], quantityleft[i]);
            }
            int choice;
            printf("\nEnter the product number you want to update (1 to %d): ", n);
            scanf("%d", &choice);
            int idx = choice - 1; 

            if (idx >= 0 && idx < n) {
                printf("\nUpdating details for: %s\n", productname[idx]);
                
                printf("Enter NEW product name: ");
                scanf("%s", productname[idx]);
                
                printf("Enter NEW unit price: ");
                scanf("%d", &unitprice[idx]);
                
                printf("Enter NEW quantity available: ");
                scanf("%d", &quantityleft[idx]);
                
                printf("\nProduct updated successfully!\n");
            } else {
                printf("Invalid Section GO AWAY\n");
            }
            admin();
        }
    }
    if(number==4)
    {  int remove;
        int tell;
         printf("PRODUCT REMOVAL MENUE  - :\n\n"); 
        printf("%-20s %-12s %-10s %-10s\n", "PRODUCT NAME", "UNIT PRICE", "QUANTITY", "DISCOUNT");
        printf("----------------------------------------------------\n");
        for(int i =0 ; i<n ; i++)
        {
            printf("%-20s %-12d %-10d %-10d\n", productname[i], unitprice[i], quantityleft[i], discount[i]);
        }
        printf("\n");
        printf("WHAT PRODUCT YOU WANT TO REMOVE - :");
        scanf("%d" , &remove);
        if(remove < 1 || remove > n)
{
    printf("Invalid product number\n");
    admin();
    
}
        int loop = remove-1;
       for(int i = loop ; i<remove ; i++)
       {
         printf("SELECTED PRODUCT -: %s\n" , productname[i]);
         printf("are you sure want to remove this product - : 1.) YES / 2.) NO\n");
         scanf("%d" , &tell);
         if(tell==1)
         {
               
           for(int j = i; j < n-1; j++)
    {
        strcpy(productname[j], productname[j+1]);
        unitprice[j]        = unitprice[j+1];
        quantityleft[j]     = quantityleft[j+1];
        copyquantityleft[j] = copyquantityleft[j+1];
        discount[j]         = discount[j+1];
        strcpy(copyproductname[j], copyproductname[j+1]);
        copyunitprice[j]    = copyunitprice[j+1];
        copydiscount[j]     = copydiscount[j+1];
        newarr[j]           = newarr[j+1];
    }
    n--;
    printf("\nPRODUCT REMOVED SUCCESSFULLY\n");
    admin();
         }
         else if(tell==2)
         {
            printf("PRODUCT REMOVAL CANCEL");
            admin();

         }
       }

    }
    if(number == 5)
    {
        main();
    }
    else{
        printf("invalid choice \n");
        admin();
    }
  

}

void userarea()
{  
    
   int k , pick;
   printf("\n-------WELCOME TO THE GROCERY STORE USER ID - 01001001 --------\n");
   printf("\n1.)PRODUCT AVAILABILITY VIEW  2.)CART 3.)BILLS  4.)EXIT\n");
   printf("Choose the option - :");
  scanf(" %d", &k);
   if(k == 1)
   {
    if(n==0)
    {
    
        printf("NO PRODUCT AVILABLE IN THE STORE \n");
        userarea();
    }
    else{
        printf("\n-------PRODUCT AVILABLE AREA-------\n");
        printf("%-20s %-12s %-10s %-10s\n", "PRODUCT NAME", "UNIT PRICE", "QUANTITY", "DISCOUNT");
        printf("--------------------------------------------------\n");

        for(int i = 0; i < n; i++)
        {
        
            printf("%-20s %-12d %-10d %-10d\n", productname[i], unitprice[i], quantityleft[i], discount[i]);
        }
        printf("want to Proceed with Buying product -: 1)yes / press any key to exit ?\n");
            scanf("%d" , &pick);
            if(pick==1)
            {
        usercart();
            }
            else{
                main();
            }
        }
   }
   if(k == 4)
   {
        main();
   }
   if(k == 2)
   {
     if(n==0)
     {
        printf("NO PRODUCT ADDED IN CART :( ");
        printf("\n");
        main();
     }
     else{
        userorder();
     }
   }
   if(k==3)
   {
   
    userbill();
   }
   else
   {
    printf("invalid input \n");
    userarea();
   }
   
}

void usercart()
{ 
    int select, quantity; 
    char choice;
    printf("\nWhich product you want to ADD TO CART - ?\n");
    scanf("%d", &select);
    int cart1 = select - 1;

    if(cart1 >= 0 && cart1 < n)
    {
        for(int i = cart1; i < select; i++)
        {
            strcpy(copyproductname[i], productname[cart1]);  
            copyunitprice[i] = unitprice[i]; 
            copydiscount[i] = discount[i];
            printf("\nselected  product = %s\n", productname[cart1]);
         
            if(quantityleft[i] != 0)
            {
                do {
                    printf("select the quantity (max %d) = ", quantityleft[i]);
                    scanf("%d", &quantity);
                    if(quantity < 1 || quantity > quantityleft[i])
                        printf("Not enough stock! Only %d available.\n", quantityleft[i]);
                } while(quantity < 1 || quantity > quantityleft[i]);
                quantityleft[i] = quantityleft[i] - quantity;
                newarr[i] = copyquantityleft[i] - quantityleft[i]; 
                printf("\n");
                printf("%d %s Added to cart ", quantity, productname[cart1]);
            } 
            else if(quantityleft[i] == 0)
            {
                printf("%s is out of stock  come back tomorrow !!", productname[cart1]);
            }                       
            printf("\n");

            printf("ADD MORE(+) / EXIT(1)");
            scanf(" %c", &choice);
            switch(choice)
            {
                case '+':
                    usercart();
                    break;
                case '1':
                    userarea();
                    break;
                default:
                    printf("invalid");
                    adds();
                    break;
            } 
        }
    }
}

void adds()
{   
    char choice;
    printf("ADD MORE(+) / EXIT(1)");
    scanf(" %c", &choice);
    switch(choice)
    {
        case '+':
            usercart();
            break;
        case '1':
            userarea();
            break;
        default:
            printf("invalid");
            adds();
            break;
    }
}

void userorder()
{
    char ch;
    int rem, items = 0;

    printf("\n---------YOUR ORDER CART----------\n");
    printf("%-5s %-20s %-12s %-10s %-10s\n", "NO.", "PRODUCT NAME", "UNIT PRICE", "QUANTITY", "DISCOUNT");
    printf("--------------------------------------------------------\n");

    total = 0;
    for(int i = 0; i < n; i++)
    {
        if (newarr[i] == 0) continue;
        items++;
        printf("%-5d %-20s %-12d %-10d %-10d\n", i + 1, copyproductname[i],
               copyunitprice[i], newarr[i], copydiscount[i]);
        total = total + copyunitprice[i] * newarr[i];
    }

    if(items == 0)
    {
        printf("YOUR CART IS EMPTY\n");
        userarea();
        return;
    }

    printf("TOTAL AMMOUNT - :%d\n", total);
    printf("\nPROCEED WITH BILLING ? - 1.) CONFIRM THE ITEMS / (-) TO REMOVE AN ITEM : ");
    scanf(" %c", &ch);

    if(ch == '1')
    {
        userbill();
    }
    else if(ch == '-')
    {
        printf("Enter the NO. of the product to remove from cart : ");
        scanf("%d", &rem);

        if(rem >= 1 && rem <= n && newarr[rem - 1] > 0)
        {
            quantityleft[rem - 1] += newarr[rem - 1];   
            newarr[rem - 1] = 0;                       
            printf("%s removed from cart.\n", copyproductname[rem - 1]);
        }
        else
        {
            printf("Invalid product number or item not in cart.\n");
        }
        userorder();   
    }
    else
    {
        printf("invalid choice\n");
        userorder();
    }
}

void userbill()
{  
int empty = 1;               
for(int i = 0; i < n; i++)
{
    if(newarr[i] != 0) { empty = 0; break; }
}
if(empty)
{
  printf("YOU HAVE NOT SELECTED ANY ITEMS - NOTHING TO BILL \n");
  printf("\n");
  userarea();

  }
  else
  {
double total_discount = 0.0;
total = 0; 
int x;
 printf("\n---------------YOUR FINAL BILL-----------------\n");
    printf("%-20s %-12s %-10s %-10s\n", "PRODUCT NAME", "UNIT PRICE", "QUANTITY", "DISCOUNT");
    printf("--------------------------------------------------\n");

for(int i = 0; i < n; i++)
{
    if (newarr[i] == 0) continue; 
     

    printf("%-20s %-12d %-10d %-10d\n", copyproductname[i], copyunitprice[i], newarr[i], copydiscount[i]);
    
    int item_cost = copyunitprice[i] * newarr[i];
    total = total + item_cost;
    
   
    double item_discount = item_cost * (copydiscount[i] / 100.0);
    total_discount = total_discount + item_discount;
}

double final_payable = total - total_discount;
printf("\n");
printf("SUBTOTAL  = :%d\n", total);
printf(" SUBTOTAL AFTER DISCOUNT = : %.2lf\n", final_payable);
printf("TOTAL AMMOUNT TO PAY - :%.2lf\n" , final_payable);
printf("\n");
printf("PAY  - 1) YES / 2) NO\n");
scanf("%d"  , &x);
if(x==1)
{
    printf("Redirecting to UPI.....");
    printf("THANKS USER COME AGAIN :) SYSTEM WILL REMEMBER YOU !!!");
    exit(0);
}
if(x==2)
{
    printf("cancelled...Redirecting to main menue...");
    printf("\n");
    main();
}

  }
}
