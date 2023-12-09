#include <iostream>
#include <string>
using namespace std;

class DateType {
public:
    int day;
    int month;
    int year;

    DateType(int d, int m, int y) : day(d), month(m), year(y) {}

    ostream& operator<<(ostream& os) const {
        os << day << "/" << month << "/" << year;
        return os;
    }
};

class PersonType {
public:
    string first_name;
    string last_name;
    string date_birth;
    int age;

    PersonType(const string& first, const string& last, const string& dob, int age)
        : first_name(first), last_name(last), date_birth(dob), age(age) {}
};

class DoctorType : public PersonType {
public:
    string speciality;

    DoctorType(const string& first, const string& last, const string& spec)
        : PersonType(first, last, "", 0), speciality(spec) {}

    ostream& operator<<(ostream& os) const {
        os << first_name << " " << last_name << " (" << speciality << ")";
        return os;
    }
};

class BillType {
public:
    int patient_ID;
    float hosp_cost;
    float med_cost;
    float doct_cost;
    float room_cost;

    BillType(int id, float hosp, float med, float doct, float room)
        : patient_ID(id), hosp_cost(hosp), med_cost(med), doct_cost(doct), room_cost(room) {}
};

class PatientType : public PersonType {
public:
    int patient_ID;
    DateType patient_dob;
    DateType admit_date;
    DateType discharge_date;
    DoctorType phys_name;
    BillType patient_bill;

    PatientType(const string& first, const string& last, int id, int age, const DateType& dob,
                const DateType& adm, const DateType& disch, const DoctorType& doctor, const BillType& bill)
        : PersonType(first, last, "", age), patient_ID(id), patient_dob(dob),
          admit_date(adm), discharge_date(disch), phys_name(doctor), patient_bill(bill) {}

    void display() const {
        cout << "Name: " << first_name << " " << last_name << endl;
        cout << "ID: " << patient_ID << endl;
        cout << "Age: " << age << endl;
        cout << "Date of Birth: ";
        patient_dob.operator<<(cout);
        cout << endl;
        cout << "Admit Date: ";
        admit_date.operator<<(cout);
        cout << endl;
        cout << "Discharge Date: ";
        discharge_date.operator<<(cout);
        cout << endl;
        cout << "Attending Physician: ";
        phys_name.operator<<(cout);
        cout << endl<<endl;
        displayBill();
    }

    void displayBill() const {
        cout << "Bill Information:" << endl;
        cout << "Hospital Cost: $" << patient_bill.hosp_cost << endl;
        cout << "Medication Cost: $" << patient_bill.med_cost << endl;
        cout << "Doctor's Fee: $" << patient_bill.doct_cost << endl;
        cout << "Room Cost: $" << patient_bill.room_cost << endl;
    }
};

int main() {
    // Data Pasien Pertama
    DateType dob1(4, 4, 2004);
    DateType admit_date1(14, 11, 2023);
    DateType discharge_date1(20, 11, 2023);

    DoctorType doctor1("Johny", "Sins", "Teeth");

    BillType bill1(9108, 240.56, 48.95, 78.95, 870.99);

    PatientType patient1("Azka", "Atqia", 9108, 18, dob1, admit_date1, discharge_date1, doctor1, bill1);

    // Data Pasien Kedua
    DateType dob2(28, 2, 2005);
    DateType admit_date2(15, 11, 2023);
    DateType discharge_date2(25, 11, 2023);

    DoctorType doctor2("Dion", "Hibatullah", "Orthopedic");

    BillType bill2(9109, 300.00, 75.50, 120.75, 1200.00);

    PatientType patient2("Bisma", "Misbahudin", 9109, 19, dob2, admit_date2, discharge_date2, doctor2, bill2);

    // Menampilkan Informasi Pasien Pertama
    cout << "\n--------------------------------\n\n";
    
    patient1.display();

    cout << "\n--------------------------------\n\n";

    // Menampilkan Informasi Pasien Kedua
    patient2.display();

return 0;
}