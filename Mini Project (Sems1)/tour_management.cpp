#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <chrono>
#include <thread>
#include <filesystem>  // Requires C++17
#include <cctype>
#include <map>
namespace fs = std::filesystem;
using namespace std;


class User {
public:
    string username;
    string password;
    vector<Booking> bookings;

    User(string uname, string pass) : username(uname), password(pass) {}

    // Method to add booking to user's account
    void addBooking(const Booking& booking) {
        bookings.push_back(booking);
    }

    // Method to cancel a booking
    bool cancelBooking(int bookingID) {
        for (auto it = bookings.begin(); it != bookings.end(); ++it) {
            if (it->getBookingID() == bookingID) {
                bookings.erase(it);
                return true;
            }
        }
        return false;
    }

    void displayBookings() const {
        if (bookings.empty()) {
            cout << "No bookings found!" << endl;
        } else {
            cout << "Your Bookings: \n";
            for (const auto& booking : bookings) {
                booking.display();
            }
        }
    }

    // Display user details (for testing purposes)
    void displayUserDetails() const {
        cout << "Username: " << username << "\n";
        displayBookings();
    }
};


class UserManager {
private:
    map<string, User> users; // Key: username, Value: User object

public:
    // Add new user to the system
    void registerUser(const string& username, const string& password) {
        if (users.find(username) != users.end()) {
            cout << "Username already taken. Try a different one." << endl;
        } else {
            users[username] = User(username, password);
            cout << "Registration successful!" << endl;
        }
    }

    // Login method
    User* loginUser(const string& username, const string& password) {
        if (users.find(username) == users.end()) {
            cout << "Username not found." << endl;
            return nullptr;
        }
        User& user = users[username];
        if (user.password == password) {
            return &user;
        } else {
            cout << "Incorrect password." << endl;
            return nullptr;
        }
    }

    // Check if user exists
    bool userExists(const string& username) {
        return users.find(username) != users.end();
    }
};
// Utility functions for input verification
namespace InputValidator {
    bool isValidAge(const string& ageStr) {
        // Ensure the age string contains only digits and represents a valid number (between 1 and 120, for example)
        for (char c : ageStr) {
            if (!isdigit(c))
                return false;
        }
        int age = stoi(ageStr);
        return (age > 0 && age < 121);
    }

    bool isValidEmail(const string& email) {
        // Very basic email validation: must have one '@' and at least one '.'
        size_t atPos = email.find('@');
        size_t dotPos = email.find('.', atPos);
        return (atPos != string::npos && dotPos != string::npos && email.length() > 5);
    }

    bool isValidPhone(const string& phone) {
        if (phone.length() != 10)
            return false;
        for (char c : phone) {
            if (!isdigit(c))
                return false;
        }
        return true;
    }

    bool isValidAdhaar(const string& id) {
        if (id.length() != 12)
            return false;
        for (char c : id) {
            if (!isdigit(c))
                return false;
        }
        return true;
    }

    bool isValidPAN(const string& id) {
        // For simplicity, only checking length; you can add pattern checks if needed.
        return (id.length() == 10);
    }
}

// Class to hold customer information
class Customer {
public:
    string name;
    int age;
    string email;
    string phone;
    char gender;
    string idProof;   // Either Adhaar or PAN number
    string idType;    // "Adhaar" or "PAN"

