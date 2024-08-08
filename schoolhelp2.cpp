

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

// SchoolHELP Class
class SchoolHELP {
    public:
        int schoolID; // Auto-generated
        string schoolName;
        string schoolAddress;
        string city;
};

// Admin Class
class Admin {
    public:
        string username;
        string password;
        string fullname;
        string email;
        string phone;
        string staffID;
        string position;
};

// Volunteer Class
class Volunteer {
    public:
        string username;
        string password;
        string fullname;
        string email;
        string phone;
        string occupation;
        string dob;
};

// Request Class
class Request :public SchoolHELP{
    public:
        int requestID; // Auto-generated
        string description;
        string proposedDate;
        string studentLevel;
        int numStudents;
        string requestDate;
        string requestStatus;
        string resourceType;
        int numberRequired;
};

// Offer Class
class Offer {
    public:
        string offerRemarks;
        string offerStatus;
        string offerDate;
        string volunteerName;
        int volunteerAge;
        string volunteerOccupation;
};

// Function to Register School
void registerSchool(SchoolHELP &school, Admin &admin) {
    // Get School Details
    cout << "Enter School Name: ";
    cin >> school.schoolName;
    cout << "Enter School Address: ";
    cin >> school.schoolAddress;
    cout << "Enter City: ";
    cin >> school.city;
    cout << "\nSchool Registered Successfully!" << endl;
    
    // Auto-generate School ID
    school.schoolID = rand() % 10000;
    cout << "School ID: " << school.schoolID << endl;

    // Get Admin Details
    cout << "\nEnter Admin Username: ";
    cin >> admin.username;
    cout << "Enter Admin Password: ";
    cin >> admin.password;
    cout << "Enter Admin's Full Name: ";
    cin >> admin.fullname;
    cout << "Enter Admin's Email: ";
    cin >> admin.email;
    cout << "Enter Admin's Phone: ";
    cin >> admin.phone;
    cout << "Enter Admin's Staff ID: ";
    cin >> admin.staffID;
    cout << "Enter Admin's Position: ";
    cin >> admin.position;
    cout << "\nAdmin Registered Successfully!" << endl;
}

// Function to Submit Request
void submitRequest(Request &request) {
    // Get Request Details
    cout << "\nEnter Request Description: ";
    cin >> request.description;
    cout << "Enter Proposed Date and Time: ";
    cin >> request.proposedDate;
    cout << "Enter Student Level: ";
    cin >> request.studentLevel;
    cout << "Enter Number of Students: ";
    cin >> request.numStudents;
    cout << "\nRequest Submitted Successfully!" << endl;

    // Auto-generate Request ID
    request.requestID = rand() % 10000;
    cout << "Request ID: " << request.requestID << endl;

    // Set Request Date
    request.requestDate = "";
    cout << "Request Date: " << request.requestDate << endl;

    // Set Request Status
    request.requestStatus = "NEW";
    cout << "Request Status: " << request.requestStatus << endl;
}

// Function to Register as Volunteer
void registerVolunteer(Volunteer &volunteer) {
    // Get Volunteer Details
    cout << "\nEnter Volunteer Username: ";
    cin >> volunteer.username;
    cout << "Enter Volunteer Password: ";
    cin >> volunteer.password;
    cout << "Enter Volunteer's Full Name: ";
    cin >> volunteer.fullname;
    cout << "Enter Volunteer's Email: ";
    cin >> volunteer.email;
    cout << "Enter Volunteer's Phone: ";
    cin >> volunteer.phone;
    cout << "Enter Volunteer's Occupation: ";
    cin >> volunteer.occupation;
    cout << "Enter Volunteer's Date of Birth: ";
    cin >> volunteer.dob;
    cout << "\nVolunteer Registered Successfully!" << endl;
}

// Function to View Requests
void viewRequests(Request &request) {
    int option;
    // Get Request Details
    cout << "\nEnter Option to View Requests (1 - School, 2 - City, 3 - Request Date): ";
    cin >> option;

    // Show Request List
    cout << "\nRequest List: " << endl;
    cout << "Request ID" << "\t" << "Request Description" << "\t" << "School Name" << "\t" << "City" << endl;
    cout << request.requestID << "\t" << request.description << "\t" << request.schoolName<< "\t" << request.city << endl;

    // Show Request Details
    cout << "\nRequest Details: " << endl;
    cout << "Request ID: " << request.requestID << endl;
    cout << "Request Description: " << request.description << endl;
    if (option == 1) {
        cout << "School Name: " << request.schoolName << endl;
    }
    else if (option == 2) {
        cout << "City: " << request.city << endl;
    }
    else if (option == 3) {
        cout << "Request Date: " << request.requestDate << endl;
    }
    cout << "Student Level: " << request.studentLevel << endl;
    cout << "Number of Students: " << request.numStudents << endl;
}

