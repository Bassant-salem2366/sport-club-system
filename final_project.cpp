#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include "User_2.h"
#include "admin.h"
#include "HealthTracker.h"
#include "Member.h"
#include "SportSystem.h"
#include "Membership.h"
#include "UI.h"
#include "FileManager.h"
#include "ApplicationManager.h"
using namespace std;

Member::Member() {
    id = 0;
    name = "";
    sport = "";
}

USER_2::USER_2(string Uusername, string password, int id) {
    this->Uusername = Uusername;
    this->password = password;
    this->id = id;
}

bool USER_2::login(string Uusername, string password) {
    return (this->Uusername == Uusername && this->password == password);
}

void USER_2::logout() {
    cout << "\nUser " << Uusername << " logged out." << endl;
}

void USER_2::setUusername(string Uusername) {
    this->Uusername = Uusername;
}

void USER_2::setPassword(string password) {
    this->password = password;
    cout << "Password updated successfully!" << endl;
}

void USER_2::setId(int id) {
    this->id = id;
}

string USER_2::getUusername() const {
    return Uusername;
}

string USER_2::getPassword() const {
    return password;
}

int USER_2::getId() const {
    return id;
}

void USER_2::displayinfo() const {
    cout << "Username: " << Uusername << endl;
    cout << "ID: " << id << endl;
}

USER_2::~USER_2() {
}
Admin::Admin() : USER_2() {}

Admin::Admin(string username, string password, int id) : USER_2(username, password, id) {}

void Admin::ADDmember(int id, string username, string password) {
    USER_2 newUser(username, password, id);
    members.push_back(newUser);
    cout << "Member added successfully." << endl;
}

void Admin::DeleteMember(int id) {
    bool found = false;
    for (int i = 0; i < (int)members.size(); i++) {
        if (members[i].getId() == id) {
            members.erase(members.begin() + i);
            found = true;
            break;
        }
    }
    if (found) {
        cout << "Member deleted successfully." << endl;
    }
    else {
        cout << "Member not found." << endl;
    }
}

void Admin::viewallMembers() const {
    if (members.empty()) {
        cout << "No members found." << endl;
    }
    else {
        for (const auto& member : members) {
            member.displayinfo();
            cout << "==========================" << endl;
        }
    }
}

void Admin::DisplayAdminInfo() const {
    cout << "===== Admin Information =====" << endl;
    cout << "ID: " << getId() << endl;
    cout << "Username: " << getUusername() << endl;
}


Membership::Membership() {
    status = "Inactive";
    startDate = "Not Set";
    endDate = "Not Set";
    planType = "Basic";
}

Membership::Membership(string pType, string sDate, string eDate, string stat) {
    planType = pType;
    startDate = sDate;
    endDate = eDate;
    status = stat;
}

string Membership::getStatus() {
    return status;
}
void Membership::setStat(string stat) {
    status = stat;
}
string Membership::getStartDate() {
    return startDate;
}
void Membership::setStartDate(string date) {
    startDate = date;
}
string Membership::getEndDate() {
    return endDate;
}
void Membership::setEndDate(string date) {
    endDate = date;
}
string Membership::getPlanType() {
    return planType;
}
void Membership::setPlanType(string type) {
    planType = type;
}
void Membership::setStatus(string newStatus) {
    status = newStatus;
}

#include <string>

string Membership::displayStatus() {
    string details = "";

    details += " Membership Details: \n";
    details += "Plan Type: " + planType + "\n";
    details += "Status: " + status + "\n";
    details += "Start Date: " + startDate + "\n";
    details += "End Date: " + endDate + "\n";
    details += "---------------------------\n";

    return details;
}

string Membership::DisplayBenefits(string stat) {
    if (stat == "standard" || stat == "Standard" || stat == "STANDARD") {
        return standard;
    }
    else if (stat == "gold" || stat == "Gold" || stat == "GOLD") {
        return gold;
    }
    else if (stat == "vip" || stat == "VIP" || stat == "Vip") {
        return VIP;
    }
    else {
        return invalid;
    }
}


double height;
double weight;
double BMI;
string BMIstat;
string invalid_health = "invalid please try again!";

double BMIcalc(double h, double w) {
    height = h;
    weight = w;
    BMI = weight / (height * height);
    return BMI;
}