    // Get details interactively and save to file
    void inputDetails() {
        cout << "\nEnter Passenger Name: ";
        getline(cin, name);

        string ageStr;
        cout << "Enter Age: ";
        getline(cin, ageStr);
        while (!InputValidator::isValidAge(ageStr)) {
            cout << "Invalid age. Please enter a valid age (numeric between 1 and 120): ";
            getline(cin, ageStr);
        }
        age = stoi(ageStr);

        cout << "Enter Email Address: ";
        getline(cin, email);
        while (!InputValidator::isValidEmail(email)) {
            cout << "Invalid email address. Please re-enter: ";
            getline(cin, email);
        }

        cout << "Enter Phone Number (10 digits): ";
        getline(cin, phone);
        while (!InputValidator::isValidPhone(phone)) {
            cout << "Invalid phone number. Please re-enter (10 digits): ";
            getline(cin, phone);
        }

        cout << "\nSelect Gender:\n"
             << "1. Male\n2. Female\n3. Prefer not to say\n"
             << "Enter choice: ";
        int gChoice = 0;
        cin >> gChoice;
        cin.ignore(); // consume newline
        switch (gChoice) {
        case 1:
            gender = 'M';
            break;
        case 2:
            gender = 'F';
            break;
        case 3:
            gender = 'N';
            break;
        default:
            gender = 'N';
            break;
        }

        cout << "\nSelect type of ID Proof:\n"
             << "1. Adhaar Card\n2. PAN Card\n"
             << "Enter choice: ";
        int idChoice = 0;
        cin >> idChoice;
        cin.ignore();
        if (idChoice == 1) {
            idType = "Adhaar";
            cout << "Enter Adhaar Number (12 digits): ";
            getline(cin, idProof);
            while (!InputValidator::isValidAdhaar(idProof)) {
                cout << "Invalid Adhaar Number. Re-enter (12 digits): ";
                getline(cin, idProof);
            }
        } else {
            idType = "PAN";
            cout << "Enter PAN Number (10 characters): ";
            getline(cin, idProof);
            while (!InputValidator::isValidPAN(idProof)) {
                cout << "Invalid PAN Number. Re-enter (10 characters): ";
                getline(cin, idProof);
            }
        }
    }

    // Save customer info to a file
    void saveToFile(const fs::path& filePath) const {
        ofstream outFile(filePath, ios::app);
        if (!outFile) {
            cerr << "Error opening file for saving customer info." << endl;
            return;
        }
        outFile << "Name       : " << name << "\n"
                << "Age        : " << age << "\n"
                << "Email      : " << email << "\n"
                << "Phone      : " << phone << "\n"
                << "Gender     : " << gender << "\n"
                << "ID Type    : " << idType << "\n"
                << "ID Number  : " << idProof << "\n"
                << "------------------------------------------\n";
        outFile.close();
    }

    // Display customer info
    void display() const {
        cout << "Name       : " << name << "\n"
             << "Age        : " << age << "\n"
             << "Email      : " << email << "\n"
             << "Phone      : " << phone << "\n"
             << "Gender     : " << gender << "\n"
             << "ID Type    : " << idType << "\n"
             << "ID Number  : " << idProof << "\n";
    }
};

// Class to manage different travel packages
class Package {
public:
    int packageID;
    string title;
    string from;
    string to;
    int days;
    int nights;
    int distance;         // in km
    bool isDomestic;      // true if domestic, false if international

    // Additional details (amenities)
    vector<string> amenities;

    Package(int id, const string& title, const string& from, const string& to,
            int days, int nights, int distance, bool domestic, const vector<string>& amenities)
        : packageID(id), title(title), from(from), to(to), days(days), nights(nights),
          distance(distance), isDomestic(domestic), amenities(amenities) {}

    void display() const {
        cout << "Package ID: " << packageID << " - " << title << "\n"
             << "   Route: " << from << "  -->  " << to << "\n"
             << "   Duration: " << days << " Days / " << nights << " Nights\n"
             << "   Distance: " << distance << " km\n"
             << "   Amenities: ";
        for (const auto& amenity : amenities)
            cout << amenity << "  ";
        cout << "\n------------------------------------------\n";
    }
};

