#include <stdio.h>
#include <stdlib.h>
//functions used
void printMainMenu(int *seatInfoA, int *seatInfoB, int *seatInfoC, int *seatInfoD, int *ticketPricesA, int *ticketPricesB, int *ticketPricesC, int *ticketPricesD);

void printSeatInformation(int *seatInfoA, int *seatInfoB, int *seatInfoC, int *seatInfoD);
void printTicketPrices(int *ticketPricesA, int *ticketPricesB, int *ticketPricesC, int *ticketPricesD);
void printTickets(int *seatInfoA, int *seatInfoB, int *seatInfoC, int *seatInfoD);
void printCashInfo();
int seatControl(int seatInfo, int numberOfSold);
void updatePrices(int *ticketPricesA, int *ticketPricesB, int *ticketPricesC, int *ticketPricesD);
void sell(int *seatInfoA, int *seatInfoB, int *seatInfoC, int *seatInfoD, int *ticketPricesA, int *ticketPricesB, int *ticketPricesC, int *ticketPricesD);
int CalculateBill(int ticketPrice, int numberOfSold);


int cash = 0;
int running = 1;

int main()
{
    int seatInfoA = 40;
    int seatInfoB = 40;
    int seatInfoC = 40;
    int seatInfoD = 40;

    int ticketPricesA = 100;
    int ticketPricesB = 80;
    int ticketPricesC = 60;
    int ticketPricesD = 40;

    int choice;
    while (running)
    {
        printMainMenu(&seatInfoA, &seatInfoB, &seatInfoC, &seatInfoD, &ticketPricesA, &ticketPricesB, &ticketPricesC, &ticketPricesD);
    }
}

void printMainMenu(int *seatInfoA, int *seatInfoB, int *seatInfoC, int *seatInfoD, int *ticketPricesA, int *ticketPricesB, int *ticketPricesC, int *ticketPricesD)
//we define this function above because we return it from other functions
{
    int choice;
    int cash = 0;
    printf("\n---------------\n");
    printf("OPERATIONS:\n");
    printf("---------------\n");
    printf("1. Seat Info\n");
    printf("2. Update Prices\n");
    printf("3. Sell a ticket\n");
    printf("4. Current cash info\n");
    printf("5. Quit\n");
    printf("Select your operation: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        printf("**************************************\n");
        printSeatInformation(seatInfoA, seatInfoB, seatInfoC, seatInfoD);
        printf("\n");
        printTicketPrices(ticketPricesA, ticketPricesB, ticketPricesC, ticketPricesD);
        printf("**************************************\n");

        printf("\n");
    }
    else if (choice == 2)
    {
        updatePrices(ticketPricesA, ticketPricesB, ticketPricesC, ticketPricesD);
    }
    else if (choice == 3)
    {
        printf("**************************************\n");
        printSeatInformation(seatInfoA, seatInfoB, seatInfoC, seatInfoD);
        printf("\n");
        printTicketPrices(ticketPricesA, ticketPricesB, ticketPricesC, ticketPricesD);
        printf("**************************************\n");
        sell(seatInfoA, seatInfoB, seatInfoC, seatInfoD, ticketPricesA, ticketPricesB, ticketPricesC, ticketPricesD);
        printf("\n");
        printf("**************************************\n");
        printSeatInformation(seatInfoA, seatInfoB, seatInfoC, seatInfoD);
        printf("**************************************\n");
        printf("\n---------------\n");
        printf("OPERATIONS:\n");
        printf("---------------\n");
        printf("1. Continue to sell a ticket\n");
        printf("2. Return to main menu\n");
        int subChoice;
        printf("Select your operation : ");
        scanf("%d", &subChoice);
        if (subChoice == 1)
        {
            printf("**************************************\n");
            printSeatInformation(seatInfoA, seatInfoB, seatInfoC, seatInfoD);
            printf("\n");
            printTicketPrices(ticketPricesA, ticketPricesB, ticketPricesC, ticketPricesD);
            printf("**************************************\n");
            sell(seatInfoA, seatInfoB, seatInfoC, seatInfoD, ticketPricesA, ticketPricesB, ticketPricesC, ticketPricesD);
            printf("\n");
            printf("**************************************\n");
            printSeatInformation(seatInfoA, seatInfoB, seatInfoC, seatInfoD);
            printf("**************************************\n");
        }
        else if (subChoice == 2)
        {
        }
    }
    else if (choice == 4)
    {
        printf("**************************************\n");
        printCashInfo();
        printf("**************************************\n");
    }
    else if (choice == 5)
    {
        printf("\n");
        printCashInfo();
        printf("Bye!\n");
        running = 0;
    }
}

void printSeatInformation(int *seatInfoA, int *seatInfoB, int *seatInfoC, int *seatInfoD)
//this function tells us the current seats
{
    printf("Current Seat Information :\n");
    printf("\t\t\tLevel A : %d\n", *seatInfoA);
    printf("\t\t\tLevel B : %d\n", *seatInfoB);
    printf("\t\t\tLevel C : %d\n", *seatInfoC);
    printf("\t\t\tLevel D : %d\n", *seatInfoD);
}

