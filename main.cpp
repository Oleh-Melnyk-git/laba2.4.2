#include "ListPerson.h"
#include <iostream>
#include <limits>
using namespace std;

void printMenu() {
  cout << "\n========== МЕНЮ ==========" << endl;
  cout << "1. Додати персону до списку 1" << endl;
  cout << "2. Додати персону до списку 2" << endl;
  cout << "3. Видалити персону зі списку 1" << endl;
  cout << "4. Видалити персону зі списку 2" << endl;
  cout << "5. Показати список 1" << endl;
  cout << "6. Показати список 2" << endl;
  cout << "7. Знайти картку за прізвищем (список 1)" << endl;
  cout << "8. Знак зодіаку за прізвищем (список 1)" << endl;
  cout << "9. Об'єднання (Union)" << endl;
  cout << "10. Перетин (Intersection)" << endl;
  cout << "11. Різниця (Difference, Список1 - Список2)" << endl;
  cout << "0. Вийти" << endl;
  cout << "Ваш вибір: ";
}

Person inputPerson() {
  Person p;
  cout << "Введіть прізвище: ";
  cin >> p.surname;
  cout << "Введіть дату народження (DD.MM.YYYY): ";
  cin >> p.birthDate;
  return p;
}

int main() {
  ListPerson list1, list2;
  int choice;

  do {
    printMenu();
    cin >> choice;

    // Якщо введено не число — скидаємо стан потоку
    if (cin.fail()) {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Невірний вибір!" << endl;
      continue;
    }

    switch (choice) {
    case 1: {
      Person p = inputPerson();
      list1.AddPerson(p);
      cout << "Додано до списку 1." << endl;
      break;
    }
    case 2: {
      Person p = inputPerson();
      list2.AddPerson(p);
      cout << "Додано до списку 2." << endl;
      break;
    }
    case 3: {
      string surname;
      cout << "Введіть прізвище для видалення: ";
      cin >> surname;
      list1.RemovePerson(surname);
      cout << "Видалено зі списку 1." << endl;
      break;
    }
    case 4: {
      string surname;
      cout << "Введіть прізвище для видалення: ";
      cin >> surname;
      list2.RemovePerson(surname);
      cout << "Видалено зі списку 2." << endl;
      break;
    }
    case 5:
      cout << "\nСписок 1:" << endl;
      list1.Print();
      break;
    case 6:
      cout << "\nСписок 2:" << endl;
      list2.Print();
      break;
    case 7: {
      string surname;
      cout << "Введіть прізвище: ";
      cin >> surname;
      Person p = list1.GetPerson(surname);
      if (p.surname.empty())
        cout << "Не знайдено." << endl;
      else
        cout << "Знайдено: " << p.surname << " | " << p.birthDate << endl;
      break;
    }
    case 8: {
      string surname;
      cout << "Введіть прізвище: ";
      cin >> surname;
      cout << "Знак зодіаку: " << list1.GetZodiac(surname) << endl;
      break;
    }
    case 9: {
      cout << "\nОб'єднання (Union):" << endl;
      ListPerson u = list1.Union(list2);
      u.Print();
      break;
    }
    case 10: {
      cout << "\nПеретин (Intersection):" << endl;
      ListPerson i = list1.Intersection(list2);
      i.Print();
      break;
    }
    case 11: {
      cout << "\nРізниця (Difference, Список1 - Список2):" << endl;
      ListPerson d = list1.Difference(list2);
      d.Print();
      break;
    }
    case 0:
      cout << "До побачення!" << endl;
      break;
    default:
      cout << "Невірний вибір! Спробуйте ще раз." << endl;
    }

  } while (choice != 0);

  return 0;
}