// Class to manage available packages and booking costs
class PackageManager {
private:
    vector<Package> domesticPackages;
    vector<Package> internationalPackages;
public:
    PackageManager() {
        // Initialize domestic packages
        domesticPackages.push_back(Package(1, "Manali Escape", "New Delhi", "Manali", 7, 6, 555, true,
                                           { "Breakfast Included", "CAB Service", "Local Guide" }));
        domesticPackages.push_back(Package(2, "Srinagar Delight", "Chandigarh", "Srinagar", 6, 5, 570, true,
                                           { "Breakfast Included", "CAB Service", "Local Guide" }));
        domesticPackages.push_back(Package(3, "Kedarnath Trek", "Dehradun", "Kedarnath", 5, 4, 110, true,
                                           { "Breakfast Included", "CAB Service", "Local Guide" }));
        domesticPackages.push_back(Package(4, "Dalhousie Retreat", "Dharamshala", "Dalhousie", 5, 4, 118, true,
                                           { "Breakfast Included", "CAB Service", "Local Guide" }));
        domesticPackages.push_back(Package(5, "Mount Abu Getaway", "Udaipur", "Mount Abu", 5, 4, 110, true,
                                           { "Breakfast Included", "CAB Service", "Local Guide" }));

        // Initialize international packages
        internationalPackages.push_back(Package(1, "Dubai Extravaganza", "New Delhi", "Dubai", 9, 8, 2200, false,
                                                  { "Breakfast Included", "CAB Service", "Local Guide" }));
        internationalPackages.push_back(Package(2, "Maldives Paradise", "Mumbai", "Maldives", 8, 7, 1933, false,
                                                  { "Breakfast Included", "CAB Service", "Local Guide" }));
    }

    void displayPackages(bool domestic) const {
        if (domestic) {
            cout << "\n----- Domestic Packages -----\n";
            for (const auto& pkg : domesticPackages) {
                pkg.display();
            }
        } else {
            cout << "\n----- International Packages -----\n";
            for (const auto& pkg : internationalPackages) {
                pkg.display();
            }
        }
    }

    // Retrieve package by ID and type (domestic/international)
    Package getPackage(bool domestic, int packageID) const {
        const vector<Package>& packages = domestic ? domesticPackages : internationalPackages;
        for (const auto& pkg : packages) {
            if (pkg.packageID == packageID)
                return pkg;
        }
        throw runtime_error("Invalid package ID selected.");
    }
};

// Class to handle booking and cost calculations
class Booking {
private:
    const Customer customer;
    const Package travelPackage;
    bool isDomestic;
    int numPassengers;
    // Travel options:
    // For domestic: transport: 1=BUS, 2=TRAIN, 3=FLIGHT
    int transportChoice;  
    // For both types: hotel choice: 1=Hostel, 2=Regular, 3=Luxury
    int hotelChoice;
    bool wantCab;
    int cabDistance; // in km (if wantCab true)
    bool wantGuide;
public:
    Booking(const Customer& cust, const Package& pkg, int numPassengers, bool isDomestic)
        : customer(cust), travelPackage(pkg), numPassengers(numPassengers), isDomestic(isDomestic),
          transportChoice(0), hotelChoice(0), wantCab(false), cabDistance(0), wantGuide(false) {}
   
   
    int Booking::getBookingID() const {
    return customer.age; // Just for illustration; use a unique identifier like an auto-increment ID
    }

    void Booking::display() const {
    cout << "\nBooking ID: " << getBookingID() << "\n"
         << "Package: " << travelPackage.title << "\n"
         << "Number of Passengers: " << numPassengers << "\n"
         << "Accommodation Choice: " << hotelChoice << "\n"
         << "Transport Mode: " << transportChoice << "\n"
         << "Cab Service: " << (wantCab ? "Yes" : "No") << "\n"
         << "Local Guide: " << (wantGuide ? "Yes" : "No") << "\n";
}