void printTicketPrices(int *ticketPricesA, int *ticketPricesB, int *ticketPricesC, int *ticketPricesD)
//this function tells us the current prices
{
    printf("Current Price Information :\n");
    printf("\t\t\tLevel A : %d\n", *ticketPricesA);
    printf("\t\t\tLevel B : %d\n", *ticketPricesB);
    printf("\t\t\tLevel C : %d\n", *ticketPricesC);
    printf("\t\t\tLevel D : %d\n", *ticketPricesD);
}

void sell(int *seatInfoA, int *seatInfoB, int *seatInfoC, int *seatInfoD, int *ticketPricesA, int *ticketPricesB, int *ticketPricesC, int *ticketPricesD)
// level selection (a,b,c,d)
{
    char level;
    printf("Select level : ");
    scanf(" %c", &level);
    if (level == 'A' || level == 'a')
    {
        int countTicket;
        printf("Enter number of tickets for level A seat : ");
        scanf("%d", &countTicket);
        if (seatControl(*seatInfoA, countTicket))
        {
            printf("%d Seats from Level A is sold\n", countTicket);
            int bill = CalculateBill(*ticketPricesA, countTicket);
            *seatInfoA -= countTicket;
            cash += bill;
            printf("Your bill is %d*%d=%d TL", countTicket, *ticketPricesA, bill);
        }
        else
        {
            printf("There is no enough seat for this level\n");
        }
    }
    else if (level == 'B' || level == 'b')
    {
        int countTicket;
        printf("Enter number of tickets for level B seat : ");
        scanf("%d", &countTicket);
        if (seatControl(*seatInfoB, countTicket))
        {
            printf("%d Seats from Level B is sold\n", countTicket);
            int bill = CalculateBill(*ticketPricesB, countTicket);
            *seatInfoB -= countTicket;
            cash += bill;
            printf("Your bill is %d*%d=%d TL", countTicket, *ticketPricesB, bill);
        }
        else
        {
            printf("There is no enough seat for this level\n");
        }
    }
    else if (level == 'C' || level == 'c')
    {
        int countTicket;
        printf("Enter number of tickets for level C seat : ");
        scanf("%d", &countTicket);
        if (seatControl(*seatInfoC, countTicket))
        {
            printf("%d Seats from Level A is sold\n", countTicket);
            int bill = CalculateBill(*ticketPricesC, countTicket);
            *seatInfoC -= countTicket;
            cash += bill;
            printf("Your bill is %d*%d=%d TL", countTicket, *ticketPricesC, bill);
        }
        else
        {
            printf("There is no enough seat for this level\n");
        }
    }
    else if (level == 'D' || level == 'd')
    {
        int countTicket;
        printf("Enter number of tickets for level D seat : ");
        scanf("%d", &countTicket);
        if (seatControl(*seatInfoD, countTicket))
        {
            printf("%d Seats from Level D is sold\n", countTicket);
            int bill = CalculateBill(*ticketPricesD, countTicket);
            *seatInfoD -= countTicket;
            cash += bill;
            printf("Your bill is %d*%d=%d TL", countTicket, *ticketPricesD, bill);
        }
        else
        {
            printf("There is no enough seat for this level\n");
        }
    }
}

int seatControl(int seatInfo, int numberOfSold)
//Receives two parameters â€œseatInfoâ€ and â€œnumberOfSoldâ€ and controls the stock.
{
    if (seatInfo >= numberOfSold)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void updatePrices(int *ticketPricesA, int *ticketPricesB, int *ticketPricesC, int *ticketPricesD)
// price update
{
    printTicketPrices(ticketPricesA, ticketPricesB, ticketPricesC, ticketPricesD);
    char level;
    printf("Select level to update : ");
    scanf(" %c", &level);
    if (level == 'A' || level == 'a')
    {
        int newPrice;
        printf("Enter new price for Level A :");
        scanf("%d", &newPrice);
        *ticketPricesA = newPrice;
        printf("Level A ticket price is updated to %d", newPrice);
    }
    else if (level == 'B' || level == 'b')
    {
        int newPrice;
        printf("Enter new price for Level B :");
        scanf("%d", &newPrice);
        *ticketPricesB = newPrice;
        printf("Level B ticket price is updated to %d", newPrice);
    }
    else if (level == 'C' || level == 'c')
    {
        int newPrice;
        printf("Enter new price for Level C :");
        scanf("%d", &newPrice);
        *ticketPricesC = newPrice;
        printf("Level C ticket price is updated to %d", newPrice);
    }
    else if (level == 'D' || level == 'd')
    {
        int newPrice;
        printf("Enter new price for Level D :");
        scanf("%d", &newPrice);
        *ticketPricesD = newPrice;
        printf("Level D ticket price is updated to %d", newPrice);
    }
}

int CalculateBill(int ticketPrice, int numberOfSold)
// calculating the invoice amount
{
    return ticketPrice * numberOfSold;
}

void printTickets(int *seatInfoA, int *seatInfoB, int *seatInfoC, int *seatInfoD)
// seat info
{
    printf("Current Seat Information :\n");
    printf("\t\t\tLevel A : %d\n", *seatInfoA);
    printf("\t\t\tLevel B : %d\n", *seatInfoB);
    printf("\t\t\tLevel C : %d\n", *seatInfoC);
    printf("\t\t\tLevel D : %d\n", *seatInfoD);
}
void printCashInfo()
// money earned from the sale
{
    printf("Current cash information : %d TL\n", cash);
    
}