// Function to Submit Offer
void submitOffer(Request &request, Offer &offer, Volunteer &volunteer) {
    // Get Offer Details
    cout << "\nEnter Offer Remarks: ";
    cin >> offer.offerRemarks;
    offer.offerStatus = "PENDING";
    offer.offerDate = "";
    offer.volunteerName = volunteer.fullname;
    offer.volunteerAge = 0;
    offer.volunteerOccupation = volunteer.occupation;

    // Show Offer Details
    cout << "\nOffer Details: " << endl;
    cout << "Request ID: " << request.requestID << endl;
    cout << "Offer Remarks: " << offer.offerRemarks << endl;
    cout << "Offer Status: " << offer.offerStatus << endl;
    cout << "Offer Date: " << offer.offerDate << endl;
    cout << "Volunteer Name: " << offer.volunteerName << endl;
    cout << "Volunteer Age: " << offer.volunteerAge << endl;
    cout << "Volunteer Occupation: " << offer.volunteerOccupation << endl;
    cout << "\nOffer Submitted Successfully!" << endl;
}

// Function to Review Offers
void reviewOffers(Request &request, Offer &offer) {
    // Show Request Details
    cout << "\nRequest Details: " << endl;
    cout << "Request ID: " << request.requestID << endl;
    cout << "Request Description: " << request.description << endl;
    cout << "Request Status: " << request.requestStatus << endl;
    cout << "Request Date: " << request.requestDate << endl;

    // Show Offer Details
    cout << "\nOffer Details: " << endl;
    cout << "Offer Remarks: " << offer.offerRemarks << endl;
    cout << "Offer Status: " << offer.offerStatus << endl;
    cout << "Offer Date: " << offer.offerDate << endl;
    cout << "Volunteer Name: " << offer.volunteerName << endl;
    cout << "Volunteer Age: " << offer.volunteerAge << endl;
    cout << "Volunteer Occupation: " << offer.volunteerOccupation << endl;

    // Accept Offer
    int option;
    cout << "\nEnter Option to Accept Offer (1 - Accept, 2 - Reject): ";
    cin >> option;
    if (option == 1) {
        offer.offerStatus = "ACCEPTED";
        cout << "\nOffer Accepted Successfully!" << endl;
    }
    else if (option == 2) {
        offer.offerStatus = "REJECTED";
        cout << "\nOffer Rejected Successfully!" << endl;
    }

    // Close Request
    cout << "\nEnter Option to Close Request (1 - Yes, 2 - No): ";
    cin >> option;
    if (option == 1) {
        request.requestStatus = "CLOSED";
        cout << "\nRequest Closed Successfully!" << endl;
    }
}
void mainsection(){
    // Create objects
    SchoolHELP school;
    Admin admin;
    Volunteer volunteer;
    Request request;
    Offer offer;
     while (true)
    {
    int n;
    cout<<"\t\t\t\tWelcome To School Help\n";
    cout<<"\t\t\t\t1.Register School\n";
    cout<<"\t\t\t\t2.Submit Request\n";
    cout<<"\t\t\t\t3.Register As Volunteer\n";
    cout<<"\t\t\t\t4.View Requests\n";
    cout<<"\t\t\t\t5.Submit Offer\n";
    cout<<"\t\t\t\t6.Review Offers\n";
    cout<<"\t\t\t\t7.Exit\n";
    cin>>n;
    switch (n)
    {
    case 1:
         registerSchool(school, admin);
        break;
    case 2:
         // Submit Request
       submitRequest(request);
       break;
     case 3:
         // Register as Volunteer
    registerVolunteer(volunteer);
        break;
     case 4:
          // View Requests
    viewRequests(request);
         break;
    case 5:
        // Submit Offer
    submitOffer(request, offer, volunteer);
      break;
    case 6:
       // Review Offers
    reviewOffers(request, offer);
         break;
    case 7:
       return;
         break;
     default:
        break;
    }
    }
}
int main() {
    

    //admin id
    string adminid="Admin";
    string adminpass="12345678";
    while(true){
     int click;
     cout<<"Welcome To my Project \n";
    cout<<"\t\t\t\t1.Login\n";
    cout<<"\t\t\t\t2.Sign Up\n";
    cout<<"\t\t\t\t3.Exit\n";
    cin>>click;
    string id,pass;
    switch (click)
    {
    case 1:
        cout<<"\t\t\t\tEnter username \n";
         cin>>id;
         cout<<"\t\t\t\tEnter Password\n";
         cin>>pass;
         if(id==adminid && pass==adminpass)
            mainsection();
         else 
         cout<<"Wrong UserName or Password \n";
        break;
    case 2:
          cout<<"Creating usrname and password......\n";
          cout<<"create username \n";
          cin>>adminid;
          cout<<"create Password\n";
          cin>>adminpass;
          cout<<"Successfully Created \n";
          break;
    case 3:
         return 0;
        default:
        break;
    }
    }
    return 0;
}