    void inputOptions() {
        if (isDomestic) {
            cout << "\nSelect Mode of Travel for Domestic Tour:\n";
            cout << "1. Bus\n2. Train\n3. Flight\nEnter choice: ";
            cin >> transportChoice;
            while (transportChoice < 1 || transportChoice > 3) {
                cout << "Invalid choice. Please select 1, 2, or 3: ";
                cin >> transportChoice;
            }
        }
        cout << "\nSelect Accommodation Option:\n"
             << "1. Hostel (Rs. 500/day per person)\n"
             << "2. Regular Room (Rs. 1000/day per person)\n"
             << "3. Luxury Suite (Rs. 2500/day per person)\n"
             << "Enter choice: ";
        cin >> hotelChoice;
        while (hotelChoice < 1 || hotelChoice > 3) {
            cout << "Invalid choice. Please select 1, 2, or 3: ";
            cin >> hotelChoice;
        }

        int cabOpt;
        cout << "\nDo you require Cab Service? (Cab rate: Rs.11/km per person)\n";
        cout << "1. Yes\n2. No\nEnter choice: ";
        cin >> cabOpt;
        wantCab = (cabOpt == 1);
        if (wantCab) {
            cout << "Enter the number of kilometers you wish to travel by cab: ";
            cin >> cabDistance;
        }

        int guideOpt;
        cout << "\nDo you require a Local Guide? (Local guide: Rs.1000/day per booking)\n";
        cout << "1. Yes\n2. No\nEnter choice: ";
        cin >> guideOpt;
        wantGuide = (guideOpt == 1);
        cin.ignore();  // Clear input buffer
    }

    // Calculate cost components based on selections and package details
    int calculateTransportationCost() const {
        int cost = 0;
        if (isDomestic) {
            // Transportation costs for domestic packages vary by package and mode
            // (Example rates; you can adjust as needed.)
            if (travelPackage.packageID == 1) {
                if (transportChoice == 1)
                    cost = 850;
                else if (transportChoice == 2)
                    cost = 1100;
                else if (transportChoice == 3)
                    cost = 5500;
            } else if (travelPackage.packageID == 2) {
                if (transportChoice == 1)
                    cost = 2000;
                else if (transportChoice == 2)
                    cost = 1500;
                else if (transportChoice == 3)
                    cost = 3200;
            } else if (travelPackage.packageID == 3) {
                if (transportChoice == 1)
                    cost = 1900;
                else if (transportChoice == 2)
                    cost = 3000;
                else if (transportChoice == 3)
                    cost = 6500;
            } else if (travelPackage.packageID == 4) {
                if (transportChoice == 1)
                    cost = 3100;
                else if (transportChoice == 2)
                    cost = 2300;
                else if (transportChoice == 3)
                    cost = 4300;
            } else if (travelPackage.packageID == 5) {
                if (transportChoice == 1)
                    cost = 1600;
                else if (transportChoice == 2)
                    cost = 900;
                else if (transportChoice == 3)
                    cost = 3500;
            }
            // Multiply by number of passengers and round-trip (x2)
            return cost * numPassengers * 2;
        } else {
            // International fixed costs for simplicity
            if (travelPackage.packageID == 1)
                cost = 12000;
            else if (travelPackage.packageID == 2)
                cost = 9000;
            return cost * numPassengers * 2;
        }
    }

    int calculateHotelCost() const {
        int ratePerDay = 0;
        if (hotelChoice == 1)
            ratePerDay = 500;
        else if (hotelChoice == 2)
            ratePerDay = 1000;
        else if (hotelChoice == 3)
            ratePerDay = 2500;
        // Use package days for calculation
        return ratePerDay * numPassengers * travelPackage.days;
    }

    int calculateCabCost() const {
        if (!wantCab)
            return 0;
        return cabDistance * 11 * numPassengers;
    }

    int calculateGuideCost() const {
        if (!wantGuide)
            return 0;
        // Guide cost is Rs.1000 per day (per booking)
        return 1000 * travelPackage.days;
    }

    int calculateTotalCost() const {
        return calculateTransportationCost() + calculateHotelCost() +
               calculateCabCost() + calculateGuideCost();
    }

