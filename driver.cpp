//Lesley Amezcua
//Athena Raya
//Louis Romero
//Dario Molina

#include <iostream>
#include <cstring>
#include <cctype> // toupper()
#include <cassert>

using namespace std;

char menu( );
double climbing();
double scuba();
double skyDive();
double spelunk();

int main()
{
    char userChoice, loopController = 'Y';
        
    while(loopController == 'Y')
    {
        cout << endl;
        cout << "Welcome to the High Travel Agency Program" << endl;
        cout << "Which vacation would you like to go on?" << endl;
        cout << endl;
        menu();
        cin >> userChoice;
        
          switch(userChoice)
          {
              case '1':
                  cout << "Price of trip will be $" << climbing() << endl;
                  cout << endl;
                  break;
              case '2':
                  cout << "Price of trip will be $" << scuba();
                  cout << endl;
                  break;
              case '3':
                  cout << "Price of trip will be $" << skyDive();
                  cout << endl;
                  break;
              case '4':
                  cout << "Price of trip will be $" << spelunk();
                  cout << endl;
                  break;
              default:
                  cout << "Invalid Input" << endl;
                  cout << endl;
        }
        
    cout << "Would you like to check the price of another trip?" << endl;
    cout << "Press Y to continue or any key to terminate" << endl;
    cin >>loopController;
    loopController = toupper(loopController);
    }
    cout << "Thank you for using our program!" << endl;
    return 0;
}
char menu()
{   
    cout << "Select your desired choice by keying in the corresponding number and pressing Enter." << endl;
    cout << endl;
    cout << "1. Devil's Courthouse Adventure Weekend" << endl;
    cout << "2. Scuba Bahama" << endl;
    cout << "3. Sky Dive Colorado" << endl;
    cout << "4. Barron Cliff Spelunk" << endl;
    cout << endl;
}
double climbing()
{
    const double baseChargePerPerson = 350.00;
    const double climbingInstructionCost = 100.00;
    const double equipmentRentalCharge = 40.00;
    const double percentDiscount = 0.10;
    const double numberOfDays = 3.0;
    double needInstruction, needEquipment, numPeople;
    double baseChargePrice, instructionCharge, equipmentRentalPrice, totalPrice, daysEquipmentNeeded;
    
    cout << "How many people are going climbing?" << endl;
    cin >> numPeople;
    
    if (numPeople < 0)
    {
        return 0.00;
    }
    
    else
    {
        if( numPeople < 5)//If less than 5 people no discount for that group
        {
            baseChargePrice = numPeople * baseChargePerPerson;//Price of base charge for group smaller than 5 people
        }
        else//Else they get a 10 % discount
        {
            baseChargePrice = numPeople * baseChargePerPerson;
            baseChargePrice = baseChargePrice - (baseChargePrice * percentDiscount);//Price of base charge for group greater than 5 people
        }
        
        cout << "How many people need instruction: "  << endl;
        cin >> needInstruction;
        cout << "How many people need to rent equipment: " << endl;
        cin >> needEquipment;
        
        instructionCharge = climbingInstructionCost * needInstruction;
        equipmentRentalPrice = needEquipment * equipmentRentalCharge * numberOfDays;
        
        totalPrice = baseChargePrice + instructionCharge + equipmentRentalPrice;
        return totalPrice;
    }
 
}
double scuba()
{
  double  baseCharge, people, discount;
  double totalCost = 0; 
  double peopleLessons, scubaCharge;
  string answer;
  
  while (true)// keeps repeating making sure user enters info desired.
  {
    cout << " Hello, how many people will be attending Scuba Bahama?\n";
    cin >> people;
    
    if ( people <= 0)
    {
      continue;
    }
    
    cout << "Would you like scuba lessons? Type yes or no.\n";
    cin >> answer;
    
    
     baseCharge = 1000 * people;// calculating basecharge
     
    
    if (answer == "yes")// conditional step to see if they want lessons
     {
       cout << " How many people will be getting lessons?\n";
       cin >> peopleLessons;
       
       scubaCharge = 100 * peopleLessons;
       
       totalCost = baseCharge + scubaCharge;// calculating totalCost
       
       if (people >= 5)// checking to see if user gets a discount
       {
         discount = totalCost * .10;
         totalCost = totalCost - discount;
         
         return totalCost;
       
       }
       
       return totalCost;
     }
  
    if ( answer == "no")// if they dont want scuba lessons
    {
        if (people >= 5)// make sure they get discount if they meet criteria
       {
         discount = baseCharge * .10;
         baseCharge = baseCharge - discount;
         
         return baseCharge;
       
       }
       
       return baseCharge;
    
    }
  
  }

}
double skyDive()
{
   double  baseCharge, people, discount;
  double totalCost = 0; 
  double wildernessLodge, luxuryInn, cost;
  string answer;
  
  while (true)//make sure user enters only the information desired
  {
    cout << " Hello, how many people are attending Sky Dive Colorado?\n";
    cin >> people;
    
    if( people <= 0)
    {
      continue;
    }
    
    baseCharge = 700 * people;// calculating base charge
    
    cout << "Would you like to stay at the Wilderness Lodge or at the Luxury Inn hotel? Type in w or l for respective hotel.\n"
    "  If you dont want to stay at a hotel please press any other key.\n";
    cin >> answer;// check if they want to stay at a hotel

    
    if (answer == "w")// if they choose Wilder hotel do the mathd
     {
       cout << " How many people are staying at the Wilderness Lodge  hotel?\n";
       cin >> wildernessLodge;
       
       cost = 65 * wildernessLodge; // cost of attending this hotel
       
       totalCost = baseCharge + cost;// total cost of the event
       
       if( people >= 5)// check if they get  discount
       {
         discount = totalCost * .10;
         
         totalCost = totalCost - discount;
         
         return totalCost;
       }
       
       return totalCost;
     }
  
    else if ( answer == "l")// if they choose the Luxury hotel
    {
      
      cout << " How many people are staying at the Luxury Inn hotel?\n";
       cin >> luxuryInn;
       
       cost = 120 * luxuryInn;// cost of staying at hotel
       
        totalCost = baseCharge + cost;// total cost of event including hotel
        
        if( people >= 5) // check to see if they qualify for discount
        {
          discount = totalCost * .10;
          
          totalCost = totalCost - discount;
          
          return totalCost;
        
        }
    
       return totalCost;
    }
    
    else// if they dont want to stay from either hotels
     {
      if( people >= 5)// check to see if they qualify for discount
      {
        discount = baseCharge * .10;
        
        baseCharge = baseCharge - discount;
        
        return baseCharge;
      
      }
      
       return baseCharge;// no discount return total cost
     } 
    }

}
double spelunk()
{
    const double baseChargePerPerson = 700.00;
    const double equipRental = 40.00;
    const double discount = 0.10;
    const double daysSpent = 8.0;
    
    double needEquip, numOfPeople;
    double baseCharge, equipPrice, totalCost;
    
    cout << " How many people are in your party ? " << endl;
    cin >> numOfPeople;
    if( numOfPeople < 5 )
    {
        baseCharge = (numOfPeople * baseChargePerPerson);
    }
    else
    {
        baseCharge = (numOfPeople * baseChargePerPerson);
        baseCharge = baseCharge -(baseCharge * discount);
    }
    
    cout << " How many people will be needing rental equiment ? " << endl;
    cin >> needEquip;
    needEquip = (needEquip * daysSpent) * equipRental;
    
    totalCost = baseCharge + needEquip;
    return totalCost;

}
