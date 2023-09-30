#include "iostream"
using namespace std;

void storeCoords(int counter, int x, int y, int arrayX[], int arrayY[]){
    cout << "\nEnter in X coordinate:";
    cin >> x;
    arrayX[counter] = x;
    cout << "\nEnter in Y coordinate:";
    cin >> y;
    arrayY[counter] = y;
    cout << "\nLocation " << x << ", " << y << " has been stored.\n\n";
}
void remove(int index, int counter, int arrayX[], int arrayY[]){
    cout << "\nLocation " << arrayX[index - 1] << ", " << arrayY[index - 1] << "has been removed from memory.\n\n";
    // Replaces the element at index with the element to the right and shifts the array over to the right once
    for (int i = index - 1; i < counter; i++) {
        arrayX[i] = arrayX[i + 1];
        arrayY[i] = arrayY[i + 1];
    }
    // Sets the last element in the array to null
    arrayX[counter - 1] = NULL;
    arrayY[counter - 1] = NULL;
}
void printStored(int counter, int arrayX[], int arrayY[]){
    cout << "\nThe following locations are stored:\n";
    for (int i = 0; i < counter; i++){
        cout << i + 1 << ": " << arrayX[i] << ", " << arrayY[i] << "\n";
    }
    cout << "\n";
}
int main() {
    int userChoice;
    int x, y, r;
    int counter = 0;
    int *arrayX = new int[counter];
    int *arrayY = new int[counter];
    while(userChoice != 0) {
        cout << "Choose an option:\n0) To exit\n1) Store a new location:\n2) Remove a location \n3) Show stored locations\n\n";
        cin >> userChoice;
        switch(userChoice) {
            case 0:
                delete arrayX;
                delete arrayY;
                break;
            case 1:
                // Stores coords
                storeCoords(counter, x, y, arrayX, arrayY);
                counter++;
                break;
            case 2:
                // Displays coords
                printStored(counter, arrayX, arrayY);
                // Prompts user to enter which location they wish to remove
                cout << "Which location do you want to remove?\n";
                cin >> r;
                // Calls remove function
                remove(r, counter, arrayX, arrayY);
                counter--;
                break;
            case 3:
                // Display coords
                printStored(counter, arrayX, arrayY);
                break;
        }
    }
    return 0;
}