    void displayReceipt() const {
        system("cls"); // Clear screen (platform dependent)
        cout << "\n==================== BOOKING RECEIPT ====================\n\n";
        cout << "Passenger Details:\n";
        customer.display();
        cout << "\nPackage Details:\n";
        cout << "   Package: " << travelPackage.title << "\n"
             << "   Route  : " << travelPackage.from << " -> " << travelPackage.to << "\n"
             << "   Duration: " << travelPackage.days << " Days / " << travelPackage.nights << " Nights\n\n";

        cout << "Cost Breakdown:\n";
        cout << left << setw(35) << "Transportation Cost:" << "Rs. " << calculateTransportationCost() << "\n";
        cout << left << setw(35) << "Hotel Cost:" << "Rs. " << calculateHotelCost() << "\n";
        if (wantCab)
            cout << left << setw(35) << "Cab Cost:" << "Rs. " << calculateCabCost() << "\n";
        else
            cout << left << setw(35) << "Cab Cost:" << "Rs. 0" << "\n";
        if (wantGuide)
            cout << left << setw(35) << "Local Guide Cost:" << "Rs. " << calculateGuideCost() << "\n";
        else
            cout << left << setw(35) << "Local Guide Cost:" << "Rs. 0" << "\n";

        cout << "\n" << string(50, '=') << "\n";
        cout << left << setw(35) << "Total Cost:" << "Rs. " << calculateTotalCost() << "\n";
        cout << string(50, '=') << "\n\n";
    }
};

// A function to display a decorative startup design with delay
void displayDesign() {
    system("cls");
    cout << "\n\n\t\t\tWELCOME TO THE TRAVEL BOOKING SYSTEM\n";
    cout << "\t\t      ***************************************\n\n";
    cout << "\t\t        Your journey begins here...\n\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    system("cls");
}
// Main function to handle user login, booking, viewing, and cancellation
int main() {
    UserManager userManager;

    // Register a new user (only run once for first-time registration)
    userManager.registerUser("john_doe", "password123");

    // Simulate the login process
    string username, password;
    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;

    User* loggedInUser = userManager.loginUser(username, password);
    if (loggedInUser) {
        cout << "Login successful!" << endl;

        bool userMenuActive = true;
        while (userMenuActive) {
            cout << "\n--- User Menu ---\n";
            cout << "1. View Bookings\n";
            cout << "2. Book a Package\n";
            cout << "3. Cancel a Booking\n";
            cout << "4. Log Out\n";
            cout << "Enter choice: ";
            int choice;
            cin >> choice;

            switch (choice) {
                case 1: {
                    loggedInUser->displayBookings();
                    break;
                }
                case 2: {
                    cout << "Choose a package (1 for Domestic, 2 for International): ";
                    bool isDomestic;
                    cin >> isDomestic;

                    // Display packages based on domestic or international
                    PackageManager packageManager;
                    packageManager.displayPackages(isDomestic);

                    // Assume user selects a package (we will simulate with ID 1 for now)
                    int packageID;
                    cout << "Enter Package ID: ";
                    cin >> packageID;

                    // Get selected package (this assumes the ID exists)
                    Package selectedPackage = packageManager.getPackage(isDomestic, packageID);

                    // Input booking details (simplified)
                    Customer customer;
                    customer.inputDetails();

                    int numPassengers;
                    cout << "Enter number of passengers: ";
                    cin >> numPassengers;

                    // Create booking
                    Booking newBooking(customer, selectedPackage, numPassengers, isDomestic);

                    // Add to user's bookings
                    loggedInUser->addBooking(newBooking);
                    cout << "Booking Successful!" << endl;

                    break;
                }
                case 3: {
                    // Allow user to cancel a booking
                    loggedInUser->displayBookings();
                    int bookingID;
                    cout << "Enter Booking ID to cancel: ";
                    cin >> bookingID;

                    if (loggedInUser->cancelBooking(bookingID)) {
                        cout << "Booking canceled successfully!" << endl;
                    } else {
                        cout << "Booking ID not found." << endl;
                    }
                    break;
                }
                case 4: {
                    cout << "Logging out..." << endl;
                    userMenuActive = false;
                    break;
                }
                default:
                    cout << "Invalid choice!" << endl;
                    break;
            }
        }
    }

    return 0;
}