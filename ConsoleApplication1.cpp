#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <string>
#include "Provider.h"
class
Goods



{ protected:
std::string _name_of_goods;
double _price_of_goods;
int _count;
Provider _provider; public:
//Constructors
Goods();
Goods(std::string GoodsName);
Goods(std::string GoodsName, double Price);
Goods(std::string GoodsName, double Price, int Count);
Goods(std::string GoodsName, double Price, int Count, Provider GoodsProvider);
Goods(const Goods& src);
//Destrucrtor
~Goods();
//Getters
std::string GetName() { return _name_of_goods; }
double GetPrice() { return _price_of_goods; }
int GetCount() { return _count; }
Provider GetProvider() { return _provider; }
//Setters
Goods &SetName(std::string GoodsName),
&SetPrice(double Price),
&SetCount(int Count),
&SetProvider(Provider GoodsProvider);
//Methods
void Put(),
PutFull();
std::string alarm();
Goods operator + (Goods& sec),
operator ++ (int), //postfix
&operator ++ (), //prefix
&operator = (const Goods& src); bool operator
== (Goods& sec),
Equals(const Goods& sec),
operator<(Goods& sec), operator>(Goods&
sec);
friend std::ostream & operator << (std::ostream &, Goods); };
#include "Goods.h"
Goods::Goods(const Goods& src)
{
_count = src._count;
_name_of_goods = src._name_of_goods;
_price_of_goods = src._price_of_goods;
}
_provider = src._provider;

Goods::Goods() : Goods("StdName"){}
Goods::Goods(std::string GoodsName) : Goods(GoodsName, 0){}
Goods::Goods(std::string GoodsName, double Price) : Goods(GoodsName, Price, 0){}
Goods::Goods(std::string GoodsName, double Price, int Count) : Goods(GoodsName, Price, Count,
Provider()){}
Goods::Goods(std::string GoodsName, double Price, int Count, Provider GoodsProvider) {
_name_of_goods = GoodsName;
_price_of_goods = Price;


_count = Count;
_provider = GoodsProvider;
}
Goods::~Goods()
{
}
void Goods::Put()
{
std::cout << "" << _name_of_goods << "" << std::endl;
} void
Goods::PutFull()
{ std::cout << "Goods: " << _name_of_goods << " Price: " << _price_of_goods << " Count:
" << _count << " Provider: " << _provider.GetName() << std::endl;
}
std::string Goods::alarm()
{
return _name_of_goods;
}
Goods Goods::operator+(Goods & sec)
{
try
{
if (this->_name_of_goods != sec._name_of_goods)
{
throw std::exception("Not the same goods");
}
Goods temp = *this;
temp._count = this->_count + sec._count;
return temp;
}
catch (std::exception err)
{
std::cerr << err.what() << std::endl;
return *this;
}
}

Goods & Goods::operator=(const Goods & src) {
_name_of_goods = src._name_of_goods;
_price_of_goods = src._price_of_goods;
_count = src._count;
_provider = src._provider;
return *this;
} bool Goods::operator==(Goods & sec)
{
return this->Equals(sec); }
bool Goods::operator>(Goods & sec)


{ return _price_of_goods > sec._price_of_goods; }
bool Goods::operator<(Goods & sec)
{ return _price_of_goods < sec._price_of_goods;
} bool Goods::Equals(const Goods&
sec)
{
if ( this->_name_of_goods == sec._name_of_goods &&
this>_count == sec._count &&
this->_price_of_goods == sec._price_of_goods &&
>_provider.Equals(sec._provider)

this-

)
return true;
}
return false;

Goods & Goods::operator++()
{
_count++;
return *this;
}
Goods Goods::operator++(int)
{
Goods temp = *this;
++*this;
}
return temp;

Goods& Goods::SetName(std::string GoodsName)
{
_name_of_goods = GoodsName;
}
return *this;