string ShowStat(double bmi) {
    BMI = bmi;
    if (BMI < 18.5) {
        BMIstat = "your BMI is underweight";
        return BMIstat;
    }
    else if (BMI >= 18.5 && BMI <= 24.9) {
        BMIstat = "your BMI is fit";
        return BMIstat;
    }
    else if (BMI > 24.9 && BMI <= 29.9) {
        BMIstat = "your BMI is overweight";
        return BMIstat;
    }
    else {
        BMIstat = "your BMI is obese";
        return BMIstat;
    }
}


string tips(string stat) {
    BMIstat = stat;
    string display;
    if (BMIstat == "underweight") {
        display = "Here are some tips based on you current BMI: \n Add Healthy Calories: Increase daily intake by 300-500 calories through nutrient-dense foods like nuts, seeds, avocados, and dairy \n Eat Frequently : Aim for five to six smaller, nutritious meals throughout the day rather than three large ones. \nStrength Training : Focus on lifting weights or resistance training to build muscle mass, which helps gain weight healthily.\nConsult a Professional : Speak with a doctor or dietitian to rule out underlying health conditions.";
        return display;
    }
    else if (BMIstat == "fit") {
        display = "Here are some tips based on you current BMI: \n Balanced Diet: Consume a variety of whole grains, vegetables, fruits, and lean proteins.\n Consistent Activity : Continue with at least 150 minutes of moderate - intensity exercise per week.\n Mindful Eating : Focus on portion control and pay attention to hunger cues, avoiding eating while distracted.\n Monitor Trends : Keep an eye on your weight and waist circumference to catch significant changes early. ";
        return display;
    }
    else if (BMIstat == "overweight") {
        display = "Here are some tips based on you current BMI: \n Gradual Weight Loss: Aim to lose 1-2 lbs (0.5-1 kg) per week.\n Reduce Hidden Sugars : Limit sugary drinks, pasta sauces, salad dressings, and processed snacks.\n Increase Movement : Add more activity into your daily routine, such as taking the stairs or walking more, aiming for at least 30 minutes of activity on most days.\n Portion Management : Use smaller plates and pay attention to food labels, focusing on high - fiber foods to increase fullness";
        return display;
    }
    else if (BMIstat == "obese") {
        display = "Here are some tips based on you current BMI: \n Seek Support: Utilize healthcare professionals, dietitians, or support groups to create a personalized, sustainable plan.\n  Set Small, Specific Goals : Aim for a 10 % reduction in body weight initially, as this can deliver significant health benefits.\n Behavioral Changes : Focus on changing habits, such as keeping a food diary to track eating patterns.\n  Avoid Crash Diets : Ignore :quick fix diets, which are unsustainable, and focus on sustainable, long - term diet and activity changes";
        return display;
    }
    else {
        return invalid_health;
    }
}

double HealthTracker::calculateBMI(double weight, double height) {
    return weight / (height * height);
}

string HealthTracker::evaluateProgress(double currentBMI, double lastBMI) {
    double diff = currentBMI - lastBMI;
    string feedback;
    if (diff == 0) {
        feedback = "Feedback: Your BMI hasn't changed since last time.";
        return feedback;
    }
    else if (lastBMI > 24.9) {
        if (diff < 0) {
            feedback = "Feedback: Great job! Your BMI is decreasing towards a healthier range.";
            return feedback;
        }
        else {
            feedback = "Feedback: Your BMI increased. Let's review your diet and exercise plan.";
            return feedback;
        }
    }
    else if (lastBMI < 18.5) {
        if (diff > 0) {
            feedback = "Feedback: Excellent progress! You are gaining healthy weight.";
            return feedback;
        }
        else {
            feedback = "Feedback: Your BMI decreased. Make sure you are eating enough calories!";
            return feedback;
        }
    }
    else {
        if (currentBMI >= 18.5 && currentBMI <= 24.9) {
            feedback = "Feedback: Perfect! You are maintaining a healthy BMI.";
            return feedback;
        }
        else {
            feedback = "Feedback: Your BMI moved out of the healthy range. Let's get back on track!";
            return feedback;
        }
    }
}

