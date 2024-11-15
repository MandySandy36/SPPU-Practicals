#include <iostream>
#include <map>
#include<string>
using namespace std;
int main()
{	string ch;
    map < string, long int > state;
    state = 
    {
    	{
      		"Andhra Pradesh",49577103
        },
    	{
    		"Assam", 31205576
    	},
    	{
    		"Arunachal Pradesh",1383727
    	},
    	{
    		"Bihar",104099452
    	},
    	{
    		"Chhattisgarh", 25545198
    	},
    	{
      		"Goa", 1458545
    	},
    	{
      		"Gujarat",60439692
    	},
    	{
      		"Haryana",25351462
    	},
    	{
      		"Himachal Pradesh", 6864602
    	},
    	{
      		"Jharkhand",32988134
    	},
    	{
      		"Karnataka",61095297
    	},
    	{
      		"Kerala",33406061
    	},
    	{
      		"Madhya Pradesh",72626809
    	},
    	{
      		"Maharashtra",112374333
    	},
    	{
      		"Manipur",2570390
    	},
        {
      		"Meghalaya",2966889
    	},
    	{
      		"Mizoram",1097206
    	},
    	{
      		"Nagaland",1978502
    	},
    	{
      		"Odisha",41974219
    	},
    	{
      			"Punjab",27743338
    	},
    	{
      		"Rajasthan",68548437
    	},
    	{
      		"Sikkim",610577
    	},
    	{
      		"Tamil Nadu",72147030
    	},
    	{
      		"Telangana",35003674
    	},
    	{
      		"Tripura",3673917
    	},
    	{
      		"Uttarakhand",10086292
    	},
    	{
      		"Uttar Pradesh",199812341
    	},
    	{
      		"West Bengal",91276115
    	},
  	};
    cout << "Enter State (in capital camel case e.g-'Tamil Nadu')" << endl;
  	cin >> ch;
  	cout << "Population of " << ch << " is " << state[ch] << endl;
    return 0;
}