Goods& Goods::SetPrice(double Price)
{
_price_of_goods = Price;
return *this;
}
Goods& Goods::SetCount(int Count)
{
_count = Count;
return *this;
}
Goods& Goods::SetProvider(Provider GoodsProvider)
{
_provider = GoodsProvider;
return *this;

8

}
std::ostream & operator << (std::ostream & o, Goods src) {
return o << "<Goods>\nName: " << src._name_of_goods << "\nPrice: " <<
src._price_of_goods << "\nCount: " << src._count << "\nProvider: " << src._provider.GetName()
<< std::endl;
}
#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "Goods.h"
#include <ctime>
class Food :
public Goods
{
time_t _prodDate;
time_t _expirationDate;
public:
Food();
Food(Goods Good);
Food(Goods Good, int day, int month, int year);
Food(Goods Good, int day, int month, int year, int days);
Food(int day, int month, int year);
Food(int day, int month, int year, int days);
Food(std::string GoodsName);
Food(std::string GoodsName, double Price);
Food(std::string GoodsName, double Price, int Count);
Food(std::string GoodsName, double Price, int Count, Provider GoodsProvider);
Food(std::string GoodsName, double Price, int Count, Provider GoodsProvider, int day,
int month, int year);
Food(std::string GoodsName, double Price, int Count, Provider GoodsProvider, int day,
int month, int year, int days);
Food(const Food& src);
~Food();
Food& SetProdDate(int day, int month, int year);
Food& SetExpireDate(int days); time_t makeDate(int
day, int month, int year); time_t
GetProdDate() { return _prodDate; } time_t
GetExpDate() { return _expirationDate; }
std::string alarm();
};
#include "Food.h"
Food::Food() : Food(0, 0, 0)
{
}
Food::Food(Goods Good) : Food(Good, 0, 0, 0) {
}
Food::Food(Goods Good, int day, int month, int year) : Food(Good, day, month, year, 0)
{
}
Food::Food(Goods Good, int day, int month, int year, int days) : Goods(Good) {
_expirationDate = 60 * 60 * 24 * days;
_prodDate = makeDate(day, month, year);
}
Food::Food(int day, int month, int year) : Food(day,month,year, 0) {

9

}
Food::Food(int day, int month, int year, int days) : Goods()
{
_expirationDate = 60 * 60 * 24 * days;
_prodDate = makeDate(day, month, year); }
Food::Food
(
std::string GoodsName
) : Food(GoodsName, 0)
{
}
Food::Food
( std::string GoodsName,
double Price
) : Food(GoodsName, Price, 0)
{
}
Food::Food
(
std::string GoodsName,
double Price,
int Count
) : Food(GoodsName, Price, Count, Provider())
{
}
Food::Food
(
std::string
GoodsName, double Price,
int Count,
Provider GoodsProvider
) : Food(GoodsName, Price, Count, GoodsProvider, 0, 0, 0) {
}
Food::Food
(
std::string
GoodsName, double Price,
int Count,
Provider GoodsProvider,
int day, int
month,
int year
) : Food(GoodsName, Price, Count, GoodsProvider, day, month, year, 0) {
}
Food::Food
(
std::string
GoodsName, double Price,
int Count,
Provider GoodsProvider, int day, int
month, int year, int days
) : Goods(GoodsName, Price, Count, GoodsProvider)

10

{
_expirationDate = 60 * 60 * 24 * days;
}
_prodDate = makeDate(day, month, year);

Food::Food(const Food& src)
{
_name_of_goods = src._name_of_goods;
_count = src._count;
_price_of_goods = src._price_of_goods;
_provider = src._provider;
_expirationDate = src._expirationDate;
}
_prodDate = src._prodDate;

Food::~Food()
{
}
Food& Food::SetProdDate(int day, int month, int year)
{
_prodDate = makeDate(day, month, year);
}
return *this;

Food& Food::SetExpireDate(int days)
{
//std::cout << "Set expire time in days:" << std::endl;
_expirationDate = 60 * 60 * 24 * days;
}
return *this;

time_t Food::makeDate(int day, int month, int year)
{
time_t now;
time(&now);
struct tm *timeinfo = localtime(&now);
timeinfo->tm_year = year - 1900;
timeinfo->tm_mon = month - 1; timeinfo-
>tm_mday = day; return
mktime(timeinfo);
}
std::string Food::alarm()
{ return _prodDate + _expirationDate >= time(0) ? "Goods suitable for consumption" :
"Goods unfit for consumption";
}

11