string HealthTracker::trackUserHealth(string name, double weight, double height) {
    string filename = name + "_health.txt";
    double currentBMI = calculateBMI(weight, height);
    double lastBMI = 0.0;
    string status;
    ifstream inFile(filename);
    if (inFile.is_open()) {
        inFile >> lastBMI;
        inFile.close();
        ofstream outFile(filename);
        outFile << currentBMI;
        outFile.close();
        status = evaluateProgress(currentBMI, lastBMI);
        return status;
    }
    else {
        ofstream outFile(filename);
        outFile << currentBMI;
        outFile.close();
        if (currentBMI >= 18.5 && currentBMI <= 24.9) {
            status = "Welcome! This is your first health log. Status: You are starting at a healthy weight.";
            return status;
        }
        else if (currentBMI < 18.5) {
            status = "Welcome! This is your first health log. Status: You are currently underweight.";
            return status;
        }
        else {
            status = "Welcome! This is your first health log. Status: You are currently overweight.";
            return status;
        }
    }
}
string SportSystem::suggestSport() {
    string sports[] = { "Football", "Swimming", "Gym", "Running", "Yoga" };
    int size = 5;
    int index = rand() % size;
    return sports[index];
}
string SportSystem::assignSport(Member& m) {
    if (m.sport == "") {
        m.sport = suggestSport();
        return "Suggested sport for " + m.name + ": " + m.sport;
    }
    else {
        return m.name + " already has a sport: " + m.sport;
    }
}
string SportSystem::changeSport(Member& m, string newSport) {
    m.sport = newSport;
    return "Sport updated successfully for " + m.name;
}
string SportSystem::showSport(Member& m) {
    if (m.sport == "")
        return m.name + " has no sport assigned.";
    else
        return m.name + "'s sport: " + m.sport;
}



int UI::MainMenu() {
    int choice;
    cout << "\n===== Welcome to the Sport Club System =====" << endl;
    cout << "1. Admin" << endl;
    cout << "2. User" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}
void UI::LoginMenu(string& username, string& password, string& type) {
    int typeChoice;
    cout << "\n===== Login =====" << endl;
    cout << "Login as:" << endl;
    cout << "1. Admin" << endl;
    cout << "2. User" << endl;
    cout << "Enter choice: ";
    cin >> typeChoice;
    type = (typeChoice == 2) ? "user" : "admin";

    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;
}
void UI::PrintMessage(const string& msg) {
    cout << "\n[NOTIFICATION] " << msg << endl;
}
void UI::ShowProfile(const Member& m) {
    cout << "\n===== Member Profile =====" << endl;
    cout << "ID    : " << m.id << endl;
    cout << "Name  : " << m.name << endl;
    cout << "Sport : " << (m.sport.empty() ? "Not assigned" : m.sport) << endl;
    cout << "==========================" << endl;
}
void UI::ShowHealthReport(const string& name, double weight, double height) {
    HealthTracker ht;
    double bmi = ht.calculateBMI(weight, height);
    string progress = ht.trackUserHealth(name, weight, height);
    cout << "\n===== Health Report for " << name << " =====" << endl;
    cout << "Weight : " << weight << " kg" << endl;
    cout << "Height : " << height << " m" << endl;
    cout << "BMI    : " << bmi << endl;
    cout << "Status : " << ShowStat(bmi) << endl;
    cout << "Progress: " << progress << endl;
    cout << "==========================" << endl;
}



