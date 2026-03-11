#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class Parcel {
public:
    int id;
    string sender;
    string receiver;
    string dispatchAddress;
    string deliveryAddress;
    string currentLocation;
    string status;

    Parcel(int i, string s, string r, string dispatch, string delivery) {
        id = i;
        sender = s;
        receiver = r;
        dispatchAddress = dispatch;
        deliveryAddress = delivery;
        currentLocation = dispatch;
        status = "Registered";
    }
};

vector<Parcel> parcels;
int nextID = 1001;

void registerParcel() {

    string sender, receiver, dispatch, delivery;

    cin.ignore();

    cout << "\nEnter Sender Name: ";
    getline(cin, sender);

    cout << "Enter Receiver Name: ";
    getline(cin, receiver);

    cout << "Enter Dispatch Address: ";
    getline(cin, dispatch);

    cout << "Enter Delivery Address: ";
    getline(cin, delivery);

    Parcel p(nextID, sender, receiver, dispatch, delivery);
    parcels.push_back(p);

    cout << "\nParcel Registered Successfully!\n";
    cout << "Tracking ID: " << nextID << endl;

    nextID++;
}

void updateStatus() {

    int id, choice;

    cout << "\nEnter Tracking ID: ";
    cin >> id;

    for (auto &p : parcels) {

        if (p.id == id) {

            cin.ignore();

            cout << "\nSelect Status Update\n";
            cout << "1. In Transit\n";
            cout << "2. Out For Delivery\n";

            cout << "Enter Choice: ";
            cin >> choice;

            cin.ignore();

            cout << "Enter Current Location: ";
            getline(cin, p.currentLocation);

            if(choice == 1)
                p.status = "In Transit";
            else if(choice == 2)
                p.status = "Out For Delivery";

            cout << "\nTracking Updated!\n";
            return;
        }
    }

    cout << "\nParcel Not Found\n";
}

void confirmDelivery() {

    int id;

    cout << "\nEnter Tracking ID: ";
    cin >> id;

    for (auto &p : parcels) {

        if (p.id == id) {

            p.status = "Delivered";
            p.currentLocation = p.deliveryAddress;

            cout << "\nDelivery Confirmed!\n";
            return;
        }
    }

    cout << "\nParcel Not Found\n";
}

void viewAllParcels() {

    if (parcels.empty()) {
        cout << "\nNo Parcels Registered\n";
        return;
    }

    cout << "\nAll Parcels\n";
    cout << "------------------------------------------------------------------------------------------------\n";

    cout << setw(8) << "ID"
         << setw(15) << "Sender"
         << setw(15) << "Receiver"
         << setw(20) << "Dispatch"
         << setw(20) << "Delivery"
         << setw(15) << "Location"
         << setw(15) << "Status" << endl;

    cout << "------------------------------------------------------------------------------------------------\n";

    for (auto &p : parcels) {

        cout << setw(8) << p.id
             << setw(15) << p.sender
             << setw(15) << p.receiver
             << setw(20) << p.dispatchAddress
             << setw(20) << p.deliveryAddress
             << setw(15) << p.currentLocation
             << setw(15) << p.status << endl;
    }
}

void trackParcel() {

    int id;

    cout << "\nEnter Tracking ID: ";
    cin >> id;

    for (auto &p : parcels) {

        if (p.id == id) {

            cout << "\nParcel Details\n";
            cout << "----------------------------\n";
            cout << "Sender: " << p.sender << endl;
            cout << "Receiver: " << p.receiver << endl;
            cout << "Dispatch Address: " << p.dispatchAddress << endl;
            cout << "Delivery Address: " << p.deliveryAddress << endl;
            cout << "Current Location: " << p.currentLocation << endl;
            cout << "Status: " << p.status << endl;

            return;
        }
    }

    cout << "\nParcel Not Found\n";
}

void courierMenu() {

    int choice;

    do {

        cout << "\n===== Courier Staff Menu =====";
        cout << "\n1. Register Parcel";
        cout << "\n2. Update Tracking";
        cout << "\n3. Confirm Delivery";
        cout << "\n4. View All Parcels";
        cout << "\n5. Back";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch(choice) {

            case 1:
                registerParcel();
                break;

            case 2:
                updateStatus();
                break;

            case 3:
                confirmDelivery();
                break;

            case 4:
                viewAllParcels();
                break;
        }

    } while(choice != 5);
}

void customerMenu() {

    int choice;

    do {

        cout << "\n===== Customer Menu =====";
        cout << "\n1. Track Parcel";
        cout << "\n2. Back";

        cout << "\nEnter Choice: ";
        cin >> choice;

        if(choice == 1)
            trackParcel();

    } while(choice != 2);
}

int main() {

    int role;

    do {

        cout << "\n================================";
        cout << "\n Courier & Parcel Tracking System";
        cout << "\n================================";

        cout << "\n1. Courier Staff";
        cout << "\n2. Customer";
        cout << "\n3. Exit";

        cout << "\nSelect Role: ";
        cin >> role;

        switch(role) {

            case 1:
                courierMenu();
                break;

            case 2:
                customerMenu();
                break;

        }

    } while(role != 3);

    cout << "\nSystem Closed\n";

    return 0;
}