#include <iostream>
#include <cmath>
using namespace std;
int china(bool, bool, bool, int);
int turkey(bool, bool, bool, int);
int UAE(bool, bool, bool, int);
int USA(bool, bool, bool, int);
char country, type;
double weight, price;
int main ()
{
    int remainder = 0;
    int floored;
    bool firstKg = false;
    bool secondKg = false;
    bool decimal = false;
    cin >> country >> weight >> price >> type;

    if ((country != 'c' && country != 'C' && country != 'E' && country != 'e' && country != 't' && country != 'T' && country != 's' && country != 'S') || weight <= 0 || price <= 0)
      cout << "invalid";
      else {
    weight *= 10;
    floored = floor(weight);
    if (floored % 10 >=1 && floored % 10 <= 9 && weight >= 10){
      decimal = true;
    }
    if (floored / 10 >= 2) {
        firstKg = true;
        secondKg = true;
        remainder = (floored / 10) - 2;
      }
    else if (floored / 10 >= 1) {
      firstKg = true;
      remainder = (floored / 10) - 1;
    }
  int customsFees = 0;
  bool tobacco = type == 't' || type == 'T';
    
  if(!tobacco && price > 0 && price <= 50)
    customsFees = 5;
  else if (!tobacco && price > 50 && price <= 200)
    customsFees = price * 0.1;
  else if(!tobacco && price > 200)
    customsFees = price * 0.2;
  else customsFees = price * 1.5;

  if (country == 'c' || country == 'C')
  cout << china(decimal, firstKg, secondKg, remainder)<<endl<<customsFees;
  else if (country == 'E' || country == 'e')
  cout << UAE(decimal, firstKg, secondKg, remainder)<<endl<<customsFees;
  else if (country == 'T' || country == 't')
  cout << turkey(decimal, firstKg, secondKg, remainder)<<endl<<customsFees;
  else if (country == 'S' || country == 's')
  cout << USA(decimal, firstKg, secondKg, remainder)<<endl<<customsFees;

    return 0;
      }
}
int china(bool decimal, bool firstKg, bool secondKg, int remainder){
  int shippingFees = 0;
  
  if(firstKg)
    shippingFees += 8;
  if(secondKg)
    shippingFees += 10;
  shippingFees += remainder * 12;
  if (weight < 10)
    shippingFees += 8;
  else if(decimal)
    shippingFees += 12;
return shippingFees;
}
int turkey(bool decimal, bool firstKg, bool secondKg, int remainder){
  int shippingFees = 0;
  if(firstKg)
    shippingFees += 5;
  if(secondKg)
    shippingFees += 8;
  shippingFees += remainder * 10;
  if (weight < 10)
    shippingFees += 5;
  else if(decimal)
    shippingFees += 10;
return shippingFees;
}
int UAE(bool decimal, bool firstKg, bool secondKg, int remainder){
  int shippingFees = 0;
  if(firstKg)
    shippingFees += 3;
  if(secondKg)
    shippingFees += 5;
  shippingFees += remainder * 8;
  if (weight < 10)
    shippingFees += 3;
  else if(decimal)
    shippingFees += 8;
return shippingFees;
}
int USA(bool decimal, bool firstKg, bool secondKg, int remainder){
  int shippingFees = 0;
  if(firstKg)
    shippingFees += 12;
  if(secondKg)
    shippingFees += 18;
  shippingFees += remainder * 22;
  if (weight < 10)
    shippingFees += 12;
  else if(decimal)
    shippingFees += 22;
return shippingFees;
}