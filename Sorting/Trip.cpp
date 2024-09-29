#include <iostream>
#include <vector>
using namespace std;

class GulFatima_Lab05 {
    int capacity;
    vector<vector<int>> trips;

public:
    GulFatima_Lab05(int cap, const vector<vector<int>>& tripData) {
        capacity = cap;
        trips = tripData;
    }
    bool cancap() {
        int stops[100] = { 0 };
        for (const auto& trip : trips) {
            int numPassengers = trip[0];
            int from = trip[1];
            int to = trip[2];
            stops[from] += numPassengers;
            stops[to] -= numPassengers;
        }
        int currentPassengers = 0;
        for (int i = 0; i < 100; ++i) {
            currentPassengers += stops[i];
            if (currentPassengers > capacity)
                return false;
        }
        return true;
    }
    void inputTrips() {
        int numTrips;
        cout << "Enter the number of trips: ";
        cin >> numTrips;

        trips.resize(numTrips, vector<int>(3));

        cout << "Enter trip details (numPassengers, from, to) for each trip:" << endl;
        for (int i = 0; i < numTrips; ++i) {
            cout << "Trip " << (i + 1) << ": ";
            cin >> trips[i][0] >> trips[i][1] >> trips[i][2];
        }
    }
};
int main() {
    int capacity1;
    cout << "Enter the capacity of the car: ";
    cin >> capacity1;
    vector<vector<int>> tripData; // Temp var for trips
    GulFatima_Lab05 car1(capacity1, tripData);
    car1.inputTrips();
    if (car1.cancap()) {
        cout << "It's possible to complete all trips (true)." << endl;
    }
    else {
        cout << "It's not possible to complete all trips (false)." << endl;
    }

    return 0;
}