#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "Goods.h"
#include <map> class
IndustrialGoods :
public Goods
{ private:
std::string _plc[3] = {
"In stock", "Depend on the trading", "On display"
};
std::string _cond[5] = {
"Warning!", "Not cant", "Fragile", "Do not throw", "Hazard"
};
int _conditions;
int _place;
public:
IndustrialGoods();
IndustrialGoods(Goods Good);
IndustrialGoods(Goods Good, int Conditions);
IndustrialGoods(Goods Good, int Conditions, int Place);
IndustrialGoods(int Conditions);
IndustrialGoods(int Conditions, int Place);
IndustrialGoods(std::string GoodsName);
IndustrialGoods(std::string GoodsName, double Price);
IndustrialGoods(std::string GoodsName, double Price, int Count);
IndustrialGoods(std::string GoodsName, double Price, int Count, Provider
GoodsProvider);
IndustrialGoods(std::string GoodsName, double Price, int Count, Provider
GoodsProvider, int Conditions);
IndustrialGoods(std::string GoodsName, double Price, int Count, Provider
GoodsProvider, int Conditions, int Place);
IndustrialGoods(const IndustrialGoods& src);
~IndustrialGoods();
IndustrialGoods& SetConditions(int Conditions);
IndustrialGoods& SetPlace(int Place); std::string
GetConditions() { return _cond[_conditions]; }
std::string GetPlace() { return _plc[_place]; }
std::string alarm(); operator Goods() { return Goods(this->GetName(),
this>GetPrice(), this->GetCount(), this->GetProvider()); }
};
#include "IndustrialGoods.h"
IndustrialGoods::IndustrialGoods() : IndustrialGoods(0) {
}
IndustrialGoods::IndustrialGoods(Goods Good) : IndustrialGoods(Good, 0)
{
}
IndustrialGoods::IndustrialGoods(Goods Good, int Conditions) : IndustrialGoods(Good,
Conditions, 0)
{
}
IndustrialGoods::IndustrialGoods(Goods Good, int Conditions, int Place) : Goods(Good) {
_conditions = Conditions;
_place = Place;
}
IndustrialGoods::IndustrialGoods(int Conditions) : IndustrialGoods(Conditions, 0)
{
}
IndustrialGoods::IndustrialGoods(int Conditions, int plc) : Goods(), _conditions(Conditions),
_place(plc)

12

{
}
IndustrialGoods::IndustrialGoods
(
std::string GoodsName
) : IndustrialGoods(GoodsName, 0.0)
{
}
IndustrialGoods::IndustrialGoods
(
std::string GoodsName,
double Price
) : IndustrialGoods(GoodsName, Price, 0)
{
}
IndustrialGoods::IndustrialGoods
(
std::string GoodsName,
double Price,
int Count
) : IndustrialGoods(GoodsName, Price, Count, Provider())
{
}
IndustrialGoods::IndustrialGoods
(
std::string GoodsName,
double Price,
int Count,
Provider GoodsProvider
) : IndustrialGoods(GoodsName, Price, Count, GoodsProvider, 0) { }
IndustrialGoods::IndustrialGoods
(
std::string GoodsName,
double Price,
int Count,
Provider GoodsProvider,
int Conditions
) : IndustrialGoods(GoodsName, Price, Count, GoodsProvider, Conditions, 0)
{
}
IndustrialGoods::IndustrialGoods
(
std::string GoodsName,
double Price,
int Count,
Provider GoodsProvider,
int Conditions,
int plc
) : Goods(GoodsName, Price, Count, GoodsProvider) {

13

_conditions = Conditions;
_place = plc;
}
IndustrialGoods::IndustrialGoods(const IndustrialGoods& src)
{
_name_of_goods = src._name_of_goods;
_count = src._count;
_price_of_goods = src._price_of_goods;
_provider = src._provider;
_conditions = src._conditions;
}
_place = src._place;

