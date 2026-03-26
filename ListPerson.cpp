#include "ListPerson.h"

// Варіант 1: ListPerson — звичайний масив Zodiac

void ListPerson::InitZodiacs() {
  zodiacs[CAPRICORN] = {"Capricorn", "22.12", "19.01"};
  zodiacs[AQUARIUS] = {"Aquarius", "20.01", "18.02"};
  zodiacs[PISCES] = {"Pisces", "19.02", "20.03"};
  zodiacs[ARIES] = {"Aries", "21.03", "19.04"};
  zodiacs[TAURUS] = {"Taurus", "20.04", "20.05"};
  zodiacs[GEMINI] = {"Gemini", "21.05", "20.06"};
  zodiacs[CANCER] = {"Cancer", "21.06", "22.07"};
  zodiacs[LEO] = {"Leo", "23.07", "22.08"};
  zodiacs[VIRGO] = {"Virgo", "23.08", "22.09"};
  zodiacs[LIBRA] = {"Libra", "23.09", "22.10"};
  zodiacs[SCORPIO] = {"Scorpio", "23.10", "21.11"};
  zodiacs[SAGITTARIUS] = {"Sagittarius", "22.11", "21.12"};
}

ListPerson::ListPerson() { InitZodiacs(); }
ListPerson::ListPerson(const ListPerson &other) : persons(other.persons) {
  InitZodiacs();
}
ListPerson::~ListPerson() {}

void ListPerson::AddPerson(const Person &p) {
  for (auto &person : persons) {
    if (person.surname == p.surname) {
      cout << "Person with surname " << p.surname << " already exists!" << endl;
      return;
    }
  }
  if (persons.size() < MAX_SIZE) {
    persons.push_back(p);
  } else {
    cout << "List is full!" << endl;
  }
}

void ListPerson::RemovePerson(const string &surname) {
  persons.erase(
      remove_if(persons.begin(), persons.end(),
                [&](const Person &p) { return p.surname == surname; }),
      persons.end());
}

Person ListPerson::GetPerson(const string &surname) const {
  for (auto &p : persons) {
    if (p.surname == surname)
      return p;
  }
  return {"", ""};
}

ListPerson ListPerson::Union(const ListPerson &other) const {
  ListPerson result(*this);
  for (auto &p : other.persons) {
    bool exists = false;
    for (auto &r : result.persons) {
      if (r.surname == p.surname) {
        exists = true;
        break;
      }
    }
    if (!exists)
      result.persons.push_back(p);
  }
  return result;
}

ListPerson ListPerson::Intersection(const ListPerson &other) const {
  ListPerson result;
  for (auto &p : persons) {
    for (auto &o : other.persons) {
      if (p.surname == o.surname)
        result.persons.push_back(p);
    }
  }
  return result;
}

ListPerson ListPerson::Difference(const ListPerson &other) const {
  ListPerson result;
  for (auto &p : persons) {
    bool exists = false;
    for (auto &o : other.persons) {
      if (p.surname == o.surname) {
        exists = true;
        break;
      }
    }
    if (!exists)
      result.persons.push_back(p);
  }
  return result;
}

string ListPerson::GetZodiac(const string &surname) const {
  Person p = GetPerson(surname);
  if (p.surname.empty())
    return "Person not found";

  // Конвертуємо DD.MM → число MMDD для коректного числового порівняння
  auto toMMDD = [](const string &s) -> int {
    return stoi(s.substr(3, 2)) * 100 + stoi(s.substr(0, 2));
  };

  int mmdd = toMMDD(p.birthDate.substr(0, 5));

  for (int i = 0; i < ZODIAC_COUNT; i++) {
    int start = toMMDD(zodiacs[i].startDate);
    int end = toMMDD(zodiacs[i].endDate);
    if (start <= end) {
      if (mmdd >= start && mmdd <= end)
        return zodiacs[i].name;
    } else {
      // Козеріг перетинає межу року (грудень–січень)
      if (mmdd >= start || mmdd <= end)
        return zodiacs[i].name;
    }
  }
  return "Unknown zodiac";
}

void ListPerson::Print() const {
  if (persons.empty()) {
    cout << "  (empty)" << endl;
    return;
  }
  for (auto &p : persons) {
    cout << "  Surname: " << p.surname << ", BirthDate: " << p.birthDate
         << endl;
  }
}

// Варіант 2: ListPersonStatic — статичний масив Zodiac

