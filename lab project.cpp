# include <iostream>
# include <fstream>
# include <string>
using namespace std;
int ID;
struct store{
	int id;
	string name;
	int weight;
	int mfg;
	int exp;
	int price;
	int quantity;
};
void additems()
{
	fstream ofile;
	ofile.open("items.txt",ios::app);
	store store;
	cout << "Enter product id " << endl;
	cin >> store.id;
	cout << "Enter product name" << endl;
	cin.get();
	getline(cin,store.name);
	cout << "Enter Weight of the product" << endl;
	cin >> store.weight;
	cout << "Enter mfg date of the product" << endl;
	cin >> store.mfg;
	cout << "Enter exp date of the product" << endl;
	cin >> store.exp;
	cout << "Enter the price of the product" << endl;
	cin >> store.price;
	cout << "Enter Quantity of product you want to store" << endl;
	cin >> store.quantity;
    ID++;
	ofile << store.id << endl;
	ofile << store.name << endl;
	ofile << store.weight << endl;
	ofile << store.mfg << endl;
	ofile << store.exp << endl;
	ofile << store.price << endl;
	ofile << store.quantity << endl;
	ofile.close();
	ofile.open("id.txt");
	ofile << ID << endl;
	ofile.close();
}  
void read()
{
	store store;
	fstream newfile;
	newfile.open("items.txt");
	newfile>>store.id;
	newfile.ignore();
	getline(newfile,store.name);
	newfile >> store.weight;
	newfile >> store.mfg;
	newfile >> store.exp;
	newfile >> store.price;
	newfile >> store.quantity;
	while(!newfile.eof())
	{
	cout << "Product id = " << store.id << endl;
	cout << "Product Name = " << store.name << endl;
	cout << "weight = " << store.weight << endl;
	cout << "Mfg Date = " << store.mfg << endl;
	cout << "Exp Date = " << store.exp << endl;
	cout << "Price = " << store.price << endl;
	cout << "Quantity = " << store.quantity << endl;
	newfile>>store.id;
	newfile.ignore();
	getline(newfile,store.name);
	newfile >> store.weight;
	newfile >> store.mfg;
	newfile >> store.exp;
	newfile >> store.price;
	newfile >> store.quantity;
	}
	newfile.close();
}
int search()
{
	int id;
	cout << "Enter the product id you want to search/delete/update" << endl;
	cin >> id;
	store store;
	ifstream newfile;
	newfile.open("items.txt");
	newfile>>store.id;
	newfile.ignore();
	getline(newfile,store.name);
	newfile >> store.weight;
	newfile >> store.mfg;
	newfile >> store.exp;
	newfile >> store.price;
	newfile >> store.quantity;
	while(!newfile.eof())
	{
		if (store.id==id)
		{
			cout << "Product id = " << store.id << endl;
	cout << "Product Name = " << store.name << endl;
	cout << "weight = " << store.weight << endl;
	cout << "Mfg Date = " << store.mfg << endl;
	cout << "Exp Date = " << store.exp << endl;
	cout << "Price = " << store.price << endl;
	cout << "Quantity = " << store.quantity << endl;
			return id;
			}
		newfile>>store.id;
	newfile.ignore();
	getline(newfile,store.name);
	newfile >> store.weight;
	newfile >> store.mfg;
	newfile >> store.exp;
	newfile >> store.price;
	newfile >> store.quantity;
	}
}
void search_price_quantity()
{
	int id;
	cout << "Enter the product id you want to search for price and quantity" << endl;
	cin >> id;
	store store;
	ifstream newfile;
	newfile.open("items.txt");
	newfile>>store.id;
	newfile.ignore();
	getline(newfile,store.name);
	newfile >> store.weight;
	newfile >> store.mfg;
	newfile >> store.exp;
	newfile >> store.price;
	newfile >> store.quantity;
	while(!newfile.eof())
	{
		if (store.id==id)
		{
			cout << "Price = " << store.price << endl;
			cout << "Quantity = " << store.quantity << endl;
			break;
			}
		newfile>>store.id;
	newfile.ignore();
	getline(newfile,store.name);
	newfile >> store.weight;
	newfile >> store.mfg;
	newfile >> store.exp;
	newfile >> store.price;
	newfile >> store.quantity;
	}
}
void delete_item()
{
	int id=search();
	cout << "Do you want to delete an item (y/n)" << endl;
	char choice;
	cin >> choice;
	if (choice=='y')
	{
		store store;
		ofstream temp;
		temp.open("temp.txt");
		ifstream newfile;
		newfile.open("items.txt");
		newfile>>store.id;
	newfile.ignore();
	getline(newfile,store.name);
	newfile >> store.weight;
	newfile >> store.mfg;
	newfile >> store.exp;
	newfile >> store.price;
	newfile >> store.quantity;
	while(!newfile.eof())
	{
		if (id!=store.id)
		{
			temp << store.id << endl;
	temp << store.name << endl;
	temp << store.weight << endl;
	temp << store.mfg << endl;
	temp << store.exp << endl;
	temp << store.price << endl;
	temp << store.quantity << endl;
		}
		newfile>>store.id;
	newfile.ignore();
	getline(newfile,store.name);
	newfile >> store.weight;
	newfile >> store.mfg;
	newfile >> store.exp;
	newfile >> store.price;
	newfile >> store.quantity;
    }
	newfile.close();
	temp.close();
	remove("items.txt");
	rename("temp.txt","items.txt");
	cout << "Data deleted sucessfully" << endl;
	}
}
void update()
{
	int id=search();
	cout << "Do you want to update an item (y/n)" << endl;
	char choice;
	cin >> choice;
	if (choice=='y')
	{
		store newdata;
		cout << "Enter product id " << endl;
		cin >> newdata.id;
	cout << "Enter product name" << endl;
	cin.get();
	getline(cin,newdata.name);
	cout << "Enter Weight of the product" << endl;
	cin >> newdata.weight;
	cout << "Enter mfg date of the product" << endl;
	cin >> newdata.mfg;
	cout << "Enter exp date of the product" << endl;
	cin >> newdata.exp;
	cout << "Enter the price of the product" << endl;
	cin >> newdata.price;
	cout << "Enter Quantity of product you want to store" << endl;
	cin >> newdata.quantity;
		store store;
		ofstream ofile;
		ofile.open("temp.txt");
		ifstream newfile;
		newfile.open("items.txt");
		newfile>>store.id;
	newfile.ignore();
	getline(newfile,store.name);
	newfile >> store.weight;
	newfile >> store.mfg;
	newfile >> store.exp;
	newfile >> store.price;
	newfile >> store.quantity;
	while(!newfile.eof())
	{
		if (store.id==id)
		{
			ofile << store.id << endl;
	ofile << store.name << endl;
	ofile << store.weight << endl;
	ofile << store.mfg << endl;
	ofile << store.exp << endl;
	newfile >> store.price;
	ofile << store.quantity << endl;
	break;
			}
		else{
			ofile<<newdata.id<<endl;
			ofile<<newdata.name<<endl;
			ofile<<newdata.weight<<endl;
			ofile<<newdata.mfg<<endl;
			ofile<<newdata.exp<<endl;
			ofile<<newdata.price<<endl;
			ofile<<newdata.quantity<<endl;
			break;
		}
		newfile>>store.id;
	newfile.ignore();
	getline(newfile,store.name);
	newfile >> store.weight;
	newfile >> store.mfg;
	newfile >> store.exp;
	newfile >> store.price;
	newfile >> store.quantity;
    }
	newfile.close();
	ofile.close();
	remove("items.txt");
	rename("temp.txt","items.txt");
	cout << "Data updated sucessfully" << endl;
	}
}
void bill()
{
	store store;
	int number,n,v;
	string name;
    int id[20]={1001,1002,1003,1004,1005,1006,1007,1008,1009,1010/*,1011,1012,1013,1014,1015,1016,1017,1018,1019,1020*/};
	int price[20]={15,25,10,1000,2000,500,20,100,200,180/*,230,30,100,300,30,120,380,450,200,700*/};
	int total=0;
	char ask;
	cout << "How many items you want to purchase" << endl;
	cin >> v;
	for (int i=0;i<v;i++)
	{
		cout << "Enter the product id of an item you want to purchase" << endl;
		cin >> number;
		cout << "Enter the name of the product" << endl;
		cin >> name;
	switch(number)
	{
	case 1001:
		cout << "Enter the quantity you want to buy" << endl;
		cin >> n;
		total+=price[0]*n;
		break;
	case 1002:
		cout << "Enter the quantity you want to buy" << endl;
		cin >> n;
		total+=price[1]*n;
		break;
	case 1003:
		cout << "Enter the quantity you want to buy" << endl;
		cin >> n;
		total+=price[2]*n;
		break;
	case 1004:
		cout << "Enter the quantity you want to buy" << endl;
		cin >> n;
		total+=price[3]*n;
		break;
	case 1005:
		cout << "Enter the quantity you want to buy" << endl;
		cin >> n;
		total+=price[4]*n;
		break;
	case 1006:
		cout << "Enter the quantity you want to buy" << endl;
		cin >> n;
		total+=price[5]*n;
		break;
	case 1007:
		cout << "Enter the quantity you want to buy" << endl;
		cin >> n;
		total+=price[6]*n;
		break;
	case 1008:
		cout << "Enter the quantity you want to buy" << endl;
		cin >> n;
		total+=price[7]*n;
		break;
	case 1009:
		cout << "Enter the quantity you want to buy" << endl;
		cin >> n;
		total+=price[8]*n;
		break;
	case 1010:
		cout << "Enter the quantity you want to buy" << endl;
		cin >> n;
		total+=price[9]*n;
		break;
	}
	}
	cout << "**********************************************************" << endl;
	cout << "                          BILL                            " << endl;
	cout << "**********************************************************" << endl;
	cout << number << '\t' << name << '\t' <<  n << '\t' << endl;
	cout << "Your Bill is = "<< total << endl;
	ifstream newfie;
	ofstream ofile;
	ofile.open("Bill.txt");
	ofile << "**********************************************************" << endl;
	ofile << "                          BILL                            " << endl;
	ofile << "**********************************************************" << endl;
	ofile << number << '\t' << name << '\t' <<  n << '\t' << endl;
	ofile << "Your Bill is = "<< total << endl;
	ofile.close();
}
int main ()
{
	int n,z=0;
	fstream newfile;
   fstream ofile;
   newfile.open("items.txt",ios::in);
	while(z!=-1)
	{
	cout << "**********************************************************" << endl;
	cout << "           Grocery Store Managment System                 " << endl;
	cout << "**********************************************************" << endl;
	cout << "1. to get the information about items for owner" << endl;
	cout << "2. Add Items" << endl;	
	cout << "3. Delete Item" << endl;
	cout << "4. Search an Item" << endl;
	cout << "5. Search Price and Quantity of an Item" << endl;
	cout << "6. Update an Item" << endl;
	cout << "7. Bill" << endl;
	cin >> n;
	fstream newfile;
   fstream ofile;
    newfile.open("items.txt",ios::in);
	if (n==1)
	{
		read();
	}
	else if (n==2)
	{
		 additems();
	}
	else if (n==3)
	{
		delete_item();
	}
	else if (n==4)
	{
		search();
	}
	else if (n==5)
	{
		search_price_quantity();
	}
	else if (n==6)
	{
		update();
	}
	else if (n==7)
	{
		bill();
	}
	cout << "Press -1 to exit or Press any other key to continue" << endl;
	cin >> z;
	}
	exit(0);
	system("pause");
   return 0;
}