int main() {
    srand(time(0));
    ApplicationManager app;
    app.startSystem();

    Member m;
    SportSystem s;
    Membership membership;
    HealthTracker ht;
    int choice;

    do {
        cout << "\n===== System Menu =====" << endl;
        cout << "1. Admin" << endl;
        cout << "2. User" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;


        switch (choice) {
        case 1: {
            string adminUsername, adminPassword;
            cout << "\n===== Admin Login =====" << endl;
            cout << "Enter admin username: ";
            cin >> adminUsername;
            cout << "Enter admin password: ";
            cin >> adminPassword;

            if (app.loginAdmin(adminUsername, adminPassword)) {
                cout << "\nAdmin login successful!" << endl;
                int adminChoice;
                do {
                    cout << "\n===== Admin Menu =====" << endl;
                    cout << "1. Add Member" << endl;
                    cout << "2. Delete Member" << endl;
                    cout << "3. View All Members" << endl;
                    cout << "4. Display Admin Info" << endl;
                    cout << "5. Exit" << endl;
                    cout << "Enter choice: ";
                    cin >> adminChoice;


                    switch (adminChoice) {
                    case 1: {
                        int id; string username, password;
                        cout << "Enter ID: ";
                        cin >> id;
                        cout << "Enter Username: ";
                        cin >> username;
                        cout << "Enter Password: ";
                        cin >> password;
                        app.getAdmin().ADDmember(id, username, password);


                        FileManager::saveMembers(app.getAdmin().members);
                        break;
                    }
                    case 2: {
                        int id;
                        cout << "Enter member ID to delete: ";
                        cin >> id;
                        app.getAdmin().DeleteMember(id);
                        FileManager::saveMembers(app.getAdmin().members);
                        break;
                    }
                    case 3:
                        app.getAdmin().viewallMembers();
                        break;
                    case 4:
                        app.getAdmin().DisplayAdminInfo();
                        break;
                    case 5:
                        cout << "Exiting Admin Menu..." << endl;
                        app.logout();
                        break;
                    default:
                        cout << "Invalid choice!" << endl;
                    }
                } while (adminChoice != 5);
            }
            else {
                cout << "\nAdmin login failed!" << endl;
            }
            break;
        }
        case 2: {
            string username, password;
            cout << "\n===== Login =====" << endl;
            cout << "Enter username: "; cin >> username;
            cout << "Enter password: "; cin >> password;


            USER_2* found = app.loginUser(username, password);

            if (found != nullptr) {
                cout << "\nLogin successful!" << endl;
                m.name = found->getUusername();
                m.id = found->getId();
                string editchoice;
                cout << "Would you edit your password? (yes/no): ";
                cin >> editchoice;
                if (editchoice == "yes") {
                    string newPassword;
                    cout << "Enter new password: "; cin >> newPassword;
                    found->setPassword(newPassword);
                    FileManager::saveMembers(app.getAdmin().members);
                }
                cout << "\n===== User Information =====" << endl;
                found->displayinfo();

                int userChoice;
                do {
                    cout << "\n===== User Menu =====" << endl;
                    cout << "1. View My Profile\n2. Health Tracker\n3. BMI Tips\n4. Sport Assignment\n5. Change My Sport\n6. Show My Sport\n7. Membership Details\n8. Set Membership Plan\n9. View Membership Benefits\n10. Logout\nEnter choice: ";
                    cin >> userChoice;

                    switch (userChoice) {
                    case 1:
                        UI::ShowProfile(m);
                        break;
                    case 2: {
                        double w, h;
                        cout << "Enter weight (kg): ";
                        cin >> w;
                        cout << "Enter height (m): ";
                        cin >> h;
                        UI::ShowHealthReport(m.name, w, h);
                        break;
                    }
                    case 3: {
                        double w, h;
                        cout << "Enter weight (kg): ";
                        cin >> w;
                        cout << "Enter height (m): ";
                        cin >> h;
                        double bmi = ht.calculateBMI(w, h);
                        string bmiStatus = ShowStat(bmi);
                        cout << "BMI Status: " << bmiStatus << endl;
                        string keyword;
                        if (bmi < 18.5) keyword = "underweight";
                        else if (bmi <= 24.9) keyword = "fit";
                        else if (bmi <= 29.9) keyword = "overweight";
                        else keyword = "obese";
                        cout << tips(keyword) << endl;
                        break;
                    }
                    case 4:
                        cout << s.assignSport(m) << endl;
                        break;
                    case 5: {
                        string newSport;
                        cout << "Enter new sport: ";
                        cin >> newSport;
                        cout << s.changeSport(m, newSport) << endl;
                        break;
                    }
                    case 6:
                        cout << s.showSport(m) << endl;
                        break;
                    case 7:
                        membership.displayStatus();
                        break;
                    case 8: {
                        string plan, start, end;
                        cout << "Enter plan type (standard / gold / VIP): ";
                        cin >> plan;
                        cout << "Enter start date (e.g. 2025-01-01): ";
                        cin >> start;
                        cout << "Enter end date    (e.g. 2025-12-31): ";
                        cin >> end;
                        membership.setPlanType(plan);
                        membership.setStartDate(start);
                        membership.setEndDate(end);
                        membership.setStatus("Active");
                        cout << "Membership updated successfully!" << endl;
                        break;
                    }
                    case 9: {
                        string plan = membership.getPlanType();
                        cout << "\n===== Benefits for plan: " << plan << " =====" << endl;
                        cout << membership.DisplayBenefits(plan) << endl;
                        break;
                    }
                    case 10:
                        app.logout();
                        break;
                    default:
                        cout << "Invalid choice!" << endl;
                    }
                } while (userChoice != 10);
            }
            else {
                cout << "\nLogin failed!" << endl;
            }
            break;
        }
        case 3:
            app.shutdownSystem();
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 3);

    return 0;
}