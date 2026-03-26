#include "ListPerson.h"
#include <iostream>
using namespace std;

int main() {
  // ============================================================
  // Варіант 1: ListPerson — звичайний масив Zodiac
  // ============================================================
  cout << "=== Variant 1: regular Zodiac array ===" << endl;

  ListPerson list1, list2;

  Person p1 = {"Ivanov", "15.03.1990"};
  Person p2 = {"Petrenko", "25.07.1985"};
  Person p3 = {"Shevchenko", "10.12.1975"};

  list1.AddPerson(p1);
  list1.AddPerson(p2);

  list2.AddPerson(p2);
  list2.AddPerson(p3);

  cout << "\nList1:" << endl;
  list1.Print();

  cout << "\nList2:" << endl;
  list2.Print();

  cout << "\nUnion:" << endl;
  ListPerson u = list1.Union(list2);
  u.Print();

  cout << "\nIntersection:" << endl;
  ListPerson i = list1.Intersection(list2);
  i.Print();

  cout << "\nDifference (List1 - List2):" << endl;
  ListPerson d = list1.Difference(list2);
  d.Print();

  cout << "\nZodiac for Petrenko: " << list1.GetZodiac("Petrenko") << endl;

  cout << "\nAfter removing Ivanov from List1:" << endl;
  list1.RemovePerson("Ivanov");
  list1.Print();

  // ============================================================
  // Варіант 2: ListPersonStatic — статичний масив Zodiac
  // ============================================================
  cout << "\n=== Variant 2: static Zodiac array ===" << endl;

  ListPersonStatic slist1, slist2;
  slist1.AddPerson(p1);
  slist1.AddPerson(p2);
  slist2.AddPerson(p2);
  slist2.AddPerson(p3);

  cout << "\nList1:" << endl;
  slist1.Print();

  cout << "\nList2:" << endl;
  slist2.Print();

  cout << "\nUnion:" << endl;
  slist1.Union(slist2).Print();

  cout << "\nIntersection:" << endl;
  slist1.Intersection(slist2).Print();

  cout << "\nDifference (List1 - List2):" << endl;
  slist1.Difference(slist2).Print();

  cout << "\nZodiac for Shevchenko: " << slist2.GetZodiac("Shevchenko") << endl;

  return 0;
}