// Визначення статичних членів
Zodiac ListPersonStatic::zodiacs[ZODIAC_COUNT];
bool ListPersonStatic::zodiacsInited = false;

void ListPersonStatic::InitZodiacs() {
  if (zodiacsInited)
    return; // ініціалізуємо лише один раз
  zodiacs[CAPRICORN] = {"Capricorn", "22.12", "19.01"};
  zodiacs[AQUARIUS] = {"Aquarius", "20.01", "18.02"};
  zodiacs[PISCES] = {"Pisces", "19.02", "20.03"};
  zodiacs[ARIES] = {"Aries", "21.03", "19.04"};
  zodiacs[TAURUS] = {"Taurus", "20.04", "20.05"};
  zodiacs[GEMINI] = {"Gemini", "21.05", "20.06"};
  zodiacs[CANCER] = {"Cancer", "21.06", "22.07"};
  zodiacs[LEO] = {"Leo", "23.07", "22.08"};
  zodiacs[VIRGO] = {"Virgo", "23.08", "22.09"};
  zodiacs[LIBRA] = {"Libra", "23.09", "22.10"};
  zodiacs[SCORPIO] = {"Scorpio", "23.10", "21.11"};
  zodiacs[SAGITTARIUS] = {"Sagittarius", "22.11", "21.12"};
  zodiacsInited = true;
}

ListPersonStatic::ListPersonStatic() { InitZodiacs(); }
ListPersonStatic::ListPersonStatic(const ListPersonStatic &other)
    : persons(other.persons) {
  InitZodiacs();
}
ListPersonStatic::~ListPersonStatic() {}

void ListPersonStatic::AddPerson(const Person &p) {
  for (auto &person : persons) {
    if (person.surname == p.surname) {
      cout << "Person with surname " << p.surname << " already exists!" << endl;
      return;
    }
  }
  if (persons.size() < MAX_SIZE) {
    persons.push_back(p);
  } else {
    cout << "List is full!" << endl;
  }
}

void ListPersonStatic::RemovePerson(const string &surname) {
  persons.erase(
      remove_if(persons.begin(), persons.end(),
                [&](const Person &p) { return p.surname == surname; }),
      persons.end());
}

Person ListPersonStatic::GetPerson(const string &surname) const {
  for (auto &p : persons) {
    if (p.surname == surname)
      return p;
  }
  return {"", ""};
}

ListPersonStatic ListPersonStatic::Union(const ListPersonStatic &other) const {
  ListPersonStatic result(*this);
  for (auto &p : other.persons) {
    bool exists = false;
    for (auto &r : result.persons) {
      if (r.surname == p.surname) {
        exists = true;
        break;
      }
    }
    if (!exists)
      result.persons.push_back(p);
  }
  return result;
}

ListPersonStatic
ListPersonStatic::Intersection(const ListPersonStatic &other) const {
  ListPersonStatic result;
  for (auto &p : persons)
    for (auto &o : other.persons)
      if (p.surname == o.surname)
        result.persons.push_back(p);
  return result;
}

ListPersonStatic
ListPersonStatic::Difference(const ListPersonStatic &other) const {
  ListPersonStatic result;
  for (auto &p : persons) {
    bool exists = false;
    for (auto &o : other.persons)
      if (p.surname == o.surname) {
        exists = true;
        break;
      }
    if (!exists)
      result.persons.push_back(p);
  }
  return result;
}

string ListPersonStatic::GetZodiac(const string &surname) const {
  Person p = GetPerson(surname);
  if (p.surname.empty())
    return "Person not found";

  auto toMMDD = [](const string &s) -> int {
    return stoi(s.substr(3, 2)) * 100 + stoi(s.substr(0, 2));
  };

  int mmdd = toMMDD(p.birthDate.substr(0, 5));

  for (int i = 0; i < ZODIAC_COUNT; i++) {
    int start = toMMDD(zodiacs[i].startDate);
    int end = toMMDD(zodiacs[i].endDate);
    if (start <= end) {
      if (mmdd >= start && mmdd <= end)
        return zodiacs[i].name;
    } else {
      if (mmdd >= start || mmdd <= end)
        return zodiacs[i].name;
    }
  }
  return "Unknown zodiac";
}

void ListPersonStatic::Print() const {
  if (persons.empty()) {
    cout << "  (empty)" << endl;
    return;
  }
  for (auto &p : persons)
    cout << "  Surname: " << p.surname << ", BirthDate: " << p.birthDate
         << endl;
}