IndustrialGoods::~IndustrialGoods()
{
}
IndustrialGoods& IndustrialGoods::SetConditions(int Conditions) {
//std::cout << "Set Conditions:\n0."<<_cond[0]<<std::endl<< "1." << _cond[1] <<
std::endl << "2." << _cond[2] << std::endl << "3." << _cond[3] << std::endl << "4." <<
_cond[4] << std::endl;
if (Conditions < 0)
Conditions =
0; if (Conditions > 4)
Conditions = 4;
_conditions = Conditions;
return *this;
}
IndustrialGoods& IndustrialGoods::SetPlace(int Place)
{
if (Place < 0)
Place = 0; if
(Place > 2)
Place = 2;
_place = Place;
return *this;
} std::string
IndustrialGoods::alarm()
{
return _cond[_conditions];
}
#pragma once
#include "Goods.h"
class Warehouse
{ public:
Warehouse();
Warehouse(unsigned int length);
Warehouse(unsigned int length, Goods* goods);
~Warehouse(); private: static unsigned
int cnt;
unsigned int _number_of_warehouse;
unsigned int _length;
unsigned int _COUNT_;
Goods* _goods; public:
// Длина массива товаров inline unsigned int length()
{ return _length; } unsigned long long count() { return
_COUNT_; } Goods &operator[] (unsigned int x) { return _goods[x];
}

14

Goods & getGoodsByIndex(unsigned int index) { return _goods[index]; }
Goods* getGoods() { return _goods; } unsigned int getWarehouseNumber()
{ return _number_of_warehouse; }
Warehouse & setLength(unsigned int length);
Warehouse & setGoods(Goods* goods_to_insert, unsigned int
length_of_array); Warehouse & addGoods(Goods* goods_to_insert, unsigned int
length_of_array); friend std::ostream & operator << (std::ostream &o, Warehouse
src); };
#include "Warehouse.h"
#include <array>
#include <locale>
unsigned int Warehouse::cnt = 1;
Warehouse::Warehouse() : Warehouse(0){}
Warehouse::Warehouse(unsigned int length)
{
setLength(length);
_number_of_warehouse = cnt++;
}
Warehouse::Warehouse(unsigned int length, Goods* goods)
{
setLength(length);
setGoods(goods, length);
}
_number_of_warehouse = cnt++;

Warehouse::~Warehouse(){}

Warehouse & Warehouse::setLength(unsigned int length) {
_COUNT_ = length;
return *this;
}

Warehouse & Warehouse::setGoods(Goods* goods_to_insert, unsigned int length_of_array)
{
try
{
_leng

15

th = length_of_a
rray;
delet
e[] _goods;
_goods = new Goods[_length];
for (; length_of_array > 0; length_of_array--)
{
_goods[_length - length_of_array] = goods_to_insert[_length - length_of_array];
}
}
catch (std::exception e)
{
std::cerr << e.what() << std::endl;
}
return *this;
}
Warehouse& Warehouse::addGoods(Goods* goods_to_insert, unsigned int length_of_array)
{
try
{
_length += length_of_array;
delete[] _goods;
_goods = new Goods[_length]; for (unsigned long long index =
_length - length_of_array; index < _length;
index++)
{
_goods[index] = goods_to_insert[index];
}
}
catch (std::exception e)
{
std::cerr << e.what() << std::endl;
}
return *this;
}
std::ostream& operator<<(std::ostream& o, Warehouse src)
{
o << "<Warehouse>"
<< "\nNumber: " << src._number_of_warehouse
<< "\nCount of goods: " << src._length
<< "\nCapacity: " << src._COUNT_
<< "\nGoods:\n[\n";
for (unsigned long long index = 0; index < src._length; index++)
{
o << "{" << src._goods[index] << "}" << std::endl;
}
o <<"]"<< std::endl;
} return o;

#include "Provider.h"
#include "Goods.h"
#include "Food.h"
#include "IndustrialGoods.h"
#include<windows.h>
#include "Warehouse.h"

16

using namespace std;
int main()
{
SetConsoleCP(1251);
SetConsoleOutputCP(1251);
Warehouse WR1(3), WR2(2);
Provider prov = Provider("Macdonalds", "Ukraine", "+380777777777");
cout << prov;
Goods g("fri", 100500, 33333, prov);
IndustrialGoods *IG = new IndustrialGoods(g, 4, 2);
Goods &G = *IG; cout << "\nvirtual func\n" <<
IG->alarm() << "\n\n";
cout << "g: "; g.Put();
g.PutFull(); cout
<< "Postfix ";
(g++).PutFull(); cout
<< "After postfix ";
g.PutFull(); cout
<< "Prefix ";
(++g).PutFull();
Goods g1("burger", 100500, 2222, prov);
cout << "g1: ";
g1.PutFull();
Goods g2("chicken", 100, 2, prov);
cout << "g2: ";
g2.PutFull();
Goods* ga = new Goods[3];
ga[0] = g;
ga[1] = g1;
ga[2] = g2;
Goods* gb = new Goods[2];
gb[0] = g2; gb[1] = g1;
WR1.addGoods(ga, 3);
WR2.addGoods(gb, 2);
cout << "Equal plus (g+g1)
";
(g + g1).PutFull();
cout << "Not equal plus (g+g2) ";
(g = g + g2).PutFull(); cout
<< "g > g2 "; cout << (g > g2)
<< endl; cout << "g == g1 ";
cout << (g == g1) << endl;
cout << WR1 << endl; cout
<< WR2 << endl;
system("pause");
}
